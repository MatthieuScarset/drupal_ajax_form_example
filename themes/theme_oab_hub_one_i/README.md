## WEBPACK OAB HUB ONE-I

### Pourquoi ?

Ce Readme est fait pour vous expliquer comment exécuter
les commandes yarn sur ce thème. En effet, pour ne pas
dupliquer le code dans le webpack config de one-i dans
celui du webpack de oab_hub_one_i, dans le webpack du
oab_hub_one_i on index le webpack de one-i et donc on ne
définit que le "output" et le "entry". Le problème est
qu'une fois dans le dossier thème oab_hub_one_i pour faire
les commandes yarn, il est en échec à cause de la commande
```docker run -it --rm -v $(pwd):/app -w /app node yarn```
qui exécute yarn dans le repertoire ```$(pwd)``` .

### Solution
Il faudra donc uniquement pour le thème_oab_hub_one_i pour
exécuter les commandes yarn, en fonction de votre emplacement
exécuter plutôt cette commande pour yarn :

- Si vous êtes à la racine du projet : ``yrn --cwd themes/theme_oab_hub_one_i [install][build][watch]``
- Dans le dossier thèmes : ``yrn --cwd theme_oab_hub_one_i [install][build][watch]``

Le ``--cdw`` est pour spécifer le dossier dans lequel il doit exécuter
sa commande. Ce qui veut dire que cette commande marche aussi pour les
autres thèmes avec du scss
