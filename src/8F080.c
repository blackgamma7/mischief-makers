#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008E480.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008E790.s")

void func_8008E918(uint16_t index){
    func_80081790(index,&D_800E8BEC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008E948.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008EA4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008EB44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008EBF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008ECDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008EDB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008EEF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008EFA8.s")

uint32_t func_8008F094(uint16_t index,uint16_t dmg){
    thisActor.health-=dmg;
    if(thisActor.health&0x8000)thisActor.health=0;
    return func_8008EFA8(index);
}

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008F108.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008F168.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008F220.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008F294.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008F2E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008F498.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008F734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008F7E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008FA50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008FB20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008FD08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80090064.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800902B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80090558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800907E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80090A88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80090BFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80090CDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80090F48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80091158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800911D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80091300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800913C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80091524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8009159C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80091664.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800918D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800919C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80091BDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80091C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80091D28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80092028.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80092114.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800922D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800923C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800924F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800925D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80092660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800929B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80092E30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80092F2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80092FD4.s")
#ifdef NON_MATCHING
uint32_t func_800930AC(uint16_t x){
    //should push/pop RA. like several other funcs...
    uint32_t ret =func_80092FD4(x);
    if(ret) ret = func_8005DFC8(0);
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800930AC.s")
#endif
void func_800930E4(uint32_t x){}
//displays Calina's Henshin text
#pragma GLOBAL_ASM("asm/nonmatchings/8F080/CalinaChange_PrintText.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800931CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80093274.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8009333C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80093410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8009349C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8009351C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800935B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80093654.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80093704.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80093C10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80093D38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80094C5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80094CF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80094D84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80094E10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80094EB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80094F24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80094FE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800955F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/ActorTick_CalinaDialouge.s")

void CalinaChange_WandSpin(uint16_t index){
    thisActor.unk_0x118+=thisActor.unk_0x114;
    if(thisActor.unk_0x118>360){
        thisActor.unk_0x118-=360;
        SFX_Play_2(0x116); //dash sound
        }
}

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/ActorTick_CalinaChange.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80095FC8.s")

void func_80096058(uint16_t index){
  func_800819A8(index,&D_800E9414);
  func_800817D8(index,3,4);
  func_800817D8(index,5,4);
  func_800817D8(index,9,4);
  func_800817D8(index,0xb,4);
  gActors[index + 7].scaleY = 0.5;
  gActors[index + 0xd].scaleY = 0.5;
}
//#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80096058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80096104.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800962C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80096478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8009672C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8009685C.s")

void func_800968EC(uint16_t x){
    func_800819A8(x, D_800E9654);
}

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8009691C.s")

void func_800969CC(uint16_t x){
    func_80090558(x);
}

void func_800969F4(uint16_t x){}

void func_800969FC(uint16_t x){}

void func_80096A04(uint16_t x){}

void func_80096A0C(uint16_t x){}

void func_80096A14(uint16_t x){}

void func_80096A1C(uint16_t index) {
    gActors[index + 1].unk_0xD8 = 1;
    func_8008FB20(index);
}

void func_80096A70(uint16_t index) {
    gActors[index + 1].unk_0xD8 = 2;
    func_8008FD08(index);
}

void func_80096AC4(uint16_t index) {
    gActors[index + 1].unk_0xD8 = 3;
    func_80090064(index);
}

void func_80096B18(uint16_t index) {
    gActors[index + 1].unk_0xD8 = 5;
    func_800902B0(index);
}
