#include "Alphabet.h"
#include "SFX.h"
#include "actor.h"
#include "music.h"
#include "common.h"

#ifdef NON_MATCHING
int32_t Knockback_NegSinDmg(uint16_t index0,uint16_t index1,int32_t x){
  int theta;
  float dmg;
  
  dmg = sqrtf(gActors[index0].healthDelta);
  
  theta = atan2(gActors[index0].pos.x_w - gActors[index1].pos.x_w ,
                       gActors[index0].pos.y_w - gActors[index1].pos.y_w );
  //mismatch here
  return (gCosineLookup[theta + 0x100 & 0x200] * dmg * (float)x * 2.0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/1F1E0/Knockback_NegSinDmg.s")
#endif
#ifdef NON_MATCHING
int32_t Knockback_SinDmg(uint16_t index0,uint16_t index1,int32_t x){
  int theta;
  float dmg;
  
  dmg = sqrtf(gActors[index0].healthDelta);
  
  theta = atan2(gActors[index0].pos.x_w - gActors[index1].pos.x_w ,
                       gActors[index0].pos.y_w - gActors[index1].pos.y_w );
  //mismatch here again
  return (float)(SIN(theta) * dmg * x * 2.0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/1F1E0/Knockback_SinDmg.s")
#endif

void Knockback_Noop(uint16_t arg0, uint16_t arg1) {}

#ifdef NON_MATCHING
void Knockback_Arc(uint16_t index0, uint16_t index1) {
    //branching for first condition inaccurate.
    if ((gActors[index0].vel.x_w) && (gActors[index0].vel.y_w)) {
        gActors[index1].speedX._w = gActors[index0].vel.x_w;
        gActors[index1].speedY._w = gActors[index0].vel.y_w;
    }
    else {
        gActors[index1].speedX._w = Knockback_NegSinDmg(index0, index1, 0x2000);
        gActors[index1].speedY._w = Knockback_SinDmg(index0, index1, 0x2000);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/1F1E0/Knockback_Arc.s")
#endif

void Knockback_Linear(uint16_t index0, uint16_t index1) {
    IFFACINGRIGHT(index0) {
        gActors[index1].speedX._w = gActors[index0].speedX._w;
    }
    else {
        gActors[index1].speedX._w = -gActors[index0].speedX._w;
    }
    gActors[index1].speedY._w = gActors[index0].speedY._w;
}

#ifdef NON_MATCHING
// Differences are regalloc
void Knockback_Linear2(uint16_t index0, uint16_t index1) {
    Actor* actor0 = &gActors[index0];
    Actor* actor1 = &gActors[index1];

    if (actor0->pos.x < actor1->pos.x) {
        actor0->speedX._w = -actor1->speedX._w;
    }
    else {
        actor0->speedX._w = actor1->speedX._w;
    }
    actor0->speedY._w = actor1->speedY._w;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/1F1E0/Knockback_Linear2.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/1F1E0/Knockback_RandomArc.s")

void func_8001EADC(uint16_t index0, uint16_t index1) {
    Actor* actor = &gActors[index1];

    if (actor->unk_0xDE == 11 || actor->unk_0xDE == 14 || actor->unk_0xDE == 15) {
        actor->flag3 &= ~2;

        actor = &gActors[index0];
        actor->flag3 ^= 3;
        actor->unk_0xDC = actor->unk_0xDA;
        actor->unk_0xDD = actor->unk_0xDB;
    }
    else {
        Knockback_RandomArc(index0, index1);
    }
}

#ifdef NON_MATCHING
/* This function is related to hit / knockback effects?
 * Differences are regalloc, behaviorally the same
 */
void Knockback_Get(uint16_t index0, uint16_t index1) {
    gActors[index1].unk_0xDC = gActors[index0].unk_0xDA;
    gActors[index1].unk_0xDD = gActors[index0].unk_0xDB;
    gKnockbackFuncTable[gActors[index0].unk_0xDB](index0, index1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/1F1E0/Knockback_Get.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/1F1E0/func_8001EC1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1F1E0/func_8001F88C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1F1E0/func_8001FA78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1F1E0/func_8001FCA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1F1E0/func_8001FEB0.s")

void DebugFunc_8000h(void) {}

void func_8001FF30(void) {
    gPlayerActorp->flag3 &= 0x80600;
}

void func_8001FF50(void) {
    uint16_t index;

    for (index = 1; index < ACTOR_COUNT1; index++) {
        thisActor.flag3 &= 0x380600;
    }
}

void func_8001FFA0(void) {}

void func_8001FFA8(void) {
    gIsPlayerInactive = 0;
    gCameraScrollThrottleX = D_801781C8;
    gCameraScrollThrottleY = D_801781CA;
    gCameraScrollFlags = D_801781CC;
    D_800D2920 = D_801781CE;
    D_800D2924 = D_801781D0;
    D_800D2918 = D_801781D2;
    D_800D291C = D_801781D4;
}

void GamePlay_Tick_Active(void) {
    int32_t phi_s0;
    int16_t* phi_s1;
    uint8_t* phi_s2;
    uint16_t* phi_s3;
    int32_t phi_s4;

    gSceneFrames++;
    gStageTimeReal++;

    phi_s0 = 36000; // probably a fake match, but it is obvious that s0 or s4 is reused somewhere before the loop at the bottom
    if ((((gStageTime < phi_s0) && (D_800D28E8 >= 2)) && (func_8005DEFC() == 0)) && (D_800D28E4 < 0x61)) {
        gStageTime++;
    }

    func_800122B0(); // input history

    if ((gDebugBitfeild & 2)) { //debug game speed throttle
        if ((gButtonPress & gButton_LTrig)) {
            if (gDebugThrottle != 1) {
                gDebugThrottle--;
                gThrottleInput[0] = 0;
            }
        }

        if (((gButtonPress & gButton_RTrig)) && (gDebugThrottle != 50)) {
            gDebugThrottle++;
            gThrottleInput[0] = 0;
        }

        if ((gSceneFramesReal % gDebugThrottle) == 0) {
            gButtonPress |= gThrottleInput[0];
            gThrottleInput[0] = 0;
        }
        else {
            gThrottleInput[0] |= gButtonPress; //save button inputs and wait for the next "frame"
            return;
        }
    }

    func_800253B0(); // background
    func_8001F88C(); // unknown, does something with actors
    Actors_PositionTick(); // physics
    Actors_PhysicsTick(); // collision
    ActorMarina_ScreenScroll(); // camera
    func_80016D94(); // offsets objects from the camera so that they are in the correct relative position
    func_8001EC1C(); // interaction with objects
    func_8001107C(); // foreground layer of background?

    if (gIsPlayerInactive == 0) {
        ActorTick_Marina(0);    // updates the player
        func_8008C528(0x41); // unknown
    }

    func_8001FF30(); // sets a value in the player
    SceneActorSpawn_Tick(); // unknown, does something with camera
    func_8008CA90(); // unknown, does something with actors
    Actors_Tick(); // actors
    func_80014C44(); // clamp to world bounds? also saves position/graphic history for unimplimented afterimages' state.
    CameraShake_Tick(); // camera quake
    func_8001FF50(); // update actor flags
    Textbox_Tick(); // text
    LifeBar_Tick(); // ui (blinking, health bar)

    if (gGameState == GAMESTATE_GAMEPLAY) {
        func_80047CCC(); // scene init
    }

    func_80047C98(); // level objects

    if ((gDebugBitfeild & 0x4000)) {
        phi_s2 = gSFX_ChannelStates, phi_s3 = gSFXCurrentIndex, phi_s1 = gSFX_Volumes; // Whitespace memes
        phi_s0 = 0x3C;
        phi_s4 = 0x30;
        do {
            DebugText_PrintShortHexBlack(phi_s2[0], -0x90, phi_s0);
            DebugText_PrintInt(phi_s3[0] - 0x21, -0x90, phi_s4);
            DebugText_PrintShortHexBlack(phi_s1[0], -0x68, phi_s0);

            phi_s2++;
            phi_s0 -= 0x20;
            phi_s3++;
            phi_s4 -= 0x20;
            phi_s1++;
        } while (phi_s1 != D_800EF500);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/1F1E0/Playtime_PrintPause.s")


#pragma GLOBAL_ASM("asm/nonmatchings/1F1E0/RedGem_PrintPause.s")

void YellowGem_PrintProgress(void) {
    if (YellowGem_GetFlag(gCurrentStage))
        func_800836A0(9, 1, &Alpha_GotIt, 0);
    else
        func_800836A0(9, 1, &Alpha_NotYet, 0);
}

#ifdef NON_MATCHING
void PauseGame_RestoreVolume(void) { // resets sound levels after exiting pause menu?
    uint16_t i;
    for (i = 0; i < 4; i++)
        SFX_Volumes[i] = D_801781C0[i];
    SFX_Play_1(SFX_MARINA_YELL2);
    for (i = 204; i < 208; i++)
        gActors[i].flag = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/1F1E0/PauseGame_RestoreVolume.s")
#endif

void PauseGame_Unpause(void) {
    uint16_t index;

    for (index = 0xC8; index < 0xCC; index++) {
        thisActor.flag = 0;
    }

    gBgmVolume = gBgmVolumeTemp;
    gGameSubState = 0;
    gGamePaused = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/1F1E0/PauseGame_SpawnBars.s")

void PauseGame_ResetBars(void) {
    uint16_t index;

    for (index = 200; index < 204; index++) {
        thisActor.flag = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/1F1E0/PauseGame_Tick.s")

void GamePlay_Tick(void) {
    uint32_t time;

    time = osGetTime();
    ColorCycle_Tick(); // this function dmas sprite data for things like gems
    gTickDelta = osGetTime() - time;

    if (gGamePaused) {
        PauseGame_Tick();
    }
    else {
        GamePlay_Tick_Active();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/1F1E0/AttractMode_PlayInput.s")

#ifdef NON_MATCHING
/* Behavior is mostly the same (besides softlocking when the game state should change out of demo mode)
 * Needs reordering and major regalloc fixes, start has branching behavior that I don't know how to replicate
 */
void AttractMode_Tick(void) {
    if (gGameSubState != 0) {
        if (gGameSubState == 1) {
            if (D_801037AA == 0x90) {
                D_80103918 = 0;
                D_80103780 = 0;
                D_801035E8 = 0;
                D_80103450 = 0;
            }
            else {
                D_80103480 += 2;
                D_80103616 -= 2;
                D_801037AA += 3;
                D_80103944 -= 3;
            }

            AttractMode_PlayInput();
            gAttractModeTimer -= -1;
            if ((gAttractModeTimer == 0 || ((gButtonPress & gButton_Start) != 0)) && (D_80103450 == 0)) {
                func_80003F24(1, 0x40, &gAttractModeTimer);
                gGameSubState += 1;
                gAttractModeTimer = 0x40;
            }
        }
        else if (gGameSubState == 2) {
            AttractMode_PlayInput();
            gAttractModeTimer += 1;
            if (gAttractModeTimer == 0x30) {
                D_80103918 = 0xB;
                D_80103780 = 0xB;
                D_801035E8 = 0xB;
                D_80103450 = 0xB;
                gGameSubState += 1;
            }
        }
        else if (gGameSubState == 3) {
            AttractMode_PlayInput();
            if (D_801037AA == D_80103944) {
                gAttractModeIndex += 1;
                D_80137D90 = 0;
                gGameState = GAMESTATE_SOFTRESET;
                gGameSubState = 0;
            }
            else {
                D_80103480 -= 2;
                D_80103616 += 2;
                D_801037AA -= 3;
                D_80103944 += 3;
            }
        }
    }
    else {
        if (3 < gAttractModeIndex) {
            gAttractModeIndex = 0;
        }

        gCurrentStage = attractModeStages[gAttractModeIndex];
        gCurrentScene = gStageScenes[gCurrentStage];
        D_800D28E4 = D_800C83F8[gCurrentStage];
        gAttractModeTimer = 0xA00;
        D_800D2908 = 1;
        gPlayerActor.health = 1000;
        D_800BE668 = 0x32;
        D_800BE5A4 = 0x1234;
        GamePlay_Load();
        gGameState = GAMESTATE_ATTRACT;
        gGameSubState = 1;
        HealthFace.flags = 0;
        HealthBar.flags = 0;
        PauseGame_SpawnBars();
        D_80103944 = 0;
        D_801037AA = 0;
        D_80103616 = 0;
        D_80103480 = 0;
        gAttractModeInputHoldIndex = 0;
        gAttractModeInputHold = 0;
        gAttractModeInputIndex = 0;
        D_800CA24C = 0;
        gAttractModeInputHoldTimer = gAttractModeHoldInputs[gAttractModeIndex];
        gAttractModeInputTimer = gAttractModePressInputs[gAttractModeIndex];
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/1F1E0/AttractMode_Tick.s")
#endif

/* when I first came across this ages ago, I was really confused, now I know:
 * it changes the color of debug text when you press R (see usage of gDebugBitfeild)
 * will need to investigate further, but it seems to just be an i8 color
 * why didn't they just give the text an outline?
 */
void DebugText_BorW(void) {
    if ((gButtonPress & gButton_RTrig)) {
        gDebugBorW._s ^= 0xFF;
    }
}

void DebugFunc_40h(void) {}

void DebugFunc_1000h(void) {}

void func_80021668(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3) {}

void DebugFunc_1h(void) {}
