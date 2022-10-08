#ifndef ACTORPLUS_H_INCLUDED
#define ACTORPLUS_H_INCLUDED
#include "main.h"
#include <time.h>

namespace actor_p{
	struct act_p {
		const char* name;
		int nameLabel;
		const char* speak;
		int speakLabel;
		bool talk;
	};
	bool IsPlayerAimingActor(const int playerid, const int actorid);
	void SetActorChatBubble(const int actorid, const char* text);
	void SetActorName(const int actorid, const char* name);
	void ToggleActorTalk(const int actorid, bool toggle);
}

#endif