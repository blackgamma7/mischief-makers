#include "common.h"
#ifdef NON_MATCHING
uint16_t func_800592A0(uint16_t other, int32_t* pos){
    uint16_t index;
    Actor* otherp;
    if(other<16) index=Actor_GetInactive(0x10,0x2d);
    else index=Actor_GetInactive(0x90,0xc0);
    if(index){
        ACTORINIT(index,9);
        otherp=&gActors[other];
        thisActor.flag2|=otherp->flag2&0x160;
        thisActor.flag|=otherp->flag&0x28|0x8000;
        thisActor.rgba.a=0xFE;
        thisActor.pos.x_w=pos[0]<<16;
        thisActor.pos.y_w=pos[1]<<16;
        thisActor.pos.z_w=pos[2]<<16;
        thisActor.unk_0x130=-1.0;
    }
    return index;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_800592A0.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_800593DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_80059624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_80059ABC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_80059D88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_80059F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005A068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005A1A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005A320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005A4B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005A6D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005A7D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005A930.s")

void func_8005ACA8(uint16_t index){}

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005ACB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005B164.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005B1E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005B3F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005B5FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005B82C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005BA38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005BBC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005BCF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005BFA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/ActorMarina_SetField180h.s")
//an unused version of the afterimage, generates 3 that follow Marina for more frames, not blue.
#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/ActorSpawn_MarinaAfterImages.s")
#ifdef NON_MATCHING
uint16_t ActorSpawn_MarinaAfterImage(uint16_t other){
  Actor* parent;
  uint16_t index = Actor_GetInactive(0x10,0x2d);
  if (index) {
    ACTORINIT(index,ACTORTYPE_MARINAAFTERIMAGE);
    parent= &gActors[other];
    thisActor.flag2 |= parent->flag2 & 0x160 | 0x800;
    thisActor.flag |= parent->flag & (ACTOR_FLAG_UNK3|ACTOR_FLAG_FLIPPED) | (ACTOR_FLAG_UNK19|ACTOR_FLAG_UNK27);
    thisActor.graphic = (D_800BE6A4 + gCurrentFramebufferIndex) * 2 + 2;
    thisActor.pos.x_w = parent->pos.x;
    thisActor.pos.y_w = parent->pos.y;
    thisActor.pos.z_w = parent->pos.z + -0x18000;
    thisActor.gp0._w = 0xf;
    thisActor.flag2 |= 0x10;
    thisActor.rgba.r = 0x7f;
    thisActor.rgba.g = 0x7f;
    thisActor.unk_0x14C = other;
    thisActor.actorState = 1;
  }
  return index;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/ActorSpawn_MarinaAfterImage.s")
#endif
#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/ActorTick_MarinaAfterImage.s")
