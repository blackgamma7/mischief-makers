#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A6900_76FDD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A6B24_76FFF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A6D14_7701E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A7004_7704D4.s")
#ifdef NON_MATCHING
//one of the gunships in "clnce war"
void func_801A7240_770710(uint16_t index){
    Actor* actorp;
    
    func_80078418(index);
    actorp=&thisActor;
    switch(actorp->actorState){
        case 0:
         actorp->actorState=0x20;
         break;
        case 0x21:
        {
          if ((gViptoActorFlags & 0x30000)&&((func_80029B00(0x80,0x80,-0x80)) && ((gSceneFrames & 0xf) == 0)))
            actorp->gp0._w |= 0x8000;
          if (gSceneFrames & 0x100)
            actorp->unk_0x184._w = actorp->unk_0x174 - 0x50;
          else
            actorp->unk_0x184._w = actorp->unk_0x174 + 0x50;
          break;
        }
        case 0x20:
         break;
    }
    actorp->flag3&=~0x200600;
}
#else
extern void func_801A7240_770710(uint16_t index);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A7240_770710.s")
#endif


void func_801A735C_77082C(uint16_t x){
    func_80078418(x);
}

void func_801A7384_770854(uint16_t x){
    func_80078418(x);
}

void func_801A73AC_77087C(uint16_t x){
    func_80078418(x);
}


#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A73D4_7708A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A748C_77095C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A7658_770B28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A788C_770D5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A7B04_770FD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A7D54_771224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A7E58_771328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A8088_771558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A80B0_771580.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A80D8_7715A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A8204_7716D4.s")

void func_801A837C_77184C(uint16_t x){}

void func_801A8384_771854(uint16_t x){}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A838C_77185C.s")
//generates the surfing missle's fire
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A85E0_771AB0.s")
//surfing missle
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A88C8_771D98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A8FE4_7724B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A9064_772534.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A916C_77263C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A951C_7729EC.s")

void func_801A9604_772AD4(uint16_t x) {
    Actor_ModVelX(x, 0x8000);
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A9630_772B00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A96DC_772BAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A9734_772C04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A9788_772C58.s")

uint32_t func_801A97D8_772CA8(uint16_t x, uint16_t y){return 0;}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A97E8_772CB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A9900_772DD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A9974_772E44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A9B80_773050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A9CC8_773198.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801A9E6C_77333C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801AA034_773504.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801AA154_773624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801AA2B0_773780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801AAA8C_773F5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801AAC54_774124.s")

uint16_t func_801AACFC_7741CC(void) {
    return Actor_GetInactive(0x70, 0x88);
}
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801AAD20_7741F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World3/func_801AAD54_774224.s")
