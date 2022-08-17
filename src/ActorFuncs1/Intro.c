#include "common.h"
//Intro funcs

#define LERPI(a,b,t) a = func_80192698_6D2D18(a,b,t)
#define LERPF(a,b,t) a = func_8019265C_6D2CDC(a,b,t)

typedef struct IntroStruct_s{ //inital transform data for rocks at end
 int16_t posX,posY;
 int32_t velX,velY,velZ;
 float scale;
}IntroStruct;

extern IntroStruct D_80198DE0_6D9460[24];

typedef struct IntroStruct2_s{
 float rotateZ;
 int32_t actorField0x158,actorField0x15C;
 uint32_t unk0xc; //align?
}IntroStruct2;

extern IntroStruct2 D_80199070_6D96F0[50];

void func_80192100_6D2780(uint16_t other,uint16_t index,uint16_t t,uint16_t g,int16_t posX,int16_t posY,int16_t posZ){
  ACTORINIT(index,t);
  thisActor.flag2 = 0x900;
  thisActor.flag = ACTOR_FLAG_ENABLED;
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
//spawner for 3D title letters
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

//lerpf?
#ifdef NON_MATCHING
float func_8019265C_6D2CDC(float a, float b, float* t){
  if (*t != 0.0) return (b - a) / *t + a;
  return b;
}
#else
extern float func_8019265C_6D2CDC(float a, float b, float* t);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_8019265C_6D2CDC.s")
#endif
///lerpi?
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
  gIsPlayerInactive = 0;
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
#ifdef NON_MATCHING
void func_801960BC_6D673C(uint16_t index, IntroStruct2* p,uint16_t i){
    IntroStruct2* j=&p[i];
    thisActor.unk_0x158._w=j->actorField0x158;
    thisActor.unk_0x15C=j->actorField0x15C;
    thisActor.rotateZ=j->rotateZ;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_801960BC_6D673C.s")
#endif

void func_8019611C_6D679C(uint16_t index, IntroStruct2* p,uint16_t i,float* t){
    IntroStruct2* j=&p[i];
    LERPI(thisActor.unk_0x158._w,j->actorField0x158,t);
    LERPI(thisActor.unk_0x15C,j->actorField0x15C,t);
    LERPF(thisActor.rotateZ,j->rotateZ,t);
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_801961D0_6D6850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80196848_6D6EC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80196FC8_6D7648.s")

extern int16_t D_80199390_6D9A10[4][6];
#ifdef NON_MATCHING
void func_80197224_6D78A4(uint16_t index){
  int iVar9;
  uint uVar10;
  char cVar11;
  uint uVar14;
  double dVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  double dVar23;
  uint in_fcsr;
  
 
  switch(thisActor.actorState_b[1]) {
  case 6:
    if (thisActor.actorState_b[0] == 0) {
      iVar9 = 0x3c;
      thisActor.actorState_b[0] = 1;
      thisActor.unk_0x114 = 60.0;
      if (true) {
        if (false) goto l__8019732c;
      }
      else if (false) {
l__8019732c:
        iVar9 = -1;
      }
      else {
        iVar9 = 0;
      }
      fVar16 = func_801927F8_6D2E78((u16)index,221.0,(u16)(iVar9 << 1));
      if ((((in_fcsr | 3) ^ 2) & 3) == 0) {
        fVar16 = ROUND(fVar16 * 65536.0);
      }
      else {
        fVar16 = FLOOR(fVar16 * 65536.0);
      }
      fVar18 = thisActor.unk_0x114;
      fVar17 = thisActor.unk_0x11C * 65536.0;
      thisActor.field71_0x164 = func_801927F8_6D2E78((index,221.0,(u16)(iVar9 << 1))*0x10;
      if ((((in_fcsr | 3) ^ 2) & 3) == 0) {
        fVar17 = ROUND(fVar17);
      }
      else {
        fVar17 = FLOOR(fVar17);
      }
      thisActor.unk_0x168 = (undefined *)(int)fVar17;
      if (false) {
        fVar16 = ROUND(fVar18);
      }
      else {
        fVar16 = FLOOR(fVar18);
      }
      iVar9 = (int)fVar16;
      if (true) {
        if (iVar9 < 0) goto l__80197430;
      }
      else {
        if (false) {
          fVar16 = ROUND(fVar18 - 2.147484e+09);
        }
        else {
          fVar16 = FLOOR(fVar18 - 2.147484e+09);
        }
        iVar9 = (int)fVar16;
        if (false) {
l__80197430:
          iVar9 = -1;
        }
      }
      fVar17 = func_801927F8_6D2E78(index,284.0,(u16)(iVar9 << 1));
      thisActor.pos.x-=0xcd;
      thisActor.pos.y-=0x128;
      thisActor.rgba.a = 0;
      thisActor.unk_0x16C = (undefined *)(int)fVar17;
      thisActor.unk_0x170=thisActor.unk_0x11C*0x10000;
    }
    else if (thisActor.actorState_b[0] != 1) {
      return;
    }
    thisActor.pos.x_w +=thisActor.unk_0x168;
    thisActor.pos.y_w += thisActor.unk_0x170;
    thisActor.unk_0x168 -=thisActor.field71_0x164;
    thisActor.unk_0x170 -= thisActor.unk_0x16C;
    thisActor.rgba.a = func_80192698_6D2D18(thisActor.rgba.a,0xff,&thisActor.unk_0x114);
    if (thisActor.unk_0x114-- <= 0.0) {
      thisActor.actorState_b[0]++;
      thisActor.pos.x = -3;
      thisActor.pos.y = -0x4c;
      thisActor.rgba.a = 0xff;
    }
    break;
  case 7:
    if (true) {
      switch(thisActor.actorState_b[0]) {
      case 0:
        thisActor.actorState_b[0]++;
        thisActor.flag2 = 9;
        thisActor.flag = ACTOR_FLAG_ACTIVE;
        thisActor.rgba.a = 0;
        thisActor.unk_0x114 = 60.0;
      case 1:
        if (thisActor.unk_0x114-- <= 0.0) {
          thisActor.actorState_b[0]++;
          thisActor.flag = ACTOR_FLAG_ENABLED;
          thisActor.pos.x = 0;
          thisActor.pos.y = 0;
          thisActor.pos.z = 0;
          thisActor.unk_0x114 = 120.0;
          thisActor.unk_0x118 = 500.0;
          SFX_Play_1(SFX_THEO_HELP1);
        }
        break;
      case 2:
        MODi(thisActor.rgba.a,0xff,8);
        thisActor.unk_0x118 = func_8019265C_6D2CDC(thisActor.unk_0x118,100000.0,&thisActor.unk_0x114);
        fVar16 = (float)((double)((ulonglong)uVar10 << 0x20) /
                        ((double)fVar16 / (double)((ulonglong)uVar22 << 0x20)));
        thisActor.scaleX = fVar16;
        thisActor.scaleY = fVar16;
        thisActor.pos.x_w = func_80192698_6D2D18(thisActor.pos.x_w,0x600000,&thisActor.unk_0x114);
        thisActor.pos.y_w = func_80192698_6D2D18(thisActor.pos.y_w,0x880000,&thisActor.unk_0x114);
        if (0.0 < thisActor.unk_0x11C) thisActor.unk_0x11C-= 1.0;
        if (thisActor.unk_0x114-- <= 0.0) {
          thisActor.actorState_b[0]++;
          thisActor.unk_0x114 = 60.0;
          thisActor.unk_0x11C = 360.0;
        }
        break;
      case 3:
        thisActor.unk_0x118 = func_8019265C_6D2CDC(thisActor.unk_0x118,1000000.0,&thisActor.unk_0x11C);;
        iVar9 = thisActor.pos.x_w;
        fVar16 = (float)(double)thisActor.unk_0x118/1000.0;
        thisActor.scaleX = fVar16;
        thisActor.scaleY = fVar16;
        thisActor.pos.x_w = func_80192698_6D2D18(thisActor.pos.x_w,0x600000,&thisActor.unk_0x114);
        thisActor.pos.y_w = func_80192698_6D2D18(thisActor.pos.y_w,0x480000,&thisActor.unk_0x114);
        if (0.0 < thisActor.unk_0x11C) thisActor.unk_0x11C--;
        if (thisActor.unk_0x114-- <= 0.0) {
          thisActor.actorState_b[0]++;
          thisActor.unk_0x114 = 120.0;
        }
        break;
      case 4:
        thisActor.unk_0x118 = func_8019265C_6D2CDC(thisActor.unk_0x118,1000000.0,&thisActor.unk_0x11C);
        fVar16 = (float)(double)thisActor.unk_0x118/1000.0;
        thisActor.scaleX = fVar16;
        thisActor.scaleY = fVar16;
        thisActor.pos.x_w = func_80192698_6D2D18(thisActor.pos.x_w,0x600000,&thisActor.unk_0x114);
        thisActor.pos.y_w = func_80192698_6D2D18(thisActor.pos.y_w,0x300000,&thisActor.unk_0x114);
        if (0.0 < thisActor.unk_0x11C) thisActor.unk_0x11C-= 1.0;
        if (thisActor.unk_0x114-- <= 0.0) {
          thisActor.actorState_b[0]++;
          thisActor.graphic = 0x182c;
          thisActor.rotateZ = 0.0;
          thisActor.scaleX = 0.1;
          thisActor.scaleY = 0.1;
          thisActor.unk_0x114 = 4.0;
          SFX_Play_1(0x140);
        }
        break;
      case 5:
        fVar16 = func_8019265C_6D2CDC(thisActor.scaleX,1.0,&thisActor.unk_0x114);
        thisActor.scaleX = fVar16;
        thisActor.scaleY = fVar16;
        thisActor.rotateZ++;
        if (thisActor.unk_0x114-- <= 0.0) {
          thisActor.actorState_b[0]++;
          thisActor.unk_0x114 = 120.0;
        }
        break;
      case 6:
        fVar16 = func_8019265C_6D2CDC(thisActor.scaleX,0.01,&thisActor.unk_0x114);
        thisActor.scaleX = fVar16;
        thisActor.scaleY = fVar16;
        thisActor.rotateZ -= 10.0;
        if ((gSceneFrames & 2) == 0) thisActor.flag |= 1;
        else thisActor.flag&=~ACTOR_FLAG_DRAW;
        if (thisActor.unk_0x114-- <= 0.0) {
          thisActor.actorState_b[0]++;
        }
      }
    }
    break;
  case 8:
    if (thisActor.actorState_b[0] == 0) {
      thisActor.actorState_b[0] = 1;
      thisActor.flag2 |= 9;
      thisActor.scaleX = 0.5;
      thisActor.scaleY = 0.5;
      thisActor.unk_0x114 = 20.0;
    }
    else if (thisActor.actorState_b[0] != 1) {
      return;
    }
    fVar16 = func_8019265C_6D2CDC(thisActor.scaleX,2.0,&thisActor.unk_0x114);
    thisActor.scaleX = fVar16;
    thisActor.scaleY = fVar16;
    thisActor.rotateZ -= 20.0;
    if (thisActor.unk_0x114-- <= 0.0) {
      thisActor.flag = ACTOR_FLAG_ACTIVE;
      thisActor.actorState_b[0]++;
    }
    break;
  case 10:
    if (thisActor.actorState_b[0] == 0) {
      thisActor.actorState_b[0] = 1;
      thisActor.unk_0x114 = 20.0;
    }
    else if (thisActor.actorState_b[0] != 1) {
      return;
    }
    if (thisActor.unk_0x114-- <= 0.0) {
      thisActor.actorState_b[0]++;
    }
    break;
  case 0xc:
    if (thisActor.actorState_b[0] == 0) {
      thisActor.actorState_b[0] = 1;
      thisActor.rgba.a = 0;
      thisActor.unk_0x114 = 60.0;
    }
    else if (thisActor.actorState_b[0] != 1) {
      return;
    }
    thisActor.rgba.a = func_80192698_6D2D18(thisActor.rgba.a,0xff,&thisActor.unk_0x114);
    if (thisActor.unk_0x114-- <= 0.0) {
      thisActor.actorState_b[0]++;
    }
    break;
  case 0xd:
    cVar11 = thisActor.actorState_b[0];
    if (cVar11 == 0) {
      thisActor.actorState_b[0] = 1;
      thisActor.unk_0x114 = 30.0;
    }
    else if (cVar11 != 1) {
      if (cVar11 != 2) {
        return;
      }
      thisActor.unk_0x154 = func_80192698_6D2D18(thisActor.unk_0x154,0x1f0000,&thisActor.unk_0x114);
      thisActor.unk_0x158 = thisActor.unk_0x154/0x10000;
      FUN_8002b82c(&DAT_8033a2b8,&DAT_80199930,0x8f,thisActor.unk_0x158,thisActor.unk_0x158,thisActor.unk_0x158);
      if (0.0 < thisActor.unk_0x114--) {
        return;
      }
      thisActor.actorState_b[0]++;
      gActors[50].actorState._b[0]++;
      return;
    }
    if (thisActor.unk_0x114-- <= 0.0) {
      thisActor.actorState_b[0]++;
      thisActor.flag2 |= 0x200;
      thisActor.palletteP = 0x80199930;
      thisActor.unk_0x154 = 0;
      thisActor.unk_0x114 = 180.0;
    }
    break;
  case 0xf:
    if (thisActor.actorState_b[0] == 0) {
      thisActor.actorState_b[0] = 1;
      thisActor.unk_0x114 = 26.0;
      thisActor.unk_0x16C = (undefined *)(int)func_801927F8_6D2E78(index,183.0,0x3c);
      thisActor.unk_0x168 = (undefined *)(int)thisActor.unk_0x11C * 65536.0;
    }
    else if (thisActor.actorState_b[0] != 1) {
      return;
    }
    thisActor.pos.x_w = thisActor.unk_0x168 + thisActor.pos.x_w;
    thisActor.unk_0x168 -=thisActor.unk_0x16C;
    if (thisActor.unk_0x114-- <= 0.0) {
      thisActor.actorState_b[0]++;
      gActors[53].actorState._b[0] = gActors[53].actorState._b[0] + 1;
    }
    break;
  case 0x13:
    cVar11 = thisActor.actorState_b[0];
    if (cVar11 == 0) {
      thisActor.actorState_b[0] = 1;
      thisActor.unk_0x114 = 60.0;
    }
    else if (cVar11 != 1) {
      if (cVar11 != 2) {
        return;
      }
      fVar16 = func_8019265C_6D2CDC(thisActor.unk_0x118,200000.0,&thisActor.unk_0x114);
      dVar15 = 0.99;
      thisActor.unk_0x118 = fVar16;

      fVar17 = thisActor.unk_0x114;
      fVar16 /=1000.0;
      thisActor.scaleX = fVar16;
      thisActor.scaleY = fVar16;
      thisActor.pos.x_w *=.99;
      thisActor.pos.y_w *=.99;
      thisActor.unk_0x114 = fVar17 - 1.0;
      if (0.0 < thisActor.unk_0x114) return;
      thisActor.actorState_b[0]++;
      return;
    }
    if (0.0 < thisActor.unk_0x114--) return;
    thisActor.actorState_b[0]++;
    thisActor.unk_0x114 = 120.0;
    thisActor.flag2 = 9;
    thisActor.unk_0x118 = 50000.0;
    switch(thisActor.graphic){
        case 0x100a: thisActor.unk_0x178 = 2;break;
        case 0x100c: thisActor.unk_0x178 = 3;break;
        case 0x1818: thisActor.unk_0x178 = 0;break;
        case 0x181a: thisActor.unk_0x178 = 1;break;
        }
    thisActor.pos.x = D_80199390_6D9A10[thisActor.unk_0x178][2];
    thisActor.pos.y = D_80199390_6D9A10[thisActor.unk_0x178][3];
    break;
  case 0x14:
    if (thisActor.actorState_b[0] == 0) {
      thisActor.actorState_b[0] = 1;
      thisActor.unk_0x138 = -2 - RNG(7);
    }
    else if (thisActor.actorState_b[0] != 1) {
      return;
    }
    if (-0x20000 < thisActor.vel.y_w) thisActor.vel.y_w -=0x2000;
    thisActor.scaleX +=0.001;
    thisActor.scaleY +=0.001;
    thisActor.rotateX +=thisActor.unk_0x138;
    thisActor.unk_0x12C =+=0.001;
    if ((((thisActor.pos.x < -0xb0) || (0xb0 < thisActor.pos.x)) ||(thisActor.pos.y < -0xb0)) || (0xb0 < thisActor.pos.y))
      thisActor.flag = 0;
    break;

  case 0x15:
#ifdef VER_JPN
    switch(thisActor.actorState_b[0]){
    case 0:
      thisActor.actorState_b[0] = 1;
      thisActor.flag2 = 0x3005;
      thisActor.scaleX = 1.0;
      thisActor.scaleY = 1.0;
      thisActor.unk_0x12C = 1.0;
      thisActor.unk_0x17C = PTR_ARRAY_800d74a0[thisActor.unk_0x158 + 0x10];
      break;
    case 1:
      thisActor.rotateY += 43.0; //spin the letters around
      if (thisActor.unk_0x150-- < 1) {
        thisActor.actorState_b[0]++;
        thisActor.rotateY = 0.0;
        if (index == 0x68) gActors[50].actorState_b[0]++;
      }
      break;
    }
#else
    cVar11 = thisActor.actorState_b[0];
    if (cVar11 == 0) {
      thisActor.actorState = 1;
      thisActor.flag2 = 0x3005;
      thisActor.flag &=~1; //the letters are invisible.
      cVar11 = 1;
      thisActor.scaleX = 1.0;
      thisActor.scaleY = 1.0;
      thisActor.unk_0x12C = 1.0;
      thisActor.unk_0x17C = PTR_ARRAY_800d74a0[thisActor.unk_0x158 + 0x10];
    }
    else if (cVar11 == 1) {
      thisActor.actorState_b[0]++;
      thisActor.rotateY = 0.0;
      if (index == 0x68) gActors[50].actorState_b[0]++;
    }
#endif	
  }
  return;
}
#else
extern void func_80197224_6D78A4(uint16_t index);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80197224_6D78A4.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80198274_6D88F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_801987F0_6D8E70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_8019897C_6D8FFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs1/intro/func_80198B18_6D9198.s")
