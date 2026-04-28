# Sommaire

- [Sommaire](#sommaire)
- [Classe](#classe)
- [Fonctionnement technique](#fonctionnement-technique)

# Classe

Les options sont toutes gérées par une classe nommé Options, dans le fichier lib/options/Options.hpp

# Fonctionnement technique

La classe option possède une map qui as pour clés le nom d'une option et pour valeur un pointeur vers la fonction correspondante.

Lors de la vérification des arguments de la ligne de commande il suffit d'éxécuter un find() sur la map avec l'argument sélectionné.
Si le find sort quelque chose c'est que l'argument est correcte.
Il suffit seulement d'éxécuter le pointeur de fonction correspondant à la clés trouvé avec le find.