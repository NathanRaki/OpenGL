# Synthèse d'image

Ce cours a été principalement du calcul de géométrie dans l'espace.

En effet, nous avons d'abord revu les opérations vectorielles et les avons implémentées dans un programme simple destiné à représenter le tracé de la chute d'un saut en parachute.
Pour cela nous avons créé un fichier ppm de manière à stocker automatiquement le dessin du tracé.

La prochaine étape était d'implémenter le raycasting.
Nous devions, à partir de chaque pixel, envoyer un rayon vers le "fond" de la scène.
Pour cela nous avons représenté une sphère avec sa position et son rayon puis avons écrit une méthode permettant de définir si le rayon passe par la sphère.
S'il y a un croisement on dessine un pixel coloré, sinon, on dessine de l'ombre.
En modifiant la façon dont les rayons étaient créés nous avons pu obtenir des ombres plus réalistes pour la sphère.

Ce raycasting nous a également permis d'opérer différement selon les matériaux rencontrés.
Un miroir le fait réfléchir, une surface d'eau le réfracte.

La dernière étape a été de créer un parser de fichier .obj afin de charger des modèles 3D dans la scène.
Il a donc fallu créer une méthode d'intersection entre un rayon et un triangle.
Avec un calcul de normales, nous avons pu obtenir des structures bien plus intéressantes que des sphères.

# Simulation physique

Dans ce cours, la représentation des algorithmes a été réalisée sur Unity.

La première partie consistait à créer un bras articulé à l'aide de l'algorithme FABRIK.
Il consiste à itérer sur chaque segment du bras et à calculer sa position en fonction du suivant.
Le F correspondant à Forward, il symbolise l'itération de l'extrémité jusqu'à la racine tandis que le B signifiant Backward désigne l'itération de la racine à l'extrémité.
L'opération Forward permet ainsi de garantir que le noeud final du bras essaye d'atteindre la cible et l'opération Backward vient ensuite rattacher le bras à sa racine afin de s'assurer qu'il soit bien fixe.

Ensuite, nous avons réalisé de la simulation de fluide grâce à des systèmes de particules.
Pour cela nous devions créer ces dernières puis gérer leur physique afin d'avoir un comportement semblable à un liquide.
La gestion de toutes les particules à chaque frame étant très couteuse, il nous a donc fallu faire en sorte que chacune prenne en compte ses voisins et non la totalité des particules.