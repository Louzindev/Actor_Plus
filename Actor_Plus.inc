#if defined _inc_ACTOR_PLUS
	#undef _inc_ACTOR_PLUS
#endif

#if defined _ACTOR_PLUS_included
	#endinput
#endif
#define _ACTOR_PLUS_included

#define MAJOR_VERISON (1)
#define MINOR_VERSION (2)
#define PATCH_VERSION (0)


native HelloWorld();
native GetActorWhoPlayerTarget(const playerid);
native SetActorChatBubble(const actorid, const str[], delay); 
native TogglePlayerTargetActor(const playerid, Togle);
native CheckVersion(major, minor, patch);


forward OnPlayerTargetActor(const playerid, const actorid);

#if !defined NO_ACTORPLUS_CHECK_VERSION 
	public OnGameModeInit()
	{
		CheckVersion(MAJOR_VERISON, MINOR_VERSION, PATCH_VERSION);
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