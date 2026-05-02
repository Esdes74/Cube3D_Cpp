# Cude3D_Cpp

Cube3D de l'école 42 fais en c++ et un peu refait a ma convenance

# Sommaire

- [Cude3D\_Cpp](#cude3d_cpp)
- [Sommaire](#sommaire)
- [Lancement du projet](#lancement-du-projet)
	- [Options](#options)
	- [Exemples](#exemples)
	- [Tests](#tests)

# Lancement du projet

Pour lancer le moteur:
`./motor <options> <argument>`

`<options>`

    Ce sont les options pour lancer le moteur, elles sont facultatives.

---
`<argument>`

    C'est l'argument de lancement que prends le programme.
    Dans certains cas (avec certaines options) les arguments sont facultatifs mais si le moteur est lancé sans options le moteur affichera une erreure d'argument invalide dans la console et s'arretera

---
Les options ont un ordre d'appel, si vous ne le respectez pas pas de panique le programme les remet dans l'ordre pour vous.
L'ordre est `--debug -> --log-repository -> --logout`
> Pour les autres options l'ordre n'est pas important
>
> Si vous ne mettez pas l'option debug alors l'ordre appliqué sera `--log-repository -> --logout`

[Cliquer ici pour voir la doc technique des options et arguments](Doc/Documentation_technique/Index.md)

## Options

`--cli`

    Il s'agit d'une cli, un programme qui permet d'interragire avec le moteur depuis une interface de commande
>Pour voir toutes les commandes accessibles dans la cli [fouillez ce document](Doc/CLI_COMMAND.md)

    Le heredoc est utilisable.
		Le problème ne venait pas du c++ qui ne peut pas lire depuis un scirpt bash mais du comportement du script bash lui meme.

---
`--cli-file <file>`

    Elle permet de lancer le moteur en mode cli
    Elle va lire les instructions dans le fichier `file` pour les éxécuter

---
`--debug`

    Elle permet de lancer le moteur en mode debug
    Cela signifie que le moteur se lance avec un terminal accessible
    Le terminal sera une reproduction de la cli (il permettra donc de faire les memes commandes que la cli)

	Le mode debug permet également l'impression de message dans le fichier de logout et un affichage différent ou non des éléments dans le moteur (chunk box, hit box, etc...)

---
`--headless`

    Elle permet de lancer le moteur sans l'affichage. Tous les calculs sont fait. Seulement l'affichage n'est pas fait

> Seulement l'affichage du jeu ne se fait pas. En revanche la console du debug ou de la cli peut s'afficher pour intéragir avec

--> A tester sur un server headless (comme le vps pour mon site)

---
`--logout <file>`

	Elle permet de définir un fichier de log pour les logs de sortis

> Par défault le fichier de log s'appel Error.log

---
`--log-repository <rep>`

	Elle permet de définir un répertoire où imprimer le log de sortie

> Par défault le répertoire d'impression des logs est .log/

## Exemples

`./motor --cli` ou `./motor --cli-file tests/lancement1.txt` ou `./motor --debug`

    Va pouvoir se lancer car la cli possède des commandes pour prendre un fichier en argument

---
`./motor` ou `./motor --headless`

    Va se lancer, afficher un message d'erreure dans le terminale et se terminer

---
`./motor map/fire/cave.txt` ou `./motor --headless map/fire/cave.txt`

    Va se lancer correctement dans le premier cas
    Dans le second cas (--headless) se lancera sans l'affichage mais il sera fonctionnel (cela signifie qu'on pourra se déplacer, attaquer etc... mais qu'on ne verras rien du tous)

## Tests

Le but de ce projet est de créer un moteur de jeux 3D

Le but est également de faire un développement le plus poussé possible.
Dans ce but, la cli est mise en place pour faciliter l'automatisation des tests grace à l'éxécution de scripts.
> Il serait intéressant de mettre en place un systeme de statistique des tests, avec des graphiques qui donnent les tendances etc...





Pour la cli je peux voir pour lancer les commandes depuis un fichier externe
la commande de lancement ressemblera à ca: `./motor --cli-file test.txt`
Ce qui signifie que les commandes de la cli à éxécuter sont dans le fichier test.txt

--> Ca permet de ne pas surcharger le script de lancement des tests avec des commandes de cli, la les commandes de cli seront dans un fichier à part