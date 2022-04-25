#include "common.h"
//funcs related to the dialouge/textbox system
#pragma GLOBAL_ASM("asm/nonmatchings/Textbox/func_8005DE30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/Textbox/func_8005DEFC.s")

int16_t func_8005DF30(){return D_801783F8[0];}

void func_8005DF40(int16_t x, int16_t y){
    D_801783F4=x,D_801783F6=y;
}

#pragma GLOBAL_ASM("asm/nonmatchings/Textbox/func_8005DF5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/Textbox/func_8005DFC8.s")
#ifdef NON_MATCHING
void func_8005E09C(int32_t i,int16_t x){
    D_801783F8[i]=x; //regalloc, original doesn't push a1
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/Textbox/func_8005E09C.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/Textbox/func_8005E0B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/Textbox/func_8005E1CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/Textbox/func_8005E260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/Textbox/func_8005E56C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/Textbox/func_8005E8F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/Textbox/func_8005EC20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/Textbox/func_8005EE24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/Textbox/func_8005F088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/Textbox/func_8005F6D4.s")