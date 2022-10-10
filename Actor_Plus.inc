#if defined _inc_ACTOR_PLUS
	#undef _inc_ACTOR_PLUS
#endif

#if defined _ACTOR_PLUS_included
	#endinput
#endif
#define _ACTOR_PLUS_included

#define MAJOR_VERISON (1)
#define MINOR_VERSION (0)
#define PATCH_VERSION (0)


native HelloWorld();
native GetActorWhoPlayerTarget(const playerid);
native SetActorChatBubble(const actorid, const str[], delay); 
native TogglePlayerTargetActor(const playerid, Togle);
forward OnPlayerTargetActor(const playerid, const actorid);
native CheckVersion(major, minor);

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

#if !defined NO_ACTORPLUS_CHECK_VERSION 
	public OnGameModeInit()
	{
		CheckVersion(MAJOR_VERISON, MINOR_VERSION);
		#if defined actp_OnGameModeInit
			return actp_OnGameModeInit();
		#else
			return 1;
		#endif
	}
	#if defined _ALS_OnGameModeInit
		#undef OnGameModeInit
	#else
		#define _ALS_OnGameModeInit
	#endif

	#define OnGameModeInit actp_OnGameModeInit
	#if defined actp_OnGameModeInit
		forward actp_OnGameModeInit();
	#endif
#endif