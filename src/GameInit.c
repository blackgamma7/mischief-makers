#include "common.h"
#include "music.h"

void func_80022D10(void) {
    func_80043478();
    D_800BE668 = 0x32;
    D_800BE6E4 = 0;
    D_800BE6E8 = 0;
    D_800BE6EC = 0;
    gButton_B = B_BUTTON;
    gButton_A = A_BUTTON;
    gCurrentFramebufferIndex = 0;
    gAttractModeIndex = 0;
    gGameState = GAMESTATE_SOFTRESET;
    gGameSubState = 0;
}
#ifdef NON_MATCHING
void Reset_InitB(void){ //~96%matching
  uint16_t i;
  gGamePaused = 0;
  D_80137D90 = 0;
  D_800CBF40 = 0;
  gIsPlayerInactive = 0;
  D_800BE4EC = 0;
  D_800BE670 = 0;
  D_800BE66C = 0;
  D_800BE674 = 0;
  D_8013747C = 0;
  D_800BE6FC = 0;
  gDebugBitfeild = 4;
  gDebugThrottle = 1;
  gRNGSeed = 0x1234;
  gCamShakeV = 0;
  gCamShakeTime = 0;
  D_800BE678 = 0;
  gPortraitTint = 0xFF;
  gHPDisplayed = gPlayerActor.health;
  BGM_Stop();
  SFX_StopAll();
  ClearActorsAndGems();
  ClearPortraits();
  func_80023168();
  func_80010A10();
  func_8008310C();
  gCurrentScene = SCENE_SPLASHSCREEN;
  InitScene();
  func_80043918();
  func_80010C20(gCurrentScene);
  D_80380200[2] = 1; //"addiu" instead of "ori"
  D_80380200[1] = 1;
  func_80028260(2,1,0,0,0);
  func_80028260(2,2,0,0,0);
  for(i = 0;i < 4;i++) { //regAlloc
    gEnvColorsOpaque[i]=1;
    gEnvColorsRed[i]=0xFF;
    gEnvColorsGreen[i]=0xFF;
    gEnvColorsBlue[i]=0xFF;
  }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/GameInit/Reset_InitB.s")
#endif
// This function is called when the user soft-resets the game
void start_game(void) {
    if (gGameSubState != 0) { //fake match? seems like case-switch.
        if (gGameSubState != 1) {
            return;
        }
    }
    else {
        ClearActorsAndGems();
        ClearPortraits();
        func_80023168();

        gGameSubState++;
        return;
    }

    Reset_InitB();
    func_80025E6C();
    GameSave_Initialize(0);
    GameSave_Initialize(1);
    GameSave_SetDefaults();

    gButton_Start = START_BUTTON;
    gButton_DUp = U_JPAD;
    gButton_DDown = D_JPAD;
    gButton_DLeft = L_JPAD;
    gButton_DRight = R_JPAD;
    gButton_B = B_BUTTON;
    gButton_A = A_BUTTON;
    gButton_CLeft = L_CBUTTONS;
    gButton_CDown = D_CBUTTONS;
    gButton_CUp = U_CBUTTONS;
    gButton_CRight = R_CBUTTONS;
    gButton_ZTrig = Z_TRIG;
    gButton_LTrig = L_TRIG;
    gButton_RTrig = R_TRIG;
    D_801781F8 = 0;
    D_800CBF44 = 0;
    gPlayerActor.health = 1000;
    gRedGems = 30;
    gGameState = GAMESTATE_INTRO;
    gGameSubState = 0;
    return;
}
void ClearActorsAndGems(void){
    uint16_t i;
    for(i=0;i<ACTOR_COUNT2;i++){
        gActors[i].flag=0;
        gActors[i].graphicList=NULL;
    }
    for(i=0;i<ARRAYLENGTH(gStaticGems);i++){
        gStaticGems[i].flags=0;
    }
}

void ClearPortraits(void){
    uint16_t i;
    for(i=0;i<ARRAYLENGTH(gPortraits);i++){
        gPortraits[i].flags=0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/GameInit/func_80023168.s")

#ifdef NON_MATCHING
// Needs regalloc fixes, and reordering related to a structure
void GamePlay_Load(void) {
    int32_t temp_t6_2;
    int32_t temp_t8_2;
    int32_t temp_v0;
    uint16_t temp_t8_3;
    int16_t index;
    int32_t phi_v0_2;

    for (index = 0; index < 4; index++) {
        gEnvColorsOpaque[index] = 1;
        gEnvColorsBlend[index] = 1;
        gEnvColorsRed[index] = 0;
        gEnvColorsGreen[index]=0;
        gEnvColorsBlue[index]=0;
        gEnvColorsAlpha[index]=255;
    }

    gPortraitTint = 0xFF;
    gHPDisplayed = gPlayerActorp->health;
    D_800BE6C0 = -8;
    gDebugBitfeild = 4;

    for (index = 0; index < 8; index++) {
        D_80137480[index] = 0;
    }

    
    gPlayerManager->unk_0x078 = 0;
    gSpeaker_ActorLink = 0;
    D_800BE5F4._w = 0;
    gIsPlayerInactive = 0;
    D_80137D90 = 0;
    D_800BE6FC = 0;
    D_800BE58C = 0;
    D_800BE588 = 0;
    gPlayerActorp->actorState_b[0] = 0;
    gScreenPosNextY = temp_t8_2 & 0xFFFF;
    temp_t6_2 = gScreenPosNextY;
    gScreenPosNextX = (uint32_t)temp_t6_2;
    gScreenPosCurrentY = temp_t6_2;
    gScreenPosCurrentX = temp_t6_2;
    gScreenPosTargetY = temp_t6_2;
    gScreenPosTargetX = temp_t6_2;
    D_800BE618 = temp_t6_2;
    D_800BE614 = temp_t6_2;
    D_800BE610 = temp_t6_2;
    D_800BE73C = temp_t6_2;
    D_800BE5F0 = (int16_t)temp_t6_2;
    gPlayerVelYMirror = (int32_t)D_800BE5F0;
    gPlayerVelXMirror = (int32_t)gPlayerVelYMirror;
    gPlayerPosYMirror = gPlayerVelXMirror;
    gPlayerPosXMirror._w = gPlayerPosYMirror._w;
    gPlayerActorp->pos.y = gPlayerPosXMirror._w;
    gPlayerActorp->pos.x = gPlayerPosXMirror._w;
    D_800BE6A4 = (uint16_t)gPlayerPosXMirror._w;
    temp_t8_3 = D_800BE6A4;
    gCamShakeTime = temp_t8_3;
    gCamShakeV = temp_t8_3;
    gStageTimeReal = temp_t8_3;
    gSceneFrames = temp_t8_3;
    gSceneFramesReal = temp_t8_3;
    D_8013747C = temp_t8_3;
    D_800BE674 = temp_t8_3;
    D_800BE66C = temp_t8_3;
    gGamePaused = temp_t8_3;
    func_80042D84(0);
    func_80010A10();
    ClearActorsAndGems();
    func_80023168();
    ActorSpawn_Marina();
    D_800BE5D4 = 1;
    func_8008C4E0(0x41);
    func_80043918();
    if (gGameState == GAMESTATE_LOADING) {
        D_800D2908 = (uint16_t)0;
    }

    InitScene();
    gStageTime = 0;
    D_800D294C = (uint16_t)0;
    func_80010C20(gCurrentScene); // collision?
    GamePlay_Tick();
    func_80047CCC();
    func_80047C98();
    SceneActorSpawn_Init();
    gYellowGemBitfeildTemp = gYellowGemBitfeild;
    gGameState = GAMESTATE_GAMEPLAY;
    gGameSubState = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/GameInit/GamePlay_Load.s")
#endif
