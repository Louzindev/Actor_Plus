#include "ActorPlus.h"

namespace actor_p {

	bool IsPlayerAimingActor(const int playerid, const int actorid) {
        int aimid = GetPlayerTargetActor(playerid);

        if (aimid == actorid) {
            return true;
        }
        else {
            return false;
        }
        return true;
	}

    void SetActorChatBubble(const int actorid, const char* text, int delay) {
        float pos[3];
        GetActorPos(actorid, &pos[0], &pos[1], &pos[2]);

        int textLabel = Create3DTextLabel(text, -1, pos[0], pos[1], pos[2]+1.5, 30.0, 0, false);
        delay *= CLOCKS_PER_SEC;

        clock_t now = clock();

        while (clock() - now < delay);

        Delete3DTextLabel(textLabel);

    }

    void SetActorName(const int actorid, const char* name) {
        float pos[3];
        GetActorPos(actorid, &pos[0], &pos[1], &pos[2]);
        actor[actorid].name = name;
        actor[actorid].nameLabel = Create3DTextLabel(name, -1, pos[0], pos[1], pos[2], 30.0, 0, false);
    }

}