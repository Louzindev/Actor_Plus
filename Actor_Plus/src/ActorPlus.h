#ifndef ACTORPLUS_H_INCLUDED
#define ACTORPLUS_H_INCLUDED

#include "main.h"
#include "lzn_lib.h"

namespace actor_p {

    struct act_speak {
        const char* speak1;
        const char* speak2;
        const char* speak3;
    };

    typedef struct act_plus_data {
        const char* name;
        int nameLabel;
        int speakLabel;
        int BubbleLabel;
        int speak;
        struct act_speak speaks;
    }act_p;

    typedef struct player_plus_data {
        int targetActor;
        int actorAiming;
        AMX* public_amx;
    }player_p;
    
    void callback(AMX* amx);
    void TogglePlayerTargetActor(int playerid, int toggle, AMX* amx);
    bool IsPlayerAimingActor(const int playerid, const int actorid);
    int GetActorWhoPlayerTarget(const int playerid);

    void SetActorChatBubble(const int actorid, const char* text, int delay = 5);

    void ToggleActorTalk(const int actorid);
    void SetActorSpeak(const int actorid, struct act_speak speaks);

    void GetServerActors();
};
#endif