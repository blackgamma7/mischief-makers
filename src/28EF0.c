#include "BGM.h"
#include "GameSave.h"
#include "common.h"


void func_800282F0(int16_t x,int16_t y){
    ActorSpawn_Marina();
    gPlayerManager.buttonHold._w=0;
    gPlayerManager.buttonPress._w=0;
    gPlayerActor.pos.x=x;
    gPlayerActor.pos.y=y;
    gPlayerPosXMirror._hi=gScreenPosCurrentX._hi+x;
    gPlayerPosYMirror._hi=gScreenPosCurrentY._hi+y;
    gIsPlayerInactive=0;
    if(gPlayerActor.health<0) gPlayerActor.health=0;
}


void func_80028380(void) {
    gPlayerActor.flag = 0;
    gIsPlayerInactive = 1;
    gPlayerManager.flags = 0;
    if (gPlayerActor.health < 0) gPlayerActor.health = 0;
}
#ifdef NON_MATCHING
int32_t func_800283BC(uint32_t SFX, uint16_t index){
    int32_t x = (thisActor.pos.x - gAtX)/2.0;
    if( (x<64) && (x<-64) ) x = -64;
    else x=63;
    if(index&0x8000) return SFX_Play_6(SFX,256,x+64);
    return SFX_Play_5(SFX,256,x+64);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800283BC.s")
#endif


void ActorTick_29(uint16_t x) {}


#ifdef NON_MATCHING
uint16_t Actor_GetInactive(uint16_t x, uint16_t y) {

    while(y > x){
        if (gActors[x++].flag & 2 == 0) return x;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/Actor_GetInactive.s")
#endif

uint16_t Actor_GetInactive_144_192(void) {
    return Actor_GetInactive(ACTOR_COUNT0, ACTOR_COUNT1);
}

uint16_t Actor_SpawnTypeAt(uint16_t T,int16_t pos_x,int16_t pos_y,int16_t pos_z){
    uint16_t index = Actor_GetInactive(ACTOR_COUNT0, ACTOR_COUNT1);
    if(index){
        ACTORINIT(index,T);
        thisActor.pos.x = pos_x;
        thisActor.pos.y = pos_y;
        thisActor.pos.z = pos_z;
    }
    return index;
}

void Actor_ZeroFlagRange(uint16_t from, uint16_t to) {
    for (from = from; from < to; from++) {
        gActors[from].flag = 0;
    }
}

void Actor_ZeroFlag_16_32(void) {
    Actor_ZeroFlagRange(0x10, 0x20);
}

void Actor_ZeroFlag_48_144(void) {
    Actor_ZeroFlagRange(0x30, ACTOR_COUNT0);
}

void Actor_ZeroFlag_144_192(void) {
    Actor_ZeroFlagRange(ACTOR_COUNT0, ACTOR_COUNT1);
}

void Actor_ZeroFlag_192_199(void) {
    Actor_ZeroFlagRange(ACTOR_COUNT1, 199);
}
void Portraits_Reset(){
    uint16_t i;
    for(i=0;i<64;i++) gPortraits[i].flags = 0;
}

void func_80028704(void) {
    Actor_ZeroFlag_16_32();
    Actor_ZeroFlag_48_144();
    Actor_ZeroFlag_144_192();
    Actor_ZeroFlag_192_199();
    Portraits_Reset();
}

void func_80028744(void) {
    Actor_ZeroFlag_16_32();
    Actor_ZeroFlag_48_144();
    Actor_ZeroFlag_144_192();
    Actor_ZeroFlag_192_199();
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002877C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002884C.s")
#ifdef NON_MATCHING
int32_t func_800288EC(uint16_t index, int16_t x) {
    if ((thisActor.pos.x <= (x + 0x90)) && (thisActor.pos.x > (x - 0x90)) && (thisActor.pos.y <= (x + 0x60)) &&
        (thisActor.pos.y > (x - 0x60)))
        return 0;
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800288EC.s")
#endif

void func_80028980(uint16_t index, int16_t arg1, uint32_t SFX) {
    if (func_800288EC(index, arg1) == 0)
        SFX_ActorPanX(SFX, index);
}

int32_t ABS_800289cc(int32_t x) { //redundant function - thus listing the address.
    if (x < 0)
        return -x;
    return x;
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/Actor_FindVIPActor.s")

void func_80028AE8(uint16_t index) {
    Actor_FindVIPActor(index, D_800D36FC, 0x7FFF);
}
void func_80028B1C(uint16_t index){
    Actor_FindVIPActor(index,D_800D36DC,ABS_800289cc(thisActor.pos.x-gPlayerActor.pos.x));
}


void func_80028B90(uint16_t index){
    uint16_t other = thisActor.actorLink;
    if(thisActor.pos.x<gActors[other].pos.x) thisActor.speedX._w= -gActors[other].speedX._w;
    else thisActor.speedX._w= gActors[other].speedX._w;
}


void func_80028C00(uint16_t x) {}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80028C08.s")

uint32_t func_80028C80(uint16_t index){
    if(thisActor.flag3&0x200){
        thisActor.pos.x_w=thisActor.pos2.x_w;
        thisActor.pos.y_w=thisActor.pos2.y_w;
        thisActor.pos.z_w=thisActor.pos2.z_w;
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80028CE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80028DAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80028E1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80029044.s")

#ifdef NON_MATCHING
void func_80029134(uint16_t index) {
    thisActor.flag &= ~(ACTOR_FLAG_UNK12|ACTOR_FLAG_UNK16);
    thisActor.flag |= ACTOR_FLAG_UNK17; // this step is off?
    thisActor.vel.x_w = 0;
    thisActor.vel.y_w = 0;
    thisActor.vel.z_w = 0;
    thisActor.pos.x_w = thisActor.pos2.x_w;
    thisActor.pos.y_w = thisActor.pos2.y_w;
    thisActor.pos.z_w = thisActor.pos2.z_w;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80029134.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800291AC.s")
//calculates "theta" based on position in gCosineLookup
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/atan2.s")

uint32_t func_800295D8(int32_t A, int32_t B) {
    return atan2(A,B) + (COSPiOver2) & (COSPiOver2*2);
}

uint32_t func_80029600(int32_t A, int32_t B) {
    return atan2(A,B) + (COSPiOver2/2) & (COSPiOver2*3);
}

uint32_t func_80029628(int32_t A, int32_t B) {
    return atan2(A,B) + (COSPiOver2/4) & 0x380;
}

uint32_t func_80029650(int32_t A, int32_t B) {
    return atan2(A,B) + (COSPiOver2/8) & 0x3C0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80029678.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80029798.s")

#ifdef NON_MATCHING
int32_t ModInRange_i(int32_t A, int32_t B, int32_t C) {
    int32_t D = A - B;
    if (D < 1) {
        if (-C <= D)
            return B;
        return A + C;
    }
    if (D <= C)
        return B;
    return A - C;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/ModInRange_i.s")

#endif
#ifdef NON_MATCHING
float ModInRange_f(float A, float B, float C) {
    if (B < A) {
        if (C > A - B)
            return B;
        return A - C;
    }
    if (-C <= (A - B))
        return B;
    return A + C;
}

#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/ModInRange_f.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800298D0.s")

#ifdef NON_MATCHING
int32_t func_8002995C(int32_t A, int32_t B) {
    if (A > B) {
        if (A - B < 0x2000000)
            return 1;
        return -1;
    }
    if (-0x2000000 < A - B)
        return -1;
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002995C.s")
#endif

// Regalloc mismatch
#ifdef NON_MATCHING
void func_800299B0(uint16_t index){
    int32_t x= thisActor.vel.x_w;
    if((x>0)&&(thisActor.flag3&8)){
        thisActor.vel.x_w=0;
        x=0;
    }
    if((x<0)&&(thisActor.flag3&4)){
        thisActor.vel.x_w=0;
    }
    x= thisActor.vel.y_w;
    if((x>0)&&(thisActor.flag3&16)){
        thisActor.vel.y_w=0;
        x=0;
    }
    if((x<0)&&(thisActor.flag3&32)){
        thisActor.vel.y_w=0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800299B0.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80029A7C.s")

uint32_t func_80029B00(int16_t x,int16_t yHi,int16_t yLo){
    if(((VipToPlayerX<x)&&(VipToPlayerX>-x))&&((VipToPlayerY<yHi)&&(VipToPlayerY>yLo)))
      return 1;
    return 0;
}

uint32_t func_80029B74(int16_t x){
    if((VipToPlayerX<x)&&(VipToPlayerX>-x)) return 1;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80029BB4.s")

uint32_t func_80029C44(int16_t xHi,int16_t xLo,int16_t yHi,int16_t yLo){
    if(((VipToPlayerX>xHi)&&(VipToPlayerX<xLo))&&((VipToPlayerY<yHi)&&(VipToPlayerY>yLo)))
      return 1;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80029CC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80029D58.s")

int32_t func_80029DEC(uint16_t frame, uint16_t rng) {
    if (((gSceneFrames & frame) == 0) && (RNG(rng)) == 0)
        return 1;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80029E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80029F00.s")

uint16_t func_80029FB8(uint16_t index, int16_t x1, int16_t x2, int16_t y1, int16_t y2) {
    return func_80029E48(index, x1, x2) | func_80029F00(index, y1, y2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002A018.s")

int32_t func_8002A090(int32_t a, int32_t b) {
    if (b < 0) {
        b = -b;
    }
    if (b < a) {
        a = b;
    }
    if (a < -b) {
        a = -b;
    }

    return a;
}

void func_8002A0C4(uint16_t index, int32_t x) {
    IFFACINGLEFT(index) {
        thisActor.vel.x_w = -x;
    }
    else {
        thisActor.vel.x_w = x;
    }
}

void func_8002A118(uint16_t index, int32_t x) {
    thisActor.vel.x_w = func_8002A090(thisActor.vel.x_w, x);
}

void func_8002A170(uint16_t index, int32_t x) {
    thisActor.vel.y_w = func_8002A090(thisActor.vel.y_w, x);
}

void func_8002A1C8(uint16_t index, int32_t x) {
    func_8002A118(index, x);
    func_8002A170(index, x);
}

void func_8002A200(uint16_t index, int32_t x) {
    thisActor.speedX._w = func_8002A090(thisActor.speedX._w, x);
}
void func_8002A258(uint16_t index, int32_t x) {
    thisActor.speedY._w = func_8002A090(thisActor.speedY._w, x);
}

void func_8002A2B0(uint16_t index, int32_t x) {
    thisActor.speedX._w = func_8002A090(thisActor.speedX._w, x);
    thisActor.speedY._w = func_8002A090(thisActor.speedY._w, x);
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002A320.s")

void Actor_ModVelX(uint16_t index, int32_t x) {
    MODi(thisActor.vel.x_w, 0, x);
}

void Actor_ModVelY(uint16_t index, int32_t y) {
    MODi(thisActor.vel.y_w, 0, y);
}

void Actor_ModVelXY(uint16_t index, int32_t x, int32_t y) {
    Actor_ModVelX(index, x);
    Actor_ModVelY(index, y);
}
#ifdef NON_MATCHING
int32_t func_8002A4FC(uint16_t index) {
    if (thisActor.vel.x_w < 1) && (thisActor.flag3 & 4) {
        thisActor.vel.x_w = 0;
        return 2;
    }
    else if (thisActor.flag3 & 8) {
        thisActor.vel.x_w = 0;
        return 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002A4FC.s")
#endif
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002A57C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002A658.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002A898.s")
//these 2 seem to calculate player position relative to boss
#ifdef NON_MATCHING
int32_t Actor_SetVIPToPlayerX(uint16_t A, uint16_t B){
    int32_t x,y;
    x=(gActors[A].hitboxBX1+gActors[A].hitboxBX0)/2;
    y=(gActors[B].hitboxBX1+gActors[B].hitboxBX0)/2;
    return ((x)+gActors[B].pos.x+(y))-gActors[A].pos.x;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/Actor_SetVIPToPlayerX.s")
#endif
#ifdef NON_MATCHING
int32_t Actor_SetVIPToPlayerY(uint16_t A, uint16_t B){
    int32_t x,y;
    x=gActors[A].hitboxBY0+gActors[A].hitboxBY1/2;
    y=gActors[B].hitboxBY0+gActors[B].hitboxBY1/2;
    return (x+gActors[B].pos.y+y)-gActors[A].pos.y;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/Actor_SetVIPToPlayerY.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/Actor_SetVIPToPlayerCoords.s")
void Actor_HitboxASet(uint16_t index, int16_t x) {
    thisActor.hitboxAY0 = x;
    thisActor.hitboxAY1 = -x;
    thisActor.hitboxAX0 = -x;
    thisActor.hitboxAX1 = x;
}

void Actor_HitboxBSet(uint16_t index, int16_t x) {
    thisActor.hitboxBY0 = x;
    thisActor.hitboxBY1 = -x;
    thisActor.hitboxBX0 = -x;
    thisActor.hitboxBX1 = x;
}

void Actor_HitboxAXSet(uint16_t index, int16_t x, int16_t y) {
    IFFACINGLEFT(index) {
        thisActor.hitboxAX1 = -x;
        thisActor.hitboxAX0 = -y;
    }
    else {
        thisActor.hitboxAX0 = x;
        thisActor.hitboxAX1 = y;
    }
}

void func_8002ACFC(uint16_t index, int16_t x, int16_t y) {
    IFFACINGLEFT(index) {
        thisActor.hitboxBX1 = -x;
        thisActor.hitboxBX0 = -y;
    }
    else {
        thisActor.hitboxBX0 = x;
        thisActor.hitboxBX1 = y;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002AD7C.s")
//this seems to begin actor coloring functions.
#ifdef NON_MATCHING
u16 func_8002AE44(s16 x, s16 y) { //99.11% accurate
    s16 temp;

    if (y < 0) {
        if (-y >= x) return 0;
        return (x + y);
    }
    temp = x + y;
    if (temp > 255) return 255;
    return temp;
}

#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002AE44.s")
#endif

void Actor_Shade(uint16_t index, uint8_t col) { // uniform grayscale.
    thisActor.rgba.r = col;
    thisActor.rgba.g = col;
    thisActor.rgba.b = col;
}

void Actor_ShadeBy(uint16_t x, int16_t y) { //tint actor[x] by y, unused
    gActors[x].rgba.r = func_8002AE44(gActors[x].rgba.r, y);
    gActors[x].rgba.g = func_8002AE44(gActors[x].rgba.g, y);
    gActors[x].rgba.b = func_8002AE44(gActors[x].rgba.b, y);
}

void func_8002AF7C(uint16_t index, uint16_t arg1, int16_t arg2) {
    if ((gSceneFrames & arg1) == 0) {
        thisActor.rgba.r = 0x7f;
        thisActor.rgba.g = 0x7f;
        thisActor.rgba.b = 0x7f;
    }
    else {
        Actor_ShadeBy(index, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002B010.s")

void func_8002B140(uint16_t index, int16_t y) { // looks to be some actor color blend.
    thisActor.rgba.r = func_8002B010(index, thisActor.rgba.r, y);
    thisActor.rgba.g = func_8002B010(index, thisActor.rgba.g, y);
    thisActor.rgba.b = func_8002B010(index, thisActor.rgba.b, y);
}

void func_8002B1D0(uint16_t index, int16_t y) {
    MODi(thisActor.rgba.r, 0, y);
    MODi(thisActor.rgba.g, 0, y);
    MODi(thisActor.rgba.b, 0, y);
}

#ifdef NON_MATCHING
void func_8002B25C(uint16_t index, int16_t y) {
    thisActor.rgba.r = thisActor.rgba.g = thisActor.rgba.b = func_8002B010(i, (uint16_t)thisActor.rgba.r, y); // non-matching stack?
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002B25C.s")
#endif
#ifdef NON_MATCHING
void func_8002B2D0(uint16_t index){
    int8_t c;
    thisActor.gFlag&= ~ACTOR_GFLAG_4;
    c= ((-gSceneFrames & 0xf)<<3);
    thisActor.rgba.r = thisActor.rgba.g = thisActor.rgba.b = c;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002B2D0.s")
#endif
#ifdef NON_MATCHING
void func_8002B330(uint16_t index) {
    uint8_t c;

    if (gSceneFrames & 4) {
        c = func_8002B010(i, thisActor.rgba.r, 64);
        thisActor.rgba.r = c;
        thisActor.rgba.g = c;
        thisActor.rgba.b = c;
    }
    else {
        c = func_8002B010(i, thisActor.rgba.r, -64);
        thisActor.rgba.r = c;
        thisActor.rgba.g = c;
        thisActor.rgba.b = c;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002B330.s")
#endif

#ifdef NON_MATCHING
void func_8002B400(uint16_t index) {

    if (gSceneFrames & 4) {
        thisActor.rgba.r = func_8002B010(i, thisActor.rgba.r, 64);
        thisActor.rgba.g = 0;
        thisActor.rgba.b = 0;
    }
    else {
        thisActor.rgba.r = 0;
        thisActor.rgba.g =  thisActor.rgba.b = func_8002B010(i, thisActor.rgba.g, -64);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002B400.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002B4D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/RGB16_Add.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002B6E8.s")

void func_8002B7B8(uint16_t*p0,uint16_t*p1,uint16_t x){
    uint16_t i = *p0;
    while(i!=256){
        p1[i]=x;
        p0+=2;
        i=*p0;
    }
}

void func_8002B7F4(uint16_t*p0,uint16_t*p1){
    uint16_t i = *p0;
    while(i!=256){
        p1[i]=p0[1];
        p0+=2;
        i=*p0;
    }
}

#ifdef NON_MATCHING
void RGB16_AddN(uint16_t* arg0, int16_t* arg1, int16_t arg2, int16_t arg3, int16_t arg4, int16_t arg5) {
    uint16_t index;
    for (index = arg2; 0 < index; index--) {
        *arg1++ = RGB16_Add(*arg0++, arg3, arg4, arg5);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/RGB16_AddN.s")
#endif

int32_t func_8002B8F0(uint16_t index, uint16_t dmg) {
    if (thisActor.health <= dmg) {
        thisActor.health = 0;
        return 0;
    }
    thisActor.health -= dmg;
    return 1;
}

int32_t func_8002B954(uint16_t index, uint16_t arg1) {
    if (D_800BE4D8 == 0) {
        if (arg1 & 0x80) {
            return 1;
        }

        if ((arg1 & 0x40) && (thisActor.vel.y_w < 0)) {
            return 1;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002B9D8.s")

int32_t func_8002BACC(uint16_t arg0, uint16_t arg1) {
    if ((D_800BE4D8 == 0) && (arg1 & 0x80)) {
        return 1;
    }

    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002BB04.s")

#ifdef NON_MATCHING
// RegAlloc?
uint8_t func_8002BC10(uint16_t index) {
    uint16_t x = func_80012C04(thisActor.pos.x, thisActor.pos.y) & 0x7F;

    if ((x == 50) || (x == 54)) {
        x = 0;
    }

    return x;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002BC10.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002BC90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002C044.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002C140.s")
void ActorTick_27(uint16_t x){}

void memcpy16(uint16_t* x, uint16_t* y, uint16_t z) {
    for (z != 0; z > 0; z--) {
        *y = *x;
        x++;
        y++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002C218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002C328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002C3C8.s")


void func_8002C510(uint16_t index) {
    if (thisActor.flag & ACTOR_FLAG_UNK7) Actor_HitboxASet(index, thisActor.gp2._w + 6);
    else Actor_HitboxASet(index, thisActor.gp2._w - 8);
    Actor_HitboxBSet(index, thisActor.gp2._lo); // that's why we'll call it a union.
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002C5C4.s")

void ActorTick_30(uint16_t x){}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002C6E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002CCD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002D040.s")
/*
void ActorTick_1(uint16_t index){
    thisActor.hitboxAY0+=2;
    thisActor.hitboxAY1-=2;
    thisActor.hitboxAX0-=2;
    thisActor.hitboxAX1+=2;
    if(thisActor.unk_0x110==0.0)thisActor.flag=0;
    else thisActor.unk_0x110-=1.0;
}*/
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/ActorTick_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002D2F4.s")
//spawns in cinematic as soon as Leo hits Marina.
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002D3C0.s")
//tick of the above. Looks to be a screen flood and fade?
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002D488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002D5E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002D670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002D904.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002DB0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002DC74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002DFC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002E288.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002E500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002E89C.s")

const float D_800EB904 = 0.8; //dirty hack, 
//spawns a shuriken?
void func_8002EBB8(uint16_t index, int16_t x, int16_t y, int32_t vx, int32_t vy) {
    float temp;

    ACTORINIT(index,0x2602);
    temp = D_800EB904;
    thisActor.gFlag = ACTOR_GFLAG_ROTZ|ACTOR_GFLAG_0;
    thisActor.flag = ACTOR_FLAG_ENABLED | ACTOR_FLAG_ONSCREEN_ONLY;
    thisActor.graphic = GINDEX_SHURIKEN;
    thisActor.unk_0xCE = 5;
    thisActor.unk_0xDF = 0;
    thisActor.unk_0xDA = 4;
    thisActor.unk_0xDB = 4;
    thisActor.scaleX = temp;
    thisActor.scaleY = temp;

    Actor_HitboxASet(index, 4);
    Actor_HitboxBSet(index, 8);

    thisActor.health = 1;
    thisActor.attackDmg = 30;
    thisActor.pos.x = x;
    thisActor.pos.y = y;
    thisActor.vel.x_w = vx;
    thisActor.vel.y_w = vy;
}

void func_8002ECAC(uint16_t index, int16_t x, int16_t y, int32_t vx, int32_t vy) {
    ACTORINIT(index,0x2600);
    thisActor.pos.x = x;
    thisActor.pos.y = y;
    thisActor.vel.x_w = vx;
    thisActor.vel.y_w = vy;
}

void func_8002ED34(uint16_t index, int16_t x, int16_t y, int32_t z) {}

#ifdef NON_MATCHING
void func_8002ED48(uint16_t index, int16_t x, int16_t y) {
    ACTORINIT(index,0x2603);
    thisActor.health = 10;
    thisActor.pos.x = x;
    thisActor.pos.y = y;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002ED48.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002EDC8.s")

uint16_t Gem_ActorSpawn(uint16_t index,uint16_t flags, uint16_t x){
    uint16_t gemIndex;
    if(((flags&GEMFLAG_GREEN)==GEMFLAG_YELLOW)&&YellowGem_GetFlag(gCurrentStage)) return 0;
    gemIndex= Actor_GetInactive(122,130);
    if(gemIndex){
        ACTORINIT(gemIndex,ACTORTYPE_GEM);
        gActors[gemIndex].flag=2;
        gActors[gemIndex].unk_0x110=flags;
        gActors[gemIndex].pos.x=thisActor.pos.x;
        gActors[gemIndex].pos.y=thisActor.pos.y;
        if(flags&GEMFLAG_BOUNCE) gActors[gemIndex].vel.y_w=0x40000;
        if(flags&GEMFLAG_FINITE) gActors[gemIndex].gp0._w=120;
        SFX_ActorPanX(SFX_GEM_APPEAR,index);
    }
    return gemIndex;
}
uint16_t func_8002F154(uint16_t index,uint16_t flags, uint16_t x){
    uint16_t gemIndex=Gem_ActorSpawn(index,flags,x);
    if(gemIndex)gActors[gemIndex].actorType=0x3D;
    return gemIndex;
}
//spawns "No hit" yellow gem
uint16_t YellowGem_NoHit(uint16_t index){
    uint16_t gemIndex=0;
    if((-1<gNoHit)&&(YellowGem_GetFlag(gCurrentStage)==0)){
        func_8003FE4C(1.0,gPlayerActor.pos.x,gPlayerActor.pos.y+0x30,2); 
        gemIndex=Gem_ActorSpawn(index,GEMFLAG_YELLOW|GEMFLAG_BOUNCE|GEMFLAG_FINITE,0);
        if(gemIndex){
            gActors[gemIndex].actorType=0x3D;
            gActors[gemIndex].pos.x=gPlayerActor.pos.x;
            gActors[gemIndex].pos.y=gPlayerActor.pos.y+0x30;
        }
    }
    return gemIndex;
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/ActorSpawn_RedGemRing.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002F420.s")


void RedGem_Clamp(void) {
    if (gRedGems >= 9999) {
        gRedGems = 9999;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/ActorTick_RedGemRing.s")

#ifdef NON_MATCHING
void GemCollision(uint16_t arg0, uint16_t arg1, int32_t arg2, int16_t arg3, int16_t arg4) {
    uint16_t temp_v1;
    uint16_t temp_v1_2;
    uint16_t temp_v1_3;

    if (arg2 == &Data_RedGem) {
        gRedGems++;
        RedGem_Clamp();
        func_8003FB20(arg0, 0, 1.0, arg3, (int32_t)arg4, (int32_t)((gPlayerActorIndex * 0x198) + 0x800F0000)->unk - A60);
        if (arg1) SFX_GemX(0x57, arg0);
        else SFX_ActorPanX(0x57, arg0);
    }
    if (arg2 == &Data_BlueGem) {
        if (gPlayerActorIndex)
            gActors[gPlayerActorIndex].health += 30;
        else
            Actor_AddHP(0, 30);
        func_800337F4(arg3, arg4, 4, 0x132);
        if (arg1) SFX_GemX(0x95, arg0);
        else SFX_ActorPanX(0x95, arg0);
    }
    else if (arg2 == &Data_YellowGem) {
        YellowGem_setFlag();
        if (gPlayerActorIndex)
            gActors[gPlayerActorIndex].health += 500;
        else
            Actor_AddHP(0, 500);
        func_8003F9CC(2.5, arg3, arg4, 0);
        if (arg1) SFX_GemX(0x3B, arg0);
        else SFX_ActorPanX(0x3B, arg0);
    }
    else{ //green gem as catch-all
      func_8003F8B0(1.0, arg3, arg4, ((gPlayerActorIndex * 0x198) + 0x800F0000)->unk - A60);
    if (gPlayerActorIndex)
        gActors[gPlayerActorIndex].health += 300;
    else
        Actor_AddHP(0, 300);
    if (arg1) {
        SFX_GemX(0x125, arg0);
    }
    SFX_ActorPanX(0x125, arg0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/GemCollision.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/GemCollision_Actor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/GemCollision_Static.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8002FEF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80030008.s")
//behavoir for gem actor
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/ActorTick_Gem.s")

void ActorTick_GemChild(uint16_t index){
    ActorTick_Gem(index);
    thisActor.gFlag|=0x100;
}

//actor 0x000e - a clancer doing a shake-shake?
void func_800309C0(uint16_t index){
    if(thisActor.actorState==0){
        thisActor.actorState++;
        thisActor.flag=ACTOR_FLAG_ENABLED;
        thisActor.graphicList=&D_800E1DEC;
        thisActor.graphicTime=1;
    }
}

void func_80030A24(uint16_t index){
    func_8002B25C(index,thisActor.pos2.x_1);
}

void func_80030A74(uint16_t index) {
    if (gSceneFrames & 1) {
        thisActor.rgba.r = 0x7f;
        thisActor.rgba.g = 0x7f;
        thisActor.rgba.b = 0x7f;
    }
    else {
        thisActor.rgba.r = 0x4f;
        thisActor.rgba.g = 0x4f;
        thisActor.rgba.b = 0x4f;
    }
}

#ifdef NON_MATCHING
void func_80030B0C(uint16_t index) {
    if (thisActor.pos2.x_w <=0)
        thisActor.rgba.a = func_8002AE44(thisActor.rgba.a, thisActor.unk_0x108._lo);
    else
      thisActor.pos2.x_w--;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80030B0C.s")
#endif

void func_80030B84(uint16_t index) {
    func_80030A74(index);
    func_80030B0C(index);
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80030BB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80030D9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80030E58.s")

uint16_t ActorSpawn_Particle(uint16_t i, void* p, int32_t x, int32_t y, uint32_t z){
    uint16_t index = i & 0x7fff;
    if(index){
        ACTORINIT(index,9);
        thisActor.flag = ACTOR_FLAG_ENABLED;
        if(i&0x8000){
          thisActor.pos.x_w = x;
          thisActor.pos.y_w = y;
          thisActor.pos.z_w = z;
        }
        else{
          thisActor.pos.x = x;
          thisActor.pos.y = y;
          thisActor.pos.z = z;
        }

        thisActor.unk_0x130=-1.0;
        thisActor.unk_0x184._w=thisActor.pos.x_w;
        thisActor.unk_0x188._w=thisActor.pos.y_w;
        thisActor.unk_0x148=240.0;
        if(p==&gGraphicListDefault) thisActor.graphicTime = 0x1E0;
        else thisActor.graphicList=p;
    }
    return index;
}


uint16_t ActorSpawn_ParticleImage(uint16_t i, uint16_t c, uint32_t x, uint32_t y, uint32_t z){
    uint16_t index = i & 0x7fff; 
    if(index){
        ACTORINIT(index,9);
        thisActor.flag = ACTOR_FLAG_ENABLED;
        if(i&0x8000){
          thisActor.pos.x_w = x;
          thisActor.pos.y_w = y;
          thisActor.pos.z_w = z;
        }
        else{
          thisActor.pos.x = x;
          thisActor.pos.y = y;
          thisActor.pos.z = z;
        }
        thisActor.unk_0x130=-1.0;
        thisActor.unk_0x184._w=thisActor.pos.x_w;
        thisActor.unk_0x188._w=thisActor.pos.y_w;
        thisActor.unk_0x148=240.0;
        thisActor.graphic = c;
    }
    return index;
}


uint16_t ActorSpawn_Particle_16_45(void* p, int32_t x, int32_t y, int32_t z) {
    return ActorSpawn_Particle(Actor_GetInactive(16, 45), p, x, y, z);
}

uint16_t ActorSpawn_ParticleImage_16_45(uint16_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3) {
    return ActorSpawn_ParticleImage(Actor_GetInactive(16, 45), arg0, arg1, arg2, arg3);
}

uint16_t ActorSpawn_Particle_144_192(void* p, int32_t x, int32_t y, int32_t z) {
    return ActorSpawn_Particle(Actor_GetInactive_144_192(), p, x, y, z);
}

uint16_t ActorSpawn_ParticleImage_144_192(uint16_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3) {
    return ActorSpawn_ParticleImage(Actor_GetInactive_144_192(), arg0, arg1, arg2, arg3);
}

uint16_t ActorSpawn_Particle_pos32_16_45(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3) {
    return ActorSpawn_Particle(Actor_GetInactive(16, 45) | 0x8000, arg0, arg1, arg2, arg3);
}

uint16_t ActorSpawn_ParticleImage_pos32_16_45(uint16_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3) {
    return ActorSpawn_ParticleImage(Actor_GetInactive(16, 45) | 0x8000, arg0, arg1, arg2, arg3);
}

uint16_t ActorSpawn_Particle_pos32_144_192(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3) {
    return ActorSpawn_Particle(Actor_GetInactive_144_192() | 0x8000, arg0, arg1, arg2, arg3);
}

uint16_t ActorSpawn_ParticleImage_pos32_144_192(uint16_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3) {
    return ActorSpawn_ParticleImage(Actor_GetInactive_144_192() | 0x8000, arg0, arg1, arg2, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/ActorTick_Particle.s")

uint16_t func_80031CAC(uint16_t arg0, int32_t x, int32_t y, int32_t z) {
    uint16_t index = Actor_GetInactive_144_192();
    if (index) {
        ACTORINIT(index,0x34);
        thisActor.flag = ACTOR_FLAG_ENABLED;
        thisActor.graphic = arg0;
        thisActor.pos.x_w = x;
        thisActor.pos.y_w = y;
        thisActor.pos.z_w = z;
        thisActor.unk_0x148 = 1.0;
    }
    return index;
}
void func_80031D58(uint16_t arg0, uint16_t index) {
    if (index < arg0) {
        thisActor.unk_0x148 = 0.0;
    }
    else {
        thisActor.unk_0x148 = 1.0;
    }
}

#ifdef NON_MATCHING
void ActorTick_34h(uint16_t index) {
    if (thisActor.unk_0x148 == 0.0) {
        thisActor.flag = 0;
}
    thisActor.unk_0x148 -= 1.0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/ActorTick_34h.s")
#endif
//29 args. used by "cerberus Alpha"
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80031E38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800320F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800327B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80032900.s")
//seems to be used for putting on hats
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80032E60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800330A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80033204.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800333A0.s")
//actor type 7: copies an actor's transform, graphic, flags, and uses 0x18C as a fade delta.
//thus far, only used in func_801946CC_715BFC
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/ActorSpawn_7.s")

void ActorTick_7(uint16_t index){
    if(thisActor.rgba.a<(int32_t)thisActor.unk_0x18C._w) thisActor.flag=0;
    else thisActor.rgba.a-=thisActor.unk_0x18C._w;
}
//spawns Actor Type 6: dizzy stars. called in func_8006f5d4
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/ActorSpawn_DizzyStar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/ActorTick_DizzyStar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800337F4.s")

void func_800338F4(int16_t x, int16_t y, int16_t z) {
    if ((gSceneFrames & 0x0F) == 0) {
        func_800337F4(x, y, z, 0x132);
    }
}

uint16_t gNoteGraphicIndecies[4] = { 0x136, 0x138, 0x13A, 0x13A };
//spawn notes while idling
void PartcleSpawn_FloatingNotes(int16_t x, int16_t y, int16_t z) {
    if ((gSceneFrames & 0x0F) == 0) {
        func_800337F4(x, y, z, gNoteGraphicIndecies[RNG(3)]);
    }
}

void func_800339AC(int16_t x, int16_t y, int16_t z) {}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800339BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80033B54.s")
//Spawn Actor Type 0x05. unused?
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/ActorSpawn_Type5.s")

void ActorTick_Type5(uint16_t index){
    if(--thisActor.gp1._w == 0) thisActor.flag=0;
    thisActor.vel.x_w+=thisActor.gp2._w;
    thisActor.vel.y_w+=thisActor.gp3._w;
    thisActor.gp0._w = RGB16_Add(thisActor.gp0._h[1],thisActor.gp6._h[1],thisActor.gp5._lo,thisActor.gp4._lo);
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80033E7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800340CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80034644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003480C.s")
#ifdef NON_MATCHING
// How do I const floats?
void func_800348E4(uint16_t index){
    MODi(thisActor.rgba.a,0,2);
    MODi(thisActor.scaleX,-0.01f,thisActor.unk_0x114);
    MODi(thisActor.scaleY,-0.01f,thisActor.unk_0x118);
    if((thisActor.rgba.a==0)||(thisActor.scaleX<0.0)||(thisActor.scaleY<0.0)){
        thisActor.flag=0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800348E4.s")
#endif
//are these 3 unused?
void func_800349C0(uint16_t index,uint16_t x){
    if(thisActor.actorLink==0)thisActor.unk_0xD4=x;
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80034A0C.s")
void func_80034D14(uint16_t index){
    thisActor.scaleX=thisActor.gp6._w /1000.0f;
    thisActor.scaleY=thisActor.gp7._w /1000.0f;
}
//when called, u16[]* should casted as ClanpotItem*
#ifdef NON_MATCHING
void ActorClanpot_InitItems(uint16_t index, ClanpotItem* items){
    uint16_t i;
    for(i=31;-1<i;i--){
        if(items->flags==0xFFFF) return;
        gClanpotItems[i].flags=items->flags;
        gClanpotItems[i].ActorFeild0x110=items->ActorFeild0x110;
        gClanpotItems[i].ActorFeild0xD8=items->ActorFeild0xD8;
        gClanpotItems[i].unk_0x6=items->unk_0x6;
        thisActor.unk_0x170._w=i;
        gClanpotItems[i].ActorType=items->ActorType;
        items++;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/ActorClanpot_InitItems.s")
#endif
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80034E10.s")
#ifdef NON_MATCHING
int16_t func_8003510C(uint16_t index, uint16_t arg1, uint16_t arg2, uint16_t arg3, uint16_t arg4){
    uint32_t other=thisActor.unk_0xCC&0xff;
    if(((thisActor.flag3&0x200)==0)&&(thisActor.flag3&0x20)&&(gActors[other].actorType==0x18))
      return func_80034E10(index,arg1,arg2,arg3,arg4,other);
    return-1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003510C.s")
#endif

int16_t func_800351C8(uint16_t index, uint16_t arg1, uint16_t arg2, uint16_t arg3){
    return func_8003510C(index,arg1,arg2,arg3,0);
}
int16_t func_80035218(uint16_t index, uint16_t arg1, uint16_t arg2, uint16_t arg3, uint16_t arg4){
    return func_8003510C(index,arg1,arg2,arg3,arg4);
}

int16_t func_8003526C(uint16_t index, uint16_t arg1, uint16_t arg2, uint16_t arg3, uint16_t arg4){
    return func_8003510C(index,arg1,arg2,arg3,arg4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800352C0.s")
//spawn yellow gem from pot?
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80035394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80035524.s")
void func_80035824(uint16_t index){
    thisActor.hitboxAY0=0x14;
    thisActor.hitboxAY1=6;
    thisActor.hitboxAX0=-8;
    thisActor.hitboxAX1=8;
}

void func_80035878(uint16_t index){
    thisActor.hitboxBY0=14;
    thisActor.hitboxBY1=-10;
    thisActor.hitboxBX0=-8;
    thisActor.hitboxBX1=8;
}

uint32_t func_800358CC(uint16_t i , uint16_t x){return 0;}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800358DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80035978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80035A20.s")
//prints a number. used also by Teran Counting jumps.
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80035C44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80035D34.s")
//clanpot inventory behavior?

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80035E90.s")
/*
void func_8003667C(uint16_t index){
    if(thisActor.actorState) func_80035A20(index);
    else func_800358DC(index);
}*/
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003667C.s")
//spawn clanpot?
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800366E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800367D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800369A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80036A60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80036B44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80036C14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80036CE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80036DC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/clanpot_eraseItem.s")
//clanpot item merge?
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800370AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800374D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003766C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80037B18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80037B90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80038398.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800384FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80038600.s")

#ifdef NON_MATCHING
void func_80038704(uint16_t x){
    func_800384FC(x,0x4000,0x400,-(RNG(3)),RNG(3));
    func_80038600(x,0x4000,0x400,RNG(1),RNG(1));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80038704.s")
#endif

//#ifdef NON_MATCHING
void func_80038794(uint16_t index){ //uses rodata.
    if(gSceneFrames&20) MODf(thisActor,unk_0x148,.9,.02);
    else MODf(thisActor,unk_0x148,1.1,.02);
}/*
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80038794.s")
#endif*/

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80038868.s")

void func_80038C94(uint16_t index){
    thisActor.unk_0x190=NULL;
    thisActor.unk_0x180._w=thisActor.pos.x+gScreenPosCurrentX._hi;
    thisActor.unk_0x184._w=thisActor.pos.y+gScreenPosCurrentY._hi;
    if(thisActor.flag3<<15<0) SFX_ActorPanX(0x6e,index);
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80038D1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80038E1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80038FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800390BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80039134.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003929C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80039468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80039644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80039724.s")

void func_80039838(uint16_t index){
    thisActor.actorState--;
    thisActor.gp5._w=13;
    thisActor.gp0._w &= ~0xf0000;
}


void func_80039894(uint16_t index){
    thisActor.flag3 |=0x20000;
    Actor_Shade(index,127);
}
//play different sound if clanbomb.
void func_800398F8(uint16_t other,uint16_t index){
    if(thisActor.actorType==ACTORTYPE_CLANBOMB) SFX_ActorPanX(0x116,other);
    else SFX_ActorPanX(0x145,other);

}
int32_t func_80039970(uint16_t arg0, uint16_t index) {
    Actor* actorp = &thisActor;
    switch (actorp->actorType) {                             
    case ACTORTYPE_GEM: //add the bounce and lifetime as well.
        actorp->gp0._w = 0x78;
        actorp->vel.y_w = 0x40000;
        return SFX_ActorPanX(SFX_GEM_APPEAR, arg0);
    case 50:
        return SFX_ActorPanX(0x136, arg0);
    default:
        return SFX_ActorPanX(0x116, arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80039A1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80039ADC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80039C1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80039DA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80039E7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003A120.s")

void func_8003A958(uint16_t index){
    thisActor.unk_0x170._w+=0x1000000;
    SFX_ActorPanX(0x115,index);
}

void func_8003A9B8(uint16_t index){
    thisActor.unk_0x170._w-=0x1000000;
    SFX_ActorPanX(0x115,index);
}


#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003AA18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003AB24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003AC30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003B630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003B8CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003BE3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003C328.s")

uint16_t func_8003D518(uint16_t a,void* p,int32_t x,int32_t y,int32_t z){
    if(a==0) return ActorSpawn_Particle(Actor_GetInactive(0x10,0x2d), p, x, y, z);
    else return ActorSpawn_Particle(Actor_GetInactive(0x90,0xc0), p, x, y, z);
}

uint16_t func_8003D5A0(uint16_t a,uint16_t p,int32_t x,int32_t y,int32_t z){
    if(a==0) return ActorSpawn_ParticleImage(Actor_GetInactive(0x10,0x2d), p, x, y, z);
    else return ActorSpawn_ParticleImage(Actor_GetInactive(0x90,0xc0), p, x, y, z);
}
#ifdef NON_MATCHING
uint16_t ActorSpawn_AreaClear(u16 x){
    ACTORINIT(0xc0,ACTORTYPE_AREACLEAR);
    gActors[0xC0].flag = ACTOR_FLAG_ACTIVE;
    gActors[0xC0].unk_0x110=180.0f;
    gActors[0xC0].unk_0x188._w=x;
    CameraShake(8,60);
    return 0xC0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/ActorSpawn_AreaClear.s")
#endif
#ifdef NON_MATCHING
uint16_t func_8003D68C(u16 gFlag,s16 BY0,s16 BY1,s16 BX0,s16 BX1,int32_t posx,int32_t posy,int32_t posz,u8 r,u8 g,u8 b){
  uint16_t index = Actor_GetInactive_144_192();
  if (index) {
    ACTORINIT(index,0x34);
    thisActor.gFlag = gFlag & ~ACTOR_GFLAG_D;
    thisActor.flag = ACTOR_FLAG_ENABLED|ACTOR_FLAG_UNK3;
    thisActor.graphic = 0x8000;
    thisActor.pos.x_w = posx;
    thisActor.pos.y_w = posy;
    thisActor.pos.z_w = posz;
    thisActor.hitboxBY0 = BY0;
    thisActor.hitboxBY1 = BY1;
    thisActor.hitboxBX0 = BX0;
    thisActor.hitboxBX1 = BX1;
    thisActor.rgba.r = r;
    thisActor.rgba.g = g;
    thisActor.rgba.b = b;
    if (gFlag & ACTOR_GFLAG_D) thisActor.unk_0x148 = 1.0;
    else thisActor.unk_0x148 = 0.0;
  }
  return index;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003D68C.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/AreaClear_State0.s")
//"Escaped from trouble!" "Go to the Next Area!"
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/ActorTick_AreaClear.s")
//rapid explosion effect
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/BouncingExplosion.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003E230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003E52C.s")
//crosshair functions.
void Crosshair_CopyCoords(uint16_t index){
    thisActor.pos.x_w = gActors[thisActor.gp0._hu[1]].pos.x_w;
    thisActor.pos.y_w = gActors[thisActor.gp0._hu[1]].pos.y_w;
    thisActor.pos.z_w = gActors[thisActor.gp0._hu[1]].pos.z_w + 0x200000;
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/ActorSpawn_Crosshair.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/ActorTick_Crosshair.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003EAE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003EC0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003ED48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003EDF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003EEC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003EF98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/ParticleSpawn_Explosion.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003F138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003F248.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003F360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003F6A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003F7A0.s")
#ifdef NON_MATCHING
const double D_800EBC68=0.15000000000000002;
const double D_800EBC70=-0.013499999999999998;
uint16_t func_8003F8B0(float scale, int16_t x, int16_t y, int16_t z) {
    uint16_t index = ActorSpawn_ParticleImage_144_192(0x132U, x, y, z + 1);
    if (index) {
        thisActor.gFlag = 1;
        thisActor.scaleX = scale;
        thisActor.scaleY = scale;
        thisActor.unk_0x110 = (scale * D_800EBC68);
        thisActor.unk_0x114 = (scale * D_800EBC68);
        thisActor.vel.y_w = 0x20000;
        thisActor.gp3._w = -0x2000;
        thisActor.unk_0x118 = (scale * D_800EBC70);
        thisActor.unk_0x11C = (scale * D_800EBC70);
        thisActor.colorFunc= func_80030A24;
        thisActor.unk_0x148 = 24.0;
        Actor_Shade(index, 0x40U);
        thisActor.pos2.x_w = -4;
        thisActor.gp1._w = -4;
        thisActor.vel.z_w = 0x20000;
    }
    return index;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003F8B0.s")
#endif
//this was the yellow gem particle effect.
void func_8003F9CC(float f, uint16_t a, uint16_t b, uint32_t c) {}
//generate a puff of smoke
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003F9E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003FB20.s")
//generates an expanding ring
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003FD0C.s")
//above ring is white
void func_8003FE4C(float f, int16_t x, int16_t y, uint32_t z){
   func_8003FD0C(f,x,y,z,0);
}

void func_8003FE90(float f, int16_t x, int16_t y, uint32_t z){
   func_8003FD0C(f,x,y,z,1);
}

void func_8003FED8(float f, int16_t x, int16_t y, uint32_t z){
   func_8003FD0C(f,x,y,z,2);
}
void func_8003FF20(float f, int16_t x, int16_t y, uint32_t z){
   func_8003FD0C(f,x,y,z,3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8003FF68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80040098.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8004023C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800404AC.s")

//#ifdef NON_MATCHING
void func_80040564(uint16_t index) {
    switch(thisActor.actorState){
      case 0: {
          thisActor.flag = ACTOR_FLAG_ENABLED|ACTOR_FLAG_UNK7|ACTOR_FLAG_UNK8|ACTOR_FLAG_UNK12|ACTOR_FLAG_UNK15;
          break;
      }
      case 1: break;
    }
}
//#else
//#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80040564.s")
//#endif

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800405C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800406A4.s")


int32_t func_800407D4(uint16_t arg0) {
    if (gSpeaker_ActorLink==arg0) {
        switch (D_800D5824) {
        case 0x1000:
            return 0x1000;
        case 0x8000:
            return 0x8000;
        case 0x800:
            return 0x800;
        case 0x4000:
            return 0x4000;
        case 0x2000:
            return 0x2000;
        }
    }
  return 0;
}

#ifdef NON_MATCHING
void func_80040858(int16_t arg0) {
    if ((arg0 == gSpeaker_ActorLink) && (func_8005DEFC())) {
        func_8005DFC8(0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80040858.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8004089C.s")

#ifdef NON_MATCHING
int32_t func_800409E0(uint16_t index) {
    if (thisActor.health > 0 && thisActor.unk_0xD4 <= 0 && (thisActor.flag & ACTOR_FLAG_ENABLED) == 3 &&
        thisActor.actorState < 0x51) {
        return 1;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800409E0.s")
#endif

int32_t func_80040A64(void) {
    if (gPlayerActorIndex == 0) return func_80048CE4();
    else if (TeranFlag > 0) return func_800409E0(gPlayerActorIndex);
}

//start of Warp Gate/Star actor functions
//Init func - actor does not have "spawn" and is loaded from overlay code.
void WarpStar_Init(uint16_t index) {
    thisActor.gFlag = 0x205;
    thisActor.flag = ACTOR_FLAG_ENABLED | ACTOR_FLAG_UNK12;
    thisActor.graphic = 0x1a8;
    thisActor.unk_0xDF = 0x40;
    Actor_HitboxBSet(index, 10);
    thisActor.pos.z = -1;
    thisActor.unk_0x11C = 1.0;
    thisActor.unk_0x120 = 255.0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80040B4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80040E08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80041018.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8004151C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_8004168C.s")

void WarpStar_MoveActor(uint16_t index, uint16_t* pos) {
    thisActor.pos.x = pos[0] - gScreenPosCurrentX._hi;
    thisActor.pos.y = pos[1] - gScreenPosCurrentY._hi;
}

#ifdef NON_MATCHING
void WarpStar_MoveAndFlip(uint16_t index, uint16_t* pos) {
    if (thisActor.unk_0x174)
        WarpStar_MoveActor(thisActor.unk_0x174, pos);
    else {
        WarpStar_MoveActor(0, pos);
        gPlayerPosXMirror._hi = gScreenPosCurrentX._hi + gPlayerActor.pos.x;
        gPlayerPosXMirror._hi = gScreenPosCurrentY._hi + gPlayerActor.pos.y;

        gPlayerActor.flag &= ~ACTOR_FLAG_FLIPPED;
        if ((pos[2] & 1)) {
            gPlayerActor.flag |= ACTOR_FLAG_FLIPPED;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/WarpStar_MoveAndFlip.s")
#endif

int32_t func_8004185C(uint16_t index) {
    if (thisActor.actorState == 2) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/ActorTick_WarpStar.s")

int32_t func_80042290(uint16_t index) {
    if (thisActor.actorType == 0x90C && (thisActor.flag & ACTOR_FLAG_ACTIVE)) {
        if ((thisActor.unk_0x188._w & 0x8000) == 0) {
            return 1;
        }
    }
    return 0;
}

void ActorTick_4(uint16_t index) {}
//used by the worm once.
void func_80042310(uint16_t arg0, int32_t arg1, int16_t arg2, uint32_t arg3) {}
//unused
void func_80042324(int32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3) {}

void func_80042338(uint16_t index) {}
void func_80042340(uint16_t index) {}
void func_80042348(uint16_t index) {}
void func_80042350(uint16_t index) {}
void func_80042358(uint16_t index) {}

void func_80042360(uint16_t index) {
    thisActor.actorState++;
}

#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_800423A0.s")

void func_800427E0(uint16_t index){
    uint16_t other = thisActor.gp1._hu[1];
    if(gActors[other].actorType==12){
        gActors[other].pos.x=thisActor.pos.x;
        gActors[other].pos.y=thisActor.pos.y;
        gActors[other].pos.z=thisActor.pos.z;
        return;
    }
    thisActor.actorState++;
}


#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80042864.s")

void func_800429A4(uint16_t index){
    thisActor.actorState++;
    thisActor.gFlag=0;
    thisActor.flag=ACTOR_FLAG_ENABLED;
    thisActor.graphic=0x1CE; //last frame of "poof" animation
    thisActor.rgba.r=128;
    thisActor.unk_0x110=30;
}


#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80042A0C.s")

void func_80042AEC(uint16_t index) {
    func_80042864(index);
    func_800423A0(index);
    func_800427E0(index);
}

#ifdef NON_MATCHING
void func_80042B2C(uint16_t index) {
    if (0.0 <= thisActor.unk_0x110) thisActor.actorState -=2;
    else thisActor.flag = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80042B2C.s")
#endif


void (*D_800D28B0[8])(uint16_t)={
    func_800429A4,func_80042360,func_80042A0C,func_80042AEC,func_80042B2C,
    NULL,NULL,NULL
};
//actor type 0x000B
void func_80042B94(uint16_t index){
    D_800D28B0[thisActor.actorState](index);
    thisActor.flag3&=~0x200600;
}

//stack issue?
#ifdef NON_MATCHING
void func_80042C10(uint16_t index){
  if ((thisActor.flag3 & 0x200) == 0) thisActor.flag3&=~0x200600;
  else if (thisActor.actorLink == 0) {
    if (thisActor.gp0._w == 0) func_8002ED34(index,thisActor.speedX._lo,thisActor.speedY._lo,0);
    thisActor.actorLink = 0;
    thisActor.flag3|= 0x200;
  }
  else {
    thisActor.flag = 0;
    thisActor.actorType = 0;
  }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/28EF0/func_80042C10.s")
#endif