native HelloWorld();
native GetActorWhoPlayerTarget(const playerid);
native SetActorChatBubble(const actorid, const str[], delay); 
native TogglePlayerTargetActor(const playerid, Togle);
forward OnPlayerTargetActor(const playerid, const actorid);

forward GetOnPlayerTargetActor(const playerid);
public GetOnPlayerTargetActor(const playerid) {

	new actorid = GetActorWhoPlayerTarget(playerid);
	if(!IsValidActor(actorid))
		return 1;
	CallLocalFunction(#OnPlayerTargetActor, "dd", playerid, actorid);
	return 1;
}

new TimerTarget = 0;
public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if((newkeys & KEY_HANDBRAKE) && !(oldkeys & KEY_HANDBRAKE)) {
        TimerTarget = SetTimerEx(#GetOnPlayerTargetActor, 800, true, "d", playerid);
    }
    if((oldkeys & KEY_HANDBRAKE) && !(newkeys & KEY_HANDBRAKE)) {
        KillTimer(TimerTarget);
    }
	
	#if defined actp_OnPlayerKeyStateChange
		return actp_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerKeyStateChange
	#undef OnPlayerKeyStateChange
#else
	#define _ALS_OnPlayerKeyStateChange
#endif

#define OnPlayerKeyStateChange actp_OnPlayerKeyStateChange
#if defined actp_OnPlayerKeyStateChange
	forward actp_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif