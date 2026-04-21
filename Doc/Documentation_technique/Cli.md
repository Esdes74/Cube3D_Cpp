# Sommaire

- [Sommaire](#sommaire)
- [Classe](#classe)
- [Fonctionnement technique](#fonctionnement-technique)
- [Les commandes](#les-commandes)

# Classe

Les commandes cli sont toutes gérées par une classe nommé Cli, dans le fichier lib/cli/Cli.hpp

# Fonctionnement technique

La classe cli possède une map qui as pour clés le nom d'une commande cli et pour valeur un pointeur vers la fonction correspondante.

Lors de l'utilisation de la cli, il suffit de parser avec espace les lignes récupérés à l'aide de getline, puis d'éxécuter un find sur la map de cli avec le premier élément parsé de la ligne.
Si le find sort quelque chose alors la commande est valide.
Il suffit d'éxécuter le pointeur de fonction trouvé en lui donnant le reste de la ligne en arguments.

# Les commandes

Lancement d'un fichier de map

Clean tous le contexte (pour relancer une map depuis le début par exemple)

Changement d'une texture

Headless

print variable
--> utiliser une map

Assert sur une variable
--> Par exemple pour vérifier que la munition récupéré à bien augmenté le stock de 1

Pause

Resume

Déplacements

Toggles différents éléments (par exemple la minimap s'il y en as une)

Actions diverses possible par le joueur
