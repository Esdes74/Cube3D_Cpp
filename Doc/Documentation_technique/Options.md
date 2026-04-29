# Sommaire

- [Sommaire](#sommaire)
- [Classe](#classe)
- [Fonctionnement technique](#fonctionnement-technique)
- [Les options](#les-options)
	- [--debug](#--debug)
	- [--headed](#--headed)
	- [--cli-file](#--cli-file)

# Classe

Les options sont toutes gérées par une classe nommé Options, dans le fichier lib/options/Options.hpp

# Fonctionnement technique

La classe option possède une map qui as pour clés le nom d'une option et pour valeur un pointeur vers la fonction correspondante.

Lors de la vérification des arguments de la ligne de commande il suffit d'éxécuter un find() sur la map avec l'argument sélectionné.
Si le find sort quelque chose c'est que l'argument est correcte.
Il suffit seulement d'éxécuter le pointeur de fonction correspondant à la clés trouvé avec le find.

# Les options

## --debug

Elle passe la variable globale debug à true.

## --headed

Elle passe la variable global headed à false

## --cli-file

Elle ouvre le fichier donné en argument pour éxécuter les commandes à l'intérieur.

S'il n'y a pas de fichier, l'éxception `NoCliFileArgument` est lancé
Si le fichier donné contient une commande qui n'éxiste pas, l'exception `CliFileArgumentDontExist` est lancé.
Si le fichier donné n'éxiste pas, l'éxéception `CliFileCommandDontExist` est lancé.

La lecture du fichier ne doit pas souffrir des whitespaces