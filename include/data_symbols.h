#ifndef DATA_SYMBOLS_H
#define DATA_SYMBOLS_H

#include "actor.h"
#include "structs.h"
#include "common.h"
#include "inttypes.h"
#include <ultra64.h>

extern float gCosineLookup[1024]; // returns cos((n&0x3FF/256)*90 degrees)
extern float gUnusedFloatTable[512];  // second lookup table, 1.0 to -0.99998. unused?
extern UNK_TYPE D_0040AC80;
extern UNK_TYPE D_05095C98;
extern uint16_t gGamePaused;
extern uint16_t gGameState;
extern uint16_t gGameSubState;
extern float gAtX;
extern float gAtY;
extern float gAtZ;
extern float gUpX;
extern float gUpY;
extern float gUpZ;
extern float gEyeX;
extern float gEyeY;
extern float gEyeZ;
extern UNK_TYPE D_800BA9E0;
extern UNK_TYPE D_800BAAB0;
extern uint16_t g3DHitboxCount1;
extern uint16_t D_800BE4D8;
extern uint16_t gButtonHold;
extern uint16_t gButtonPress;
extern uint16_t gButton_Start;
extern uint16_t gButton_DUp;
extern uint16_t gButton_DDown;
extern uint16_t gButton_DLeft;
extern uint16_t gButton_DRight;
extern uint16_t gButton_B;
extern uint16_t gButton_A;
extern uint16_t gButton_CLeft;
extern uint16_t gButton_CDown;
extern uint16_t gButton_CUp;
extern uint16_t gButton_CRight;
extern uint16_t gButton_ZTrig;
extern uint16_t gButton_LTrig;
extern uint16_t gButton_RTrig;
extern int8_t gJoyX;
extern int8_t gJoyY;
extern fixed32 gPlayerPosXMirror;
extern fixed32 gPlayerPosYMirror;
extern int32_t gPlayerVelXMirror;
extern int32_t gPlayerVelYMirror;
extern uint16_t gCurrentFramebufferIndex;
extern uint8_t gSpriteColR;
extern uint8_t gSpriteColG;
extern uint8_t gSpriteColB;
extern uint8_t gSpriteColA;
extern int32_t D_800C4EBC;
extern uint32_t D_800C4EC0;
extern int32_t D_800C4EC4;
extern uint32_t D_800C4EC8;
extern double gSpriteScaleX;
extern double gSpriteScaleY;
extern uint16_t gNameEntrySpace[11];
extern uint8_t gSaveSlotIndex;
extern ActorInit gActorInit[125];
extern int32_t gActorInitFlags[125];
extern uint16_t gAttractModeIndex;
extern uint16_t Alpha_NotYet[];              //"Not Yet"
extern uint16_t Alpha_GotIt[];               //"Got it"
extern ActorFunc gActorFuncTable_Marina[64]; // TODO: Investigate
extern ActorFunc gActorFuncTable_Clancer[74]; // TODO: Investigate
extern int16_t D_800E24EC[10];
extern int16_t D_800E2500[10];
extern int16_t D_800E2514[10];
extern int16_t D_800E2528[20];
extern int16_t D_800E2550[10];
extern int16_t D_800E2564[10];
extern int16_t D_800E2578[6];
extern int16_t D_800E2584[10];
extern int16_t D_800E2598[12];
extern int16_t D_800E25B0[40];
extern int16_t D_800E2600[66];
extern int16_t D_800E5E48[66];
extern ActorFunc gActorFuncTable_800E5AC0[];
extern uint16_t* D_800E574C[];
extern UNK_TYPE D_800E8BEC;
extern UNK_TYPE D_800E89D4;
extern uint16_t LifeBar_Colors[]; //16-bit colors. may be structure.
extern uint16_t gInputHistoryPress[64]; // buffer of controller inputs
extern Gfx* gDListHead;
extern OSContStatus gOSContStatArray[4];
extern OSContPad gConpadArrayA[4];
extern OSContPad gConpadArrayB[4];
extern Gfx_Data gDListTail[2];
extern uint32_t gPlayerControllerIndex;
extern uint16_t gButtonCur;
extern UNK_TYPE gTickDelta;
extern ALCSPlayer* gBGM_pALCPlayer;
extern uint64_t gYellowGemBitfeild;
extern uint8_t gWorldProgress;
extern uint16_t gContinueChoice;
extern uint16_t gRedGems;
extern uint16_t gCurrentStage;
extern uint16_t gStageTime; // pauses for cutscene, loading
extern uint16_t gStageTimeReal;
extern ActorFunc_u gActorFuncTable_Overlay1[64]; // proceeded by 0xBF00 bytes for DMA'd code/data
extern ActorFunc_u gActorFuncTable_Overlay2[64]; // proceeded by 0xB700 bytes for DMA'd code/data
extern ActorFunc_u gActorFuncTable_Overlay3[64]; // proceeded by 0x9F00 bytes for DMA'd code/data
extern ActorFunc gActorFuncTable_Overlay4[64]; // proceeded by 0x8F00 bytes for DMA'd code/data
extern uint8_t gSpriteData_YellowGem[];
extern uint8_t gSpriteData_RedGem[];
extern uint8_t gSpriteData_BlueGem[];
extern uint32_t gPlayTime;
extern UNK_TYPE D_800BA9E0;
extern UNK_TYPE D_800BAAB0;
extern uint16_t g3DHitboxCount1;
extern uint16_t g3DHitboxCount2;
extern uint16_t gSceneFrames; //pair of frame counters. get AND'd a lot for animations
extern uint16_t gSceneFramesReal; //like gStageTime and gStageTimeReal, the latter doesn't pause
extern uint16_t D_800BE4EC;
extern uint16_t gButtonMask;
extern uint16_t gCameraScrollFlags;
extern fixed32 gScreenPosTargetX; // these few seem to be screen position related
extern fixed32 gScreenPosTargetY;
extern fixed32 gScreenPosCurrentX;
extern fixed32 gScreenPosCurrentY;
extern fixed32 gScreenPosNextX;
extern fixed32 gScreenPosNextY;
extern fixed32 D_800BE568; //scene X bounday?
extern fixed32 D_800BE56C;
extern fixed32 D_800BE570; //scene Y boundary?
extern fixed32 D_800BE574;
extern int16_t D_800BE578;
extern int16_t D_800BE57C;
extern int16_t D_800BE580;
extern int16_t D_800BE584;
extern uint16_t D_800BE588;
extern uint16_t D_800BE58C; //flag for BG layer rendering? set for "merco" and "trapped"
extern int16_t gCamShakeTime;
extern int16_t gCamShakeV;
extern uint16_t gCamShakeType;
extern int32_t gCamShakeMag;
extern int32_t gCamShakeMagDelta;
extern uint16_t gRNGSeed;
extern uint16_t gCurrentScene; //determines DMA's, bgm and camera behavior.
extern uint16_t D_800BE5D4;
extern int16_t D_800BE5E0;
extern int16_t D_800BE5E4;
extern int16_t D_800BE5F0;
extern word_u D_800BE5F4; 
extern uint16_t D_800BE5F8;
extern uint16_t D_800BE5FC;
extern uint32_t D_800BE610; //these 4 are zero'd, but unused
extern uint32_t D_800BE614;
extern uint32_t D_800BE618;
extern uint32_t D_800BE620;
extern uint16_t gScreenXLock;
extern uint16_t gScreenYLock;
extern uint16_t  D_800BE638;
extern uint16_t  gHPDisplayed;
extern uint16_t D_800BE668;
extern uint16_t D_800BE66C;
extern uint16_t D_800BE670;
extern uint16_t D_800BE674; //only set during "snowstorm Maze" and "Lunar". determines rendering order.
extern uint16_t D_800BE678;
extern uint16_t D_800BE6A4;
extern uint16_t D_800BE6A8;
/* a set of flags with the following properties for each bit (hi-to-lo):
 * 0 unknown (DebugFunc_8000h is just jr ra)
 * 1 Draw SFX Channel data
 * 2
 * 3 unknown (DebugFunc_1000h is just jr ra)
 * 4 unknown
 * 5 unknown
 * 6 Force pause (see PauseGame_Check)
 * 7 pause does not open menu.
 * 8 Draw some debug info
 * 9 unknown (DebugFunc_40h is just jr ra)
 * A unknown
 * B unknown
 * C unknown
 * D Ortho / perspective view
 * E L and R change gameplay speed (60 / gDebugThrottle fps)
 * F unknown (DebugFunc_1h is just jr ra)
 */
extern uint16_t gDebugBitfeild;
extern float D_800BE6B0;    // 90.0f, never used.
extern uint16_t gDebugThrottle; 
extern b2_s gDebugBorW;
extern int32_t D_800BE6C0;
extern uint8_t D_800BE6E4;
extern uint8_t D_800BE6E8;
extern uint8_t D_800BE6EC;
extern uint8_t gPortraitTint;
extern uint16_t D_800BE6F8;
extern uint16_t D_800BE6FC;
extern uint16_t gCameraScrollThrottleX;
extern uint16_t gCameraScrollThrottleY;
extern uint8_t D_800BE70C;
extern uint8_t D_800BE710;
extern uint16_t D_800BE714;
extern int32_t D_800BE71C;
extern int32_t D_800BE720;
extern int32_t D_800BE724;
extern int32_t D_800BE728;
extern int32_t gCameraRot;
extern int32_t gCameraRotDelta;
extern int32_t D_800BE73C;

extern UNK_TYPE D_800C3908;
extern Sprite gSprite;
extern double gSpriteScaleX;
extern double gSpriteScaleY;
extern uint16_t gNameEntrySpace[11];
extern uint8_t gSaveSlotIndex;
extern uint32_t D_800C4FC0[];
extern fixed32 D_800C500C;
extern uint8_t D_800C5010[];
extern uint16_t gNameEntryRow0HIRA[18];
extern uint16_t gNameEntryRow1HIRA[18];
extern uint16_t gNameEntryRow2HIRA[18];
extern uint16_t gNameEntryRow3HIRA[18];
extern uint16_t gNameEntryRow4HIRA[18];
extern uint16_t gNameEntryRow0KATA[18];
extern uint16_t gNameEntryRow1KATA[18];
extern uint16_t gNameEntryRow2KATA[18];
extern uint16_t gNameEntryRow3KATA[18];
extern uint16_t gNameEntryRow4KATA[18];
extern uint16_t D_800C52A4[];
extern uint16_t D_800C52B0[];
extern uint16_t D_800C52BC[];
extern uint16_t gNameEntryRow0ENG[18]; // arrays with the english name entry characters
extern uint16_t gNameEntryRow1ENG[18]; // there are 2 more like this for other languages
extern uint16_t gNameEntryRow2ENG[18]; // Japan version had 3 character sets to select with L/R
extern uint16_t gNameEntryRow3ENG[18]; // one is still readable, but the other seems lost.
extern uint16_t gNameEntryRow4ENG[18];
extern UNK_TYPE D_800C71A0;
extern uint16_t D_800C7E14[16]; //"G......AME......OV...E...R"
extern const char*D_800C81E4[22]; //used by stage select in building menu.
extern uint16_t D_800C823C[];
extern uint16_t gStageScenes[64]; //holds the scene indecies for each stage.
extern uint16_t D_800C83F8[64];
extern uint16_t gTimesToBeat[64];
extern uint16_t* D_800C8BE4[5]; //level Names
extern uint16_t* D_800C8C10[10]; //lv1 names
extern uint16_t* D_800C8C38[11]; //lv2 names
extern uint16_t* D_800C8C64[12]; //lv3 names
extern uint16_t* D_800C8C94[11]; //lv4 names
extern uint16_t* D_800C8CC0[10]; //lv5 names
extern uint16_t** D_800C8CE8[5]; //all stage names
extern char** D_800C8E58[5]; //debug stage select labels (ascii)
extern UNK_TYPE D_800C8EF0;
extern char D_800C8F68[]; // PRESS START
extern char D_800C8F74[]; // @1997 TREASURE/ENIX
extern char D_800C8F88[]; // LICENCED TO NINTENDO
extern uint32_t D_800C8FA0;
extern uint32_t D_800C8FC0;
extern Gfx D_800C9080[];
extern uint16_t gSoundTest_SFXEntries[294];
extern char D_800C94CC[4]; //"BGM"
extern char D_800C94D0[5]; //"S.E."
extern int16_t soundtest_IconPos[2][2]; //only [x][1] is used
extern char* D_800C9680[5]; //'rank' letters
extern int16_t D_800C9694[5];
extern ActorInit gActorInit[];
extern int32_t gActorInitFlags[125];
extern uint16_t* gActorInitGraphics[];
extern uint16_t gIsPlayerInactive;
extern uint16_t gAttractModeTimer;
extern uint16_t gAttractModeInputHoldIndex;
extern uint16_t gAttractModeInputHold;
extern uint16_t gAttractModeInputHoldTimer;
extern uint16_t gAttractModeInputIndex;
extern uint16_t D_800CA24C;
extern uint16_t gAttractModeInputTimer;
extern UNK_TYPE D_800CA2B0;
extern uint16_t* D_800C96A0[5]; // "perfect","excellent","very good","   good   ","try harder"
extern uint16_t* gAttractModeHoldInputs[4]; //attract mode button inputs {time, input}
extern uint16_t* gAttractModePressInputs[4]; //the first for held buttons, second for tapped.
extern int16_t D_800CBF40;
extern uint16_t D_800CBF44;
extern int16_t D_800CBF50;
extern uint16_t D_800CBF54;
extern uint16_t gLetterboxMode; //0: Normal (4:3 overscan cutoff) 1: Beastector (horizontal scaling) 2: Phoneix Gamma (vertical scaling)
extern int16_t D_800CC228[256];
extern int8_t D_800CC428;
extern void (*Scene_CameraInits[88])(void); //each scene's CameraInit function
extern void (*Scene_CameraFuncs[88])(void); //each scene's CameraTick function
extern int16_t D_800CC6EC[88][8]; //{D_800BE568,D_800BE56C,D_800BE574,D_800BE570,gScreenX,gPlayeractor.pos.x,gScreenY,gPlayeractor.pos.y}
extern int16_t D_800CCC6C[88][5];
extern uint8_t gSceneBGMs[88]; // Scene BGM indices
extern uint8_t D_800CD034[88];
extern uint32_t D_800CD08C[88][4]; // Romcopy tables for actor func tables
extern uint32_t D_800CD60C[88][4]; // {Romaddr of tables, Romaddr of tables+sizeof(), Romaddr of code, Romaddr of code+sizeof()}
extern uint32_t D_800CDD8C[88][4];
extern uint32_t D_800CE10C[88][4];
extern uint32_t D_800CE68C[88][4];
extern uint32_t D_800CEC0C; //offset subtracted from some romcopy's (0x04000000)
extern uint32_t D_800CEC10[88][2]; //another romcopy lookup uses D_800CEC0C's offset.
extern uint32_t D_800CEED0; //offset subtracted from some romcopy's (0x03000000)
extern uint32_t D_800CEED4[132][2]; //another romcopy lookup uses D_800CEED0's offset.
extern uint32_t D_800CF5B8; //offset subtracted from some romcopy's (0x03000000)
extern uint32_t D_800CF5BC[88][2]; //another romcopy lookup uses D_800CF5B8's offset.
extern uint32_t D_800CF87C; //offset subtracted from some romcopy's (0x03000000)
extern uint32_t D_800CF880[88][2]; //another romcopy lookup uses D_800CF87C's offset.
extern uint32_t D_800CFB40; //offset subtracted from some romcopy's (0x02000000)
extern uint32_t D_800CFB44[88][2]; //another romcopy lookup uses D_800CFB40's offset.
extern uint32_t D_800CFE04[88][12];
extern void* D_800D0E84[88][6];
extern int16_t D_800D16C4; //may relate to lifebar position.

extern uint16_t gASCIIAlphaIndecies[92]; //ASCII graphic indecies - starts at 0x20 (space char)
extern uint16_t gTextPalettes[8][4];
#ifndef VER_JPN
extern uint8_t gEngTextKerning[52]; //for the letters in the US version that are kerned.
#endif
extern uint16_t D_800D17FC[4]; //palette used in Text_PrintAlphaAt2()

extern ClanpotItem gClanpotItems[32]; //stacked in reverse order for some reason.
extern int32_t D_800D2504[2][2];
extern int32_t D_800D2514[7][6];
extern uint8_t D_800D28D0[20];
extern uint16_t D_800D28E4;
extern uint16_t D_800D28E8;
extern int32_t D_800D28EC;
extern uint16_t D_800D28F0;
extern int16_t D_800D28F4;
extern int16_t D_800D28F8;
extern uint32_t D_800D28FC;
extern int16_t D_800D2900;
extern int16_t gNoHit; //no-hit flag, start hp if yes, -1 if no.
extern uint16_t D_800D2908;
extern int16_t D_800D2914;
extern uint16_t D_800D2918;
extern uint16_t D_800D291C;
extern uint16_t D_800D2920;
extern uint16_t D_800D2924;
extern int32_t D_800D2928;
extern int32_t D_800D292C;
extern int32_t gExitAnimationProgress;
extern uint16_t D_800D294C;
extern uint16_t gPlayerActorIndex;
extern uint16_t TeranFlag;
extern uint16_t D_800D2968;
extern int16_t D_800D296C;
extern int16_t D_800D2970;
extern int16_t D_800D2974;
extern uint16_t D_800D2978[];
extern uint16_t D_800D36DC[16];
extern uint16_t D_800D36FC[16];
extern uint16_t D_800D3770[];
extern uint16_t D_800D3888[24];
extern int16_t gExitPortraitPositions[140][2];//coords for "scene transition" portaits.
extern int16_t gExitPortraitGraphics[70]; //indecies for "scene transition" portaits.
extern int16_t D_800D3B74;
extern uint16_t* D_800D8088[8]; //japan-only text for actor 0x56
extern uint16_t D_800D80A8[8]; //SFX Arrays for same actor
extern uint16_t D_800D81AC[];
extern uint16_t D_800D81F8[];
extern uint16_t D_800D84E8[];
extern uint16_t gPalletteWhite[16]; //RGBA5551 pallette for white screens.
extern UNK_TYPE gPalletteBlack;
extern uint16_t D_800D37A4;
extern void(*D_800D37BC[51])(void); //static gem funcs
extern UNK_TYPE D_800D4000;
extern int8_t D_800D401C[5][4];
extern int8_t D_800D4030[5][4];
extern int8_t D_800D4044[5][4];
extern int8_t D_800D4058[5][4];
extern int8_t D_800D406C[5][4];
extern int8_t D_800D4080[5][4];
extern int8_t (*D_800D4094[6])[4];
extern uint32_t D_800D4184[82]; // pointer array?
extern uint16_t D_800D46A8[18];
extern int32_t gMarinaVelocities[32]; //table for Marina's movement speeds.
extern int32_t D_800D57E0;
extern uint16_t gSpeaker_ActorLink;
extern uint16_t D_800D5824;
extern uint16_t D_800D85C8[16];
extern uint16_t D_800D85E8[16];
extern uint16_t D_800D8608[16];
extern uint16_t D_800D8628[16];
extern uint16_t D_800D8648[16];
extern uint16_t D_800D8668[16];
extern UNK_TYPE D_800D8750;
extern UNK_TYPE D_800D87C8;
extern UNK_TYPE D_800D8840;
extern UNK_TYPE D_800D8930;
extern UNK_TYPE D_800D89A8;
extern UNK_TYPE D_800D8A20;
extern UNK_TYPE gPaletteGemGreen;
extern UNK_TYPE D_800D8B10;
extern UNK_TYPE D_800D8B88;
extern UNK_TYPE D_800D8C00;
extern UNK_TYPE D_800D8CF0;
extern UNK_TYPE D_800D8D68;
extern UNK_TYPE D_800D8DE0;
extern UNK_TYPE D_800D9B54;
extern uint16_t D_800D9B64[];
extern UNK_TYPE D_800D9B7C;
extern UNK_TYPE D_800D9AE4;
extern UNK_TYPE D_800D9284;
extern UNK_TYPE D_800D9474;
extern int16_t D_800D9BC4;
extern UNK_TYPE D_800D9C7C;
extern int16_t D_800D9CC4;
extern UNK_TYPE D_800D9D7C;
extern int16_t D_800D9DC4;
extern UNK_TYPE D_800D9E7C;
extern int16_t D_800D9EC4;
extern UNK_TYPE D_800D9F7C;
extern int16_t D_800D9FC4;
extern UNK_TYPE D_800DB07C;
extern int16_t D_800DB0BA;
extern UNK_TYPE D_800DB27C;
extern int16_t D_800DB2BA;
extern UNK_TYPE D_800DB47C;
extern int16_t D_800DB4BA;
extern UNK_TYPE D_800DB67C;
extern int16_t D_800DB6BA;
extern UNK_TYPE D_800DB87C;
extern int16_t D_800DB8BA;
extern UNK_TYPE D_800DBA7C;
extern int16_t D_800DBABA;
extern UNK_TYPE D_800DBC7C;
extern int16_t D_800DBCBA;
extern int16_t D_800DBEBA;
extern UNK_TYPE D_800DC07C;
extern int16_t D_800DC0DE;
extern UNK_TYPE D_800DC27C;
extern int16_t D_800DC2DE;
extern UNK_TYPE D_800DC47C;
extern int16_t D_800DC4DE;
extern UNK_TYPE D_800DC67C;
extern int16_t D_800DC6DE;
extern UNK_TYPE D_800DC87C;
extern int16_t D_800DC8DE;
extern UNK_TYPE D_800DCA7C;
extern int16_t D_800DCADE;
extern UNK_TYPE D_800DCC7C;
extern int16_t D_800DCCDE;
extern int16_t D_800DD47C[];
extern int16_t D_800DD4DC;
extern int16_t D_800DD67C[];
extern int16_t D_800DD6DC;
extern int16_t D_800DD87C[];
extern int16_t D_800DD8DC;
extern int16_t D_800DDA88[];
extern int16_t D_800DDAD6;
extern int16_t D_800DDC48[];
extern int16_t D_800DDC96;
extern UNK_TYPE D_800DDE08;
extern int16_t D_800DDE56;
extern UNK_TYPE D_800DDFC8;
extern int16_t D_800DE016;
extern UNK_TYPE D_800DE188;
extern UNK_TYPE D_800DE1C0;
extern int16_t D_800DE1D6;
extern UNK_TYPE D_800DE1F8;
extern UNK_TYPE D_800DE230;
extern UNK_TYPE D_800DE268;
extern UNK_TYPE D_800DE2A0;
extern UNK_TYPE D_800DE2D8;
extern UNK_TYPE D_800DE310;
extern int16_t D_800DE348[];
extern int16_t D_800DE396;
extern UNK_TYPE D_800DE508;
extern UNK_TYPE D_800DE540;
extern UNK_TYPE D_800DE578;
extern UNK_TYPE D_800DE5B0;
extern UNK_TYPE D_800DE5E8;
extern UNK_TYPE D_800DE620;
extern UNK_TYPE D_800DE658;
extern UNK_TYPE D_800DE690;
extern UNK_TYPE D_800DE6C8;
extern int16_t D_800DE716;
extern UNK_TYPE D_800DE888;
extern int16_t D_800DE8D6;
extern UNK_TYPE D_800DEA48;
extern int16_t D_800DEA96;
extern UNK_TYPE D_800DEC08;
extern int16_t D_800DEC56;
extern UNK_TYPE D_800DEDC8;
extern int16_t D_800DEE16;
extern UNK_TYPE D_800DEF88;
extern int16_t D_800DEFD6;
extern UNK_TYPE D_800DF148;
extern int16_t D_800DF196;
extern UNK_TYPE D_800DF308;
extern int16_t D_800DF356;
extern UNK_TYPE D_800DF4C8;
extern int16_t D_800DF516;
extern UNK_TYPE D_800DF688;
extern int16_t D_800DF6D6;
extern UNK_TYPE D_800DF848;
extern int16_t D_800DF8DE;
extern UNK_TYPE D_800DFA48;
extern int16_t D_800DFADE;
extern UNK_TYPE D_800DFC48;
extern int16_t D_800DFCDE;
extern UNK_TYPE D_800DFE48;
extern int16_t D_800DFEA2;
extern UNK_TYPE D_800E0048;
extern int16_t D_800E00A2;
extern int16_t D_800E0248[];
extern int16_t D_800E02A2;
extern UNK_TYPE D_800E0448;
extern int16_t D_800E04A2;
extern UNK_TYPE gGraphicListDefault;
extern UNK_TYPE D_800E154C;
extern uint16_t gGraphicListGem2[18];
extern uint16_t D_800E1700[];
extern uint16_t D_800E1750[];
extern uint16_t D_800E1788[];
extern uint16_t D_800E223C[];
extern uint16_t D_800E2250[];
extern uint16_t D_800E2274[];
extern UNK_TYPE D_800E1DEC;
extern UNK_TYPE gGraphicListGem;
extern UNK_TYPE D_800E1C00;
extern UNK_TYPE D_800E1C2C;
extern UNK_TYPE D_800E1F64;
extern int32_t VipToPlayerX; //gives the relative position from a VIP actor (usually boss) to the player
extern int32_t VipToPlayerY;
extern uint16_t gVIPActor;
extern uint16_t* D_800E31EC[54];
extern UNK_TYPE D_800E334C;
extern UNK_TYPE gViptoActorFlags;
extern Gfx D_800E38B0[];
extern Gfx D_800E3930[9];
extern Gfx D_800E3978[4];
extern Gfx D_800E3998[5];
extern Gfx D_800E39C0[14];
extern Gfx D_800E3A30[4];
extern Gfx D_800E3A50[7];
extern Gfx D_800E3A88[5];
extern Gfx D_800E3AC8[10];
extern Gfx D_800E3B60[13];
extern float D_800E90E8[64];
extern uint16_t D_800E9414[]
extern UNK_TYPE D_800E9850;
extern uint16_t D_800E9654[];
extern UNK_TYPE D_800EA110;
extern UNK_TYPE D_800EA500;
extern uint64_t D_800EF210[11]; //Sound_OSTaskp->ucode_data
extern int16_t gBgmVolumeTemp;
extern Gfx* D_800EF4F4; // I don't think this is actually a Gfx*
extern int16_t D_800EF500[];
extern uint16_t gSFXCurrentIndex[4]; // holds current SFX indicies per channel
extern int32_t D_800F4540;
extern int32_t D_800F46D8;
extern uint8_t D_80104090[];
extern uint16_t D_80106918;
extern uint16_t D_801069B8;
extern ALPan D_801069D8[];
extern int16_t D_80108DE0[];
extern uint32_t D_80103480;
extern uint32_t D_80103616;
extern uint32_t D_801037AA;
extern uint32_t D_80103944;
extern uint16_t D_8010CDE8[];
extern uint8_t D_8011CDF0[];
extern uint8_t D_8011CF18[];
extern Portrait gPortraits[66]; // last 2 are data for marina's healthbar and head thereof
extern StaticGem gStaticGems[64]; // seems to be the sprite objects (not the collision,) of level objects
extern u64 D_8011D970[128]; //gGFXTaskp->dram_stack
extern u64 D_8011DDF0[436]; //gGFXTaskp->yeild_data_ptr
extern uint16_t g3DHitbox1BX0[144];
extern uint16_t D_8011D4F0[144];
extern uint16_t g3DHitbox1BY0[144];
extern uint16_t D_8011D730[144];
extern uint16_t g3DHitbox1BY1[144];
extern uint16_t gInputHistoryHold[64];
extern u64 idleThreadStack[2048];
extern u64 mainThreadStack[1024];
extern u64 rmonThreadStack[512];
extern u64 unkThreadStack[512]; //unused thread? fits gap in ram.
extern OSMesg gPiManmsgs[8];
extern OSThread idleThread;
extern OSThread mainThread;
extern OSThread rmonThread;
extern OSMesgQueue gDMAMsgQ;
extern OSMesgQueue D_8012ABC0;
extern OSMesgQueue D_8012ABD8;
extern OSMesgQueue D_8012ABF0;
extern OSMesgQueue D_8012AC08;
extern OSMesgQueue gPiManmsgQ[2];
extern OSMesg D_8012AC68;
extern OSMesg D_8012AC6C;
extern OSMesg D_8012AC70;
extern OSMesg D_8012AC74;
extern OSMesg D_8012AC80;
extern OSTask* gGFXTaskp;
extern OSTask gGFXTasks[2];
extern OSViMode* gOSViModep;
extern OSViMode gOSViMode;
extern OSContStatus gOSContStatArray[4];
extern OSContPad gConpadArrayA[4];
extern OSContPad gConpadArrayB[4];
extern OSMesgQueue gContMesgq;
extern uint32_t gPlayerControllerIndex;
extern uint16_t gButtonCur;
extern uint32_t gPlayTime;
extern uint16_t gMarinaButtonHold;
extern uint16_t gMarinaButtonPress;
extern uint16_t D_801373D8;
extern playerManager gPlayerManager;
extern UNK_TYPE D_80137458;
extern UNK_POINTER D_8013746C;
extern uint16_t D_8013747C;
extern uint32_t D_80137420;

extern uint16_t D_80137480; 
extern void* D_801376A0;
extern void* D_801376A4;
extern uint8_t gEnvColorsRed[4]; //G_SETEVENTCOLOR RED
extern uint8_t gEnvColorsGreen[4]; //G_SETEVENTCOLOR GREEN
extern uint8_t gEnvColorsBlue[4]; //G_SETEVENTCOLOR BLUE
extern uint8_t gEnvColorsAlpha[4]; //G_SETEVENTCOLOR ALPHA
extern uint8_t gEnvColorsBlend[4];
extern uint8_t gEnvColorsOpaque[4];
extern UNK_POINTER D_801376DC;
extern int32_t D_801376E0;
extern void* D_801376E4;
extern void* D_801376E8;

extern Bitmap gSpriteBitmaps[2][56];
extern uint64_t D_8016EF20[2][696]; //sprite.rsp_dl
extern uint32_t D_80171ADC[2][2];
extern UNK_TYPE D_80171D30;
extern uint8_t D_80171B19;
extern uint16_t D_80171B1A;
extern uint16_t D_80171B1C;
extern uint16_t D_80171B1E;
extern uint16_t D_80171B20;
extern uint16_t D_80171B22;
extern uint16_t D_80171B30[128];
extern uint16_t D_80171C30[128];
extern uint16_t D_80171F10[240];
extern Mtx* D_801780F0;
extern Mtx* D_801780F4;
extern UNK_POINTER* D_80178104;
extern UNK_POINTER* D_80178108;
extern UNK_POINTER* D_8017810C;
extern UNK_POINTER* D_80178110;
extern UNK_POINTER* D_80178114;
extern UNK_POINTER* D_80178118;
extern UNK_POINTER* D_8017811C;
extern UNK_POINTER* D_80178120;
extern UNK_POINTER* D_80178124;
extern UNK_POINTER* D_80178128;
extern uint16_t D_80178130; // continue timer?
extern uint8_t D_80178132;
extern uint8_t D_80178133;
extern uint8_t D_80178134;
extern uint16_t gContinueChoice;
extern uint16_t gRedGems;
extern uint16_t gCurrentStage;
extern uint16_t D_80178150;
extern uint16_t D_80178152;
extern uint16_t D_80178154;
extern uint16_t gWorldMapSelectedStage;
extern uint16_t D_80178158;
extern uint16_t D_8017815A;
extern uint16_t gSelectedWorld;
extern uint16_t D_80178164;
extern uint16_t D_80178160;
extern uint16_t D_80178162;
extern uint16_t D_80178164;
extern uint16_t D_80178166;
extern UNK_TYPE D_80178170;
extern UNK_TYPE D_80178188;
extern uint8_t D_801781A0[8]; //set to 0x3f, only first 2 entries used.
extern int16_t D_801781C0[];
extern uint16_t D_801781C8;
extern uint16_t D_801781CA;
extern uint16_t D_801781CC;
extern uint16_t D_801781CE;
extern uint16_t D_801781D0;
extern uint16_t D_801781D2;
extern uint16_t D_801781D4;
extern uint16_t gThrottleInput[2]; //button buffer for throttle mode
extern uint16_t gStageTime; // pauses for cutscene, loading capped at 36000
extern uint64_t gYellowGemBitfeildTemp;
extern uint16_t D_801781F8;
extern uint16_t gStageTimeReal;
extern uint16_t gFestivalEventState; //looks like this starts the festival variables.
extern uint16_t gFestivalCurrentEvent; //current festival event
extern uint16_t gFestivalFouls; //False starts
extern uint8_t gFestivalEventsComplete;
extern uint16_t gFestivalPointsRed;
extern uint16_t gFestivalPointsWhite;
extern uint8_t gFestivalEventsBools[10];
extern int32_t D_801782B0;
extern int32_t D_801782B4;
extern uint16_t gStaticGemIndex;
extern int16_t D_801783F4;
extern int16_t D_801783F6;
extern int16_t D_801783F8[16];
extern uint16_t D_80178460;
extern uint32_t D_801826A0[];
extern uint16_t gFramebuffer0[320][240]; // framebuffer
extern UNK_TYPE D_802C9F70;
extern volatile uint8_t D_80296000[0x34400];
extern volatile uint16_t D_80380200[256]; // probably a volatile struct (see usage in Intro_Tick)
extern volatile uint16_t D_80380400[256];
extern uint16_t gFramebuffer1[320][240]; // framebuffer
extern UNK_TYPE D_801C4400; //adress of some buffer
#endif
