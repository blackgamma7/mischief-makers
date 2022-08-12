#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80083FB0.s")
#ifdef NON_MATCHING
void func_800840A4(uint16_t index){
    if (thisActor.unk_0x178._p) {
      thisActor.unk_0x17C._w++;
      if (0x2cf < thisActor.unk_0x17C._w) thisActor.flag = 0;
      if ((0x21b < thisActor.unk_0x17C._w) && (thisActor.unk_0x17C._w & 4)) thisActor.rgba.a = 0;
      else thisActor.rgba.a = 0xff;
  }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800840A4.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008412C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800842AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800843E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800844B8.s")

uint32_t func_800846A8(uint16_t index){
      if ((thisActor.vel.y_w < 1) && (thisActor.flag3&0x20)) {
    thisActor.actorState = 1;
    thisActor.flag &=~0x20000;
    thisActor.flag |= 0x10000;
    thisActor.vel.x_w = 0;
    thisActor.vel.y_w = 0;
    return 1;
  }
  return 0;
}


#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80084734.s")

void func_8008486C(uint16_t x) {
    func_800846A8(x), func_80084734(x);
}
#ifdef NON_MATCHING
void func_800848A0(uint16_t index){
    if(thisActor.flag3&0x200){
        thisActor.actorState=2;
        thisActor.flag= 0x20003;
        thisActor.vel.x_w=0;
        thisActor.vel.y_w=0;
        SFX_ActorPanX(0x2f,index);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800848A0.s")
#endif
#ifdef NON_MATCHING
void func_80084924(uint16_t index){
  thisActor.hitboxBX1 = 4;
  thisActor.hitboxBY0 = 12;
  thisActor.hitboxBY1 = -4;
  thisActor.hitboxBX0 = -4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80084924.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80084974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80084D18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80084E7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80084F38.s")

uint32_t func_80085108(uint16_t index){
    if((thisActor.vel.y_w<1)&&(thisActor.flag3&0x20)){
        thisActor.actorState=1;
        thisActor.flag&= ~0x20000;
        thisActor.flag|=0x10000;
        thisActor.vel.x_w=0;
        thisActor.vel.y_w=0;
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085194.s")

void func_800852CC(uint16_t x){
    func_80085108(x);
    func_80085194(x);
}

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085300.s")

void func_80085350(uint16_t index){
    if(thisActor.flag3&0x200){
        thisActor.actorState=2;
        thisActor.flag= 0x20003;
        thisActor.vel.x_w=0;
        thisActor.vel.y_w=0;
        SFX_ActorPanX(0x2f,index);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800853C8.s")

//start of Clanbomb funcs?
#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085844.s")

#ifdef NON_MATCHING
void Actor_Clanbomb_TickFuse(uint16_t index,uint16_t time){
 thisActor.unk_0x168._w-=time;
 if(thisActor.unk_0x168._w<1) func_800859C4(index);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/Actor_Clanbomb_TickFuse.s")
#endif

void func_800859C4(uint16_t index){
  thisActor.flag = 0x82;
  thisActor.health = 0;
  func_80085D00(index);
  thisActor.vel.x_w = 0;
  thisActor.vel.y_w = 0;
  thisActor.actorState = 4;
  thisActor.unk_0x168._w = 0;
  SFX_ActorPanX(0x43,index);
}

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085A4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085BAC.s")
extern float D_800E3DBC[8];
#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085D00.s")

void func_80085E60(uint16_t index){
    float f=D_800E3DBC[thisActor.unk_0xD8];
    thisActor.scaleX=f;
    thisActor.scaleY=f;
}

extern uint32_t D_800E3DE4[8][2];
#ifdef NON_MATCHING
void func_80085EB0(uint16_t index){
    thisActor.speedX._w=D_800E3DE4[thisActor.unk_0xD8][0];
    thisActor.speedY._w=D_800E3DE4[thisActor.unk_0xD8][1];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085EB0.s")
#endif

extern int32_t D_80182020[64];
void func_80085F08(uint16_t index){
    uint16_t i;
    for(i=0;i<64;i++) {
        D_80182020[i]=-1;
        }
    thisActor.unk_0x174=0;
    thisActor.unk_0x178._w=0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085F78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008603C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800860FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800862CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80086360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800865BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80086790.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80086824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80086900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80086A20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80086B74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/ActorTick_Clanbomb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80087568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80087698.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80087820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80087B4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80087BDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80087D2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80087EAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80088010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80088164.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800882E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80088408.s")

void func_80088518(uint16_t index){
    thisActor.unk_0x15C=0x3000;
    thisActor.vel.x_w=thisActor.unk_0x160._w;
}

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008855C.s")

void func_800886E0(uint16_t index){
    thisActor.flag2|=0x800;
}

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80088720.s")
void func_800887B0(uint16_t index){
    thisActor.flag|=0x1780;
}

void func_800887F0(uint16_t index){
    thisActor.flag&=~0x1780;
}

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80088834.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80088944.s")
#ifdef NON_MATCHING
void func_80088A54(uint16_t index){
  uint8_t c;
  if (thisActor.unk_0x158._w != 0) {
    thisActor.flag2&= ~0x10;
    return;
  }
  thisActor.flag2|= 0x10;
  if (0x2000000 < thisActor.unk_0x15C) {
    thisActor.rgba.r = 0;
    thisActor.rgba.g = 0;
    thisActor.rgba.b = 0;
    return;
  }
  if (0x1000000 < thisActor.unk_0x15C) {
    thisActor.unk_0x15C = 0x2000000 - thisActor.unk_0x15C;
  }
  c = (thisActor.unk_0x15C >> 0x11);
  thisActor.rgba.r = c;
  thisActor.rgba.g = c;
  thisActor.rgba.b = c;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80088A54.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80088B08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80088CB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80088E38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80088E90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80089084.s")

void func_800891EC(u16 index) {
    Actor* actorp;
    uint16_t other = func_8003123C(&gGraphicListDefault, thisActor.pos.x, thisActor.pos.y + 0xC, thisActor.pos.z + 1);
    if (other) {
        actorp = &gActors[other];
        actorp->graphic = 0x16E;
        actorp->vel.x_w = -0x200;
        actorp->unk_0x154._w = -4;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80089298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80089418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800896AC.s")
//spawns the actor when digging
#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/DiggingSpot_SpawnActor.s")
extern uint32_t* D_800E4440[6]; //common loot pools for digging spots.

//check if "digging spot" actor has unique loot or an index to the above.
#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/DiggingSpot_SpawnPoolCheck.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80089A10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80089EF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008A0F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008A32C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008A41C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008A50C.s")

//behavior for digging spots?
#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008A6E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008AA28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008AB68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008AD3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008AE78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008AF04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008AFE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008B284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008B438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008B548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008B654.s")
void func_8008B7CC(uint16_t index){
    if(((thisActor.unk_0x164._w&gSceneFrames)==0)&&(thisActor.unk_0x16C._w==0))
      thisActor.unk_0x16C._w=1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008B830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008B9FC.s")
//Actor 0x5C spawn
#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008BB64.s")
//Actor 0x5C tick
#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008BC5C.s")

void func_8008BFB0(void) {
    u16 i;
    for(i=0;i<4;i++)
     D_801826A0[i]=0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008BFE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008C038.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008C120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008C304.s")
