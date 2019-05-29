# libcms

**libcms** est une librairie C qui parcourt plusieurs domaines différents. Il me permet notamment de réutiliser certaines fonctions que j'utilise dans mes recherches. 

## Installation et utilisation

### Installation

- Cliquer sur **Releases** pour télécharger la dernière version de la librairie. 
- Intégrer le zip dans votre projet.
- déziper le dossier contenant la librairie, il se nommera **libcms-X.X** avec X.X la version de la librairie.

### Utilisation

On suppose que le projet se constitue d'un unique fichier source *test.c*. 
Pour le compiler sans l'intégration de la librairie libcms, vous aviez fait la commande : 
```shell
gcc -o test test.c
./test
```
Pour l'intégration de la librairie avec le paquet *cmsint*, il suffira de faire : 
```shell
gcc -I ./libcms/include/ -L ./libcms/lib/ -o test test.c -lcmsint
./test
```

## Contenu de la librairie

**libcms** contient plusieurs paquets : 
- **cmsint** qui permet de manipuler facilement les types *uint8_t*, *uint32_t* et *uint64_t* : à la compilation **-lcmsint** pour utiliser ce paquet
- d'autres paquets pour de futures versions
