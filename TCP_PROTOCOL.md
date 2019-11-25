# TCP Protocol Documentation

## Table of contents

- Lobby Management
  - Create Lobby
    - Create Lobby Request `TODO SERVER` `TODO CLIENT`
    - Create Lobby Response `TODO SERVER` `TODO CLIENT`
  - Join Lobby
    - Join Lobby Request `TODO SERVER` `TODO CLIENT`
    - Join Lobby Response `TODO SERVER` `TODO CLIENT`
  - Info Lobby
    - Info Lobby Request `TODO SERVER` `TODO CLIENT`
    - Info Lobby Response `TODO SERVER` `TODO CLIENT`
  - Set the player ready `TODO SERVER` `TODO CLIENT`
  - Start the game
    - Start the game Request `TODO SERVER` `TODO CLIENT`
    - Start the game Response `TODO SERVER` `TODO CLIENT`
- Level Infos Management
  - Map Shape update `TODO SERVER` `TODO CLIENT`


## Lobby Management

<br>

### Create Lobby:

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

### Join Lobby:

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

### Info Lobby:

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

### Set player ready:

Ask for server to set player ready in the Lobby.

```
    LOBBY READY [CODE] [PLAYER_NAME];
```
Where \[CODE\] is replaced with the unique code of the Lobby, and

\[PLAYER_NAME\] is replaced by the name of the current player.

<br>

Server will send to each client an Info Response.

<br>

### Start the game:

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



## Level Infos Management

### Map Shape:

#### Response from the server:

Update Map Shape.

```
    LEVEL MAP UPDATE;
    ------------------;
    ------------------;
    ------MAP------;
    ------------------;
    ------------------;
```