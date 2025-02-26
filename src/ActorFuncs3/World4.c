#include "common.h"
#define TeranActor gActors[48]
#define JumpCount gp4._w
#define JumpDelay gp5._w

#define ACTORTYPE_TERANPLAYER 0X1D02
#define ACTORTYPE_TERANCOUNT 0X1D04
//loaded during Teran's rescue stages
void func_801A6900_7754F0(int32_t arg0) {}
/*
void func_801A6908_7754F8(uint16_t index, uint8_t arg1) {
    uint16_t i;

    if (thisActor.pos.y) {}

    for (i = 0; i < 7; i++) {
        func_80012044(thisActor.pos.x, thisActor.pos.y + D_801AFE90[i], arg1);
    }
}*/

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A6908_7754F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A69CC_7755BC.s")

void func_801A6CB0_7758A0(void) {
    uint8_t a = ModInRange_i(gActors[50].rgba.a, 0xFF, 1);
    uint64_t rgb = (0xFF - a) / 2; // why does this match??

    gActors[50].rgba.a = a;
    gActors[50].rgba.r = rgb;
    gActors[50].rgba.g = rgb;
    gActors[50].rgba.b = rgb;
}


#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A6D10_775900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A7500_7760F0.s")


#ifdef NON_MATCHING
void func_801A7620_776210(uint16_t index) {

    if ((FACINGLEFT(index) && (gButtonHold & gButton_DRight)) 
     || (FACINGRIGHT(index) && (gButtonHold & gButton_DLeft))) {
        thisActor.flag ^= ACTOR_FLAG_FLIPPED;
    }

    thisActor.unk_0x148 = thisActor.scaleX * 1.0f;

    IFFACINGLEFT(index) {
        thisActor.unk_0x148 = -thisActor.unk_0x148;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A7620_776210.s")
#endif

#ifdef NON_MATCHING
// Differences are regalloc, and some instruction order
void func_801A76DC_7762CC(uint16_t index) {
    if ((gButtonHold & gButton_DRight) != 0 || (gButtonHold & gButton_DLeft) != 0) {
        IFFACINGLEFT(index) {
            // Is this an oversight?
            if (gButtonHold & gButton_DRight != 0) {}
            thisActor.actorState = 0x60;
        }
        else {
            if ((gButtonHold & gButton_DLeft) != 0) {
                thisActor.actorState = 0x60;
            }
        }
    }
    else {
        thisActor.actorState = 0x60;
    }
}
#else
extern void func_801A76DC_7762CC(uint16_t);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A76DC_7762CC.s")
#endif
#ifdef NON_MATCHING
void func_801A77AC_77639C(uint16_t index) {
    if (gButtonPress & gButton_A) {
        if (gButtonHold & gButton_DDown) {
            thisActor.actorState = 0x3C0;
        }
        else {
            thisActor.actorState = 0x130;
            thisActor.flag &= ~(ACTOR_FLAG_UNK7 | ACTOR_FLAG_UNK9 | ACTOR_FLAG_UNK15);
            thisActor.unk_0x120 = ((float)thisActor.vel.x_w * 1.5);
            thisActor.gp2._w = 0x6000;
            thisActor.gp3._w = 0;
            thisActor.gp4._w = 0;
            thisActor.gp5._w = -1;
            thisActor.unk_0x11C = 196608.0f;
            thisActor.unk_0x124 = 0.0f;
            func_801A7620_776210(index);
            SFX_ActorPanX(0x118, index);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A77AC_77639C.s")
#endif
#ifdef NON_MATCHING
// Differences are regalloc and argument spilling
void func_801A78DC_7764CC(uint16_t index) {
    if ((gButtonPress & gButton_B)) {
        if ((gButtonHold & gButton_DUp)) {
            thisActor.actorState = 0x4010;
        }
        else {
            thisActor.actorState = 0x3B0;
            thisActor.gp2._w = 0;
            thisActor.unk_0x118 = -1.0f;
            thisActor.unk_0x11C = 0.0f;
            func_801A7620_776210(index);
        }
    }
    else {
        func_801A77AC_77639C(index);
    }
}
#else
extern void func_801A78DC_7764CC(uint16_t);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A78DC_7764CC.s")
#endif
#ifdef NON_MATCHING
void func_801A79BC_7765AC(uint16_t index) {
    if ((gButtonHold & gButton_DLeft) || (gButtonHold & gButton_DRight)) {
        if (D_800BE5FC == 3) {
            thisActor.actorState = 0xA0;
        }
        else if (thisActor.actorState != 0x91) {
            thisActor.actorState = 0x90;
        }

        if (FACINGLEFT(index) && ((gButtonHold & gButton_DLeft) == 0)) {
            thisActor.actorState = 0x70;
        }
        else if ((gButtonHold & gButton_DRight)==0) { //this one branch at the end mismatches.
            thisActor.actorState = 0x70; 
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A79BC_7765AC.s")
#endif

void func_801A7AB8_7766A8(uint16_t index) {
    thisActor.unk_0x118 = 1.5;
    func_801A76DC_7762CC(index);
    func_801A78DC_7764CC(index);
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A7B20_776710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A7C34_776824.s")
//Teran counting his jumps. Tick, then spawn.
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A7E04_7769F4.s")
#ifdef NON_MATCHING
void func_801A8008_776BF8(uint16_t other){
    uint16_t index=Actor_GetInactive(8,16);
    Actor* actorp;
    if(index){
        ACTORINIT(index,ACTORTYPE_TERANCOUNT);
        actorp=&gActors[other];
        thisActor.graphic=GINDEX_QUESTIONBUBBLE;
        thisActor.pos.x=actorp->pos.x;
        thisActor.pos.z=actorp->pos.z+16;
        thisActor.gFlag=ACTOR_GFLAG_0|ACTOR_GFLAG_RGB16|ACTOR_GFLAG_B;
        thisActor.flag=0xA;
        thisActor.palletteP=D_800D8668;
        thisActor.gp0._w=0x100000;
        thisActor.scaleX=0.8; //.rodata
        thisActor.scaleY=0.8;
        thisActor.gp2._w=0x20000;
        thisActor.gp3._w=20;
        thisActor.gp1._w=actorp->JumpCount;
    }
}
#else
extern void func_801A8008_776BF8(uint16_t other);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A8008_776BF8.s")
#endif
//increment jumping. causes crash at 27 jumps
void func_801A8108_776CF8(uint16_t index){
    if(-1<thisActor.JumpDelay) thisActor.JumpDelay--;
    if((gButtonPress&gButton_A)&&(thisActor.JumpCount<3)&&(thisActor.JumpDelay<0)){
        thisActor.actorState=0x131;
        thisActor.unk_0x124=1.0;
        thisActor.vel.y_w=0x40000;
        thisActor.gp2._w=0;
        thisActor.JumpCount++;
        thisActor.JumpDelay=8;
        SFX_ActorPanX(0x118,index);
        func_801A8008_776BF8(index);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A81E4_776DD4.s")
//Player Teran Behavior
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A870C_7772FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A9478_778068.s")

void func_801A9534_778124(uint16_t index){
    if(gViptoActorFlags&0XC0000) thisActor.actorState=0x70;
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A9584_778174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A9A3C_77862C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A9D34_778924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A9E6C_778A5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A9EB8_778AA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801A9FF8_778BE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AA120_778D10.s")
#ifdef NON_MATCHING
void func_801AA224_778E14(uint16_t index0, uint16_t index1) {
    Actor* actor = &gActors[index1];
    actor->actorType = 0x45;
    Actor_Spawn(index1);
    actor->pos.x = gActors[index0].pos.x;
    actor->pos.y = gActors[index0].pos.y;
    actor->vel.x_w = gActors[index0].unk_0x148 * 131072.0f;
    actor->vel.y_w = 0x30000;
    actor->unk_0x110 = D_801B01C0;
    actor->unk_0xD8 = 2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AA224_778E14.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AA310_778F00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AA778_779368.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AA964_779554.s")

void func_801AAA2C_77961C(uint16_t x){}

void func_801AAA34_779624(uint16_t x){}
#ifdef NON_MATCHING
uint32_t func_801AAA3C_77962C(uint16_t x){
    if((gActors[81].flag&2)&&(gActors[81].actorType!=0x1D21)&&(gActors[81].health!=0)) return 0;
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AAA3C_77962C.s")
#endif
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AAA88_779678.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AAC20_779810.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AAEFC_779AEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AB104_779CF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AB354_779F44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AB3D4_779FC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AB604_77A1F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AB6DC_77A2CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AB8E8_77A4D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AB9D8_77A5C8.s")



void func_801ABAC8_77A6B8(uint16_t x, float f1,float f2){
    BouncingExplosion(0,x,f1,f2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801ABB00_77A6F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801ABCD4_77A8C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801ABDAC_77A99C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801ABE58_77AA48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AC3EC_77AFDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AC5FC_77B1EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AC8D8_77B4C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801ACA60_77B650.s")

void func_801ACE50_77BA40(uint16_t index){
    MODi(thisActor.vel.y_w,0,0x1000);
    MODi(thisActor.pos.y_w,0x2E0000,0x8000);
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801ACEC8_77BAB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AD438_77C028.s")

void func_801AD918_77C508(uint16_t x){}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AD920_77C510.s")

void func_801ADA84_77C674(uint16_t index){
    thisActor.flag|=0x1000;
    thisActor.unk_0xDE=7;
    thisActor.health=0x7FF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801ADAD4_77C6C4.s")
//Functionally the same as one below...
#ifdef NON_MATCHING
void func_801ADE38_77CA28(uint16_t index){
    thisActor.flag3&=~0x00200600;
}
void func_801ADE80_77CA70(uint16_t index){
    thisActor.flag3&=~0x00200600;
}
#else
extern void func_801ADE38_77CA28(uint16_t index);
extern void func_801ADE80_77CA70(uint16_t index);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801ADE38_77CA28.s")
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801ADE80_77CA70.s")
#endif

void func_801ADEC8_77CAB8(uint16_t index){
    thisActor.pos.x_w=gActors[thisActor.gp0._w].pos.x_w+thisActor.unk_0x184._w;
    thisActor.pos.y_w=gActors[thisActor.gp0._w].pos.y_w+thisActor.unk_0x188._w;
    thisActor.pos.z_w=gActors[thisActor.gp0._w].pos.z_w+thisActor.unk_0x178._w;
}

void func_801ADF50_77CB40(uint16_t x){}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801ADF58_77CB48.s")

void func_801AE060_77CC50(uint16_t x){}
//init calina?
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AE068_77CC58.s")
//...but THIS matches.
void func_801AE208_77CDF8(uint16_t index){
    thisActor.flag3&=~0x00200600;
}

void func_801AE250_77CE40(uint16_t x){}
void func_801AE258_77CE48(uint16_t x){}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AE260_77CE50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AE32C_77CF1C.s")

void func_801AE3E8_77CFD8(uint16_t index){
    if(gPlayerActor.pos.x<thisActor.pos.x){
        thisActor.flag|=ACTOR_FLAG_FLIPPED;
        gActors[index+1].unk_0x130=-1.0;
    }
    else{
        thisActor.flag&=~ACTOR_FLAG_FLIPPED;
        gActors[index+1].unk_0x130=1.0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AE4AC_77D09C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AE634_77D224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AEEBC_77DAAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AF1C4_77DDB4.s")

void func_801AF6AC_77E29C(uint16_t x){}

func_801AF6B4_77E2A4(uint16_t index){
    ACTORINIT(index,ACTORTYPE_GRAPHICONLY);
    thisActor.gFlag=0x1817;
    thisActor.graphic=0x262;
    thisActor.pos.x=0;
    thisActor.pos.y=0;
    thisActor.pos.z=-0x200;
    thisActor.rgba.r=0x80;
    thisActor.scaleX=8.0;
    thisActor.rotateX=45.0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AF750_77E340.s")

void func_801AF8A0_77E490(){
    func_801AF750_77E340(0x81);
    func_801AF750_77E340(0x82);
}
//"7 clancer kids" - Leo Shoots Marina.
//uh.. spoilers.
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/World4/func_801AF8C8_77E4B8.s")
