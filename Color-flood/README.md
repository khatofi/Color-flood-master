# LotD : Color Flood 

## The A-Team  

### Fichiers inclus
* grid_color.c : Contient toutes les fonctions de base utilisées dans tous les lots précédents
* grid_color.h : Contient les prototypes des fonctions du module grid_color et leurs commentaires Doxygen
* solveur_rapide.c : Contient l'implémentation des fonctions du solveur optimisé
* solveur_rapide.h : Contient les prototypes des fonctions du solveur optimisé
* unit_test.c : Contient les tests unitaires des fonctions du solveur optimisé
* unit_test.h : Contient les prototypes des tests unitaires
* loop_game.c : Contient les fonctions pour l'application Color Flood en mode console
* loop_game.h : Contient les prototypes des fonctions implémentées dans loop_game.c
* main_jeu.c : Permet d'exécuter l'application en mode console
* main_test.c : Exécute les tests unitaires
* grille1, grille2, grille3 et grille4: Définissent des grilles utilisées pour les tets unitaires
* SDL.c : Contient les fonctions de base pour le jeu en mode graphique
* SDL.h : Contient les prototypes des fonctions de base pour le jeu en mode graphique
* ColorFlood.c : Contient le main pour exécuter le jeu en mode graphique
* Doxyfile : Contient la configuration utilisée par Doxygen pour générer la documentation
* Makefile : Permet de générer les exécutables et la documentation
* resultat-valgrind: Contient les résultats de Valgrind pour les exécutables
* Rapport_Lot_D.pdf : Rapport du Lot D


### Instructions d'installation

Pour la documentation Doxygen:

`sudo apt-get install doxygen`

Pour les tests unitaires, la librairie CUnit est nécessaire:

`sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev`

Pour installer la biliothèque graphique SDL:

`sudo apt-get install libsdl1.2-dev libsdl-gfx1.2-dev libsdl-ttf2.0-dev libfreeimage-dev`

Pour installer la bibliothèque du son SDl_Mixer:
```
sudo apt-get install libsdl-mixer1.2
sudo apt-get install libsdl-mixer1.2-dev
```

### Instructions d'utilisation de l'application Color Flood en mode console

Pour compiler et exécuter l'application en mode console:

`make ./jeu`

Pour compiler et exécuter les tests:

`make ./tests`

Pour tester l'absence de fuites de mémoire (Valgrind)

`valgrind ./tests`

Pour nettoyer le répertoire:

`make clean`

### Instructions d'utilisation de l'application Color Flood en mode graphique

Pour exécuter compiler et exécuter le jeu en mode graphique:

`make ./ColorFlood`

Une fois lancé dans le terminal, le menu d'accueil s'affiche avec trois options : taille de la grille, niveau de difficulté et une dernière option pour quitter, l'utilisateur utilise le clavier (les flèches haut et bas et droite et gauche pour se déplacer) on selectionne un choix en appuyant le bouton Entrer. La grille s'affiche avec plusieurs icônes de son, de solution, et la grille de jeu. A la fin d'une partie on appuie sur la touche Échap pour quitter.

### Instructions de documentation

Tous les commentaires au format doxygen sont mis dans les headers pour éviter la duplication dans la documentation
D'autres commentaires normaux sont inclus dans les fichiers sources
Toutes les fonctions et leurs conceptions sont détaillées dans le rapport 

Pour générer la documentation (Doxygen):

`doxygen Doxyfile `
