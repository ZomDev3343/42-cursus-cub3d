# Objectif parsing

Style de map donnée:
```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

11111111111111111111
10000000001100000001
10110000011100000001
10010000000000000001
11111111101100000111
10000000000000000001111
10110000001111100000001
10010000001   1000N0001
11111111111   111111111
```

A la sortie du parser pourquoi pas avoir une stucture assez global avec:
- texture_n
- texture_s
- texture_w
- texture_e
- color_f
- color_c
- map
- player
(peut-etre regrouper les textures dans une sous structure)
Faire du player une structe avec:
- x
- y
- fov ?
- direction ?

# Format des variables:

(Pas sur mais je crois que les images on peut les recup en matrice si c'est le cas faire full matrice pour les textures);
- pour les color int[3];
- map avec exemple du dessus devient
```
[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
[1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1]
[1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1]
[1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1]
[1,1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,1,1,1]
[1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1]
[1,0,1,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1]
[1,0,0,1,0,0,0,0,0,0,1,-1,-1,-1,1,0,0,0,0,0,0,0,1]
[1,1,1,1,1,1,1,1,1,1,1,-1,-1,-1,1,1,1,1,1,1,1,1,1]
```
# Erreur possible
- couleur invalide
- texture inexistante/permission
- map pas fermé
- caractere indesiré (lettre en plein milieu de la map ou mauvaise direction avant la texture) 
