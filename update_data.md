# Update Data

Tout les paquets ont le code [0x198] devant et [0x199] à la fin de chaque paquet et un "$" entre chaque phrase.

## Etat du jeu

0x498;type

### Type

launched: Le jeu est lancé rien à signaler
```
 0x498;0x415;[map];[posx]
 ```
 - map -> numéro de la map
 - posx -> position du début de la carte
#
between: Le jeu est entre deux maps
```
 0x498;0x416;[time]
```
 - time -> temps en ms qu'il reste avant de lancer la prochaine carte
#
win: Les joueurs ont gagné
 ```
  0x498;0x417;[time]
  ```
 - time -> temps en ms avant la fin du serveur
 
#
lost: Les joueurs ont perdu
  ```
  0x498;0x418;[time]
  ```
 - time -> temps en ms avant la fin du serveur
 
## Evenements

0x598;type

### Type

hit:
 ```
  0x598;0x515;[posX];[posY]
  ```
  - posX;posY -> Nombres flottant qui indiquent les coordonnées du hit

## Entités

0x698;type

### Type

player :
 ```
  0x698;0x655;[UUID];[pseudo];[status];[score];[hp];[as];[posX];[posY];[ForcePodLevel]
 ```
 - UUID -> chaine de caractère hexa définissant le joueur
 
 - pseudo -> pseudo du joueur en hexadécimal
 
 - status -> ALIVE [0x610] ou DEAD [0x611], si DEAD alors il y a que score en info qui suit
 
 - score -> Nombre entier définissant le score
 
 - hp -> Nombre flottant définissant les hp du joueur
 
 - as -> vitesse d'attaque du joueur (sera utile avec les powerups)
 
 - posX;posY -> Nombres flottant qui indiquent les coordonnées du joueur
 
 - ForcedPodLevel -> [0x615 0x616 0x617] qui définit le niveau du PodLevel
#
monster :
 ```
  0x698;0x656;[UUID];[type];[posX];[posY]
  ```
- UUID -> chaine de caractère hexa définissant le monstre

- type -> [0x620 0x621 0x622 0x623] le type du monstre

- posX;posY -> Nombres flottant qui indiquent les coordonnées du monstre
#
bullet :
 ```
 0x698;0x657;[UUID];[type];[posX];[posY]
 ```
- UUID -> chiffre entier définissant la balle

- type -> [0x630 0x631 0x632 0x635 0x636 0x637 0x638] définissant le type de la balle (de 30 à 32 pour les joueurs / 35 à 38 pour les monstres) 

- posX;posY -> Nombres flottant qui indiquent les coordonnées de la balle
#
powerup :
 ```
 0x698;0x658;[type];[posX];[posY]
 ```

- type -> Health [0x640] , Attack speed [0x641]

 - posX;posY -> Nombres flottant qui indiquent les coordonnées du powerup

#