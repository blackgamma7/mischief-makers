#include "festival.h"
#include "GameSave.h"

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B0900_7AC820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B0C38_7ACB58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B0CD4_7ACBF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B0D5C_7ACC7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B0ECC_7ACDEC.s")


void func_801B0EF0_7ACE10(uint16_t x){
  gFestivalStructs[1].unk_0x12=0;
  gFestivalStructs[1].unk_0x10=0;
}

#ifdef NON_MATCHING
uint16_t func_801B0F08_7ACE28(uint16_t x){
 uint16_t index=Actor_GetInactive(0x60,0x70);
 if(index){
   ACTORINIT(index,0x1A07);
   thisActor.gFlag=0x801;
   thisActor.flag=ACTOR_FLAG_ACTIVE|ACTOR_FLAG_UNK3;
 }
 return index;
}
#else
extern uint16_t func_801B0F08_7ACE28(uint16_t x);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B0F08_7ACE28.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B0F8C_7ACEAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B102C_7ACF4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B10D8_7ACFF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B1194_7AD0B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B13C4_7AD2E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B14FC_7AD41C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B15C8_7AD4E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B1638_7AD558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B169C_7AD5BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B17C0_7AD6E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B1828_7AD748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B1850_7AD770.s")
void func_801B195C_7AD87C(uint16_t x){
    gActors[111].palletteP=&D_800D9AE4;
}

void func_801B1974_7AD894(uint16_t i){
    uint16_t index;
    switch(gActors[i].gp3._w){
      case 0:
      index=0x6B;break;
      case 1:
      index=0x6D;break;
      case 2:
      index=0x6A;break;
      case 3:
      index=0x6C;break;
    }
    thisActor.palletteP=&D_800D9AE4;
}

void func_801B1A18_7AD938(uint16_t i){
    uint16_t index;
    switch(gActors[i].gp3._w){
      case 0:
      index=0x6B;break;
      case 1:
      index=0x6D;break;
      case 2:
      index=0x6A;break;
      case 3:
      index=0x6C;break;
    }
    if (gSceneFrames & 0x10) thisActor.palletteP=&D_800D9B54;
    else thisActor.palletteP=NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B1ADC_7AD9FC.s")
float D_801B73B4_7B32D4[]={2.0,0.0,-21.0,180.0,0.0,0.0,0.0,3.0,1.0,1.0,448.0,1.0,1.0,1.0,60.0,0.0};
#ifdef NON_MATCHING
void func_801B1BC4_7ADAE4(uint16_t x){
    ACTORINIT(63,0x1A08);
    gActors[63].flag|=ACTOR_FLAG_UNK3;
    gActors[63].pos.x=gActors[63].pos.y=0;
    gActors[63].unk_0x178._p=D_801B73B4_7B32D4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B1BC4_7ADAE4.s")
#endif
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B1C24_7ADB44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B1CF0_7ADC10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B1DDC_7ADCFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B1EB4_7ADDD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B1F80_7ADEA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B1FC8_7ADEE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B2058_7ADF78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B20A0_7ADFC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B20F8_7AE018.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B2180_7AE0A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B2208_7AE128.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B2290_7AE1B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B242C_7AE34C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B259C_7AE4BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B2720_7AE640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B2C20_7AEB40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B2CAC_7AEBCC.s")

void func_801B2F50_7AEE70(uint16_t x){}
void func_801B2F58_7AEE78(uint16_t x){}
void func_801B2F60_7AEE80(uint16_t x){}
void func_801B2F68_7AEE88(uint16_t x){}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B2F70_7AEE90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B3104_7AF024.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B3248_7AF168.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B326C_7AF18C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B3798_7AF6B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B3874_7AF794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B3A04_7AF924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B3AE8_7AFA08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B3B84_7AFAA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B3D68_7AFC88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B3D84_7AFCA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B3EDC_7AFDFC.s")
#ifdef NON_MATCHING
uint16_t func_801B4048_7AFF68(uint16_t c){
    if(c==10) c=62;
    return ALPHAINDEX(c);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B4048_7AFF68.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B407C_7AFF9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B420C_7B012C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B42C0_7B01E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B4504_7B0424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B45A0_7B04C0.s")
uint8_t D_801B75A8_7B34C8[]={0,1,2,30,1,225,0,3,0,115,0,9,0,1,2,152,1,128,0,3,0,60,0,0};
#ifdef NON_MATCHING
void func_801B4600_7B0520(uint16_t x){
    ACTORINIT(112,0x1A07);
    gActors[112].flag=2;
    gActors[112].pos.x=560-gScreenPosCurrentX._hi;
    gActors[112].pos.y=480-gScreenPosCurrentY._hi;
    gActors[112].pos.z=-2;
    gActors[112].gp0._w=64;
    gActors[112].unk_0x174=(uint32_t)D_801B75A8_7B34C8;
}
#else
void func_801B4600_7B0520(uint16_t x);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B4600_7B0520.s")
#endif
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B469C_7B05BC.s")
//memcpy, but len is u16.
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B47DC_7B06FC.s")
//sum of 3 nums = ?
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B4818_7B0738.s")
//product of 2 = ?
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B49B8_7B08D8.s")
//sum of 2 = ?
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B4B80_7B0AA0.s")
//picks the math question.
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B4CB0_7B0BD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B4DF8_7B0D18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B4E94_7B0DB4.s")
#ifdef NON_MATCHING
void func_801B4EFC_7B0E1C(uint16_t x){
  gFestivalStructs[0].unk_0x04 = 1;
  gFestivalStructs[1].unk_0x04 = 2;
}
#else
extern void func_801B4EFC_7B0E1C(uint16_t x);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B4EFC_7B0E1C.s")
#endif

void func_801B4F1C_7B0E3C(uint16_t x){
gFestivalTimeToBeat = gFestivalRecords[gFestivalCurrentEvent];
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B4F44_7B0E64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B5064_7B0F84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B519C_7B10BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B52B4_7B11D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B53CC_7B12EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B54DC_7B13FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B5630_7B1550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B5A3C_7B195C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B5C38_7B1B58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B5CA8_7B1BC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B5D2C_7B1C4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B5FFC_7B1F1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B6128_7B2048.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B6158_7B2078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B6214_7B2134.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B62E4_7B2204.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B63B0_7B22D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B649C_7B23BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B6574_7B2494.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B6640_7B2560.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B6688_7B25A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B6718_7B2638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B6760_7B2680.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B67B8_7B26D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B6840_7B2760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B69BC_7B28DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B6AD4_7B29F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B6B24_7B2A44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B6BB4_7B2AD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs4/Festival2/func_801B71F4_7B3114.s")
