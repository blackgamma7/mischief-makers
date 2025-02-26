#include "common.h"

void ActorTick_15(uint16_t x) {}
void ActorTick_16(uint16_t x) {}
void func_8008C4B0(uint32_t x, uint32_t y, uint32_t z) {}
void func_8008C4C0(uint16_t x) {}
void func_8008C4C8(uint16_t x) {}
void func_8008C4D0(uint16_t x) {}
void func_8008C4D8(uint16_t x) {}

void func_8008C4E0(uint16_t index) {
    thisActor.rgba.b = 0;
    thisActor.rgba.g = 0;
    thisActor.rgba.r = 0;
    gPlayerManager.unk_0x40_w = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/func_8008C528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/func_8008C710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/func_8008CA90.s")
#ifdef NON_MATCHING
void func_8008CC00(void){
    D_800BE5F4._w=5;    
    gPlayerActor.pos.x=gActors[16].pos.x;
    gPlayerActor.pos.y=gActors[16].pos.y;
    gPlayerPosXMirror._hi = gScreenPosCurrentX._hi+ gActors[16].pos.x;
    gPlayerPosYMirror._hi = gScreenPosCurrentY._hi+ gActors[16].pos.y;
    gPlayerActor.flag= gPlayerActor.flag & ~0x20 | gActors[16].flag & 0x20;
    D_800D294C=0;
    gActors[16].flag=0;
    gActors[16].actorState=0;
    
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/func_8008CC00.s")
#endif
#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/func_8008CC90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/func_8008CDC4.s")

void func_8008CF10(uint16_t index){
    thisActor.hitboxBY0=8;
    thisActor.hitboxBY1=-14;
    thisActor.hitboxBX0=-8;
    thisActor.hitboxBX1=8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/func_8008CF60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/func_8008CFE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/func_8008D0A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/func_8008D128.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/func_8008D1E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/func_8008D2B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/func_8008D320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/func_8008D39C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/func_8008D418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/func_8008D480.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/func_8008D510.s")

void func_8008D728(uint16_t x){}

#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/func_8008D730.s")

void func_8008D958(uint16_t x){}

void func_8008D960(uint16_t index){
    if(func_8008D418(index)==0)func_8008CF10(index);
}
void func_8008D99C(uint16_t index){
    if(func_8008D418(index)==0){
        func_8008CF10(index);
        if(thisActor.unk_0x118==0x0)func_8008CF60(index);
        }
}

uint32_t func_8008DA24(uint16_t arg0) {
    return func_8008D480(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/func_8008DA4C.s")

void StartContinueMode(uint16_t index) {
    if (gGameState == GAMESTATE_GAMEPLAY) {
        thisActor.flag = 0;
        thisActor.actorState = 0;
        gGameState = GAMESTATE_CONTINUE;
        gGameSubState = 0;
        thisActor.vel.x_w = 0;
        thisActor.vel.y_w = 0;
        thisActor.vel.z_w = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/Check_For_Player_Death.s")

void func_8008DE20(uint16_t x){}

void func_8008DE28(uint16_t x){}

void func_8008DE30(uint16_t index){
    Actor* actorp;
    SFX_Stop(SFX_MARINA_OW1);
    SFX_Stop(SFX_MARINA_YELL1);
    actorp = &thisActor;
    if(actorp->vel.y_w>-0x68000) actorp->vel.y_w-=0x3200;
    if(actorp->pos.y<-0x100) actorp->actorState=64;
}

void func_8008DEBC(uint16_t index){
    if(0x60<D_800D28E4) thisActor.flag = 0;
    else D_800D28FC |= 0x200;
}

#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/func_8008DF20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/func_8008E1A0.s")
//Version of Marina when she hits the boulder in "Rolling Rock"
void ActorSpawn_MarinaOhNo(uint16_t index, uint16_t unk){
    D_800BE5F4._w=4;
    if(index==0)index=16; //don't overwrite player actor
    ACTORINIT(index,ACTORTYPE_MARINAOHNO);
    thisActor.flag=2;
    thisActor.pos.x=gPlayerActor.pos.x;
    thisActor.pos.y=gPlayerActor.pos.y;
    thisActor.vel.x_w=gPlayerActor.vel.x_w/2;
}

#ifdef NON_MATCHING
void ActorTick_MarinaOhNo(uint16_t index){
    Actor* actor= &thisActor;
    D_800BE5F4._w=4;
    func_8008DF20(index);
    if(actor->actorState==16){
        D_800BE5F4._w=4;
        actor->actorState=0x30;
        actor->palletteP=D_800D46A8;
        actor->vel.y_w=0x20000;
        actor->unk_0x118=1.0;
    }
    SFX_Stop(SFX_MARINA_OW1);
    SFX_Stop(SFX_MARINA_YELL1);
    SFX_Play_1(SFX_MARINA_OHNO); //...thus the name

}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/8D0A0/ActorTick_MarinaOhNo.s")
#endif