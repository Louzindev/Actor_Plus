#ifndef ACTORPLUS_H_INCLUDED
#define ACTORPLUS_H_INCLUDED
#include "main.h"
#include <time.h>

struct act_p {
	const char* name;
	int nameLabel;
	const char* speak;
	int speakLabel;
};

act_p* actor;

namespace actor_p{
	bool IsPlayerAimingActor(const int playerid, const int actorid);
	void SetActorChatBubble(const int actorid, const char* text, int delay);
	void SetActorName(const int actorid, const char* name);

}

#endif