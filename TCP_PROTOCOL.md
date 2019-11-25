# TCP Protocol Documentation

## Table of contents

- [Lobby Management](#lobby_management)
  - [Create Lobby](#lobby_create)
    - Create Lobby Request `TODO SERVER` `TODO CLIENT`
    - Create Lobby Response `TODO SERVER` `TODO CLIENT`
  - [Join Lobby](#lobby_join)
    - Join Lobby Request `TODO SERVER` `TODO CLIENT`
    - Join Lobby Response `TODO SERVER` `TODO CLIENT`
  - [Info Lobby](#lobby_info)
    - Info Lobby Request `TODO SERVER` `TODO CLIENT`
    - Info Lobby Response `TODO SERVER` `TODO CLIENT`
  - [Set the player ready](#lobby_ready) `TODO SERVER` `TODO CLIENT`
  - [Start the game](#lobby_start)
    - Start the game Request `TODO SERVER` `TODO CLIENT`
    - Start the game Response `TODO SERVER` `TODO CLIENT`
- [Level Infos Management](#level_management)
  - [Map Shape update](#level_map_shape) `TODO SERVER` `TODO CLIENT`
  - [Map Position update](#level_map_position) `TODO SERVER` `TODO CLIENT`


## Lobby Management <a name="lobby_management"></a>

<br>

### Create Lobby: <a name="lobby_create"></a>

#### Request from client:

Ask to server to create a new Lobby instance. If it succeed, server
return the Lobby code.

```
    LOBBY CREATE;
```

#### Response from server:

Tell to the client action succeed or not with additional infos.

<br>

Succeed:
```
    LOBBY CREATE SUCCEED [CODE];
```
Where \[CODE\] is replaced with the unique code of the Lobby

<br>

Failed:
```
    LOBBY CREATE FAILED;
```

<br>

### Join Lobby: <a name="lobby_join"></a>

#### Request from the client:

Ask server to join Lobby with code.

```
    LOBBY JOIN [CODE];
```
Where \[CODE\] is replaced with the unique code of the Lobby

#### Response from the server:

Tell to the client action succeed or not.

<br>

Succeed:
```
    LOBBY JOIN SUCCEED;
```

<br>

Failed:
```
    LOBBY JOIN FAILED;
```


<br>

### Info Lobby: <a name="lobby_info"></a>

#### Request from the client:

Ask for server to send updated Lobby infos.

```
    LOBBY INFO [CODE];
```
Where \[CODE\] is replaced with the unique code of the Lobby.

#### Response from the server:

Tell to client the updated Lobby infos.

```
    LOBBY INFO [CODE] [PLAYER_COUNT];
    LOBBY PLAYERS;
    [PLAYER_NAME] [PLAYER_READY_STATUS];
```
Where \[CODE\] is replaced with the unique code of the Lobby,

\[PLAYER_COUNT\] is replaced by the number of player in the Lobby, and

\[PLAYER_NAME\] is replaced by the name of the player in the Lobby and \[PLAYER_READY_STATUS\] is replaced by `TRUE` or `FALSE`

<br>

### Set player ready: <a name="lobby_ready"></a>

Ask for server to set player ready in the Lobby.

```
    LOBBY READY [CODE] [PLAYER_NAME];
```
Where \[CODE\] is replaced with the unique code of the Lobby, and

\[PLAYER_NAME\] is replaced by the name of the current player.

<br>

Server will send to each client an Info Response.

<br>

### Start the game: <a name="lobby_start"></a>

#### Request from the client:

Ask for server to start the game of the Lobby.
It it succeed, server gonna send a Start Response to all client of the
lobby, otherwise nothing append.

```
    LOBBY START [CODE];
```

#### Response from server:

Tell to the client to switch to Game Mode.
Server will send only one time a game this response.

```
    LOBBY START;
```



<br><br>

## Level Infos Management <a name="level_management"></a>

### Map Shape: <a name="level_map_shape"></a>

#### Response from the server:

Update Map Shape.

```
    LEVEL MAP SHAPE [MAP_ID];
```

### Map Position: <a name="level_map_position"></a>

#### Response from the server:

Update Map Position.

```
    LEVEL MAP POSITION [POS_X];
```


<br>