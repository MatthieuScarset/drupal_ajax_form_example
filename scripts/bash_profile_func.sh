JAUNE='\e[1;33m'
CYANFONCE='\e[0;36m'
NEUTRE='\e[0;m'
VERTCLAIR='\e[1;32m'
BLEUCLAIR='\e[1;34m'
ROUGEFONCE='\e[0;31m'

# Création d'une nouvelle branche et synchro auto sur le serveur
git_new_branch() {

	if [ -z "$1" ]
	then
		echo -e "${ROUGEFONCE}Error : Vous devez entrer un nom de branche${NEUTRE}"
	else

		##je me branche sur master que je pull
		if git checkout master && git pull
		then
			git checkout -b "$1"
			git push --set-upstream origin "$1"
		else
			echo -e "${ROUGEFONCE}Erreur avec la branche master${NEUTRE}"
		fi
	fi
}


# Push la branche update puis merge avec le dev et le master
git_push_updates() {

	nomBranche=`git branch | grep "*"`

	##Si on n'est pas sur la branche updates, je quitte le script
	if [[ $nomBranche != "* updates"* ]]
	then
		echo -e "${ROUGEFONCE}Error : Vous devez être sur la branche updates pour executer cette commande${NEUTRE}"
		return
	fi

	#on push updates
	if git push
	then
		##On merge dev et master grace à la fonction ci-dessous
		if git_merge dev integration master
		then
			echo -e "${VERTCLAIR}Success : Merge de updates sur dev & master OK${NEUTRE}"
			return
		fi
	else
		##Si le push rate, je quitte le script
		return
	fi

}


# Merge la branche actuelle avec la branche update
# puis merge la branche update avec dev, integration & master
# Si une branche est passée en paramètre, merge de cette branche avec update
git_merge_updates() {

	#On recupère le nom de la branche actuelle
	nomBranche=`git branch | grep "*"`
	nomBranche=${nomBranche:2:$((${#nomBranche}-1))}

	##On affiche un petit message
	echo -e "${CYANFONCE}___________________________"
	echo -e "branche actuelle :  ${JAUNE}$nomBranche${CYANFONCE}"
	echo -e "Liste des actions :"
	echo -e "\t- Merge de ${JAUNE}$nomBranche${CYANFONCE} sur ${BLEUCLAIR}updates${CYANFONCE}"
	if [ $# -gt 0 ]
	then
		echo -e "\t $# - Merge de ${BLEUCLAIR}updates${NEUTRE} sur ${VERTCLAIR}$1${CYANFONCE}"
	fi
	echo -e "\t- Merge de ${BLEUCLAIR}updates${CYANFONCE} sur ${BLEUCLAIR}dev${CYANFONCE},${BLEUCLAIR}integration${CYANFONCE}  et ${BLEUCLAIR}master${NEUTRE}"

	##On demande validation
	read -p "Etes-vous sur de vouloir continuer ? (O/n)" reponse

	if [ $reponse == "O" ] || [ $reponse == "o" ] || [ $reponse == "Y" ] || [ $reponse == "y" ]
	then
        echo -e "${CYANFONCE}MERGE de $nomBranche sur updates"
		##on merge updates  (le printf 'o' est pour donner la réponse à la question de la fonction git_merge)
		printf 'o' | git_merge updates

		echo -e "${CYANFONCE}git checkout updates"
		##On se déplace sur updates
		if git checkout updates
		then
		    ##S'il y a une branche en paramètre, on merge avec cette branche
            if [ $# -gt 0 ]
            then
                printf 'o' | git_merge $1
            fi

			##On merge updates avec dev et master
			printf 'o' | git_merge dev integration master
			git checkout $nomBranche
		else
			echo "${ROUGEFONCE}Erreur lors de la connexion à la branche updates${NEUTRE}"
		fi
	else
		echo -e "${ROUGEFONCE}Abandon${NEUTRE}"
	fi
}

## Merge la branche actuelle avec les branches passées en paramètre
git_merge() {

	#On recupère le nom de la branche actuelle
	nomBranche=`git branch | grep "*"`
	nomBranche=${nomBranche:2:$((${#nomBranche}-1))}
	
	if [ $# == 0 ]
	then
		echo -e "${ROUGEFONCE}Error : Vous devez entrer les branches à merger${NEUTRE}"
		return
	fi
	##On affiche un petit message
	echo -e "${CYANFONCE}___________________________"
	echo -e "Vous êtes sur la branche ${JAUNE}$nomBranche${CYANFONCE}"
	echo -e "Vous allez faire un push puis la merger sur les branches ${BLEUCLAIR}$@${NEUTRE}"
	
	read -p "Etes-vous sur de vouloir continuer ? (O/n)" reponse

	if [ $reponse == "O" ] || [ $reponse == "o" ] || [ $reponse == "Y" ] || [ $reponse == "y" ]
	then

		#on push la branche actuelle
		git push
		echo -e "${CYANFONCE}Push branche $nomBranche : OK${NEUTRE}"
		echo -e "${CYANFONCE}_____________________________${NEUTRE}"

		#On boucle sur tous les arguments et on merge avec les noms des branches
		for branch in $*
		do
			echo -e "${CYANFONCE}Passage sur la branche ${BLEUCLAIR}$branch${NEUTRE}"

			#je check que le passage sur la branche a bien fonctionné
			if git checkout $branch
			then 
				#On maj la data qu'on a sur cette branche
				echo -e "${CYANFONCE}Pull ${BLEUCLAIR}$branch${NEUTRE}"
				git pull 

				##on merge
				echo -e "${CYANFONCE}Merge de ${JAUNE}$nomBranche${CYANFONCE} sur ${BLEUCLAIR}$branch${NEUTRE}"
				if ! git merge $nomBranche
				then
					echo -e "${ROUGEFONCE}Erreur lors du merge de $nomBranche sur $branch. ABANDON${NEUTRE}"
					return
				fi

				##Resynchro avec le serveur de notre code
				git push

				echo -e "${CYANFONCE}Merge branche ${BLEUCLAIR}$branch${CYANFONCE} : OK"
			else
				echo -e "${ROUGEFONCE}Erreur lors de la connection à la branche $branch"
			fi
			echo -e "_____________________________${NEUTRE}"
		done
		echo -e "${CYANFONCE}Fin des merges demandés${NEUTRE}"
		
		#Je retourne sur la branche actuelle
		echo -e "${CYANFONCE}Retour sur la branche d'origine : $nomBranche${NEUTRE}"
		git checkout $nomBranche && git pull
	else
		echo -e "${ROUGEFONCE}Abandon${NEUTRE}"
	fi

}

## Cleane les branches locales qui sont déjà mergées sur master
git_cleanup() {
	read -p "Etes-vous sur de vouloir nettoyer vos branches locales ? (O/n)" reponse

	if [ $reponse == "O" ] || [ $reponse == "o" ] || [ $reponse == "Y" ] || [ $reponse == "y" ]
	then
		#on récupère les branches mergées sur master
		git checkout master && git branch --merged | grep -E -v 'master|recette|dev|integration|updates' | xargs git branch -d
		echo -e "${CYANFONCE}Votre GIT local est tout propre !${NEUTRE}"
		echo -e "${CYANFONCE}Plus de vilaines branches mergées sur le master qui traînent${NEUTRE}"
	else
		echo -e "${ROUGEFONCE}Abandon${NEUTRE}"
	fi
}
## Cleane les branches remote qui sont déjà mergées sur master
git_cleanup_remote() {
	read -p "Etes-vous sur de vouloir nettoyer les branches du remote ? (O/n)" reponse

	if [ $reponse == "O" ] || [ $reponse == "o" ] || [ $reponse == "Y" ] || [ $reponse == "y" ]
	then
		#on récupère les branches mergées sur le master remote
		git checkout master && git fetch -p && git branch -r --merged | grep -E -v 'master|recette|dev|integration|updates' | sed -e 's/origin\//:/' | xargs git push origin
		echo -e "${CYANFONCE}Votre GIT remote est tout propre !${NEUTRE}"
		echo -e "${CYANFONCE}Plus de vilaines branches mergées sur le master qui traînent${NEUTRE}"
	else
		echo -e "${ROUGEFONCE}Abandon${NEUTRE}"
	fi
}
## liste les branches non mergées
git_unmerged() {
    if [ -z "$1" ]
	then
		#on récupère les branches mergées sur le master remote
		echo -e "${CYANFONCE}Voici les branches non mergées sur la branche ${JAUNE}master${NEUTRE}"
        git branch --no-merged master | grep -E -v 'master|recette|dev|integration|updates'
	else
        echo -e "${CYANFONCE}Voici les branches non mergées sur la branche ${JAUNE}"$1"${NEUTRE}"
        git branch --no-merged "$1" | grep -E -v 'master|recette|dev|integration|updates'
	fi
}

## Surcharge de la fonction cap ** deploy
## Se met sur la branche en question pour faire le deploy
## Execute la fonction cap normalement si c'est pas un deploy
cap() {
	##Si on fait un deploy,
	if [[ "$2" == "deploy" ]] && [[ "$1" != "recettefinale" ]]
	then
		##Je me met sur la branche correspondante
		echo -e "${CYANFONCE}git checkout "$1" && git pull${NEUTRE}"
		if ! git checkout "$1" && git pull
		then
		    echo -e "${ROUGEFONCE}Erreur lors de la commande \"git checkout $1 && git pull\" - ABANDON${NEUTRE}"
			##Si le checkout rate, je quitte
			return
		fi
	fi

    if [[ "$1" == "recettefinale" ]]
    then
        read -p "Etes-vous bien sur Master ? Etes-vous sur de vouloir déployer en recette finale ? (O/n)" reponse

        if [ $reponse != "O" ] && [ $reponse != "o" ] && [ $reponse != "Y" ] && [ $reponse != "y" ]
        then
            echo -e "${ROUGEFONCE}Abandon${NEUTRE}"
            return
        fi
     fi

	##Dans tous les cas, j'execute la commande demandée
	echo -e "${CYANFONCE}cap $@${NEUTRE}"
	command cap "$@"
}

