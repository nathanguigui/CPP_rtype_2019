# Update Data

Tout les paquets ont le code [0x100] devant et [0x101] à la fin de chaque paquet

## Etat du jeu

0x400;type

### Type

launched: Le jeu est lancé rien à signaler
```
 0x400;0x405;[posx]
 ```
 - posx -> position du début de la carte
#
between: Le jeu est entre deux maps
```
 0x400;0x406;[time]
```
 - time -> temps en ms qu'il reste avant de lancer la prochaine carte
#
win: Les joueurs ont gagné
 ```
  0x400;0x407;[time]
  ```
 - time -> temps en ms avant la fin du serveur
 #
 lost: Les joueurs ont perdu
  ```
  0x400;0x408;[time]
  ```
 - time -> temps en ms avant la fin du serveur
 
## Evenements

0x500;type

### Type

hit:
 ```
  0x500;0x505;[posX];[posY]
  ```
  - posX;posY -> Nombres flottant qui indiquent les coordonnées du hit

## Entités

0x600;type

### Type

player :
 ```
  0x600;0x605;[UUID];[status];[score];[hp];[as];[posX];[posY];[ForcePodLevel]
 ```
 - UUID -> chaine de caractère hexa définissant le joueur
 
 - status -> ALIVE [0x610] ou DEAD [0x611], si DEAD alors il n'y a pas les infos qui suivent
 
 - score -> Nombre entier définissant le score
 
 - hp -> Nombre flottant définissant les hp du joueur
 
 - as -> vitesse d'attaque du joueur (sera utile avec les powerups)
 
 - posX;posY -> Nombres flottant qui indiquent les coordonnées du joueur
 
 - ForcedPodLevel -> [0x615 0x616 0x617] qui définit le niveau du PodLevel
#
monster :
 ```
  0x600;0x606;[UUID];[type];[posX];[posY]
  ```
- UUID -> chaine de caractère hexa définissant le monstre

- type -> [0x620 0x621 0x622 0x623] le type du monstre

- posX;posY -> Nombres flottant qui indiquent les coordonnées du monstre
#
bullet :
 ```
 0x600;0x607;[UUID];[type];[posX];[posY]
 ```
- UUID -> chiffre entier définissant la balle

- type -> [0x630 0x631 0x632 0x635 0x636 0x637 0x638] définissant le type de la balle (de 30 à 32 pour les joueurs / 35 à 38 pour les monstres) 

- posX;posY -> Nombres flottant qui indiquent les coordonnées de la balle
#
powerup :
 ```
 0x600:0x608;[type];[posX];[posY]
 ```

- type -> Health [0x640] , Attack speed [0x641]

 - posX;posY -> Nombres flottant qui indiquent les coordonnées du powerup

#