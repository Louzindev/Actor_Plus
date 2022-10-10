#pragma once
#include "main.h"

namespace actor_p {

    typedef struct act_plus_data {
        const char* name;
        int nameLabel;
        const char* speak;
        int speakLabel;
        int BubbleLabel;
        bool talk;
    }act_p;

    typedef struct player_plus_data {
        int targetActor;
        int actorAiming;
        AMX* public_amx;
    }player_p;
    
    void TogglePlayerTargetActor(int playerid, int toggle);
    bool IsPlayerAimingActor(const int playerid, const int actorid);
    int GetActorWhoPlayerTarget(const int playerid);

    void SetActorChatBubble(const int actorid, const char* text, int delay = 5);

    void TogglePlayerTargetActor(int playerid, int toggle);

    void GetServerActors();
};