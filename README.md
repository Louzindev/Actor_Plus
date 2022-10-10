# Actor_Plus
	a SAMP plugin, which increases the power of actors, adding more native functions

## natives

### GetActorWhoPlayerTarget
```
params
    const playerid
    player who target the actor
return 
    return the actor who player target
```
### SetActorChatBubble

```
params
    
    const actorid
    
    the actor to aply the chat bubble
    
    const str[]
    
    the string for bubble
    
    delay
    
    the time in miliseconds for delete the label
return
    1 - succes
    2 - failure
```
### TogglePlayerTargetActor
```
params
    
    const playerid
    
    player for autorize aim actors
    
    toggle
    
    1 - toggle
    2 - not toggle
return
    1 - succes
    2 - failure
FUNC:
    able the player to call OnPlayerTargetActor;
```
## Callbacks

### OnPlayerTargetActor
```
params
    
    const playerid
    
    player who target the actor

    
    const actorid
    
    actor who player's target
return
    1
```

