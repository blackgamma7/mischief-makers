#include "common.h"

//This script deals with the "Level clear" sequence.
#ifdef NON_MATCHING
void LevelClear_SpawnPlanetBG(void){ //spawns the "planet orbit" background
  gActors[64].actorType = ACTORTYPE_GRAPHICONLY;
  Actor_Spawn(0x40);
  gActors[64].flag2 = 0x911;
  gActors[64].flag = ACTOR_FLAG_ENABLED|ACTOR_FLAG_UNK3;
  gActors[64].graphic = 0x1820;
  gActors[64].rgba.a = 0x80;
  gActors[64].rgba.b = 0x9c;
  gActors[64].pos.x = 0;
  gActors[64].pos.y = 0x20;
  gActors[64].pos.z = 0;
  gActors[65].actorType = ACTORTYPE_GRAPHICONLY;
  gActors[64].scaleY = 0.75;
  Actor_Spawn(65);
  gActors[65].flag2 = 0xb13;
  gActors[65].flag = ACTOR_FLAG_ENABLED|ACTOR_FLAG_UNK3;
  gActors[65].graphic = 0xea;
  gActors[65].rgba.a = 0xc0;
  gActors[65].pos.x = 0;
  gActors[65].pos.y = 0xffb0;
  gActors[65].pos.z = 8;
  gActors[65].unk_0x188._w = 0xffffffc0;
  gActors[65].rgba.r = 0x3a;
  gActors[65].rgba.g = 0x82;
  gActors[65].rgba.b = 0xad;
  gActors[65].palletteP = &D_800D9284;
  gActors[66].actorType = ACTORTYPE_GRAPHICONLY;
  gActors[65].scaleX = 17.0;
  gActors[65].scaleY = 4.0;
  gActors[65].rotateX = 120.0;
  Actor_Spawn(0x42);
  gActors[66].flag2 = 0x901;
  gActors[66].flag = ACTOR_FLAG_ENABLED|ACTOR_FLAG_UNK3;
  gActors[66].graphic = 0x168;
  gActors[66].rgba.a = 0x50;
  gActors[66].rgba.b = 0x7f;
  gActors[66].pos.x = 0;
  gActors[66].pos.y = 0xffd8;
  gActors[66].pos.z = 9;
  gActors[66].unk_0x188._w = -0x40;
  gActors[67].actorType = ACTORTYPE_GRAPHICONLY;
  gActors[66].scaleX = 15.0;
  gActors[66].scaleY = 2.0;
  gActors[66].rotateX = 120.0;
  Actor_Spawn(0x43);
  gActors[67].flag2 = 0xb11;
  gActors[67].flag = ACTOR_FLAG_ENABLED|ACTOR_FLAG_UNK3;
  gActors[67].graphic = 0xe6;
  gActors[67].rgba.a = 0x60;
  gActors[67].pos.x = 0;
  gActors[67].pos.y = 0x20;
  gActors[67].pos.z = -0x800;
  gActors[67].rgba.r = 0x7f;
  gActors[67].rgba.g = 0x4f;
  gActors[67].rgba.b = 0xf;
  gActors[67].unk_0x188._w = -0x80;
  gActors[67].palletteP = 0x800D9474;
  gActors[68].actorType = ACTORTYPE_GRAPHICONLY;
  gActors[67].scaleX = 8.0;
  gActors[67].scaleY = 8.0;
  gActors[67].rotateX = 120.0;
  Actor_Spawn(0x44);
  gActors[68].flag2 = 0x800;
  gActors[68].flag = ACTOR_FLAG_ENABLED;
  gActors[68].graphic = 0x2000;
  gActors[68].rgba.a = 0xa6;
  gActors[68].pos.x = 0;
  gActors[68].pos.y = 0;
  gActors[68].pos.z = 0x30;
  gActors[68].unk_0x188._w = -0xA0;
  gActors[69].actorType = ACTORTYPE_GRAPHICONLY;
  Actor_Spawn(69);
  gActors[69].flag2 = 0x801;
  gActors[69].flag = ACTOR_FLAG_ENABLED;
  gActors[69].graphic = 0x2004;
  gActors[69].rgba.a = 0x70;
  Actor_Shade(69,0xff);
  gActors[69].pos.x = 0;
  gActors[69].pos.y = 0xffe8;
  gActors[69].pos.z = 0x30;
  gActors[69].unk_0x188._w = -0xA0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/LevelClear/LevelClear_SpawnPlanetBG.s")
#endif

//flying "stars" over Planet Clancer
#pragma GLOBAL_ASM("asm/nonmatchings/LevelClear/LevelClear_StarScape.s")

#ifdef NON_MATCHING
const float D_800ED508=0.8f; //rodata
void func_8009705C(uint16_t index) { //marina in her first victory pose
    ACTORINIT(index,ACTORTYPE_LEVELCLEAR);
    thisActor.actorState = 0x1000;
    thisActor.flag2 = 0x100;
    thisActor.flag = 11;
    thisActor.graphic = 0x800;
    thisActor.rgba.a = 0;
    thisActor.pos.x = 0xFFDF;
    thisActor.pos.y = 0xFFFC;
    thisActor.pos.z = 0x80;
    thisActor.unk_0x114 = D_800ED508;
    thisActor.gp1._w = 0x6000;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/LevelClear/func_8009705C.s")
#endif

void func_80097108(uint16_t index) {
    ACTORINIT(index,ACTORTYPE_LEVELCLEAR);
    thisActor.actorState = 0x2000;
    thisActor.flag2 = 0x110;
    thisActor.flag = 11;
    thisActor.graphic = 0x1000;
    thisActor.rgba.a = 0;
    thisActor.pos.x = 0x1e;
    thisActor.pos.y = 0xFFD8;
    thisActor.pos.z = 0xFC80;
}

void func_800971A0(uint16_t index) {
    ACTORINIT(index,ACTORTYPE_LEVELCLEAR);
    thisActor.actorState = 0x100;
    thisActor.flag2 = 0x900;
    thisActor.flag = 11;
    thisActor.graphic = 0x2800;
    thisActor.rgba.a = 0;
    thisActor.pos.x = 0x0;
    thisActor.pos.z = 0x80;
    thisActor.rgba.g = 0x50;
    thisActor.rgba.b = 0x70;
}

#pragma GLOBAL_ASM("asm/nonmatchings/LevelClear/func_8009723C.s")

#ifdef NON_MATCHING
void LevelClear_WhiteScreen(void) {
    ACTORINIT(80,ACTORTYPE_LEVELCLEAR);
    gActors[80].flag2 = 0x900;
    gActors[80].flag = ACTOR_FLAG_ENABLED;
    gActors[80].graphic = 0x2d0;
    gActors[80].scaleX = 20.0;
    gActors[80].scaleY = 20.0;
    gActors[80].palletteP = gPalletteWhite;
    gActors[80].pos.x_1 = 0;
    gActors[80].pos.y_1 = 0;
    gActors[80].pos.z_1 = 0x90;
    Actor_Shade(80, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/LevelClear/LevelClear_WhiteScreen.s")
#endif

void func_80097384(uint16_t index) {
    ACTORINIT(index,ACTORTYPE_LEVELCLEAR);
    thisActor.actorState = 0xC000;
    thisActor.flag2 = 0x900;
    thisActor.flag = 11;
    thisActor.graphic = 0xCE;
    thisActor.rgba.a = 0;
    thisActor.pos.x = 0x0;
    thisActor.pos.y = 0x0;
    thisActor.pos.z = 0x40;
    Actor_Shade(index, 127);
}

#pragma GLOBAL_ASM("asm/nonmatchings/LevelClear/LevelClear_ArmGrid.s")

#pragma GLOBAL_ASM("asm/nonmatchings/LevelClear/LevelClear_BoltEffect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/LevelClear/func_800977B8.s")
#ifdef NON_MATCHING
void LevelClear_SkipScene(void) {
    if (gButtonPress & gButton_ZTrig) {
        D_800D28E4 = 100;
        Actor_ZeroFlag_48_144();
        Actor_ZeroFlag_16_32();
        Actor_ZeroFlagRange(0x10, 0x30);
        Actor_ZeroFlagRange(0x90, 0xC0);
        Actor_ZeroFlag_192_199();
        Portraits_Reset();
        ACTORINIT(193,0x34);
        gActors[193].flag2 = 0x911;
        gActors[193].flag = 11;
        gActors[193].rgba.b = 0x40;
        gActors[193].unk_0x148 = 30.0;
        gActors[193].pos.x = 0;
        gActors[193].pos.y = 0;
        gActors[193].pos.z = 0xc0;
        gActors[193].graphic = 0x2d0;
        gActors[193].scaleX = 20.0;
        gActors[193].scaleY = 20.0;
        func_8005DFC8(0);
        D_800D16C4 = 0;
        SFX_StopAll();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/LevelClear/LevelClear_SkipScene.s")
#endif


#pragma GLOBAL_ASM("asm/nonmatchings/LevelClear/ActorTick_LevelClear.s")
