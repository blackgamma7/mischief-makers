#include "common.h"

void func_80047E30(uint16_t x){}
#ifdef NON_MATCHING
void func_80047E38(uint16_t x){
    uint16_t mask;
    gMarinaButtonHold= gPlayerManager.buttonHold._lo;
    gMarinaButtonHold= gPlayerManager.buttonPress._lo;
    mask=gButton_DLeft + gButton_DRight + gButton_DUp + gButton_DDown + gButton_B + gButton_A;
    gInputHistoryHold[0]= gPlayerManager.buttonHold._lo & mask;
    gInputHistoryPress[0]= gPlayerManager.buttonPress._lo & mask;
    gPlayerManager.buttonHold._w=0;
    gPlayerManager.buttonPress._w=0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/48A30/func_80047E38.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/48A30/func_80047ED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/48A30/func_80047F80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/48A30/func_80047FF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/48A30/func_800480B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/48A30/func_80048238.s")

#pragma GLOBAL_ASM("asm/nonmatchings/48A30/func_80048320.s")

void func_800483B4(uint16_t index){
    if(thisActor.actorState_b[1]==3)thisActor.gp0._w=600;
    D_800BE5F4._w=1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/48A30/func_80048408.s")

#pragma GLOBAL_ASM("asm/nonmatchings/48A30/func_800485AC.s")
