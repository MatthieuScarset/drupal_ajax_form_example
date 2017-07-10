# RACCOURCIS BASH POUR LES WORKFLOWS GIT

Installation
------
* Créer/ouvrir le fichier _.bash\_profile_ dans votre home.
* Copier et adapter la ligne _source ~/LIEN/VERS/DOSSIER/RUBY/scripts/bash\_profile\_func.sh_.
* Relancer le git-bash pour la prise en compte du script.

Utilisation
------
Les fonctions s'utilisent dans le git-bash comme une commande normale.

Fonctions
------
### git\_new\_branch [nom\_branche]
* Se connecte à la branche _MASTER_,
* puis crée une nouvelle branche et la synchronise automatiquement avec le serveur.

### git\_merge\_updates [nom\_branche]
* **s'utilise depuis la branche locale**
* Merge de la branche actuelle avec _updates_
* Si un nom de branche est passé en paramètre, merge de la branche actuelle avec cette branche
* Merge de _update_ avec _dev_ et _master_

**Exemples**
```bash
git_merge_updates
git_merge_updates mabranche
```

### git\_merge {[nom\_branche]}
*Séparer chaque nom de branche par une espace*
* Merge la branche actuelle avec les branches passées en paramètre

**Exemple**
```bash
git_merge ma_branche dev
```

### git\_push\_updates
* Push la branche _updates_.
* Merge la branche _updates_ avec _dev_ et _master_.

