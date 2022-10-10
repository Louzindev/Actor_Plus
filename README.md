# Actor_Plus
	a SAMP plugin, which increases the power of actors, adding more native functions

## natives

### GetActorWhoPlayerTarget
params
    ```cpp
    const playerid
    ```
    player who target the actor
return 
    return the actor who player target

### SetActorChatBubble
params
    ```cpp
    const actorid
    ```
    the actor to aply the chat bubble
    ```cpp
    const str[]
    ```
    the string for bubble
    ```cpp
    delay
    ```
    the time in miliseconds for delete the label
return
    1 - succes
    2 - failure

### TogglePlayerTargetActor
params
    ```cpp
    const playerid
    ```
    player for autorize aim actors
    ```cpp
    toggle
    ```
    1 - toggle
    2 - not toggle
return
    1 - succes
    2 - failure
FUNC:
    able the player to call OnPlayerTargetActor;

## Callbacks

### OnPlayerTargetActor
params
    ```cpp
    const playerid
    ```
    player who target the actor

    ```cpp
    const actorid
    ```
    actor who player's target
return
    1

