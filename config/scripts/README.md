# RACCOURCIS BASH POUR LES WORKFLOWS GIT

Installation
------
* Créer/ouvrir le fichier _.bash\_profile_ dans votre home. 
* NB windows7 : en général C:\Users\CUID pour creer le fichier "touch .bashrc"
* Copier et adapter la ligne ```source ~/LIEN/VERS/DOSSIER/RUBY/scripts/bash_profile_func.sh```
* Relancer le git-bash pour la prise en compte du script.

Utilisation
------
Les fonctions s'utilisent dans le git-bash comme une commande normale.

Fonctions
------
### git\_new\_branch [nom\_branche]
* Se connecte à la branche _MASTER_,
* Crée une nouvelle branche
* Synchronise la branche avec le serveur.

### git\_merge\_updates [nom\_branche]
* **s'utilise depuis la branche locale**
* Merge de la branche actuelle avec _updates_
* Si un nom de branche est passé en paramètre, merge de la branche actuelle avec cette branche
* Merge de _update_ avec _dev_ et _master_

**Exemples**

	$ git_merge_updates
	$ git_merge_updates mabranche


### git\_merge {[nom\_branche]}
*Séparer chaque nom de branche par une espace*
* Merge la branche actuelle avec les branches passées en paramètre

**Exemple**

	$ git_merge ma_branche dev

### git\_push\_updates
* Push la branche _updates_.
* Merge la branche _updates_ avec _dev_ et _master_.

### git\_cleanup
* Se positionne sur le _master_
* Check quelles branches sont déjà mergées sur le _master_.
* Suppression de ces branches

### git\_cleanup\_remote
* Se positionne sur le _master_
* Met à jour l'index des branches remote
* Check quelles branches sont déjà mergées sur le _master_.
* Suppression de ces branches

### git\_unmerged [nom\_branche]
* Liste les branches non mergées sur une branche donnée
* Si pas d'argument, branche cible = master
* Si argument, branche cible = argument

### cap
* Surcharge la commande "cap"
* Se met sur la branche en question lorsqu'on tente un deploy
* Execute ensuite la commande **cap** normalement.
