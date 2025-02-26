#include "common.h"

#ifdef NON_MATCHING
uint16_t ActorTick_Marina_SetFacing(uint16_t index) {
    uint16_t ret;

    if ((gMarinaButtonHold & gButton_DLeft) == 0) {
        ret = 0;
        if ((gMarinaButtonHold & gButton_DRight) && (ret = 2, thisActor.flag & 0x20)) {
            ret = 0x82;
        }
    }
    else {
        ret = 1;
        IFFACINGLEFT(index) {
            ret = 0x81;
        }
    }

    if (gMarinaButtonHold & gButton_DDown) {
        ret |= 0x10;
    }

    if (gMarinaButtonHold & gButton_DUp) {
        ret |= 0x20;
    }

    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/ActorTick_Marina_SetFacing.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/func_800486F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/func_80048740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/func_80048BB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/func_80048C28.s")

int32_t gMarinaVelocities[32] = {
    0x4000,  0x20000, 0x20000, 0x10000, 0x8000,  0x38000, 0x38000, 0x38000, 0x28000, 0x2666,
    0x50000, 0x50000, 0x50000, 0x50000, 0x50000, 0x30000, 0x30000, 0x30000, 0x28000, 0x6000,
    0x28000, 0x28000, 0x28000, 0x20000, 0x38000, 0x38000, 0x38000, 0x28000, 0x30000, 0x30000,
    0x30000, 0x20000
};

int32_t ActorMarina_VelByScale(int32_t arg0) {
    return gMarinaVelocities[arg0] * gPlayerActorScale;
}

int32_t func_80048CE4() {
    if (gPlayerActor.actorState_b[1] == 1) {
        return 1;
    }

    if (gPlayerActor.actorState_b[1] < 46) {
        return 0;
    }

    if (gPlayerActor.actorState_b[1] < 55) {
        return 2;
    }

    return 3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/ActorMarina_SetReachHitbox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/func_80048EDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/func_80048F70.s")

int32_t func_80049040(uint16_t index) {
    if ((thisActor.flag3 & 0x40) == 0) {
        return 0;
    }

    thisActor.flag &= ~(ACTOR_FLAG_UNK6 | ACTOR_FLAG_UNK14);
    thisActor.flag &= ~(ACTOR_FLAG_UNK16 | ACTOR_FLAG_UNK17 | ACTOR_FLAG_UNK22 | ACTOR_FLAG_UNK23),
        thisActor.flag |= ACTOR_FLAG_UNK17; // whitespace memes

    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/func_800490BC.s")

#ifdef NON_MATCHING
// Needs reordering
int32_t func_800491B8(uint16_t index, uint32_t arg1, int16_t arg2) {
    Actor* actor = &thisActor;

    if (actor->vel.y_w > 0) {
        return 0;
    }

    if ((actor->flag3 & 0x20) == 0) {
        return 0;
    }

    actor->flag &=
        ~(ACTOR_FLAG_UNK6 | ACTOR_FLAG_UNK7 | ACTOR_FLAG_UNK9 | ACTOR_FLAG_UNK11 | ACTOR_FLAG_UNK14 | ACTOR_FLAG_UNK16 | ACTOR_FLAG_UNK17 |
          ACTOR_FLAG_UNK22 | ACTOR_FLAG_UNK23); // 0xFF3CB53F;
    actor->flag |= ACTOR_FLAG_UNK16;
    arg2 = ((float)arg2 * gActors->unk_0x120);

    actor->gp0._w = ABS(actor->vel.y_w) - 4;
    if (actor->gp0._w <= 0) {
        actor->gp0._w = 1;
    }

    actor->vel.y_w = 0;
    actor->gp0._w *= 3;
    if (arg1 >= 0) {
        actor->unk_0x17C._w = arg1;
        if (arg2 < actor->hitboxBY1) {
            actor->pos.y = (actor->pos.y + actor->hitboxBY1) - arg2;
        }
    }

    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/func_800491B8.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/func_80049300.s")

uint32_t func_80049460(uint16_t index) {
    switch (func_80049300(index)) {
        case 1: {
            if (thisActor.flag3 & 0x80) thisActor.unk_0x140._bu[0] = 0;
            if (D_801373D8 & 2) thisActor.flag &= ~ACTOR_FLAG_FLIPPED;
            if (D_801373D8 & 1) thisActor.flag |= ACTOR_FLAG_FLIPPED;

            if (thisActor.actorState_b[1] != 0x16) thisActor.gp0._w = 0;
            thisActor.actorState = 0x1F;

            return 1;
            break;
        }
        case 2: {
            if (thisActor.flag3 & 0x80) thisActor.unk_0x140._bu[0] = 0;

            if (D_801373D8 & 2) thisActor.flag &= ~ACTOR_FLAG_FLIPPED;
            if (D_801373D8 & 1) thisActor.flag |= ACTOR_FLAG_FLIPPED;
            if (thisActor.actorState_b[1] != 0x16) thisActor.gp0._w = 0;

            thisActor.actorState = 0x1F;

            return 2;
            break;
        }
        case 3: {
            if (D_801373D8 & 0x20) thisActor.actorState = 0x2D;
            else thisActor.actorState = 0x2C;

            return 3;
            break;
        }
        default: {
            return 0;
            break;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/func_80049660.s")

int32_t func_80049A04(uint16_t index) {
    short new_var;
    uint32_t temp_a0;

    temp_a0 = D_800D4184[ActorMarina_Getfield172h(index)];
    if (temp_a0 == 0) {
        return 0;
    }

    new_var = *((int8_t*)(temp_a0 + thisActor.unk_0x170._b[1]));
    return (float)(new_var << 0x10) * gActors->unk_0x120;
}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/func_80049AC0.s")

void func_8004A8E0(uint16_t index) {
    thisActor.unk_0x12C._bu[2] = 0xFF;
}

void ActorMarina_State01h(uint16_t index) {
    Actor* actor = &thisActor;

    actor->unk_0x12C._bu[2] |= 0x41;
    actor->flag = actor->gp0._w;
}
//gPlayerActor.actorState 0
#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/ActorMarina_Init.s")

void func_8004AA64(uint16_t index) {
    thisActor.unk_0x12C._bu[2] |= 0x41;
    if (thisActor.actorState_b[0] == 0) {
        thisActor.unk_0x140._hu[1] = 0;
        thisActor.unk_0x140._bu[1] = 0;
        thisActor.unk_0x180._w = 0;
        gPlayerManager.unk_0x13 = 0;
        gPlayerManager.unk_0x12 = 100;
        thisActor.unk_0x12C._bu[3] = 0;
        thisActor.vel.y_w = 0;
        thisActor.vel.x_w = 0;
        thisActor.flag &= ACTOR_FLAG_FLIPPED;
        thisActor.flag |= ACTOR_FLAG_ENABLED | ACTOR_FLAG_UNK8 | ACTOR_FLAG_UNK12 | ACTOR_FLAG_UNK16 | ACTOR_FLAG_UNK27;
        thisActor.actorState_b[0] = 1;
        thisActor.unk_0x128 = 1.0f;
        thisActor.unk_0x124 = 1.0f;
    }

    thisActor.unk_0x17C._w = 0;
    func_8005D370(index, 1);
    thisActor.actorState = 3;
}
//deals with marina's idle state
#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/ActorMarina_Default.s")

void func_8004B0A0(uint16_t index) {
    Actor* actor = &thisActor;
    actor->unk_0x12C._hu[0] = 7;
    MODi(actor->vel.x_w, 0, ActorMarina_VelByScale(0));

    if (actor->actorState_b[0] == 0) {
        func_8005A4B0(index, 1.0f);
        SFX_Play_1(0x25U);
        actor->unk_0x170._w = 0x2A;
        actor->actorState_b[0]++;
    }

    if (actor->unk_0x170._b[1] == 1) {
        actor->unk_0x170._b[0] = 0;
        if (actor->gp0._w == 0) actor->unk_0x170._b[1] = 2;
        else actor->gp0._w--;
    }

    if (func_8005D418(index)) {
        actor->actorState = (uint16_t)3;
    }
}

void ActorMarina_Walk(uint16_t index) {
    int32_t vel;
    Actor* actor;

    actor = &thisActor;
    actor->unk_0x12C._hu[0] = 7;

    vel = ActorMarina_VelByScale(1);
    if (actor->flag & ACTOR_FLAG_FLIPPED) {
        vel = -vel;
    }

    MODi(actor->vel.x_w, vel, ABS(vel) / 8);
    func_8005D370(index, 29);

    if (actor->unk_0x170._b[0] == 0 && (actor->unk_0x170._b[1] == 2 || actor->unk_0x170._b[1] == 8)) {
        SFX_Play_1(0x53U);
    }

    if (((D_801373D8 & 3) == 0) || (D_801373D8 & 0x80)) {
        actor->actorState = 3;
    }
}

void func_8004B290(uint16_t index) {
    thisActor.unk_0x12C._hu[0] = 7;
    if (thisActor.actorState_b[0] == 0) {
        thisActor.unk_0x170._w = 0x2D;
        thisActor.actorState_b[0] = 1;
    }
    MODi(thisActor.vel.x_w, 0, ActorMarina_VelByScale(0) * 2);
    if (thisActor.vel.x_w != 0) {
        thisActor.unk_0x180._bu[3] = 4;
    }
    else{
        thisActor.flag |= ACTOR_FLAG_UNK14;
        thisActor.actorState = 3;
    }
}
#ifdef NON_MATCHING
void ActorMarina_Dash(uint16_t index) { //regalloc, stack. 99.48% matching
    s32 sp38[6];
    s32 temp_v1;
    s16 phi_a0;

    thisActor.unk_0x12C._hu[0] = 2U;
    if (thisActor.actorState_b[0] == 0) {
        thisActor.gp0._w = 0x10;
        if (D_801373F0 == 4) {
            thisActor.vel.x_w = (D_801373EE / 100) * ActorMarina_VelByScale(5) + ActorMarina_VelByScale(9);
            if (ActorMarina_VelByScale(10) < thisActor.vel.x_w) {
                thisActor.vel.x_w = ActorMarina_VelByScale(0xA);
            }
            thisActor.actorState_b[0] = 2U;
            IFFACINGLEFT(index) {
                thisActor.actorState_b[0] |= 0x80;
            }
        }
        if (D_801373F0 == 0xC) {
            thisActor.vel.x_w = -((D_801373EE / 100) * ActorMarina_VelByScale(5) + ActorMarina_VelByScale(9));
            if (thisActor.vel.x_w < -ActorMarina_VelByScale(0xA)) {thisActor.vel.x_w = -ActorMarina_VelByScale(0xA);}
            thisActor.actorState_b[0] = 1U;
            IFFACINGRIGHT(index) {
                thisActor.actorState_b[0]|= 0x80;
            }
        }
        thisActor.unk_0xDA = 0;
        thisActor.unk_0xDB = 0x15;
        thisActor.attackDmg = 0;
        thisActor.hitboxAY0 = thisActor.hitboxBY0 - 2;
        thisActor.hitboxAY1 = thisActor.hitboxBY1 + 8;
        if ((thisActor.actorState_b[0] & 0x80) == 0) {
            IFFACINGRIGHT(index) {
                thisActor.hitboxAX0 = 0;
                thisActor.hitboxAX1 = thisActor.hitboxBX1 + 1;
            } else {
                thisActor.hitboxAX1 = 0;
                thisActor.hitboxAX0 = thisActor.hitboxBX0 - 1;
            }
            thisActor.unk_0x170._w = 0x47;
        } else {
            IFFACINGRIGHT(index) {
                thisActor.hitboxAX1 = 0;
                thisActor.hitboxAX0 = (thisActor.hitboxBX0 - 1);
            } else {
                thisActor.hitboxAX0 = 0;
                thisActor.hitboxAX1 = (thisActor.hitboxBX1 + 1);
            }
            thisActor.unk_0x170._w = 0x4A;
        }
        ActorMarina_SetField180h(index, 1);
        thisActor.unk_0x17C = 0;
        thisActor.unk_0x17C._b[1] = 2;
        thisActor.unk_0x182 = (s8) D_801373F0;
        D_801373F2 = 0x14;
        D_801373F3 = 1;
    }
    if (((s8) thisActor.unk_0x170._b[0] == 0) && ((thisActor.unk_0x170._b[1] == 0) || (thisActor.unk_0x170._b[1] == 3))) {
        D_801370D2 = 0;
        func_8005C250(index);
    }
    if ((D_801373D8 & 0x10)) {
        thisActor.actorState = 9;
    } else {
        if (--thisActor.gp0._w == 0xA) {
            SFX_Play_1(0x27);
            sp38[1] = thisActor.pos.y+thisActor.hitboxBY1;
            sp38[3] = 0x16C;
            sp38[4] = 0;
            sp38[0] = thisActor.pos.x;
            sp38[2] = thisActor.pos.z;
            gActors[func_80059F30(index, sp38, 0.2, 0xF)].scaleY /= 2;
        }
        if (thisActor.gp0._w < 0xA) {
            thisActor.unk_0x12C._hu[0] |= 4;
        }
        if (thisActor.gp0._w < 8) {
            MODi(thisActor.vel.x_w, 0, ActorMarina_VelByScale(0));
        }
        if (ABS(thisActor.vel.x_w) >= 0x30000) {
            if (ABS(thisActor.hitboxAX0) < ABS(thisActor.hitboxAX1)) {
                phi_a0 = (thisActor.pos.x + thisActor.hitboxAX1 + 1);
            } else {
                phi_a0 = (thisActor.pos.x + thisActor.hitboxAX0  - 1);
            }
            if ((func_80012AB4(phi_a0, thisActor.pos.y) & 0x80)) {
                thisActor.actorState_b[0] = 1U;
                thisActor.actorState_b[1] = 0x11;
                thisActor.vel.x_w =-thisActor.vel.x_w *.75;
            } else {
                thisActor.flag |= 0x80;
                goto block_40;
            }
        } else {
block_40:
            if (thisActor.gp0._w == 0) {
                if (ABS(thisActor.vel.x_w)>ActorMarina_VelByScale(5)) {
                    thisActor.gp0._w = 1;
                } else {
                    thisActor.flag &=~0x80;
                    thisActor.flag |= 0x40;
                    thisActor.actorState = 3;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/ActorMarina_Dash.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/ActorMarina_SpinJump.s")
//marina's Down-A dash
#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/ActorMarina_SlideDash.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/ActorMarina_Roll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/ActorMarina_AirDash.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/func_8004CE1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/ActorMarina_DashJump.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/func_8004D6CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/ActorMarina_Reach.s")
//gPlayerActor.actorState 32
#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/func_8004DA6C.s")
//gPlayerActor.actorState 33
#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/func_8004DC44.s")
//gPlayerActor.actorState 44
void func_8004E1D4(int32_t arg0) {}
//gPlayerActor.actorState 45
void func_8004E1DC(int32_t arg0) {}
//gPlayerActor.actorState 55
#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/ActorMarina_TPAppear.s")
//gPlayerActor.actorState 56
#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/ActorMarina_TPVanish.s")
//animation test? set gplayeractor.actorState_b[1] to 0x3A
#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/ActorMarina_DebugGraphicLists.s")
//gPlayerActor.actorState 59
#ifdef NON_MATCHING
// Needs reordering
void ActorMarina_DebugGraphic(uint16_t index) {
    int16_t phi_a3;

    thisActor.unk_0x12C._bu[2] |= 0x40;

    if (thisActor.actorState_b[0] == 0) {
        thisActor.unk_0x170._w = 0;
        thisActor.actorState_b[0]++;
        thisActor.graphic = (uint16_t)thisActor.gp2._w;
    }

    func_80083A04(
        thisActor.graphic - thisActor.gp2._w, (int16_t)thisActor.pos.x - 0x20, (int16_t)thisActor.pos.y + 0x30, 0);

    phi_a3 = 0;
    if (((gButtonHold & gButton_DRight) != 0) &&
        (((thisActor.gp0._w == 0)) || (phi_a3 = 1, ((thisActor.gp0._w < 9) == 0)))) {
        thisActor.graphic++;
        phi_a3 = 1;
        if (thisActor.gp3 < (thisActor.graphic & 0xFFFF)) {
            thisActor.graphic = (uint16_t)thisActor.gp2._w;
            phi_a3 = 1;
        }
    }

    phi_a3++;
    if (((gButtonHold & gButton_DLeft) != 0) && (((thisActor.gp0._w == 0)) || (((thisActor.gp0._w < 9) == 0)))) {
        thisActor.graphic--;
        if ((thisActor.graphic & 0xFFFF) < thisActor.gp2._w) {
            thisActor.graphic = (uint16_t)thisActor.gp3;
        }
    }

    if (phi_a3 == 0) {
        thisActor.gp0._w = 0;
        return;
    }

    thisActor.gp0._w++;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/ActorMarina_DebugGraphic.s")
#endif
//gPlayerActor.actorState 3Ch -  Debug move
void ActorMarina_DebugMove(uint16_t index) {
    Actor* actor;
    uint32_t temp_v1;

    actor = &thisActor;
    thisActor.vel.x_w = 0;
    thisActor.unk_0x12C._bu[2] |= 0xC1;
    thisActor.vel.y_w = 0;

    temp_v1 = D_801373D8;
    if ((temp_v1 & 2)) {
        thisActor.vel.x_w = 0x80000;
    }

    if ((temp_v1 & 1)) {
        thisActor.vel.x_w = -0x80000;
    }

    if ((temp_v1 & 0x20)) {
        thisActor.vel.y_w = 0x80000;
    }

    if ((temp_v1 & 0x10)) {
        thisActor.vel.y_w = -0x80000;
    }

    gPlayerManager.DebugPosX = gPlayerPosXMirror._w;
    gPlayerManager.DebugPosY = gPlayerPosYMirror._w;
}

#ifdef NON_MATCHING
// ActorFunc for Marina
void ActorTick_Marina(uint16_t index) {
    int16_t* phi_v0;
    int16_t* phi_v1;

    if ((gPlayerManager.flags & 8) == 0) {
        if (thisActor.actorState == 0) {
            ActorMarina_Init(index);
        }

        D_800BE5E4 = 0;
        thisActor.gFlag &= 0xF781;
        thisActor.rgba.r = thisActor.rgba.g = thisActor.rgba.b = 0; // whitespace memes
        D_800BE5E0 = D_800BE5E4;
        gPlayerManager.playerLink = 0;
        thisActor.pos.z_w = 0;

        MODi(D_800D57E0, 0x6000, 0x400);

        if (thisActor.unk_0x12C._bu[3] < 4) {
            thisActor.unk_0x12C._bu[3]++;
        }

        gMarinaButtonHold = gButtonHold;
        D_801370CE = gButtonPress;

        if (D_800BE5F4._w != 0) {
            if (D_800BE5F4._w&0xFF == 2) {
                func_800485AC(index, &D_801370CE, &gMarinaButtonHold);
            }
            else {
                phi_v0 = gInputHistoryHold;
                phi_v1 = gInputHistoryPress;
                do {
                    phi_v0[1] = 0;
                    phi_v1[-3] = 0;
                    phi_v0[2] = 0;
                    phi_v1[-2] = 0;
                    phi_v0[3] = 0;
                    phi_v1[-1] = 0;
                    phi_v0[0] = 0;
                    phi_v1[0] = 0;

                    phi_v0 += 4;
                    phi_v1 += 4;
                } while (((uint32_t)&phi_v1[3]) != (uint32_t)&gInputHistoryPress[64]);

                D_801370CE = 0;
                gMarinaButtonHold = 0;

                thisActor.unk_0x12C._bu[3] = 0;

                gPlayerManager.unk_0x12 = 0x64;
                gPlayerManager.unk_0x13 = 0;

                func_800485AC(index, &D_801370CE, &gMarinaButtonHold);
            }
        }

        D_801373D8 = ActorTick_Marina_SetFacing(index);

        if (gPlayerManager.DebugPosX) {
            func_80083A04(gPlayerManager.DebugPosX, -0x20, 0x40);
            if ((gSceneFrames & 0x7F) == 0) {
                gPlayerManager.DebugPosX = 0;
            }
        }

        if (gPlayerManager.DebugPosY) {
            func_80083A04(gPlayerManager.DebugPosY, -0x20, 0x30);
            if ((gSceneFrames & 0x7F) == 0) {
                gPlayerManager.DebugPosY = 0;
            }
        }

        if (gPlayerManager.DebugValC) {
            func_80083A04(gPlayerManager.DebugValC, -0x20, 0x20);
            if ((gSceneFrames & 0x7F) == 0) {
                gPlayerManager.DebugValC = 0;
            }
        }

        if (gPlayerManager.DebugValD) {
            func_80083A04(gPlayerManager.DebugValD, -0x20, 0x10);
            if ((gSceneFrames & 0x7F) == 0) {
                gPlayerManager.DebugValD = 0;
            }
        }

        // when these two flags are set, marina looks like she's holding blockman,
        // however, blockman himself doesn't effect these
        // maybe it's the tricycle?
        thisActor.flag &= ~ACTOR_FLAG_UNK3;
        if (gPlayerManager.flags & 0x10000) {
            thisActor.flag |= ACTOR_FLAG_UNK3;
            thisActor.unk_0x12C._hu[0] &= 0xFFF8;
            thisActor.unk_0xDC &= 0xFFFE;
            thisActor.pos.x_w += gPlayerManager.unk_0x60;
        }

        func_80048740(index);

        if (func_80058F9C(index) == 0) {
            func_80049AC0(index);
        }

        thisActor.flag &= ~(ACTOR_FLAG_UNK7 | ACTOR_FLAG_UNK9 | ACTOR_FLAG_UNK11); //~0xA80;
        thisActor.unk_0x12C._hu[0] = 0;
        thisActor.unk_0x12C._bu[2] = 0;

        //(((thisActor.unkD0 & 0xFF) * 4) + 0x800D0000)->unk3DB0(index);
        gActorFuncTable_Marina[thisActor.actorState](index);

        func_80048BB0(index);

        if (thisActor.flag & ACTOR_FLAG_ATTACHED) {
            gPlayerManager.playerLink = thisActor.actorLink;

            if (ActorMarina_Getfield172h(index) < 0x66) {
                gActors[thisActor.actorLink].unk_0x108 += func_80049A04(index); // return size
            }

            // ((((((d6 * 4) - d6) * 4) + d6) * 4) - d6) * 8
            /* ((((((1 * 4) - 1) * 4) + 1) * 4) - 1) * 8
             * (((((4 - 1) * 4) + 1) * 4) - 1) * 8
             * ((((3 * 4) + 1) * 4) - 1) * 8
             * (((12 + 1) * 4) - 1) * 8
             * ((13 * 4) - 1) * 8
             * (52 - 1) * 8
             * 51 * 8
             * = 408 == 0x198
             * bruh
             */
            // held = (((((((thisActor.actorLink * 4) - thisActor.actorLink) * 4) + thisActor.actorLink) * 4) -
            // thisActor.actorLink) * 8) + gActors;
            gActors[thisActor.actorLink].pos2.x_w += thisActor.vel.x_w;
            gActors[thisActor.actorLink].unk_0x108 += thisActor.vel.y_w;
        }

        func_8005D450(index);
        func_8005CAA8(index, &D_800D4000);
        func_8005BFA4(index);

        if (func_8005C5E0(index) == 1 && thisActor.unk_0x13C >= 0x1F) {
            thisActor.unk_0x180._bu[3] = 6;
        }

        if ((thisActor.flag3 & 2) != 0) {
            gPlayerManager.actorSpeedX = thisActor.speedX._w;
            gPlayerManager.actorSpeedY = thisActor.speedY._w;
        }

        gPlayerManager.flag3 = thisActor.flag3;
        thisActor.flag3 &= ~0x200600;
        gPlayerManager.unk_0x7C++;

        thisActor.scaleX = D_800EF630 * thisActor.unk_0x124;
        thisActor.scaleY = (&D_800EF630)[-0x274] * thisActor.unk_0x128; // -0x9D0 (I don't know how this is produced?)

        D_800BE5D8 = thisActor.pos.x_w + gScreenPosCurrentX;
        D_800BE5DC = thisActor.pos.y_w + gScreenPosCurrentY;
        D_800BE5E8 = thisActor.vel.x_w;
        D_800BE5EC = thisActor.vel.y_w;

        if (gCurrentScene == SCENE_FREEFALL) { //play the fall whistle sound if falling in "freefall"
            if (thisActor.vel.y_w <= -294912.0) {
                if (gPlayerManager.FallBool == 0) {
                    if (func_8000334C(0x3E) >= 0) {
                        gPlayerManager.FallBool = 1;
                    }

                    return;
                }
            }
            else if (gPlayerManager.FallBool != 0) {
                SFX_Stop(0x3E);
                gPlayerManager.FallBool = 0;

                return;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ActorMarina/ActorTick_Marina.s")
#endif
