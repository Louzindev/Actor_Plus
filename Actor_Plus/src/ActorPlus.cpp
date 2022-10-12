#include "ActorPlus.h"
namespace actor_p {
    act_p* actor;
    player_p player[MAX_PLAYERS];



    // =====================> OnPlayerTargetActor <======================

    int GetActorWhoPlayerTarget(const int playerid) {
        int aimid = GetPlayerTargetActor(playerid);
        if (player[playerid].targetActor == 0)
            return INVALID_ACTOR_ID;
        if (IsValidActor(aimid)) {
            if (IsPlayerAimingActor(playerid, aimid)) {
                return aimid;
            }
        }
        return INVALID_ACTOR_ID;
    }

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

    void SAMPGDK_CALL GetsTarget(int timerid, void* param) {
        int playerid = (int)param;
        if(player[playerid].targetActor == 0) {
            KillTimer(timerid);
            return;
        }

        int actorid = GetActorWhoPlayerTarget(playerid);
        if(actorid != INVALID_ACTOR_ID) {
            int idx = 0;
            AMX* amx = player[playerid].public_amx;
            if(!amx_FindPublic(amx, "OnPlayerTargetActor", &idx)) {
                cell player = playerid;
                cell actor = actorid;
                int ret;
                amx_Push(amx, actor);
                amx_Push(amx, player);
                amx_Exec(amx, &ret, idx);

                if(ret == 0) {
                    logprintf("[Actor_Plus]:OnPlayerTargetActor(%d, %d) may not work properly", playerid, actorid);
                }
            }
        }
    }

    void TogglePlayerTargetActor(int playerid, int toggle, AMX* amx) {
        if (toggle == 1) {
            player[playerid].targetActor = 1;
            player[playerid].public_amx = amx;
        }     
        else 
            player[playerid].targetActor = 0;
    }

    int timertarget = 0;
    PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerKeyStateChange(int playerid, int newkeys, int oldkeys) {
        if((newkeys & KEY_HANDBRAKE) && !(oldkeys & KEY_HANDBRAKE)) {
            if(player[playerid].targetActor  == 1) {
                timertarget = SetTimer(800, true, GetsTarget, (void*)playerid);
            }
        }
        if((oldkeys & KEY_HANDBRAKE) && !(newkeys & KEY_HANDBRAKE)) {
            KillTimer(timertarget);
        }
        return 1;
    }
    // =====================> end OnPlayerTargetActor <====================== 



    // =====================> ActorBubble <====================== 
    void SAMPGDK_CALL DeleteActorBubble(int timerid, void* param) {
        int actorid = (int)param;
        Delete3DTextLabel(actor[actorid].BubbleLabel);
        return;
    }

    void SetActorChatBubble(const int actorid, const char* text, int delay) {
        float pos[3];
        GetActorPos(actorid, &pos[0], &pos[1], &pos[2]);

        actor[actorid].BubbleLabel = Create3DTextLabel(text, -1, pos[0], pos[1], pos[2] + 1.5, 30.0, 0, false);

        SetTimer(delay, false, DeleteActorBubble, (void*)actorid);
    }
    // =====================> end ActorBubble <======================
    int timer_actspeak = 0;
    void SAMPGDK_CALL ActorSpeaks(int timerid, void* param) {
        static int speaknum = 0;
        int actorid = (int)param;
        if(!actor[actorid].speak) {
            KillTimer(timerid);
            return;
        }
        switch(speaknum) {
            case 0: {SetActorChatBubble(actorid, actor[actorid].speaks.speak1); speaknum++;};
            case 1: {SetActorChatBubble(actorid, actor[actorid].speaks.speak2); speaknum++;};
            case 2: {SetActorChatBubble(actorid, actor[actorid].speaks.speak3); speaknum = 0;};
        }
    }
    // =====================> ActorSpeak <====================== 
    void ToggleActorTalk(const int actorid, const int toggle) {
        if(toggle) {
            actor[actorid].speak = 1;
            timer_actspeak = SetTimer(10000, true, ActorSpeaks, (void*) actorid);
        } else {
            KillTimer(timer_actspeak);
        }
    }

    void SetActorSpeak(const int actorid, struct act_speak* speaks) {
        actor[actorid].speaks.speak1 = speaks->speak1;
        actor[actorid].speaks.speak2 = speaks->speak2;
        actor[actorid].speaks.speak3 = speaks->speak3;
    }
    // =====================> end ActorSpeak <====================== 

    void GetServerActors() {
        int totalActors = 0;
        free(actor);
        for (int i = 0; i < MAX_ACTORS; ++i) {
            if (IsValidActor(i)) {
                totalActors++;
            }
        }
        actor = (act_p*)malloc(totalActors * sizeof(act_p));
    }


};