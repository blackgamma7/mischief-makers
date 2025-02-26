

#include "common.h"

void ActorTick_0(uint16_t x){}

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/ActorTick_3DIcon.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800612D8.s")
/*
void func_80061350(uint16_t index){
    if(index==ACTOR_COUNT0){
        MODi(gActors[ACTOR_COUNT0].rgba.r,0,4);
        MODi(gActors[ACTOR_COUNT0].rgba.g,0,4);
        MODi(gActors[ACTOR_COUNT0].rgba.b,0,4);
        MODi(gActors[ACTOR_COUNT0].rgba.a,0x60,4);
    }
    else{
        thisActor.rgba.r = gActors[ACTOR_COUNT0].rgba.r;
        thisActor.rgba.g = gActors[ACTOR_COUNT0].rgba.g;
        thisActor.rgba.b = gActors[ACTOR_COUNT0].rgba.b;
        thisActor.rgba.a = gActors[ACTOR_COUNT0].rgba.a;
    }
}*/
#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80061350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80061450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800614D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80061554.s")
void func_800615BC(uint16_t index){
    if(--thisActor.rgba.a==0){
        thisActor.flag &= ~1;
        thisActor.actorState-=2;
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80061624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80061E98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800623C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_8006242C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_8006275C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_8006291C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800629A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062A34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062AC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062B4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062CB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062E1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062F84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800630E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800631A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80063258.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_8006330C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800633C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80063418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_8006346C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80063FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800640A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800641CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80064328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800643CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80064528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800645F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_8006475C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800648C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/ActorSpawn_StageClear.s")
//"stage clear" fanfare behavior ?
#pragma GLOBAL_ASM("asm/nonmatchings/61B80/ActorTick_StageClear.s")
//actor "parented" to next index. spawns item when "parent" is killed. (i.e. Yellow Gem in "Meet Marina")
#pragma GLOBAL_ASM("asm/nonmatchings/61B80/ActorTick_ItemSpawn.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80064EB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80064F4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80065178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80065218.s")
//Ms. hint's behavior?
#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80065270.s")
