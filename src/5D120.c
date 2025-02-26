

#include "common.h"

void func_8005C520(int8_t x, int8_t y){
    gPlayerActor.unk_0xDC|=0x40;
    gPlayerManager.unk_0xA=x;
    gPlayerManager.unk_0xB=y;
}

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005C550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005C5E0.s")

int32_t ABS(int32_t x){
    if(x<0)x=-x;
    return x;
}

float FABS(float x){
    if(x<0)x=-x;
    return x;
}
#ifdef NON_MATCHING
uint32_t RandModulo(uint32_t x){
    int32_t ret;
    uint8_t r = Rand();
    ret=r;
    if(x!=0)ret=r % x;
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/5D120/RandModulo.s")
#endif

#ifdef NON_MATCHING
uint16_t func_8005C774(int32_t x){
 if(x==0) return D_800BE668;
 if(x>=100) return D_800BE668+1;
return (D_800BE668+1)/(100.0/(float)x);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005C774.s")
#endif

uint8_t func_8005C870(uint8_t x){
    if((x&0x30)==0x30)return x & 0xC0;
    return x;
}

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/CameraShake_Tick.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/CameraShake.s")

int16_t CameraShake_GetTime(){
    return gCamShakeTime;
}

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005CAA8.s")

uint8_t func_8005D1B0(uint16_t index){
    return thisActor.unk_0xDF&3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005D1E8.s")
uint16_t ActorMarina_Getfield172h(uint16_t index){
    return thisActor.unk_0x170._hu[1]&0x1FFF;
}
#ifdef NON_MATCHING
uint32_t func_8005D370(uint16_t index, int32_t x){
    uint16_t b=ActorMarina_Getfield172h(index);
    uint16_t a=x;
    if(x!=b) thisActor.unk_0x170._w = a;
    return a!=b;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005D370.s")
#endif

void func_8005D3D8(uint16_t index){
    thisActor.unk_0x170._hu[1]&=0x1fff;
}

uint16_t func_8005D418(uint16_t index){
    return thisActor.unk_0x170._hu[1]&0xA000;
}

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005D450.s")
