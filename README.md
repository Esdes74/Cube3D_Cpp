# Cude3D_Cpp
Cube3D de l'école 42 fais en c++ et un peu refait a ma convenance

# Lancement du projet

Pour lancer le moteur:
`./motor <options> <arguments>`

## Arguments

Le chemin vers le fichier du niveau

## Options

`--intern-cli <file>`

Elle permet de lancer le moteur en mode cli
Elle va lire les instructions dans le fichier `file` pour les éxécuter

> Il serait bien de pouvoir créer également une cli normal où on puisse interragire manuellement avec.
Il faudra surement utiliser la bibliothèque xtd

---
`--debug`

Elle permet de lancer le moteur en mode debug
Cela signifie que le moteur se lance avec un terminal accessible

---






Pour la cli je peux voir pour lancer les commandes depuis un fichier externe
la commande de lancement ressemblera à ca: `./motor --intern-cli test.txt`
Ce qui signifie que les commandes de la cli à éxécuter sont dans le fichier test.txt

--> Ca permet de ne pas surcharger le script de lancement des tests avec des commandes de cli, la les commandes de cli seront dans un fichier à part