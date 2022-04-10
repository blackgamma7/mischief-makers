#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80082380.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80082820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80082CFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80082E04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80082F10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_8008310C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80083140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_800831D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80083358.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80083454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80083488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80083518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_800836A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_8008379C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80083810.s")

#ifdef NON_MATCHING
void func_80083878(int16_t x, int16_t y){
    if(y<3) func_80083140(x,y);
    else func_80083488(x,y-3);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80083878.s")
#endif