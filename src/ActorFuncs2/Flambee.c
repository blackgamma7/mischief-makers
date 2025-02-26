#include "common.h"

#define LERPI(a,b,t) a = func_8019C984_744534(a,b,t)
#define LERPF(a,b,t) a = func_8019C948_7444F8(a,b,t)

// 801A20E0 seems to be the .bss for this script.
extern s16 D_801A20E0; //sting timer
extern s16 D_801A20E2;
extern int32_t D_801A20E8[2]; //target coords.
extern uint16_t D_801A20F0,D_801A20F2; //player coords
extern uint16_t D_801A20F4,D_801A20F6; //shake counts - Head and stinger
#define ACTORTYPE_BEESHAKE 0xc02 //the little bees it summons when shook
#define ACTORTYPE_BEERING 0xc03 //the little bees it summons in a ring.


void func_8019B100_742CB0(uint16_t x){
    ACTORINIT(48,ACTORTYPE_GRAPHICONLY);
    gActors[48].gFlag = ACTOR_GFLAG_0|ACTOR_GFLAG_RGB16|ACTOR_GFLAG_B;
    gActors[48].flag=ACTOR_FLAG_ENABLED|ACTOR_FLAG_UNK3;
    gActors[48].graphic = GINDEX_SOLIDSQARE;
    gActors[48].pos.x = 0;
    gActors[48].pos.y = 0;
    gActors[48].pos.z = -0x10;
    gActors[48].unk_0x188._p = NULL;
    gActors[48].palletteP = &gPalletteBlack;
    gActors[48].rgba.a = 0x80;
    gActors[48].scaleX = 19.0;
    gActors[48].scaleY = 13.0;

}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019B190_742D40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019B290_742E40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019B604_7431B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019B770_743320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019B87C_74342C.s")

#ifdef NON_MATCHING
extern int16_t D_801A0F8C_7483BC[];
void func_8019B990_743540(uint16_t index){
    if(thisActor.actorState) func_800819A8(index,&D_801A0F8C_7483BC);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019B990_743540.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019B9EC_74359C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019BA5C_74360C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019BB2C_7436DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019BC08_7437B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019BCF4_7438A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019BE20_7439D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019BF84_743B34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019C060_743C10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019C1F4_743DA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019C4EC_74409C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019C574_744124.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019C6DC_74428C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019C828_7443D8.s")

float func_8019C948_7444F8(float f1, float f2, int32_t i) {
    float f3 = (float) i;
    if (f3 == 0.0f) return f2;
    return ((f2 - f1) / f3) + f1;
}

int32_t func_8019C984_744534(int32_t x, int32_t y, int32_t z) {
    float f = (float) z;
    if (f == 0.0f) return y;
    return (int32_t)((float) (y - x) / f) + x;
}


#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019C9F4_7445A4.s")

//countdown to sting
uint32_t func_8019CAB8_744668(uint16_t x){
    if(D_801A20E0>0) D_801A20E0--;
    if(D_801A20E0<=0) return 1;
    return 0;
}

#ifdef NON_MATCHING
void func_8019CAF8_7446A8(uint16_t index){
    if(thisActor.flag&0x20){
        thisActor.flag&= ~20;
        thisActor.unk_0x138=0.0;
        gActors[index+1].unk_0x130=1.0f;
    }
    else{
        thisActor.flag|=ACTOR_FLAG_FLIPPED;
        thisActor.unk_0x138=1.0f;
        gActors[index+1].unk_0x130=-1.0f;    
    }
}
#else
extern void func_8019CAF8_7446A8(uint16_t index);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019CAF8_7446A8.s")
#endif

void func_8019CBC4_744774(uint16_t index){
    if(gActors[index+6].unk_0x180._w < 0x200){
        if (thisActor.flag&0x20) func_8019CAF8_7446A8(index);
        }
    else if((thisActor.flag&0x20)==0) func_8019CAF8_7446A8(index);
}

int32_t func_8019CC9C_74484C(uint16_t index){
    if(gActors[index+7].unk_0x180._w < D_801A20E8[1]) MODi(thisActor.vel.y_w,0x10000,0x1000);
    else MODi(thisActor.vel.y_w,-0x10000,0x1000);
    return thisActor.vel.y_w;
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019CD78_744928.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019CE58_744A08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019CF50_744B00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019D028_744BD8.s")

uint32_t func_8019D0D8_744C88(uint16_t index){
    if((gActors[index+3].flag3&2)&&(gActors[index+3].unk_0xDD==19)){
        thisActor.actorState=0x110;
        thisActor.unk_0xD4=60;
        gActors[index+3].health=0;
        gActors[index+5].health=0;
        SFX_ActorPanX(0x67,index);
        return 1;
    }
    return 0;
}

uint32_t func_8019D184_744D34(uint16_t index){
    if((gActors[index+5].flag3&2)&&(gActors[index+5].unk_0xDD==19)){
        thisActor.actorState=0x110;
        thisActor.unk_0xD4=60;
        gActors[index+3].health=0;
        gActors[index+5].health=0;
        SFX_ActorPanX(0x67,index);
        return 1;
    }
    return 0;
}

uint32_t func_8019D230_744DE0(uint16_t index){
    if((thisActor.vel.y_w<0)&&(thisActor.flag3&0x8000)){
        thisActor.actorState=0x120;
        thisActor.unk_0xD4=60;
        gActors[index+3].health=0;
        gActors[index+5].health=0;
        SFX_ActorPanX(0x67,index);
        return 1;
    }
    return 0;
}

uint32_t func_8019D2D8_744E88(uint16_t index) {

    if (func_8019D0D8_744C88(index)) return 1;
    if (func_8019D184_744D34(index)) return 1;
    if (func_8019D230_744DE0(index)) return 2;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019D34C_744EFC.s")
//damage function. after multi, slams do 170 dmg, dunks 340
#ifdef NON_MATCHING
const double D_801AB68_74918=1.7;
uint32_t func_8019D414_744FC4(uint16_t index, int16_t x){
    thisActor.health+= x*D_801AB68_74918;
    if(thisActor.health<=0) return 1;
    return 0;
}
#else
extern uint32_t func_8019D414_744FC4(uint16_t index, int16_t x);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019D414_744FC4.s")
#endif

#ifdef NON_MATCHING
//spawn drone bee on head shake
void func_8019D4C0_745070(uint16_t index){
    uint16_t droneIndex=Actor_GetInactive(0x70,0x80);
    if(droneIndex){
        ACTORINIT(droneIndex,ACTORTYPE_BEESHAKE);
        gActors[droneIndex].pos.x_w=gActors[index+5].pos.x_w;
        gActors[droneIndex].pos.y_w=gActors[index+5].pos.y_w;
        gActors[droneIndex].pos.z=gActors[index+5].pos.z+-1;
    }
}
#else
extern void func_8019D4C0_745070(uint16_t index);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019D4C0_745070.s")
#endif

void func_8019D588_745138(uint16_t index){
    gActors[index+3].flag|=0x1200;
    gActors[index+3].hitboxAX0=-14, gActors[index+3].hitboxAX1=14; //yes, this is needed.
    gActors[index+3].hitboxAY0=16;
    gActors[index+3].hitboxAY1=0;
    gActors[index+3].unk_0xDA=129;
    gActors[index+3].unk_0xDB=4;
    gActors[index+3].speedX._w=0x60000;
    gActors[index+3].speedY._w=0x30000;
    gActors[index+3].attackDmg=10;
}

void func_8019D60C_7451BC(uint16_t index){
    gActors[index+3].flag&=~0x1200;
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019D650_745200.s")

void func_8019D6CC_74527C(uint16_t index){
    gActors[index+3].flag&=~0x1000;
    gActors[index+5].flag&=~0x200;
}
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019D720_7452D0.s")

void func_8019D7D0_745380(uint16_t index){
    uint16_t index0=index+9;
    uint16_t other=gActors[index0].actorLink;
    gActors[other].actorLink=index+9;
    gActors[other].flag3|=0x200;
    gActors[other].pos2.x_w=gActors[index0].pos.x_w;
    gActors[other].pos2.y_w=gActors[index0].pos.y_w;
    gActors[other].pos2.z_w=gActors[index0].pos.z_w-1;
}

void func_8019D844_7453F4(uint16_t index){
    gActors[index+9].flag|=0x800;
}

void func_8019D884_745434(uint16_t index){
    gActors[index+9].flag&=~0x800;
}

void func_8019D8C8_745478(uint16_t index){
    uint16_t i=index+5; 
    gActors[i].flag|=0x200;
    gActors[i].speedX._w=0x60000;
    gActors[i].speedY._w=0;
    gActors[i].unk_0xDA=128;
    gActors[i].unk_0xDB=8;
    gActors[i].attackDmg=100;
}
void func_8019D930_7454E0(uint16_t index){
    uint16_t i=index+5; 
    gActors[i].flag&=~0x200;
}
#ifdef NON_MATCHING
void func_8019D978_745528(uint16_t index){
    uint16_t i=index+9;
    uint16_t x=gScreenPosCurrentX._hi + gActors[i].pos.x;
    uint16_t y=gScreenPosCurrentY._hi + gActors[i].pos.y;
    if(D_801A20F0>x) MODi(thisActor.vel.x_w,0x20000,0x1000);
    else MODi(thisActor.vel.x_w,-0x20000,0x1000);
    if(D_801A20F2>y) MODi(thisActor.vel.y_w,0x20000,0x1000);
    else MODi(thisActor.vel.y_w,-0x20000,0x1000);
}
#else
extern void func_8019D978_745528(uint16_t index);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019D978_745528.s")
#endif
//drone bee ring
void func_8019DA80_745630(uint16_t index){
    uint16_t i,j;
    for(i=0;i<8;i++){
        j=i+0x70;
        ACTORINIT(j,ACTORTYPE_BEERING);
        gActors[j].pos.x_w=thisActor.pos.x_w;
        gActors[j].pos.y_w=thisActor.pos.y_w;
        gActors[j].pos.z=thisActor.pos.z-1;
        gActors[j].gp1._w=i<<7;
        gActors[j].gp2._w=i*10;
        if(gActors[index+6].unk_0x180._w<0x200) gActors[j].gp3=._w1;
        else gActors[j].gp3._w=-1;
    }
}

//shake bee's head
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019DBD4_745784.s")

#ifdef NON_MATCHING
float D_801A1A94_749644[16]={
    0.0,0.38,0.7,0.924,1.0,0.924,0.7,0.38,-0.0,-0.38,0.7,-0.924,-1.0,-0.7,-0.38
};
float func_8019DD64_745914(){
    return (float)D_801A1A94_749644[gPlayerManager.unk_0x10]*gPlayerManager.unk_0xE;
}
#else
extern float func_8019DD64_745914();
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019DD64_745914.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019DD9C_74594C.s")
//shake bee's stinger
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019DF10_745AC0.s")

void func_8019E0E0_745C90(uint16_t index){
    thisActor.flag&=~0x20400;
}

void func_8019E128_745CD8(uint16_t index){
    gActors[index+3].flag&=~0x1000;
    gActors[index+5].flag&=~0x1000;
}

void func_8019E178_745D28(uint16_t x){}
#ifdef NON_MATCHING
void func_8019E180_745D30(uint16_t index,int16_t* p, uint16_t c){
    while(*p!=0x7FFF){
        p+=5;
        gActors[*p+index].rgba.r=c;
        gActors[*p+index].rgba.g=c;
        gActors[*p+index].rgba.b=c;
    }
}
#else
extern void func_8019E180_745D30(uint16_t index,int16_t* p, uint16_t c);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019E180_745D30.s")
#endif

void func_8019E1E8_745D98(uint16_t index){
    if((gActors[index+6].unk_0x180._w<0x1A0)&&(gActors[index+6].unk_0x180._w>0x260)&&(func_80029B00(64,48,-48))){
        if(D_801A20F0<gActors[index+6].unk_0x180._w) thisActor.pos.x_w+=0x28000;
        else thisActor.pos.x_w-=0x28000;
    }
}
//main BEE-havior?
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_8019E2F0_745EA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_801A00F8_747CA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_801A02E8_747E98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_801A03EC_747F9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_801A0548_7480F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_801A0650_748200.s")

void func_801A0740_7482F0(uint16_t index){
    thisActor.pos.x=thisActor.gp4._w-gScreenPosCurrentX._hi;
    thisActor.pos.y=thisActor.gp5._w-gScreenPosCurrentY._hi;
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_801A079C_74834C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_801A08D4_748484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_801A09BC_74856C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs2/Flambee/func_801A0C00_7487B0.s")
