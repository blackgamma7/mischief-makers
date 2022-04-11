#include "common.h"
//Intro funcs
//Todo: find where 3D title is displayed in Japan version.

typedef struct IntroStruct{ //inital transform data for rocks at end
 int16_t posX,posY;
 int32_t velX,velY,velZ;
 float scale;
};
extern struct IntroStruct D_80198DE0_6D9460[24];

void func_80192100_6D2780(uint16_t other,uint16_t index,uint16_t t,uint16_t g,int16_t posX,int16_t posY,int16_t posZ){
  ACTORINIT(index,t);
  thisActor.flag2 = 0x900;
  thisActor.flag = 3;
  thisActor.unk_0x188._w = 0;
  thisActor.graphic = g;
  thisActor.pos.x = posX;
  thisActor.pos.y = posY;
  thisActor.pos.z = posZ;
  thisActor.actorState_b[1]=gActors[other].actorState_b[1];
}

void func_801921C8_6D2848(uint16_t other,uint16_t index,uint16_t g,int16_t posX,int16_t posY,int16_t posZ){
    func_80192100_6D2780(other,index,0x2B02,g,posX,posY,posZ);
}
#ifdef NON_MATCHING
void func_80192224_6D28A4(uint16_t other,uint16_t index,uint16_t g,int16_t posX,int16_t posY,int16_t posZ){
    func_80192100_6D2780(other,index,0x2B03,g,posX,posY,posZ);
    thisActor.pos.x=gActors[other].pos.x+posX;
    thisActor.pos.y=gActors[other].pos.y+posY;
    thisActor.pos.z=gActors[other].pos.z+posZ;
    thisActor.unk_0x158._w=posX<<16;
    
    thisActor.unk_0x15C=posX<<16;
    thisActor.unk_0x154._w=other;
    thisActor.unk_0x160._w=posZ;
}
#else
extern void func_80192224_6D28A4(uint16_t other,uint16_t index,uint16_t g,int16_t posX,int16_t posY,int16_t posZ);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80192224_6D28A4.s")
#endif

void func_801922F4_6D2974(uint16_t other,uint16_t index,uint16_t g,int16_t posX,int16_t posY,int16_t posZ){
    func_80192100_6D2780(other,index,0x2B04,g,posX,posY,posZ);
}

void func_80192350_6D29D0(uint16_t other,uint16_t index,uint16_t g,int16_t posX,int16_t posY,int16_t posZ){
    func_80192100_6D2780(other,index,0x2B01,g,posX,posY,posZ);
}

void func_801923AC_6D2A2C(uint16_t other,uint16_t index,uint16_t g,int16_t posX,int16_t posY,int16_t posZ){
    func_80192100_6D2780(other,index,0x2B06,g,posX,posY,posZ);
    thisActor.flag2|=9;
}

void func_80192438_6D2AB8(uint16_t other,uint16_t index,uint16_t g,int16_t posX,int16_t posY,int16_t posZ){
    func_80192224_6D28A4(other,index,g,posX,posY,posZ);
    thisActor.actorType=0x2B07;
    thisActor.flag2|=9;
}
void func_801924CC_6D2B4C(uint16_t other,uint16_t index,int16_t posX,int16_t posY,int16_t posZ){
    func_80192100_6D2780(other,index,0x2B08,0,posX,posY,posZ);
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80192528_6D2BA8.s")

#ifdef NON_MATCHING
float func_8019265C_6D2CDC(float f0, float f1, float* f2){
  if (*f2 != 0.0) return (f1 - f0) / *f2 + f0;
  return f1;
}
#else
extern float func_8019265C_6D2CDC(float f0, float f1, float* f2);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_8019265C_6D2CDC.s")
#endif
int32_t func_80192698_6D2D18(int32_t x, int32_t y, float* f){
    return func_8019265C_6D2CDC(x,y,f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_801926E0_6D2D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80192778_6D2DF8.s")

extern float func_801927F8_6D2E78(uint16_t index,float f, uint16_t x);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_801927F8_6D2E78.s")

float func_801928B8_6D2F38(uint16_t index,float f, uint16_t x){
    float ret=func_801927F8_6D2E78(index,f,x);
    thisActor.unk_0x11C=0;
    return -ret;
}

void func_80192920_6D2FA0(uint16_t x){
    gActors[48].actorState=x;
    gActors[49].actorState=x;
    gActors[50].actorState=x;
}
//rocks bursting at end of sequence.
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_8019293C_6D2FBC.s")

void func_80192A98_6D3118(uint16_t x){
  Actor_ZeroFlagRange(0x31,0x8f);
  D_800CA230 = 0;
  D_800BE5F4._w = 4;
}

//main cinematic behavior
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80192AD0_6D3150.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_8019429C_6D491C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80194334_6D49B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_801943E4_6D4A64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_8019444C_6D4ACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_801945EC_6D4C6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_8019466C_6D4CEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_801946BC_6D4D3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80194D2C_6D53AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80194E0C_6D548C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80194F1C_6D559C.s")
//First shot - Marina walks on screen, uppercuts Theo.
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80195024_6D56A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80195EA0_6D6520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80195F28_6D65A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80195FC4_6D6644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_801960BC_6D673C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_8019611C_6D679C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_801961D0_6D6850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80196848_6D6EC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80196FC8_6D7648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80197224_6D78A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80198274_6D88F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_801987F0_6D8E70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_8019897C_6D8FFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80198B18_6D9198.s")
