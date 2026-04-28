# Sommaire

- [Sommaire](#sommaire)
- [Le choix de l'outil](#le-choix-de-loutil)
	- [Driver utilisé](#driver-utilisé)
		- [OpenGL](#opengl)
		- [SDL 2](#sdl-2)
- [Le choix des graphismes](#le-choix-des-graphismes)

# Le choix de l'outil

Pour l'instant le choix se dirigie plus vers l'outils imgui.

Il s'agit d'une bibliothqèue graphique offant une api agréable à utiliser et qui est éprouvé par de nombreuses entreprises du jeu vidéo.

Elle ne delande pas d'instalation supplémentaire, ni de compilation

## Driver utilisé

Imgui doit fonctionner avec un backend déjà en place, lui ne sera là que pour discuter avec ce backend via une api.

Le driver utilisé est OpenGL avec SDL 2

### OpenGL

Pour installer opengl il sufit de taper la commande `sudo apt install mesa-utils`.
Pour vérifier si opengl est bien installé on tape la commande `glxinfo | grep OpenGL`

### SDL 2

Pour installer sdl 2 il suffit de suivre le tuto sur cette page ci: `https://devopssec.fr/article/telechargement-compilation-projet-sdl`

# Le choix des graphismes

Pour l'instant il s'agit plus de graphismes super basiques (wolfenstein 3D) en 2.5D
--> Peut etre évolution vers 3D simple









Se renseigner sur les backend de plateforme (GLFW, SDL, Win32 etc...)