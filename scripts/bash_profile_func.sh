# Création d'une nouvelle branche et synchro auto sur le serveur
git_new_branch() {
	##Declas pour coloration texte
	rougefonce='\e[0;31m'
	neutre='\e[0;m'

	if [ -z "$1" ]
	then
		echo -e "${rougefonce}Error : Vous devez entrer un nom de branche${neutre}"
	else

		##je me branche sur master que je pull
		if git checkout master && git pull
		then
			git checkout -b "$1"
			git push --set-upstream origin "$1"
		else
			echo -e "${rougefonce}Erreur avec la branche master${neutre}"
		fi
	fi
}


# Push la branche update puis merge avec le dev et le master
git_push_updates() {

	##paramètres pour changer le style des echo
	jaune='\e[1;33m'
	cyanfonce='\e[0;36m'
	neutre='\e[0;m'
	vertclair='\e[1;32m'
	bleuclair='\e[1;34m'
	rougefonce='\e[0;31m'

	nomBranche=`git branch | grep "*"`

	##Si on n'est pas sur la branche updates, je quitte le script
	if [[ $nomBranche != "* updates"* ]]
	then
		echo -e "${rougefonce}Error : Vous devez être sur la branche updates pour executer cette commande${neutre}"
		return
	fi

	#on push updates
	if git push
	then
		##On merge dev et master grace à la fonction ci-dessous
		if git_merge dev master
		then
			echo -e "${vertclair}Success : Merge de updates sur dev & master OK${neutre}"
			return
		fi
	else
		##Si le push rate, je quitte le script
		return
	fi

}


# Merge la branche actuelle avec la branche update
# puis merge la branche update avec dev & master
# Si une branche est passée en paramètre, merge de cette branche avec update
git_merge_updates() {

	##paramètres pour changer le style des echo
	jaune='\e[1;33m'
	cyanfonce='\e[0;36m'
	neutre='\e[0;m'
	vertclair='\e[1;32m'
	bleuclair='\e[1;34m'
	rougefonce='\e[0;31m'

	#On recupère le nom de la branche actuelle
	nomBranche=`git branch | grep "*"`
	nomBranche=${nomBranche:2:$((${#nomBranche}-1))}

	##On affiche un petit message
	echo -e "${cyanfonce}___________________________"
	echo -e "branche actuelle :  ${jaune}$nomBranche${cyanfonce}"
	echo -e "Liste des actions :"
	echo -e "\t- Merge de ${jaune}$nomBranche${cyanfonce} sur ${bleuclair}updates${cyanfonce}"
	if [ $# -gt 0 ]
	then
		echo -e "\t $# - Merge de ${bleuclair}updates${neutre} sur ${vertclair}$1${cyanfonce}"
	fi
	echo -e "\t- Merge de ${bleuclair}updates${cyanfonce} sur ${bleuclair}dev${cyanfonce} et ${bleuclair}master${neutre}"

	##On demande validation
	read -p "Etes-vous sur de vouloir continuer ? (O/n)" reponse

	if [ $reponse == "O" ] || [ $reponse == "o" ] || [ $reponse == "Y" ] || [ $reponse == "y" ]
	then

		##on merge updates  (le printf 'o' est pour donner la réponse à la question de la fonction git_merge)
		printf 'o' | git_merge updates

		##S'il y a une branche en paramètre, on merge avec cette branche
		if [ $# -gt 0 ]
		then
			printf 'o' | git_merge $1
		fi

		##On se déplace sur updates
		if git checkout updates
		then
			##On merge updates avec dev et master
			printf 'o' | git_merge dev master
			git checkout $nomBranche
		else
			echo "${rougefonce}Erreur lors de la connexion à la branche updates${neutre}"
		fi
	else
		echo -e "${rougefonce}Abandon${neutre}"
	fi
}

## Merge la branche actuelle avec les branches passées en paramètre
git_merge() {

	##paramètres pour changer le style des echo
	jaune='\e[1;33m'
	cyanfonce='\e[0;36m'
	neutre='\e[0;m'
	vertclair='\e[1;32m'
	bleuclair='\e[1;34m'
	rougefonce='\e[0;31m'

	#On recupère le nom de la branche actuelle
	nomBranche=`git branch | grep "*"`
	nomBranche=${nomBranche:2:$((${#nomBranche}-1))}
	
	if [ $# == 0 ]
	then
		echo -e "${rougefonce}Error : Vous devez entrer les branches à merger${neutre}"
		return
	fi
	##On affiche un petit message
	echo -e "${cyanfonce}___________________________"
	echo -e "Vous êtes sur la branche ${jaune}$nomBranche${cyanfonce}"
	echo -e "Vous allez faire un push puis la merger sur les branches ${bleuclair}$@${neutre}"
	
	read -p "Etes-vous sur de vouloir continuer ? (O/n)" reponse

	if [ $reponse == "O" ] || [ $reponse == "o" ] || [ $reponse == "Y" ] || [ $reponse == "y" ]
	then

		#on push la branche actuelle
		git push
		echo -e "${cyanfonce}Push branche $nomBranche : OK${neutre}"
		echo -e "${cyanfonce}_____________________________${neutre}"

		#On boucle sur tous les arguments et on merge avec les noms des branches
		for branch in $*
		do
			echo -e "${cyanfonce}Passage sur la branche ${bleuclair}$branch${neutre}"

			#je check que le passage sur la branche a bien fonctionné
			if git checkout $branch
			then 
				#On maj la data qu'on a sur cette branche
				echo -e "${cyanfonce}Pull ${bleuclair}$branch${neutre}"
				git pull 

				##on merge
				echo -e "${cyanfonce}Merge de ${jaune}$nomBranche${cyanfonce} sur ${bleuclair}$branch${neutre}"
				if ! git merge $nomBranche
				then
					echo -e "${rougefonce}Erreur lors du merge de $nomBranche sur $branch. ABANDON${neutre}"
					return
				fi

				##Resynchro avec le serveur de notre code
				git push

				echo -e "${cyanfonce}Merge branche ${bleuclair}$branch${cyanfonce} : OK"
			else
				echo -e "${rougefonce}Erreur lors de la connection à la branche $branch"
			fi
			echo -e "_____________________________${neutre}"
		done
		echo -e "${cyanfonce}Fin des merges demandés${neutre}"
		
		#Je retourne sur la branche actuelle
		echo -e "${cyanfonce}Retour sur la branche d'origine${neutre}"
		git checkout $nomBranche && git pull
	else
		echo "${rougefonce}Abandon${neutre}"
	fi

}

## Surcharge de la fonction cap ** deploy
## Se met sur la branche en question pour faire le deploy
## Execute la fonction cap normalement si c'est pas un deploy
cap() {
	##Si on fait un deploy,
	if [[ "$2" == "deploy" ]]
	then
		##Je me met sur la branche correspondante
		echo -e "${cyanfonce}git checkout "$1" && git pull${neutre}"
		if ! git checkout "$1" && git pull
		then
		    echo -e "${rougefonce}Erreur lors de la commande \"git checkout $1 && git pull\" - ABANDON${neutre}"
			##Si le checkout rate, je quitte
			return
		fi
	fi

	##Dans tous les cas, j'execute la commande demandée
	echo -e "${cyanfonce}cap $@${neutre}"
	command cap "$@"
}