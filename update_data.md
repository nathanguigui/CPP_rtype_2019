# Update Data


## Etat du jeu

gamestate;[type]

### Type

launched: Le jeu est lancé rien à signaler
```
 gamestate;launched;[posx]
 ```
 - posx -> position du début de la carte
#
between: Le jeu est entre deux maps
```
 gamestate;between;[time]
```
 - time -> temps en ms qu'il reste avant de lancer la prochaine carte
#
win: Les joueurs ont gagné
 ```
  gamestate;win;[time]
  ```
 - time -> temps en ms avant la fin du serveur
 #
 lost: Les joueurs ont perdu
  ```
  gamestate;lost;[time]
  ```
 - time -> temps en ms avant la fin du serveur
 
## Evenements

event;[type]

### Type

hit:
 ```
  event;hit;[posX];[posY]
  ```
  - posX;posY -> Nombres flottant qui indiquent les coordonnées du hit

## Entités

entity;[type]

### Type

player :
 ```
  entity;player;[pseudo ou  UUID ?];[status];[score];[hp];[as];[posX];[posY];[ForcePodLevel]
 ```
 - pseudo ou UUID -> chaine de caractère définissant le joueur
 
 - status -> ALIVE ou DEAD, si DEAD alors il n'y a pas les infos qui suivent
 
 - score -> Nombre entier définissant le score
 
 - hp -> Nombre flottant définissant les hp du joueur
 
 - as -> vitesse d'attaque du joueur (sera utile avec les powerups)
 
 - posX;posY -> Nombres flottant qui indiquent les coordonnées du joueur
 
 - ForcedPodLevel -> [0,  1, 2] qui définit le niveau du PodLevel
#
monster :
 ```
  entity;monster;[UUID];[type];[posX];[posY]
  ```
- UUID -> chaine de caractère définissant le monstre

- type -> chaine de caractère définissant le type du monstre

- posX;posY -> Nombres flottant qui indiquent les coordonnées du monstre
#
bullet :
 ```
 entity;bullet;[UUID];[type];[posX];[posY]
 ```
- UUID -> chiffre entier définissant la balle

- type -> chaine de caractère définissant le type de la balle

- posX;posY -> Nombres flottant qui indiquent les coordonnées de la balle
#
powerup :
 ```
 entity:powerup;[type];[posX];[posY];
 ```

- type -> chaine de caractère définissant le type du powerup

 - posX;posY -> Nombres flottant qui indiquent les coordonnées du powerup

#