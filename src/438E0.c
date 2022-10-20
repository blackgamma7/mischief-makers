#include "common.h"

void func_80042CE0(void) {}

void func_80042CE8(int32_t a0) {}

void func_80042CF0(int32_t a0) {}

#ifdef NON_MATCHING
void func_80042CF8(uint16_t* arg0) {
    uint16_t* sp0;
    uint16_t index = 0;

    if (arg0 != 0 && arg0[0] != 0) {
        do {
            sp0 = D_800D2978[index];
            sp0[0] = arg0[0];
            sp0[1] = arg0[1];
            sp0[2] = arg0[2];

            index += 3;
            arg0 += 6;
        } while (arg0[3] != 0);
    }

    while (index != 0x600) {
        index += 3;
        D_800D2978[index] = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/438E0/func_80042CF8.s")
#endif

void func_80042D84(uint16_t index) {
    while (index != 0x600) {
        // index is being promoted to a u32 here (implicitly,) and this is on the same line as index += 3
        // this might be something like D_800D2978[index += 3]
        D_800D2978[index & 0xFFFFFFFF] = 0, index += 3; // whitespace memes
    }
}

#ifdef NON_MATCHING
void func_80042DBC(uint16_t* arg0, uint16_t arg1, int32_t* arg2) {
    int32_t temp_t9;
    uint16_t temp_a1;
    uint16_t temp_a1_2;
    uint16_t* temp_v0;
    uint16_t phi_a1;
    int32_t phi_a3;
    uint16_t* phi_a0;
    int32_t phi_a3_2;
    uint16_t phi_a1_2;
    int32_t* phi_a2;

    phi_a3_2 = 0;
    phi_a1_2 = arg1;
    phi_a2 = arg2;
    if (arg0 != 0) {
        temp_a1 = *arg0;
        phi_a1 = temp_a1;
        phi_a3 = 0;
        phi_a0 = arg0;
        phi_a3_2 = 0;
        phi_a1_2 = temp_a1;
        phi_a2 = &D_800D2978;
        if (temp_a1 != 0) {
            do {
                temp_v0 = &D_800D2978 + (phi_a3 * 2);
                temp_v0[0] = phi_a1;
                temp_v0[1] = phi_a0[1];
                temp_t9 = (phi_a3 + 3) & 0xFFFF;
                temp_v0[2] = phi_a0[2];
                temp_a1_2 = phi_a0[3];
                phi_a1 = temp_a1_2;
                phi_a3 = temp_t9;
                phi_a0 += 6;
                phi_a3_2 = temp_t9;
                phi_a1_2 = temp_a1_2;
                phi_a2 = &D_800D2978;
            } while (temp_a1_2 != 0);
        }
    }
    func_80042D84(phi_a3_2 & 0xFFFF);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/438E0/func_80042DBC.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/438E0/func_80042E28.s")

void func_80042E84(s16 x0,s16 y0,s16 z0,s16 x1,s16 y1,s16 z1,s16 x2,s16 y2,s16 z2){
  RGB16_AddN(0x803da200,0x80380000,0xff,x0,y0,z0);
  RGB16_AddN(0x803da400,0x80380200,0xff,x1,y1,z1);
  RGB16_AddN(0x803da600,0x80380400,0xff,x2,y2,z2);
}

void func_80042F2C(int16_t arg0, int16_t arg1, int16_t arg2) {
    func_80043234();
    RGB16_AddN(&D_800DE348, &D_800DE348, 0xDF, arg0,arg1,arg2);
    RGB16_AddN(&D_800DE508, &D_800DE508, 0xDF, arg0,arg1,arg2);
    RGB16_AddN(&D_800DE6C8, &D_800DE6C8, 0xDF, arg0,arg1,arg2);
    RGB16_AddN(&D_800DE888, &D_800DE888, 0xDF, arg0,arg1,arg2);
    RGB16_AddN(&D_800DEA48, &D_800DEA48, 0xDF, arg0,arg1,arg2);
    RGB16_AddN(&D_800DEF88, &D_800DEF88, 0xDF, arg0,arg1,arg2);
    RGB16_AddN(&D_800DEC08, &D_800DEC08, 0xDF, arg0,arg1,arg2);
    RGB16_AddN(&D_800DEDC8, &D_800DEDC8, 0xDF, arg0,arg1,arg2);
    RGB16_AddN(&D_800DF308, &D_800DF308, 0xDF, arg0,arg1,arg2);
    RGB16_AddN(&D_800DF4C8, &D_800DF4C8, 0xDF, arg0,arg1,arg2);
    RGB16_AddN(&D_800DF688, &D_800DF688, 0xDF, arg0,arg1,arg2);
    RGB16_AddN(&D_800DF148, &D_800DF148, 0xDF, arg0,arg1,arg2);
    RGB16_AddN(&D_800DDA88, &D_800DDA88, 0xDF, arg0,arg1,arg2);
    RGB16_AddN(&D_800DDE08, &D_800DDE08, 0xDF, arg0,arg1,arg2);
    RGB16_AddN(&D_800DDC48, &D_800DDC48, 0xDF, arg0,arg1,arg2);
    RGB16_AddN(&D_800DDFC8, &D_800DDFC8, 0xDF, arg0,arg1,arg2);
}


void func_8004320C(void) {
    D_800D2968 = -1;
    D_800D296C = 0;
    D_800D2974 = 0;
    D_800D2970 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/438E0/func_80043234.s")

void func_80043478(void) {
    RGB16_AddN(&D_800DD47C, &D_800DD47C, 0xFF, 4, 2, 2);
    RGB16_AddN(&D_800DD67C, &D_800DD67C, 0xFF, 2, 2, 2);
    RGB16_AddN(&D_800DD87C, &D_800DD87C, 0xFF, 2, 2, 2);
    RGB16_AddN(&D_800DCC7C, &D_800DCC7C, 0xFF, 2, 2, 2);
    RGB16_AddN(&D_800DC67C, &D_800DC67C, 0xFF, 2, 4, 2);
    RGB16_AddN(&D_800DC27C, &D_800DC27C, 0xFF, 2, 2, 4);
    RGB16_AddN(&D_800DC47C, &D_800DC47C, 0xFF, 4, 2, 2);
    RGB16_AddN(&D_800DC87C, &D_800DC87C, 0xFF, 2, 2, 2);
    RGB16_AddN(&D_800DCA7C, &D_800DCA7C, 0xFF, 2, 2, 2);
    RGB16_AddN(&D_800DC07C, &D_800DC07C, 0xFF, 2, 2, 2);
    RGB16_AddN(&D_800DB07C, &D_800DB07C, 0xFF, 7, 2, 2);
    RGB16_AddN(&D_800DB27C, &D_800DB27C, 0xFF, 7, 2, 2);
    RGB16_AddN(&D_800DB47C, &D_800DB47C, 0xFF, 1, 1, 1);
    RGB16_AddN(&D_800DB67C, &D_800DB67C, 0xFF, 2, 2, 2);
    RGB16_AddN(&D_800DB87C, &D_800DB87C, 0xFF, 1, 2, 5);
    RGB16_AddN(&D_800DBA7C, &D_800DBA7C, 0xFF, 3, 2, 3);
    RGB16_AddN(&D_800DBC7C, &D_800DBC7C, 0xFF, 4, 3, 2);
    RGB16_AddN(&D_800DFE48, &D_800DFE48, 0xFF, 2, 6, 2);
    RGB16_AddN(&D_800E0248, &D_800E0248, 0xFF, 8, 2, 2);
    RGB16_AddN(&D_800E0448, &D_800E0448, 0xFF, 3, 3, 7);
    RGB16_AddN(&D_800E0048, &D_800E0048, 0xFF, 3, 3, 3);
    RGB16_AddN(&D_800DFA48, &D_800DFA48, 0xE0, 2, 6, 2);
    RGB16_AddN(&D_800DFC48, &D_800DFC48, 0xE0, 8, 2, 2);
    RGB16_AddN(&D_800DF848, &D_800DF848, 0xE0, 4, 2, 4);
    RGB16_AddN(&D_800D9B7C, &D_800D9B7C, 0x7A, 1, 4, 1);
    RGB16_AddN(&D_800D9E7C, &D_800D9E7C, 0x7A, 4, -1, 1);
    RGB16_AddN(&D_800D9C7C, &D_800D9C7C, 0x7A, 1, 1, 3);
    RGB16_AddN(&D_800D9F7C, &D_800D9F7C, 0x7A, 1, 1, 1);
    RGB16_AddN(&D_800D9D7C, &D_800D9D7C, 0x7A, 1, 2, 3);
}

void func_80043918(void) {
    D_800D28EC = 0;
    D_800D28F0 = 0;
    D_800D28F8 = 0;
    D_800D28FC = 0;
    D_800D28F4 = 1;
    D_800D28E8 = 0;
    gExitAnimationProgress = 0;
    D_800BE668 = 0x32;
    func_8002653C();
    func_80043234();
    func_8004320C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/438E0/loadSceneActor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/438E0/LoadOverlayActors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/438E0/func_80043C10.s")
#ifdef NON_MATCHING
void func_80043D04(uint16_t *x){
  uint16_t j;
  uint16_t i = *x;
  while (i != 0xff00) {
    j = i & 0xd7ff;
    i = x[7];
    *x = j;
    x+=7;
  }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/438E0/func_80043D04.s")
#endif

void func_80043D30(uint16_t* x) {
    if (D_800D2908 == 0) {
        func_80043D04(x);
    }
    LoadOverlayActors(x);
}

#pragma GLOBAL_ASM("asm/nonmatchings/438E0/func_80043D6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/438E0/func_80043E64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/438E0/func_8004400C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/438E0/func_800441F4.s")
