#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B0900_7B3FE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B0A8C_7B416C.s")
#ifdef NON_MATCHING
void func_801B0BA0_7B4280(uint16_t x){
  ACTORINIT(50,0x1A08);
  gActors[50].flag|=8;
  gActors[50].pos.x=0;
  gActors[50].pos.y=0;
  gActors[50].unk_0x178._w=0x801b43cc; //some float array
}
#else
extern void func_801B0BA0_7B4280(uint16_t x);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B0BA0_7B4280.s")
#endif

void func_801B0C00_7B42E0(u16 index,s16 posx,s16 posy,s32 velx,s32 vely){
  ACTORINIT(index,0xE01);
  if (Rand() >= 86) thisActor.unk_0x110 = 1.0;
  else thisActor.unk_0x110 = 0.0;
  thisActor.pos.x = posx;
  thisActor.pos.y = posy;
  thisActor.vel.x_w = velx;
  thisActor.vel.y_w = vely;
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B0CB4_7B4394.s")
extern void func_801B0DA0_7B4480(uint16_t);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B0DA0_7B4480.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B0E24_7B4504.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B0EB8_7B4598.s")

void func_801B0F38_7B4618(uint16_t other, uint16_t index){
  ACTORINIT(index,0x1A09);
  thisActor.unk_0x190=func_801B0DA0_7B4480;
  if(gActors[other].flag&0x20)thisActor.vel.x_w=-0x1C000;
  else thisActor.vel.x_w=0x1C000;
  thisActor.vel.y_w=-0x20000;
}

#ifdef NON_MATCHING
void func_801B0FFC_7B46DC(uint16_t x){ //stack mismatch?
  ACTORINIT(63,0x18);
  gActors[63].pos.x = 600 - gScreenPosCurrentX._hi;
  gActors[63].pos.y = 0x60;
  gActors[63].pos.z = 0;
}
#else
extern void func_801B0FFC_7B46DC(uint16_t x);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B0FFC_7B46DC.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B1054_7B4734.s")

void func_801B1180_7B4860(uint16_t x){
  func_801B0FFC_7B46DC(x);
}

#ifdef NON_MATCHING
void func_801B11A8_7B4888(uint16_t x){
  func_8007CD68(106,0,0,0x48,0,2,99);
  gActors[106].pos.z=8;
  gActors[106].unk_0x158._w=0x3B;
}
#else
extern void func_801B11A8_7B4888(uint16_t x);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B11A8_7B4888.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B1200_7B48E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B147C_7B4B5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B1548_7B4C28.s")

void func_801B1694_7B4D74(uint16_t index){
    if(thisActor.unk_0x154._w<gActors[110].unk_0x158._w)thisActor.unk_0x154._w=gActors[110].unk_0x158._w;
}

void func_801B16E8_7B4DC8(uint16_t x){
  D_800D28E8=0;
  D_800D28F0=0x32;
  D_800D28E4=0x62;
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B1710_7B4DF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B1980_7B5060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B1A30_7B5110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B1AF4_7B51D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B1C0C_7B52EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B1D24_7B5404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B1E3C_7B551C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B1F54_7B5634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B206C_7B574C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B2184_7B5864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B229C_7B597C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B23B4_7B5A94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B2530_7B5C10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B2628_7B5D08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B2938_7B6018.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B2AC0_7B61A0.s")

void func_801B2BA0_7B6280(uint16_t index){
  thisActor.hitboxBY0 = 6;
  thisActor.hitboxBY1 = -6;
  thisActor.hitboxBX0 = -6;
  thisActor.hitboxBX1 = 6;
}

void func_801B2BEC_7B62CC(uint16_t index){
  if(thisActor.vel.y_w>-0x80000)thisActor.vel.y_w-=0x3000;
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B2C40_7B6320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B2D44_7B6424.s")

uint32_t func_801B2DF8_7B64D8(uint16_t index){
    if (thisActor.flag3 & 0x200) {
    thisActor.actorState = 2;
    thisActor.flag = 0x20003;
    thisActor.vel.x_w = 0;
    thisActor.vel.y_w = 0;
    thisActor.unk_0x154._w = 0;
    return 1;
  }
  return 0;
}

#ifdef NON_MATCHING
void func_801B2E68_7B6548(uint16_t index){
  int16_t x=gScreenPosCurrentX._hi+thisActor.pos.x;
  if((x<0x100)||(0x350<x)) thisActor.flag=0;
}
#else
extern void func_801B2E68_7B6548(uint16_t index);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B2E68_7B6548.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B2ED4_7B65B4.s")

void func_801B3158_7B6838(uint16_t index){
  thisActor.hitboxBY0 = 10;
  thisActor.hitboxBY1 = -0xe;
  thisActor.hitboxBX0 = -8;
  thisActor.hitboxBX1 = 8;
}

void func_801B31AC_7B688C(uint16_t index){
    if(-0x80000<thisActor.vel.y_w) thisActor.vel.y_w-=0x3000;
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B3200_7B68E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B32CC_7B69AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B337C_7B6A5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B33F0_7B6AD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B3538_7B6C18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B373C_7B6E1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B37FC_7B6EDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B3AD8_7B71B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B3B2C_7B720C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B3BBC_7B729C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival3/func_801B41F8_7B78D8.s")
