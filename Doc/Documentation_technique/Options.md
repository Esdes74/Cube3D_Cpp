# Sommaire

- [Sommaire](#sommaire)
- [Classe](#classe)
- [Fonctionnement technique](#fonctionnement-technique)
- [Les options](#les-options)
	- [--debug](#--debug)
	- [--headed](#--headed)
	- [--logout](#--logout)
	- [--log-rep](#--log-rep)
	- [--cli-file](#--cli-file)

# Classe

Les options sont toutes gérées par une classe nommé Options, dans le fichier lib/options/Options.hpp

# Fonctionnement technique

La classe option possède une map qui as pour clés le nom d'une option et pour valeur un pointeur vers la fonction correspondante.

Lors de la vérification des arguments de la ligne de commande il suffit d'éxécuter un find() sur la map avec l'argument sélectionné.
Si le find sort quelque chose c'est que l'argument est correcte.
Il suffit seulement d'éxécuter le pointeur de fonction correspondant à la clés trouvé avec le find.

# Les options

Description des actions de chaques options.

Certaines peuvent lancer une exception. Dans le cadre du projet motor, si une exception est lancé dans les options alors on exit le programme avec un message pllus ou moins claire

## --debug

Elle passe la variable globale debug à true.

## --headed

Elle passe la variable global headed à false

## --logout

Elle redéfinis la variable global logout pour définir un fichier de sortie log

Si l'argument n'est pas présent lance l'exception `NoLogoutArgument`
Si l'argument est présent mais non valide l'exception `LogoutArgumentUnvalid`
> Un argument valide est un non de fichier finissant par .log

## --log-rep

Elle redéfinis la variable logout log_rep avec le répertoire donnée en argument

Si l'argument n'est pas présent lance l'exception `NoLogrepArgument`
Si l'argument est présent mais que le répertoire n'éxiste pas l'exception `LogrepArgumentUnvalid`

## --cli-file

Elle ouvre le fichier donné en argument pour éxécuter les commandes à l'intérieur.

S'il n'y a pas de fichier, l'éxception `NoCliFileArgument` est lancé
Si le fichier donné n'éxiste pas, l'éxéception `CliFileArgumentUnvalid` est lancé.

La lecture du fichier ne doit pas souffrir des whitespaces
