#include "festival.h"

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A6900_78CBF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A6ED4_78D1C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A7200_78D4F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A7304_78D5F4.s")

void func_801A73F4_78D6E4(uint16_t x,uint16_t y){}
void func_801A7400_78D6F0(uint16_t x,uint16_t y){}
void func_801A740C_78D6FC(uint16_t x,uint16_t y){}
void func_801A7418_78D708(uint16_t x,uint16_t y){}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A7424_78D714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A74A0_78D790.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A76AC_78D99C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A774C_78DA3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A7878_78DB68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A7940_78DC30.s")

void func_801A7C0C_78DEFC(uint16_t x){}

extern void func_801A7C14_78DF04(uint16_t);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A7C14_78DF04.s")
extern void func_801A7CA4_78DF94(uint16_t);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A7CA4_78DF94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A7E98_78E188.s")

void func_801A821C_78E50C(u16 arg0) {
    if (gActors[arg0].unk_0xD8 >= 2) {
        func_801A7C14_78DF04(arg0);
        func_801A7CA4_78DF94(arg0);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A8284_78E574.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A8380_78E670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A8428_78E718.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A8780_78EA70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A87C0_78EAB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A8800_78EAF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A8D38_78F028.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A913C_78F42C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A92D8_78F5C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A9440_78F730.s")

void func_801A9508_78F7F8(uint16_t x){}
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A9510_78F800.s")

void func_801A9690_78F980(uint16_t x){}
void func_801A9698_78F988(uint16_t index){
    thisActor.flag=0;
}
void func_801A96CC_78F9BC(uint16_t x){}
void func_801A96D4_78F9C4(uint16_t x){}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A96DC_78F9CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A9768_78FA58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A97FC_78FAEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A99E4_78FCD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A9A6C_78FD5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A9C24_78FF14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A9DD4_7900C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801A9FF0_7902E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AA108_7903F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AA208_7904F8.s")

void func_801AA2A4_790594(uint16_t index){
if(thisActor.func_0x190) thisActor.func_0x190(index);
}

void func_801AA2FC_7905EC(uint16_t x, uint16_t y){
    D_80178292 = 0;
    }

void func_801AA310_790600(uint32_t x,uint32_t y){
uint16_t i;
for(i=0;i<10;i++) {gFestivalEventsBools[i]=0;}
  gFestivalEventsComplete = 0;
  gFestivalPointsWhite = 0;
  gFestivalPointsRed = 0;
  gLetterboxMode = 1;
}


void func_801AA368_790658(void) {}
void func_801AA370_790660(void) {}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AA378_790668.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AA42C_79071C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AA480_790770.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AAB78_790E68.s")

void func_801AAFC4_7912B4(uint16_t x){}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AAFCC_7912BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AB14C_79143C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AB1EC_7914DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AB3EC_7916DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AB474_791764.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AB5B4_7918A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AB610_791900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AB6B4_7919A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AB710_791A00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AB7A0_791A90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801ABA40_791D30.s")
//resets festival competitor data
#ifdef NON_MATCHING
void func_801ABAE4_791DD4(uint16_t x){
  uint16_t i;
  if(gFestivalCompetitors>0){
   for(i=0;i<gFestivalCompetitors;i++){
    gFestivalStructs[i].playerNumber=i;
    gFestivalStructs[i].actorIndex=0;
    gFestivalStructs[i].unk_0x04=0;
    gFestivalStructs[i].unk_0x06=0;
    gFestivalStructs[i].unk_0x12=0;
    gFestivalStructs[i].unk_0x10=0;
   }
  }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801ABAE4_791DD4.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801ABB44_791E34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801ABB80_791E70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801ABBAC_791E9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801ABC8C_791F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801ABDA8_792098.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801ABE24_792114.s")
//returns true if not race
#ifdef NON_MATCHING
uint32_t func_801AC0F8_7923E8(){
  switch(gFestivalCurrentEvent) { //table loaded in wrong register
  case 0:
  case 1:
  case 2:
  case 5:
  case 7:
    return 0;
  case 3:
  case 4:
  case 6:
  case 8:
    return 1;
  }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AC0F8_7923E8.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AC13C_79242C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AC250_792540.s")
extern float D_801AFA24_795D14[27];
#ifdef NON_MATCHING
void func_801AC360_792650(uint16_t x){
  ///should push/pop RA. dunno why yet.
  ACTORINIT(58,0x1A08);
  gActors[58].flag |= ACTOR_FLAG_UNK3;
  gActors[58].pos.x=0, gActors[58].pos.y = 0;
  gActors[58].unk_0x178._p = &D_801AFA24_795D14; //an array of floats.
}
#else
extern void func_801AC360_792650(uint16_t x);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AC360_792650.s")
#endif
#ifdef NON_MATCHING
void func_801AC3C0_7926B0(uint16_t index, uint16_t x){
  ACTORINIT(index,0x1A07);
  thisActor.flag2=0x800;
  thisActor.flag=ACTOR_FLAG_ACTIVE|ACTOR_FLAG_UNK3;
  thisActor.pos.z = 0x80;
  thisActor.unk_0x164._w = 0x40;
  thisActor.gp0._w = x;
}
#else
extern void func_801AC3C0_7926B0(uint16_t index, uint16_t x);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AC3C0_7926B0.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AC448_792738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AC624_792914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AC698_792988.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AC760_792A50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801ACB58_792E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801ACC90_792F80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801ACD80_793070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801ACEE8_7931D8.s")
//award gems.
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801ACF40_793230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AD0AC_79339C.s")
//tally points earned.
#ifdef NON_MATCHING
void func_801AD37C_79366C(uint16_t index,uint16_t instant){
    if(thisActor.gp4._w==0){
        gFestivalPointsWhite+=thisActor.gp1._w;
        gFestivalPointsRed+=thisActor.gp2._w;
        thisActor.gp4._w=1;
    }
    if(instant){
        gActors[62].gp2._w=gFestivalPointsWhite;
        gActors[64].gp2._w=gFestivalPointsRed;
    }
    else{
        MODi(gActors[62].gp2._w,gFestivalPointsWhite,1);
        MODi(gActors[64].gp2._w,gFestivalPointsRed,1);
        if (((thisActor.unk_0x170._w != gActors[62].gp2._w) || (thisActor.unk_0x174 != gActors[64].gp2._w))
          && ((gSceneFrames & 3) == 0)){
            SFX_Play_1(0x139);
            }
        thisActor.unk_0x170._w=gActors[62].gp2._w;
        thisActor.unk_0x174=gActors[64].gp2._w;
    }
}
#else
extern void func_801AD37C_79366C(uint16_t index,uint16_t instant);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AD37C_79366C.s")
#endif
//flashing letters
#ifdef NON_MATCHING
void func_801AD4F4_7937E4(uint16_t index){
  uint8_t b,g,r;
  switch(gSceneFrames & 7) {
  case 0:
    r = 0;
    g = 0;
    b = 0;
    break;
  case 1:
    b = 0xff;
    r = 0;
    g = 0;
    break;
  case 2:
    g = 0xff;
    r = 0;
    b = 0;
    break;
  case 3:
    b = 0xff;
    g = 0xff;
    r = 0;
    break;
  case 4:
    r = 0xff;
    g = 0;
    b = 0;
    break;
  case 5:
    b = 0xff;
    r = 0xff;
    g = 0;
    break;
  case 6:
    g = 0xff;
    r = 0xff;
    b = 0;
    break;
  case 7:
    b = 0xff;
    g = 0xff;
    r = 0xff;
  }
  thisActor.rgba.r = r;
  thisActor.rgba.g = g;
  thisActor.rgba.b = b;
}
#else
void func_801AD4F4_7937E4(uint16_t index);
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AD4F4_7937E4.s")
#endif

void func_801AD628_793918(uint16_t x){
  if(gIsFestivalTimeBeat) func_801AD4F4_7937E4(65);
}
//check the scores at the end.
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AD658_793948.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AD71C_793A0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AD840_793B30.s")
//some debug object?
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AD9B0_793CA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801ADE64_794154.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AE0DC_7943CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AE5A0_794890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AE5C8_7948B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AE804_794AF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AE8B4_794BA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AE8DC_794BCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AEA60_794D50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AEB10_794E00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AEB3C_794E2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AEB68_794E58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AEBD4_794EC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AEC44_794F34.s")

void func_801AECA0_794F90(uint16_t x){}
void func_801AECA8_794F98(uint16_t x){}
void func_801AECB0_794FA0(uint16_t x){}

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AECB8_794FA8.s")

void func_801AED30_795020(uint16_t index){
    thisActor.unk_0x118=1.0;
    func_80069E18(index);
}
#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AED88_795078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AEE00_7950F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AF024_795314.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AF10C_7953FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AF1EC_7954DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ActorFuncs3/Festival/func_801AF480_795770.s")
