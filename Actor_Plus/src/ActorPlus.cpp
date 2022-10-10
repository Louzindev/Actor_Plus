#include "ActorPlus.h"
#include "lzn_lib.h"

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
        return 1;
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

    void TogglePlayerTargetActor(int playerid, int toggle) {
        if (toggle == 1)
            player[playerid].targetActor = 1;
        else 
            player[playerid].targetActor = 0;
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