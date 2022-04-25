#include "common.h"
#include "GameSave.h"

ActorFunc gActorFuncTable[]={
  /*0x00*/  ActorTick_0, //NOOP - used by graphic-only actors.
  /*0x01*/  ActorTick_1, //Moves its hitboxA for a time set by unk_0x110
  /*0x02*/  ActorTick_2, //passes to NOOP
  /*0x03*/  ActorTick_3, //NOOP
  /*0x04*/  ActorTick_4, //NOOP
  /*0x05*/  func_80033DE4,
  /*0x06*/  func_800336B8,
  /*0x07*/  ActorTick_7, //turns transparent by a rate set by unk_0x18C
  /*0x08*/  ActorTick_Gem,
  /*0x09*/  func_8003141C,
  /*0x0A*/  func_80042338, //NOOP
  /*0x0B*/  func_80042B94, 
  /*0x0C*/  func_80042C10, 
  /*0x0D*/  func_80061624, //camera Actor?
  /*0x0E*/  func_800309C0,
  /*0x0F*/  ActorTick_15, //NOOP
  /*0x10*/  ActorTick_16, //NOOP
  /*0x11*/  0x80388028,  //addresses to funcs in noop.c
  /*0x12*/  0x80388010,  //I think you can guess what they do.
  /*0x13*/  0x80388018,  //maybe they were debug funcs,
  /*0x14*/  0x80388020,  //but not anymore.
  /*0x15*/  ActorTick_3DIcon, //used by the cursors in sound test
  /*0x16*/  ActorTick_Marina, //skipped for player actor here.
  /*0x17*/  func_80042340, //NOOP
  /*0x18*/  func_80037B90,
  /*0x19*/  func_80042348, //NOOP
  /*0x1A*/  func_80042350, //NOOP
  /*0x1B*/  ActorTick_27, //NOOP
  /*0x1C*/  func_8003A120,
  /*0x1D*/  ActorTick_29, //NOOP
  /*0x1E*/  func_8002C6DC, //NOOP
  /*0x1F*/  func_8005E260,
  /*0x20*/  func_80047CCC, //manages the lifebar, checks/update gNoHit
  /*0x21*/  func_80080190, //thisActor.flag3&=~0x200600 (y,tho?)
  /*0x22*/  func_8002DC74,
  /*0x23*/  func_8002D670,
  /*0x24*/  func_8002E288,
  /*0x25*/  func_8008C4C0,
  /*0x26*/  func_8007F37C,
  /*0x27*/  func_8007F078, //dialouge portrait?
  /*0x28*/  func_8007DF44,
  /*0x29*/  func_8007DB84,
  /*0x2A*/  ActorTick_42, //NOOP
  /*0x2B*/  func_8008C4C8, //NOOP
  /*0x2C*/  func_80033B54,
  /*0x2D*/  func_800348E4,
  /*0x2E*/  func_8005C3C8,
  /*0x2F*/  func_80060DB8,
  /*0x30*/  func_80061E98,
  /*0x31*/  func_80062174,
  /*0x32*/  func_800418A8,
  /*0x33*/  func_8006098C,
  /*0x34*/  func_80031DDC,
  /*0x35*/  ActorTick_JPNSpeechBox,
  /*0x36*/  func_800320F8,
  /*0x37*/  func_80032900,
  /*0x38*/  func_8003F360,
  /*0x39*/  func_8005E8F8,
  /*0x3A*/  func_8005EE24,
  /*0x3B*/  func_80040564,
  /*0x3C*/  func_800601FC,
  /*0x3D*/  func_80030964, //"child" of Gem actor, adds flag2|=0x100
  /*0x3E*/  func_8003AC30,
  /*0x3F*/  func_8003B8CC, //clanball?
  /*0x40*/  func_8003BE3C,
  /*0x41*/  func_8008C4D0, //NOOP
  /*0x42*/  func_8003C328,
  /*0x43*/  func_80084974,
  /*0x44*/  func_800853C8,
  /*0x45*/  ActorTick_Clanbomb,
  /*0x46*/  func_80087820,
  /*0x47*/  func_80042358, //NOOP
  /*0x48*/  func_80075DC4,
  /*0x49*/  func_80039134,
  /*0x4A*/  func_8003929C,
  /*0x4B*/  func_80039468,
  /*0x4C*/  func_80087D2C,
  /*0x4D*/  func_80088164,
  /*0x4E*/  func_8008855C,
  /*0x4F*/  func_80088CB0,
  /*0x50*/  func_80089084,
  /*0x51*/  func_800645F4,
  /*0x52*/  func_8006475C,
  /*0x53*/  func_8008C4D8, //NOOP
  /*0x54*/  func_80073970,
  /*0x55*/  func_80073CE8,
  /*0x56*/  func_80073A60,
  /*0x57*/  func_8008A6E4,
  /*0x58*/  func_8008AD3C,
  /*0x59*/  func_80089418,
  /*0x5A*/  func_8008C304,
  /*0x5B*/  func_800737C4,
  /*0x5C*/  func_8008BC5C,
  /*0x5D*/  func_8005E56C,
  /*0x5E*/  func_8002D488,
  /*0x5F*/  func_80077C18, //clanblob?
  /*0x60*/  func_800740C8,
  /*0x61*/  func_8006346C, //clanball on rails?
  /*0x62*/  func_8002E89C,
  /*0x63*/  func_80064528,
  /*0x64*/  func_800648C4,
  /*0x65*/  func_8006CF20,
  /*0x66*/  func_8002FEF8,
  /*0x67*/  func_8006D0EC,
  /*0x68*/  func_8003667C,
  /*0x69*/  func_8007B60C,
  /*0x6A*/  func_80076BF4,
  /*0x6B*/  func_8003DBD0, //"go to the next area"
  /*0x6C*/  func_80094FE4,
  /*0x6D*/  ActorTick_CalinaChange,
  /*0x6E*/  ActorTick_CalinaDialouge,
  /*0x6F*/  func_8009351C,
  /*0x70*/  ActorTick_MarinaOhNo,
  /*0x71*/  ActorTick_Crosshair,
  /*0x72*/  func_8008E1A0,
  /*0x73*/  func_8003E230,
  /*0x74*/  func_80064B60, //Stage clear
  /*0x75*/  ActorTick_LevelClear,
  /*0x76*/  func_80064CB4,
  /*0x77*/  func_80065178,
  /*0x78*/  func_8003766C,
  /*0x79*/  func_80035E90, //Clanpot?
  /*0x7A*/  func_80065270, //Ms. Hint?
  /*0x7B*/  ActorTick_RedGemRing,
  /*0x7C*/  func_80030008,
  /*0x7D*/  NULL,
  /*0x7E*/  NULL,
  /*0x7F*/  NULL
};

uint16_t D_800C81E0=0;
/*
const char* D_800C81E4[]={
    "opn","1-d","1-0","1-2","2-d","2-0","2-1","2-2","3-d","3-0",
    "3-1","3-2","4-d","4-0","4-1","4-2","5-d","5-0","end","e-0","---"
};
*/
uint16_t D_800C823C[]={1,1,10,10,1,1,9,2,1,1,9,2,1,1,5,5,1,1,3,2,1,1,2,2,3,0};
uint16_t D_800C8268[]={2,12,24,37,49,58,0,0};
/*
const char* D_800C8278[]={
    "0","0","0","1","2","3","4","5","6","7","8","9",
    "0","1","2","3","4","5","6","7","8","9",
    "0","0","0","1","2","3","4","5","6","7","8",
    "0","1",
    "0","0","0","1","2","3","4",
    "0","1","2","3","4",
    "0","0","0","1","2",
    "0","1",
    "0","0","0","1",
    "0","1",
    "0","1","2","0"};
*/
uint16_t gStageScenes[64]={
  SCENE_INTRO,
  SCENE_DEMOWORLD1,
  SCENE_MEETMARINA,
  SCENE_MEETCALINA,
  SCENE_CLANBALLLAND,
  SCENE_SPIKELAND,
  SCENE_3CLANCERKIDS,
  SCENE_BLOCKMANRISES,
  SCENE_WORMINUP,
  SCENE_CRISISNEPTON,
  SCENE_WESTERNWORLD,
  SCENE_VOLCANO,
  SCENE_SEAOFLAVA,
  SCENE_VERTIGO,
  SCENE_SINKORFLOAT,
  SCENE_HOTRUSH,
  SCENE_SEARINSWING,
  SCENE_FLAMBEE,
  SCENE_TIGHTROPERIDE,
  SCENE_FREEFALL,
  SCENE_MAGMARAFTS,
  SCENE_SEASICKCLIMB,
  SCENE_MIGENBRAWL,
  SCENE_DEMOWORLD3,
  SCENE_CLANPOTSHAKE,
  SCENE_CLANCEWAR,
  SCENE_MISSLESURF,
  SCENE_CLANBALLLIFT,
  SCENE_GOMARZEN64,
  SCENE_CHILLYDOG,
  SCENE_SNOWSTORMMAZE,
  SCENE_LUNAR,
  SCENE_DAYBEFORE,
  SCENE_DAYOF2,
  SCENE_CATASTROPHE,
  SCENE_CERBERUSALPHA,
  SCENE_DEMOWORLD4,
  SCENE_ROLLINGROCK,
  SCENE_TOADLYRAW,
  SCENE_7CLANCERKIDS,
  SCENE_RESCUEACT1,
  SCENE_RESCUEACT2,
  SCENE_TAURUS,
  SCENE_GHOSTCATCHER,
  SCENE_ASTERSTRYKE,
  SCENE_MOLEYCOW,
  SCENE_ASTERSMAZE,
  SCENE_SATSQUATCHBETA,
  SCENE_DEMOWORLD5,
  SCENE_CLANCEWAR2,
  SCENE_COUNTERATTACK,
  SCENE_BEESTHEONE,
  SCENE_MERCO,
  SCENE_TRAPPED,
  SCENE_PHONENIXGAMMA,
  SCENE_DEMOFINAL,
  SCENE_INNERSTRUGGLE,
  SCENE_FINALBATTLE,
  SCENE_ENDING,
  SCENE_ENDING,
  SCENE_UNK03,
  SCENE_UNK02,
  SCENE_UNK04,
  SCENE_MEETMARINA
};

void Actors_Tick_Overlayed(uint16_t index) {
    uint8_t temp_t8 = thisActor.actorType & 0xFFFF;

    switch (thisActor.actorType >> 8) {
        case 1: {
            gActorFuncTable_Overlay4[temp_t8](index);
            break;
        }
        case 2: {
            gActorFuncTable_Overlay2[temp_t8].oneArg(index);
            break;
        }
        case 3: {
            gActorFuncTable_Overlay2[temp_t8].oneArg(index);
            break;
        }
        case 4: {
            gActorFuncTable_Overlay4[temp_t8](index);
            break;
        }
        case 5: {
            gActorFuncTable_Overlay4[temp_t8](index);
            break;
        }
        case 6: {
            gActorFuncTable_Overlay1[temp_t8].oneArg(index);
            break;
        }
        case 7: {
            gActorFuncTable_Overlay4[temp_t8](index);
            break;
        }
        case 8: {
            gActorFuncTable_800E5AC0[temp_t8](index);
            break;
        }
        case 9: {
            gActorFuncTable_Overlay2[temp_t8].oneArg(index);
            break;
        }
        case 10: {
            gActorFuncTable_Overlay2[temp_t8].oneArg(index);
            break;
        }
        case 11: {
            gActorFuncTable_Overlay2[temp_t8].oneArg(index);
            break;
        }
        case 12: {
            gActorFuncTable_Overlay2[temp_t8].oneArg(index);
            break;
        }
        case 13: {
            gActorFuncTable_Overlay2[temp_t8].oneArg(index);
            break;
        }
        case 14: {
            gActorFuncTable_Overlay4[temp_t8](index);
            break;
        }
        case 15: {
            gActorFuncTable_Overlay1[temp_t8].oneArg(index);
            break;
        }
        case 16: {
            gActorFuncTable_Overlay1[temp_t8].oneArg(index);
            break;
        }
        case 17: {
            gActorFuncTable_Overlay2[temp_t8].oneArg(index);
            break;
        }
        case 18: {
            gActorFuncTable_Overlay2[temp_t8].oneArg(index);
            break;
        }
        case 19: {
            gActorFuncTable_Overlay2[temp_t8].oneArg(index);
            break;
        }
        case 20: {
            gActorFuncTable_Overlay1[temp_t8].oneArg(index);
            break;
        }
        case 21: {
            gActorFuncTable_Overlay1[temp_t8].oneArg(index);
            break;
        }
        case 22: {
            gActorFuncTable_Overlay1[temp_t8].oneArg(index);
            break;
        }
        case 23: {
            gActorFuncTable_Overlay3[temp_t8].oneArg(index);
            break;
        }
        case 24: {
            gActorFuncTable_Overlay3[temp_t8].oneArg(index);
            break;
        }
        case 25: {
            gActorFuncTable_Overlay1[temp_t8].oneArg(index);
            break;
        }
        case 26: {
            gActorFuncTable_Overlay3[temp_t8].oneArg(index);
            break;
        }
        case 27: {
            gActorFuncTable_Overlay4[temp_t8](index);
            break;
        }
        case 28: {
            gActorFuncTable_Overlay3[temp_t8].oneArg(index);
            break;
        }
        case 29: {
            gActorFuncTable_Overlay3[temp_t8].oneArg(index);
            break;
        }
        case 30: {
            gActorFuncTable_Overlay3[temp_t8].oneArg(index);
            break;
        }
        case 31: {
            gActorFuncTable_Overlay3[temp_t8].oneArg(index);
            break;
        }
        case 32: {
            gActorFuncTable_Overlay3[temp_t8].oneArg(index);
            break;
        }
        case 33: {
            gActorFuncTable_Overlay1[temp_t8].oneArg(index);
            break;
        }
        case 34: {
            gActorFuncTable_Overlay1[temp_t8].oneArg(index);
            break;
        }
        case 35: {
            gActorFuncTable_Overlay1[temp_t8].oneArg(index);
            break;
        }
        case 36: {
            gActorFuncTable_Overlay1[temp_t8].oneArg(index);
            break;
        }
        case 37: {
            gActorFuncTable_Overlay3[temp_t8].oneArg(index);
            break;
        }
        case 38: {
            gActorFuncTable_Overlay1[temp_t8].oneArg(index);
            break;
        }
        case 39: {
            gActorFuncTable_Overlay4[temp_t8](index);
            break;
        }
        case 40: {
            gActorFuncTable_Overlay4[temp_t8](index);
            break;
        }
        case 41: {
            gActorFuncTable_Overlay4[temp_t8](index);
            break;
        }
        case 42: {
            gActorFuncTable_Overlay4[temp_t8](index);
            break;
        }
        case 43: {
            gActorFuncTable_Overlay1[temp_t8].oneArg(index);
            break;
        }
        case 44: {
            gActorFuncTable_Overlay1[temp_t8].oneArg(index);
        }
        default: {
            break;
        }
    }
}

void Actors_Tick(void) {
    Actor* actor; // this is probably a fake match but I prefer this syntax over thisActor
    uint16_t index;

    // if actors are not supposed to process
    if (D_800BE670) {
        for (index = 1; index < ACTOR_COUNT2; index++) {
            actor = gActors + index;

            if ((actor->flag & ACTOR_FLAG_ACTIVE) && (actor->flag & ACTOR_FLAG_ALWAYS_UPDATE)) {
                if (actor->actorType < 0x100) {
                    gActorFuncTable[actor->actorType](index);
                }
                else {
                    Actors_Tick_Overlayed(index);
                }
            }
        }
    }
    else {
        for (index = 1; index < ACTOR_COUNT2; index++) {
            actor = gActors + index;

            if ((actor->flag & ACTOR_FLAG_ACTIVE)) {
                if (actor->actorType < 0x100) {
                    gActorFuncTable[actor->actorType](index);
                }
                else {
                    Actors_Tick_Overlayed(index);
                }
            }
        }
    }
}

#ifdef NON_MATCHING
uint32_t func_80017680(uint16_t button, uint8_t* sel){
    if((gButtonHold&button)==0) *sel=0;
    else{
        if(*sel != 33) *sel++;
        else *sel=32;
    }
    if((gButtonPress&button==0) && (*sel!=33)) return 0;
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_80017680.s")
#endif
#ifdef NON_MATCHING
uint32_t func_800176F8(uint16_t button, uint8_t* sel){
    if((gButtonHold&button)==0) *sel=0;
    else{
        if(*sel != 20) *sel++;
        else *sel=16;
    }
    if((gButtonPress&button==0) && (*sel!=20)) return 0;
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_800176F8.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_80017770.s")

#ifdef NON_MATCHING
// behavioraly equal, differences are regalloc and some of the load/stores are out of order
void Intro_Tick(void) {
    switch (gGameSubState) {
        case 0: {
            BGM_Stop();

            gCurrentScene = SCENE_SPLASHSCREEN;

            InitScene();
            func_80010C20(gCurrentScene);

            (&D_80380200)[2] = 1; // volatile?
            (&D_80380200)[1] = 1; // volatile?

            Text_SpawnAt2(0x30, 0x2000, 0, 4, 0);

            D_800F4224 |= 0x200;
            D_800F4210 |= 0x30000000;
            D_800F423A = 0x80;
            D_800F423C = 1;
            D_800F423E = 0x10;
            D_800F4240 = 8;
            D_800F430C = 0x8034E4C8;
            D_800F4310 = &D_800C9080;
            *(&D_800F42E4) = -0x1F; // volatile?

            func_8002B82C(0x803524C8, &D_800C9080, 0xFF, -0x1F, -0x1F, -0x1F);

            gGameSubState++;
            break;
        }
        case 1: {
            func_8002B82C(0x803524C8, &D_800C9080, 0xFF, D_800F42E4, D_800F42E4, D_800F42E4);

            if ((gSceneFramesReal & 1) != 0) {
                if (D_800F42E4++ == 0) {
                    gGameSubState++;
                    D_800F42E8 = 0x80;
                }
            }
            break;
        }
        case 2: {
            if (D_800F42E8-- == 0) {
                gGameSubState++;
            }
            break;
        }
        case 3: {
            func_8002B82C(0x803524C8, &D_800C9080, 0xFF, D_800F42E4, D_800F42E4, D_800F42E4);

            if ((gSceneFramesReal & 1) != 0) {
                if ((D_800F42E4-- + 0x1F) == 0) {
                    Text_SpawnAt2(0x30U, 0x2000U, 0U, 4U, (uint16_t)0);

                    D_800F4224 = D_800F4224 | 0x200;
                    D_800F4210 = D_800F4210 | 0x30000000;
                    D_800F423A = 0x50;
                    D_800F423C = 1;
                    D_800F423E = 0x18;
                    D_800F4240 = 4;
                    D_800F430C = 0x80340240;
                    D_800F4310 = (uint32_t)&D_800C8FA0;
                    D_800F42E4 = -0x1F;

                    func_8002B82C(0x80342040, &D_800C8FA0, 0xF, -0x1F, -0x1F, -0x1F);

                    gGameSubState = 10;
                }
            }
            break;
        }
        case 10: {
            func_8002B82C(0x80342040, &D_800C8FA0, 0xF, D_800F42E4, D_800F42E4, D_800F42E4);

            if ((gSceneFramesReal & 1)) {
                if (D_800F42E4++ == 0) {
                    gGameSubState++;
                    D_800F42E8 = 0x80;
                }
            }
            break;
        }
        case 11: {
            if (D_800F42E8-- == 0) {
                gGameSubState++;
            }
            break;
        }
        case 12: {
            func_8002B82C(0x80342040, &D_800C8FA0, 0xF, D_800F42E4, D_800F42E4, D_800F42E4);

            if ((gSceneFramesReal & 1)) {
                if (D_800F42E4-- + 0x1F) {
                    D_800F4210 = 0;

                    Text_SpawnAt2(0x31U, 0x2002U, 0U, 8U, (uint16_t)0);

                    D_800F43BC |= 0x200;
                    D_800F43A8 |= 0x30000000;
                    D_800F43D2 = 0x48;
                    D_800F43D4 = 1;
                    D_800F43D6 = 0x18;
                    D_800F43D8 = 4;
                    D_800F44A4 = 0x80342068;
                    D_800F44A8 = &D_800C8FC0;
                    *(&D_800F447C) = -0x1F;

                    func_8002B82C(0x80343B68, &D_800C8FC0, 0x5F, -0x1F, -0x1F, -0x1F);

                    gGameSubState++;
                }
            }
            break;
        }
        case 13: {
            func_8002B82C(0x80343B68, &D_800C8FC0, 0x5F, D_800F447C, D_800F447C, D_800F447C);

            if ((gSceneFramesReal & 1) != 0) {
                if (D_800F447C++ == 0) {
                    gGameSubState++;
                    D_800F4480 = 0x80;
                }
            }
            break;
        }
        case 14: {
            if (D_800F4480-- == 0) {
                gGameSubState++;
            }
            break;
        }
        case 15: {
            func_8002B82C(0x80343B68, &D_800C8FC0, 0x5F, D_800F447C, D_800F447C, D_800F447C);

            if ((gSceneFramesReal & 1) != 0) {
                if ((D_800F447C-- + 0x1F) == 0) {
                    D_800F43A8 = 0;
                    gGameSubState++;
                }
            }
            break;
        }
        case 16: {
            gDListHead = (uint32_t*)((uint8_t*)gDListHead + 8);
            gDListHead[0] = 0x6000000;
            gDListHead[1] = &D_800C8EF0;

            D_800F4210 = 0;
            D_800F43A8 = 0;
            gCurrentStage = 0;
            gWorldProgress = 0;
            gCurrentScene = SCENE_INTRO;
            D_800D28E4 = 0x59;
            gSaveSlotIndex = 0;
            gGameState = GAMESTATE_TRANSITION;
            gGameSubState = 65;
            break;
        }
    }

    if ((gButtonPress & gButton_Start) != 0) {
        if (gGameSubState > 0) {
            gGameState = GAMESTATE_TITLESCREEN;
            gGameSubState = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/Intro_Tick.s")
#endif

char D_800C8F68[] = "PRESS START";
char D_800C8F74[] = "@1997 TREASURE/ENIX";
#ifndef VER_JPN
char D_800C8F88[] = "LICENSED TO NINTENDO";
#endif
// prints "Press start" and copyright info
void Title_Copyright(void) {
    func_80017770();
    Text_PrintASCII(0x39U, &D_800C8F68, 0xFFCA, 0xFFE4, 0, Text_ConvertColor(0U, (0x1F - D_801781A0[0] / 4), (0x1F - D_801781A0[0] / 4), 0x1FU));
    Text_PrintASCII(0x49U, &D_800C8F74, 0xFFAA, 0xFFC0, 0, Text_ConvertColor(2U, 0x1FU, 0x1FU, 0x18U));
#ifndef VER_JPN
    Text_PrintASCII(0x60U, &D_800C8F88, 0xFFA6, 0xFFAE, 0, Text_ConvertColor(2U, 0x1FU, 0x1FU, 0x18U));
#endif
}


// cp1 stuff is producing a flipped pair of instructions
#ifdef NON_MATCHING
void func_80017FE8(uint16_t index) {
    Actor* actor;

    thisActor.actorType = 0;
    Actor_Spawn(index);
    actor = &thisActor;
    actor->pos.x = -2;
    actor->pos.y = 4;
    actor->graphic = 0x2D0;
    actor->flag2 |= 0x801;
    actor->pos.z = 0x100;
    actor->unk_0x188._w = 0;
    actor->rgba.a = 0xFF;
    actor->rgba.b = 0xFF;
    actor->rgba.g = 0xFF;
    actor->rgba.r = 0xFF;
    actor->scaleX = 18.0f;
    actor->scaleY = 12.0f;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_80017FE8.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001809C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_800180FC.s")

#ifdef NON_MATCHING
void TitleScreen_Tick(void) {
    uint16_t buttonPress;

    switch (gGameSubState) {
        // OK
        case 0: {
            BGM_Play(BGM_OPENING_TITLE);
            gGameSubState = 0x10;
            // fallthrough
        }
        // OK
        case 16: {
            gSPDisplayList(gDListHead++, &D_800C8EF0);
            func_800230B8();
            func_80017FE8(0x33);
            gCurrentScene = SCENE_TITLE;
            gGameSubState += 1;
        }
        default: {
            break;
        }
        // OK
        case 17: {
            func_80026E60(0x50);
            gGameSubState += 1;
            break;
        }
        // OK
        case 18: {
            func_80026F2C(0x50);
            gGameSubState += 1;
            break;
        }
        // OK
        case 19: {
            func_800270E4(0x15);
            gGameSubState += 1;
            break;
        }
        // OK
        case 20: {
            func_8002670C(gCurrentScene);
            gGameSubState += 1;
            break;
        }
        // OK
        case 21: {
            func_80026784(gCurrentScene);
            gGameSubState += 1;
            break;
        }
        // OK
        case 22: {
            func_80026428(gCurrentScene);
            gGameSubState += 1;
            break;
        }
        // OK
        case 23: {
            func_80025BFC();
            func_8002B82C(0x803DA400, 0x80380200, 0xFF, 2, 0, 0);
            D_800BE578 = 2;
            D_800BE580 = -0xC;
            D_801376A0 = 0x80380200;
            D_800BE6E4 = 0;
            D_800BE6E8 = 1;
            D_800BE6EC = 0;
            D_800BE70C = 1;
            func_80010C20(gCurrentScene);
            gGameSubState += 1;
            break;
        }
        // some actors are referenced by a pointer, probably Actor* local vars?
        case 24: {
            gActors[7].rgba.b = 0;
            D_801781A0[0] = 0;

            Text_SpawnAt2(16, 0x800, 0x70, 0xFF68, 0);
            gActors[16].flag2 |= 0x100;
            gActors[16].rgba.a = 0x80;

            Text_SpawnAt2(17, 0x1000, 0xFF88, 0xFF68, 0);
            gActors[17].flag2 |= 0x100;
            gActors[17].rgba.a = 0x80;

            gActors[48].actorType = 0;
            actor2_Spawn(48);
            gActors[48].flag2 |= 0x200;
            gActors[48].flag |= (ACTOR_FLAG_UNK28 | ACTOR_FLAG_UNK29); // 0x30000000;
            gActors[48].unk_0x17C._p = 0x80343C28;
            gActors[48].unk_0x180 = 0x80349728;
            gActors[48].unk_0x188._w = 0xE;
            gActors[48].pos.x = 0x2A;
            gActors[48].hitboxBX0 = 0xE0;
            gActors[48].hitboxBX1 = 1;
            gActors[48].hitboxBY0 = 8;
            gActors[48].hitboxBY1 = 0xD;

            gActors[49].flag = 0;
            gActors[50].flag = 0;
#ifdef VER_JPN
            //Spawn the subtitle
            ACTORINIT(52,0);
            gActors[52].flag2|= 0x200;
            gActors[52].pos.y= 0x4a;
            gActors[52].pos.x= 0x120;
            gGameSubState++;
            gActors[52].flag|= 0x30000000;
            gActors[52].hitboxBX0 = 0xd0;
            gActors[52].hitboxBX1 = 1;
            gActors[52].hitboxBY0 = 8;
            gActors[52].hitboxBY1 = 6;
            gActors[52].unk_0x17C._p = 0x80348c30;
            gActors[52].unk_0x180 = 0x8034b338;
#else
            gGameSubState += 1;
#endif            
            break;
        }
        case 25: {
            Title_Copyright();

            if (gActors[51].rgba.a == 7) {
                gActors[51].flag = 0;
                gActors[51].unk_0x154._w = 0x10040;
#ifdef VER_JPN
                SFX_Play_1(0x48); //subtitle go "woosh"
#endif                
                gGameSubState += 1;
            }
            else {
                gActors[51].rgba.a -= 8;
            }

            break;
        }
        case 26: {
            gActors[51].unk_0x154._w--;
            func_8001809C();

            if (gActors[51].unk_0x154._w == 0x10000) {
                SFX_Play_1(SFX_MARINA_TITLE);
            }

            // test to toggle sound test
            if (((gButtonHold & gButton_A)) && ((gButtonHold & gButton_CLeft)) && ((gButtonHold & gButton_CRight)) &&
                ((gButtonHold & gButton_LTrig)) && ((gButtonHold & gButton_B) == 0) && ((gButtonHold & gButton_CDown) == 0) &&
                ((gButtonHold & gButton_CUp) == 0) && ((gButtonHold & gButton_RTrig) == 0)) {
                gActors[7].rgba.b = 1;
            }
            else {
                gActors[7].rgba.b = 0;
            }

            Title_Copyright();

            if (gButtonPress & gButton_Start) {
                SFX_Play_1(SFX_MENU_DING);
                func_80003F24(1, 0x40);

                D_80178166 = 0;

                if (gActors[7].rgba.b) gGameSubState = 0x30;
                else gGameSubState = 0x20;
            }
            //start attract mode when BGM timer finishes or B is pressed
            if ((D_80137DA0 >= 0x1141 || (gButtonPress & gButton_B) != 0) && (buttonPress & gButton_Start) == 0) {
                func_80003F24(1, 0x20);
                gActors[51].flag2 |= 0x10;
                gActors[51].flag = ACTOR_FLAG_ENABLED;
                gActors[51].rgba.b = 0x7F;
                gActors[51].rgba.g = 0x7F;
                gActors[51].rgba.r = 0x7F;
                gActors[51].rgba.a = 7;
                gGameSubState += 1;
                break;
            }
            break;
        }
        // OK (besides regalloc)
        case 27: {
            func_8001809C();
            Title_Copyright();

            if (gActors[51].rgba.a == 0xFF) {
                D_80137D90 = 0;
                gGameState = 0xA;
                gGameSubState = 0;
            }
            else {
                gActors[51].rgba.a += 8;
            }
            break;
        }
        // OK (besides regalloc)
        case 32: {
            func_800180FC();
            if (D_80137D90 == 3) {
                D_80137D90 = 0;
                D_80178164 = 0x20U;
                gGameSubState += 1;
            }
            break;
        }
        // OK (besides regalloc)
        case 33: {
            func_800180FC();
            if (D_80178164-- == 0) {
                gGameState = 0xB;
                gGameSubState = 0;
            }
            break;
        }
        // OK (besides regalloc)
        case 48: {
            func_800180FC();
            if (D_80137D90 == 3) {
                D_80137D90 = 0;
                D_80178164 = 0x20U;
                gGameSubState += 1;
            }
            break;
        }
        // OK (besides regalloc)
        case 49: {
            func_800180FC();
            if (D_80178164-- == 0) {
                func_800230B8();
                gActors[16].flag = ACTOR_FLAG_ENABLED;
                gActors[17].flag = ACTOR_FLAG_ENABLED;
                gGameState = GAMESTATE_DEBUG_SOUNDTEST;
                gGameSubState = 0;
            }
            break;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/TitleScreen_Tick.s")
#endif
#define gSoundTest_SelectedBGM gActors[2].vel.x_w
#define gSoundTest_SelectedSFX gActors[3].vel.x_w

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/SoundTest_Tick.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/StageSelect_Print.s")



#ifdef NON_MATCHING
// Needs a lot of work
void StageSelect_Tick(void) {
    int16_t temp_t3;
    int32_t temp_a0;
    int32_t temp_t6_2;
    int32_t temp_t7;
    int32_t temp_t8_2;
    uint16_t temp_v0;
    uint8_t* temp_v1;
    uint8_t* temp_v1_2;
    uint8_t* temp_v1_3;
    uint8_t temp_a2;
    uint8_t temp_a2_2;
    uint8_t temp_t6;
    uint8_t temp_t8;
    uint8_t temp_v0_2;
    int new_var;
    uint8_t temp_v0_3;
    int32_t phi_a2;
    int32_t phi_a2_2;
    int32_t phi_a0;
    int32_t phi_v0;

    temp_v0 = gGameSubState;
    if (temp_v0 != 0) {
        if (temp_v0 != 1) {
            if (temp_v0 == 2) {
                gSaveSlotIndex = (uint8_t)0;
                gWorldProgress = gCurrentStage;
                gGameState = (uint16_t)0xC;
                gGameSubState = (uint16_t)0x41U;
            }
        }
        else {
            func_80017770();
            func_80017680(gButton_DUp, &D_800F026E);

            if (temp_v0 != 0) {
                temp_t6 = gActors.unk_0xBC6 - 1;
                gActors.unk_0xBC6 = temp_t6;
                if ((temp_t6 & 0xFF) == 0xFF) {
                    gActors.unk_0xBC6 = (uint8_t)0x15U;
                }
                SFX_Play_2(SFX_MENU_BLIP);
            }

            func_80017680(gButton_DDown, &D_800F0406);

            if (temp_v0 != 0) {
                temp_t8 = gActors.unk_0xBC6 + 1;
                gActors.unk_0xBC6 = temp_t8;
                if ((temp_t8 & 0xFF) == 0x16) {
                    gActors.unk_0xBC6 = (uint8_t)0U;
                }
                SFX_Play_2(SFX_MENU_BLIP);
            }

            func_80017680(gButton_DLeft, &D_800F059E);

            if (temp_v0 != 0) {
                temp_v1 = (&D_80178170) + gActors.unk_0xBC6;
                temp_a2 = *temp_v1;
                if (((int32_t)temp_a2) > 0) {
                    *temp_v1 = (uint8_t)(temp_a2 - 1);
                    SFX_Play_2(SFX_MENU_BLIP);
                }
            }

            func_80017680(gButton_DRight, &D_800F0736);

            if (temp_v0 != 0) {
                temp_v0_2 = gActors.unk_0xBC6;
                temp_v1_2 = (&D_80178170) + temp_v0_2;
                temp_a2_2 = *temp_v1_2;
                if (((int32_t)(temp_a2_2 & 0xFF)) < ((*((&D_800C823C) + (temp_v0_2 * 2))) - 1)) {
                    *temp_v1_2 = (uint8_t)(temp_a2_2 + 1);
                    SFX_Play_2(SFX_MENU_BLIP);
                }
            }

            temp_v0_3 = gActors.unk_0xBC6;
            temp_t3 = (*((&D_80178170) + temp_v0_3)) + (*((&D_80178188) + temp_v0_3));
            temp_t8_2 = (temp_t3 & 0xFFFF) * 2;
            gCurrentStage = temp_t3;
            gCurrentScene = *((&gStageScenes) + temp_t8_2);
            D_800D28E4 = *((&D_800C83F8) + temp_t8_2);
            StageSelect_Print(&gCurrentStage);
            if ((gButtonPress & gButton_Start) != 0) {
                BGM_Stop();
                func_80043918();
                gGameSubState = (uint16_t)(gGameSubState + 1);
                return;
            }
        }
    }
    else {
        phi_a2 = 0;
    loop_5:
        temp_t7 = (phi_a2 + 1) & 0xFFFF;
        *((&D_80178170) + phi_a2) = (uint8_t)0;
        phi_a2 = temp_t7;
        if (temp_t7 < 0x16) {
            goto loop_5;
        }
        phi_a2_2 = 0;
    loop_7:
        temp_v1_3 = (&D_80178188) + phi_a2_2;
        phi_a0 = 0;
        *temp_v1_3 = (uint8_t)0U;
        phi_v0 = 0;
        if (phi_a0 > 0) {
        loop_8:
            temp_t6_2 = (phi_v0 + 1) & 0xFFFF;
            *temp_v1_3 = (uint8_t)((*temp_v1_3) + (*((&D_800C823C) + (phi_v0 * 2))));
            phi_v0 = temp_t6_2;
            if (temp_t6_2 < phi_a0) {
                goto loop_8;
            }
        }

        temp_a0 = (phi_a2_2 + 1) & 0xFFFF;
        phi_a2_2 = temp_a0;
        phi_a0 = temp_a0;
        if (!(&gActors)) {}
        if (temp_a0 < 0x16) {
            goto loop_7;
        }

        gActors.unk_0xBC6 = (uint8_t)0U;
        gCurrentScene = 0;
        StageSelect_Print((int16_t*)temp_a0, &D_800C823C, temp_a0, &D_80178188);
        D_801376BD = (uint8_t)0;
        D_801376B9 = (uint8_t)1;
        D_801376A9 = (uint8_t)0xC0;
        new_var = 0xC0;
        D_801376AD = (uint8_t)new_var;
        D_801376B1 = (uint8_t)0xC0;
        D_801376B5 = (uint8_t)0xFF;
        gGameSubState = (uint16_t)(gGameSubState + 1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/StageSelect_Tick.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_80019520.s")

#ifdef NON_MATCHING
void CalculateFestivalTime(void){
    int32_t time0;
    int32_t time1;
    int32_t time2;
    int32_t time3;

    // is it "the day of"
    if(gCurrentStage == 33) {
        time0 = func_80019520(gFestivalRecords[2]);
        time1 = func_80019520(gFestivalRecords[1]);
        time2 = func_80019520(gFestivalRecords[0]);
        time3 = func_80019520(gFestivalRecords[5]);
        gStageTime = time0 + time1 + time2 + time3;
        if(gFestivalRecords[3] < 1800) gStageTime -= gFestivalRecords[3]       + 1800;
        if(gFestivalRecords[4] < 1800) gStageTime += gFestivalRecords[4] * -10 + 1800;
        if(gFestivalRecords[6] < 1800) gStageTime += gFestivalRecords[6] * -10 + 1800;
    }

    gGamePaused = 0;
    gGameState = 12; // transitional state
    gGameSubState = 8;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/CalculateFestivalTime.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_800197A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001983C.s")
//print the selected level name
#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_800198B4.s")
//print the selected stage name
#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_800199DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_80019A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_80019E48.s")

void func_80019EC4(void) {
    func_8008310C();
    func_80083454();
    func_80019A80();
    func_80019E48();
    func_8001A254();
}

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_80019F04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_80019FB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001A15C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001A254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001A584.s")

uint16_t gTimesToBeat[] = {
    /* 0x01 */ 0,
    /* 0x02 */ 0,
    /* 0x03 */ 840,
    /* 0x04 */ 1020,
    /* 0x05 */ 1500,
    /* 0x06 */ 480,
    /* 0x07 */ 1932,
    /* 0x08 */ 2160,
    /* 0x09 */ 1320,
    /* 0x0A */ 2580,
    /* 0x0B */ 1740,
    /* 0x0C */ 720,
    /* 0x0D */ 2160,
    /* 0x0E */ 1560,
    /* 0x0F */ 660,
    /* 0x10 */ 1000,
    /* 0x11 */ 720,
    /* 0x12 */ 1620,
    /* 0x13 */ 1680,
    /* 0x14 */ 1500,
    /* 0x15 */ 1500,
    /* 0x16 */ 6660,
    /* 0x17 */ 0,
    /* 0x18 */ 1920,
    /* 0x19 */ 1800,
    /* 0x1A */ 3000,
    /* 0x1B */ 4320,
    /* 0x1C */ 1320,
    /* 0x1D */ 3600,
    /* 0x1E */ 1080,
    /* 0x1F */ 2220,
    /* 0x20 */ 9360,
    /* 0x21 */ 660,
    /* 0x22 */ 3720,
    /* 0x23 */ 0,
    /* 0x24 */ 1620,
    /* 0x25 */ 1680,
    /* 0x26 */ 19200,
    /* 0x27 */ 2580,
    /* 0x28 */ 1800,
    /* 0x29 */ 960,
    /* 0x2A */ 4920,
    /* 0x2B */ 2340,
    /* 0x2C */ 2220,
    /* 0x2D */ 2040,
    /* 0x2E */ 3480,
    /* 0x2F */ 0,
    /* 0x30 */ 5280,
    /* 0x31 */ 1680,
    /* 0x32 */ 3873,
    /* 0x33 */ 1020,
    /* 0x34 */ 4800,
    /* 0x35 */ 3300,
    /* 0x36 */ 0,
    /* 0x37 */ 4500,
    /* 0x38 */ 5160
};

int16_t Stage_GetTimeRank(uint16_t t, uint16_t s) {
    if (t < gTimesToBeat[s]) {
        return 0;
    }

    if (t < (gTimesToBeat[s] + 1800)) {
        return 1;
    }

    if (t < (gTimesToBeat[s] + 7200)) {
        return 2;
    }

    if (t < (gTimesToBeat[s] + 18000) && t < 36000) {
        return 3;
    }

    return 4;
}

void func_8001A7E0(int16_t arg0, int16_t arg1, uint16_t time, uint16_t stage, int16_t arg4) {
    func_8008379C(arg0, arg1, D_800C9694[Stage_GetTimeRank(time, stage)], arg4);
}

void func_8001A838(int16_t arg0, int16_t arg1, uint16_t time, uint16_t stage, int16_t arg4) {
    func_80083810(arg0, arg1, D_800C96A0[Stage_GetTimeRank(time, stage)], arg4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001A890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001A96C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/Record_PrintTime.s")

void func_8001B004(void) {
    Record_PrintTime(9, 6, 0xFFFF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/World_IncrementProgress.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001B078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001B1A0.s")

void func_8001B1F8(void) {
    World_IncrementProgress();
    func_8001B1A0();
    D_80178160 = (uint16_t)gSelectedWorld;
    D_8017815A = (int16_t)gWorldMapSelectedStage;
}

void func_8001B23C() {}

#ifdef NON_MATCHING
int16_t YellowGem_Count(void) {
    uint16_t i;
    uint64_t flag = 1;
    int16_t count = 0;

    for (i = 0; i < 63; i++) {
        if (gYellowGemBitfeild & flag) count++;
        flag = __ll_lshift(flag, 1);
    }
    return count;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/YellowGem_Count.s")
#endif
#ifdef NON_MATCHING
void GameSave_Update(void) {
    uint8_t bVar1;
    uint16_t uVar2;
    uint16_t uVar4;

    uVar2 = gCurrentStage;
    bVar1 = gWorldProgress;
    D_80178150 = gTimeRecords[gCurrentStage];
    uVar4 = (uint16_t)gWorldProgress;
    if (gStageTime < D_80178150) {
        gTimeRecords[gCurrentStage] = gStageTime;
    }
    if (uVar4 == uVar2) {
        gWorldProgress = (char)uVar2 + 1;
    }
    gFileRedGems[gSaveSlotIndex] = gRedGems;
    gFileYellowGems[gSaveSlotIndex] = YellowGem_Count();
    gFilePlayTimes[gSaveSlotIndex] = (uint64_t)gPlayTime;
    GameSave_SaveRecords();
    gWorldProgress = bVar1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/GameSave_Update.s")
#endif

void func_8001B3D0(void) {
    uint16_t uVar1;
    uint32_t uVar2;

    gWorldProgress = (uint8_t)gCurrentStage;
    gFileRedGems[gSaveSlotIndex] = gRedGems;
    uVar1 = YellowGem_Count();
    uVar2 = (uint32_t)gSaveSlotIndex;
    gFileYellowGems[uVar2] = uVar1;
    gFilePlayTimes[uVar2] = (uint64_t)gPlayTime;
    GameSave_SaveRecords();
}

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/Worldmap_Tick.s")

void YellowGem_SetFlag(void) {
    gYellowGemBitfeild |= (uint64_t)1 << (uint16_t)gCurrentStage;
}

uint64_t YellowGem_GetFlag(uint16_t arg0) {
    uint64_t mask = (uint64_t)1 << arg0;

    return gYellowGemBitfeild & mask;
}

#ifdef NON_MATCHING
void func_8001C834(void) {
    Text_SpawnAt2(0x32, 0, 0xFFFC, 0x33, 1);
    D_800F4540 |= 0x50000000;
    Text_SpawnAt2(0x33, 0, 0xFFFC, 0xFFF7, 1);
    D_800F46D8 |= 0x70000000;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001C834.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001C8B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/printIcon_YellowGem.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001CA68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001CAA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001CB6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001CC34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001CC8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001CD30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001CE04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001CF14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001CFDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001D040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/Calculate_TimeRecordTotal.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/PrintRecordEntry.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001D5B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001D60C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/gameStates/func_8001D654.s")
