#include "GameSave.h"
#include "common.h"
#include "SFX.h"


char gEEPROMID[8] = "TREA0722";
uint16_t gTimeRecords[64] = {
    36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000,
    36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000,
    36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000,
    36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000,
    36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000, 36000
};
uint16_t gDefaultFileName[11] = {
    ALPHA_KERNED_UPPER_S, ALPHA_KERNED_LOWER_T, ALPHA_KERNED_LOWER_A, ALPHA_KERNED_LOWER_R, ALPHA_KERNED_LOWER_T, ALPHA_SPACE,
    ALPHA_SPACE,   ALPHA_SPACE,   ALPHA_SPACE,   ALPHA_SPACE,   ALPHA_NULL
};
uint32_t D_800C4FC0[10]={
    0x10000,0x20000,0x40000,0x64,3,0x20000,3,0x40000,0,0x40000
};
uint16_t gNameEntrySpace[11]={
    0,0,0,0,0,0,0,0,0,ALPHA_NULL
};
uint8_t D_800C5000=0;
uint8_t GameSave_SelectedAge=0;
uint8_t gSaveSlotIndex=0;

//b2_s D_800C500C=0;
uint16_t D_800C500E=0;


// This function gets the lower 4 bits of the word lhs + (offset)
// Difference is flipped instruction. ('and t8,t7,a0' vs 'and t8,a0,t7')
#ifdef NON_MATCHING
uint16_t func_80004E70(uint32_t lhs, int32_t offset) {
    return lhs & (0xF << (offset * 4)) >> (offset * 4);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80004E70.s")
#endif

uint8_t D_800C5010[8]={9,9,9,5,9,5,0,0};
int32_t func_80004E90(uint32_t arg0) {
    uint16_t index;

    for (index = 0; index < 8; index++) {
        if (D_800C5010[index] < func_80004E70(arg0, index)) {
            return 1;
        }
    }
    return 0;
}

int32_t IsOver999(uint32_t x) { //{Vegeta Joke}
    if (999 < x) {
        return 1;
    }
    return 0;
}
//seems to check festival records and default them at certain conditions.
#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80004F24.s")

#ifdef NON_MATCHING
void GameSave_Initialize(uint8_t slot) {
    uint16_t index;
    for (index = 0; index < 11; index++) {
        GameSave_Names[slot][i] = gDefaultFileName[i];
    }

    GameSave_Age[slot] = 0;
    GameSave_Sex[slot] = 0;
    GameSave_RedGems[slot] = 30;
    GameSave_YellowGems[slot] = 0;
    GameSave_PlayTime[slot] = (uint64_t)0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/GameSave_Initialize.s")
#endif

// need to implicitly call __ll_lshift
#ifdef NON_MATCHING
void GameSave_SetDefaults(void) {
    uint16_t index;

    for (index = 0; index < 10; index++) {
        gFestivalRecords[index] = D_800C4FC0[index];
    }

    gYellowGemBitfeild = 0;
    (&gYellowGemBitfeild)[362] = 0;
    gWorldProgress = 0;
    D_80171B19 = 0;

    for (index = 0; index < 64; index++) {
        gTimeRecords[index] = 0x8CA0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/GameSave_SetDefaults.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/GameSave_CheckAndWipe.s")

void GameSave_LoadRecords(void) {
    uint16_t index;

    osEepromProbe(&gContMesgq);
    if (gSaveSlotIndex) {
        osEepromLongRead(&gContMesgq, 0x24, &gFestivalRecords, 0x32);
        osEepromLongRead(&gContMesgq, 0x2C, &gTimeRecords, sizeof(gTimeRecords));
    }
    else {
        osEepromLongRead(&gContMesgq, 0xC, &gFestivalRecords, 0x32);
        osEepromLongRead(&gContMesgq, 0x14, &gTimeRecords, sizeof(gTimeRecords));
    }
    if (D_80171B19 >= 2) D_80171B19 = 0;

    func_80004F24();

    for (index = 0; index < 64; index++) {
        if (gTimeRecords[index] > 36000) gTimeRecords[index] = 36000;
    }
}

void GameSave_SaveRecords(void) {
    osEepromProbe(&gContMesgq);
    osEepromLongWrite(&gContMesgq, 2, gFileNames, 0x48);

    if (gSaveSlotIndex) {
        osEepromLongWrite(&gContMesgq, 0x24, &gFestivalRecords, 0x32);
        osEepromLongWrite(&gContMesgq, 0x2C, &gTimeRecords, sizeof(gTimeRecords));
    }
    else {
        osEepromLongWrite(&gContMesgq, 0xC, &gFestivalRecords, 0x32);
        osEepromLongWrite(&gContMesgq, 0x14, &gTimeRecords, sizeof(gTimeRecords));
    }
}

void GameSave_Erase(void) {
    GameSave_Initialize(gSaveSlotIndex);
    GameSave_SetDefaults();
    GameSave_SaveRecords();
}

void func_80005860(uint16_t index, uint16_t pos_x, uint16_t pos_y, int32_t arg3) {
    Text_SpawnIcon(index, &gGraphicList_800E13DC, pos_x, pos_y, 0);
    thisActor.flag2 |= 0x200;
    thisActor.palletteP = arg3;
}

// Differences related to implicit casts
#ifdef NON_MATCHING
void GameSave_PrintRedGems(uint16_t arg0, uint16_t arg1, uint16_t arg2, uint16_t arg3, int32_t arg4) {
    uint16_t* red_gems = &gFileRedGems[arg3];
    Text_Print2Digits(arg0, *red_gems / 0x64, arg1, arg2, 0, arg4);
    Text_Print2Digits(arg0, *red_gems % 0x64, arg1 + 18, arg2, 0, arg4);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/GameSave_PrintRedGems.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_800059A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80005B68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80005C3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_8000607C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80006360.s")

#ifdef NON_MATCHING
void func_80006B1C(uint16_t i) {
    uint16_t index;
    for (index = i + 0xab; index < i + 0xBD; index++) {
        thisActor.flag = 0;
    }

    func_80006360(i);
    gGameSubState = 1;
    gSaveSlotIndex = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80006B1C.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80006B9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80006CC8.s")

void func_80006DF4(uint16_t index) {
    uint32_t temp = index; // int promotion magic??
    gActors[temp].rotateX += 8.0f;
    gActors[temp].rotateY += 8.0f;
    gActors[temp + 1].rotateX -= 8.0f;
    gActors[temp + 1].rotateY -= 8.0f;
}
//sets selected stage
#ifdef NON_MATCHING
void func_80006E60(void) {
    gCurrentStage = gWorldProgress;
    gCurrentScene = gStageScenes[gWorldProgress]; //array of scene indecies
    D_800D28E4 = D_800C83F8[gWorldProgress];
    func_80043918();
    D_800CBF40 = 1;
    gGameState = GAMESTATE_TRANSITION;
    gGameSubState = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80006E60.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80006EDC.s")
//menus use gActors' fields rather than their own variables.
#define NameEntryLanguage gActors[185].unk_0xA0
#define NameEntryCurrentChar gActors[184].unk_0xA0
#define nameEntrySelectedColumn gActors[177].unk_0xA0
#define nameEntrySelectedRow gActors[178].unk_0xA0

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/NameEntry_ConfirmName.s")

#ifdef NON_MATCHING
uint16_t NameEntry_PrintKeyboardHIRA(uint16_t index){
    Text_SpawnAt2(index,0x11e,0x80,0x44,0);
    gActors[index+1].flag=0;
    index=Text_PrintAlphaAtColor(index+2,D_800C52B0,0x40,0x44,0,0x80,0,0);
    gActors[index++].flag=0;
    gActors[index++].flag=0;
    gActors[index++].flag=0;
    gActors[index++].flag=0;
    index= Text_PrintAlphaAt(index+1, gNameEntryRow0HIRA,0xff80,0x30,0);
    index= Text_PrintAlphaAt(index, gNameEntryRow1HIRA,0xff80,0x20,0);
    index= Text_PrintAlphaAt(index, gNameEntryRow2HIRA,0xff80,0x10,0);
    index= Text_PrintAlphaAt(index, gNameEntryRow3HIRA,0xff80,0,0);
    index= Text_PrintAlphaAt(index, gNameEntryRow4HIRA,0xff80,0xffF0,0);
    gActors[index++].flag=0;
    return index;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/NameEntry_PrintKeyboardHIRA.s")
#endif

void func_80007578(void) {
    SFX_Play_2(SFX_MENU_BLIP);
    NameEntryLanguage = 0;
    NameEntry_PrintKeyboardHIRA(0xC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/NameEntry_PrintKeyboardKATA.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/NameEntry_PrintKeyboard.s")
#ifdef NON_MATCHING
void NameEntry_Setup(uint16_t index){

  ClearActorsAndGems();
  index = func_80006b9c(index);
  Text_SpawnIcon(index,D_800e13fc,0xffc4,0x58,0);
  index = Text_PrintAlphaAtColor(index + 1,&D_800c5078,0xffdc,0x58,0,0x80,0,0x80);
  index = NameEntry_PrintKeyboardHIRA(index + 3);
  index = Text_PrintAlphaAtColor(index,D_800c5138,0x38,0xffe0,0,0x80,0,0);
  index = Text_PrintAlphaAtColor(index,D_800c513c,0x58,0xffe0,0,0x80,0,0);
  index = Text_PrintAlphaAtColor(index,D_800c5140,0x78,0xffe0,0,0x80,0,0);
  index = Text_PrintAlphaAtColorScale(index,&D_800c5144,0xffb8,0xffc4,0,0,0x60,0,1.0,1.0);
  Text_SpawnLetter(index,0x464,0xffb8,0xffbc,0,0x60,0xc0,0);
  nameEntrySelectedColumn= 0;
  nameEntrySelectedRow = 0;
  NameEntryLanguage = 0;
  gActors[183].unk_0xA0 = index + 1;
  #ifndef VER_JPN
  NameEntry_PrintKeyboard();
  NameEntryLanguage = 2; //force english language
  #endif
  for(index=0;index<10;index++){
      gNameEntrySpace[index] = 0;
      }
  NameEntryCurrentChar = 0;
  return;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/NameEntry_Setup.s")
#endif

void NameEntry_IsMaxed(void) {
    if (NameEntryCurrentChar == 10) {
        nameEntrySelectedColumn = 2;
        nameEntrySelectedRow = 5;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/func_80007ABC.s")

// Original Japanese version has 3 different character sets for name entry. All other regions have 1
#ifdef NON_MATCHING
void NameEntry_EnterChar(uint16_t* Hiragana, uint16_t* Katakana, uint16_t* Eng) {
    if (NameEntryCurrentChar != 10) {
        if (NameEntryLanguage == 0) {
            gNameEntrySpace[NameEntryCurrentChar] = Hiragana[nameEntrySelectedColumn];
        }
        if (NameEntryLanguage == 1) {
            gNameEntrySpace[NameEntryCurrentChar] = Katakana[nameEntrySelectedColumn];
        }
        if (NameEntryLanguage == 2) {
            gNameEntrySpace[NameEntryCurrentChar] = Eng[nameEntrySelectedColumn];
        }
        SFX_Play_1(SFX_MENU_DING);
        SFX_Play_1(0x10D);
        func_80007ABC();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/NameEntry_EnterChar.s")
#endif
//very ugly intrpetation
#ifdef NON_MATCHING
void FileSelect_Tick(void){
  bool bVar1;
  byte bVar2;
  short sVar6;
  sbyte sVar8;
  ushort uVar7;
  uint16_t uVar5;
  uint uVar9;
  uint uVar10;
  int iVar11;
  u16 uVar12;
  uint16_t *pAVar13;
  byte bVar14;
  
  bVar14 = gSaveSlotIndex;
  if (true) {
    switch(gGameSubState) {
    case 0:
      GameSave_CheckAndWipe();
      func_80006360(1);
      BYTE_ARRAY_801376bc[1] = 0;
      BYTE_ARRAY_801376b8[1] = 1;
      gEnvColorsRed[1] = 0x60;
      gEnvColorsGreen[1] = 0x60;
      gEnvColorsBlue[1] = 0x60;
      gEnvColorsAlpha[1] = 0xff;
      gSaveSlotIndex = 0;
      gActors[2].unk_0x158 = 0;
      gGameSubState++;
      break;
    case 1: //pick save slot, or pick to erase
    case 7: //pick which to erase
      D_800c500c._0_1_ = gSaveSlotIndex;
      if (((gButtonPress & gButton_DUp)) && (gSaveSlotIndex)) gSaveSlotIndex--;
      if (gGameSubState == 1) {
        if (((gButtonPress & gButton_DDown)) && (gSaveSlotIndex < 2)) gSaveSlotIndex++;
      }
      else if (((gButtonPress & gButton_DDown)) && (gSaveSlotIndex == 0)) gSaveSlotIndex++;
      if (bVar14 != gSaveSlotIndex) SFX_Play_2(SFX_MENU_BLIP);
      func_80006edc(1);
      if (((gButtonPress & gButton_B)) && (gGameSubState == 7)) {
        Text_PrintAlphaAtColor(0x43,&Aplha_Which,0xffd0,0x58,0,0x80,0,0x80);
        gGameSubState = 1;
      }
      if (((gButtonPress & gButton_Start)) || ((gButtonPress & gButton_A))) {
        SFX_Play_1(SFX_MENU_DING);
        if (gGameSubState == 7) { //nasty for loop ahead
          uVar5 = 0;
          sVar6 = 0;
          do {
            iVar11 = uVar5 * 2;
            pAVar13 = gDefaultFileName + uVar5;
            uVar5++;
            if (*pAVar13 !=
                *(uint16_t *)
                 ((int)gFileNames + iVar11 + ((uint)gSaveSlotIndex * 0xc - (uint)gSaveSlotIndex) * 2
                 )) {
              sVar6++;
            }
          } while (uVar5 < 0xb);
          if (sVar6 == 0) func_80006b1c(1);
          else {
            Text_ZeroFlagActors(0x43,&Aplha_Which);
            iVar11 = func_80006b9c(0xac);
            // this is likely gActors[iVar11 - something]
            *(undefined2 *)(&D_800ef268 + iVar11 * 0x198) = 0x28;
            (&D_800ef26c)[iVar11 * 0xcc] = 0x58;
            (&D_800ef400)[iVar11 * 0xcc] = *(undefined2 *)(&D_800ef268 + iVar11 * 0x198);
            (&D_800ef404)[iVar11 * 0xcc] = (&D_800ef26c)[iVar11 * 0xcc];
            uVar12 = (u16)iVar11;
            if (gSaveSlotIndex == 0) {
              uVar12 = Text_PrintAlphaAtColor(uVar12,&Alphabet_Num1,0xffe0,0x58,0,0,0xff,0xff);
            }
            else if (gSaveSlotIndex == 1) {
              uVar12 = Text_PrintAlphaAtColor(uVar12,&Alphabet_Num2,0xffe0,0x58,0,0,0xff,0xff);
            }
            uVar5 = Text_PrintAlphaAtColor(uVar12,&Alpha_Erase_Question,0xffac,0x58,0,0,0xff,0xff);
            Text_PrintAlphaAtColor((u16)uVar5,&Alphabet_800c5294,0x1e,0x58,0,0,0xff,0xff);
            gGameSubState++;
            gActors[186].unk_0xA0 = 1;
          }
        }
        else {
          uVar5 = 0;
          if (gSaveSlotIndex == 2) {
            Text_PrintAlphaAtColorScale(0x9a,&Alphabet_800c505c,0xff96,0xffae,0,0,0,0,0.5,1.0);
            Text_PrintAlphaAtColor(0x43,&Alphabet_800c5068,0xffd0,0x58,0,0,0xff,0xff);
            gSaveSlotIndex = 0;
            func_80006edc(1);
            gGameSubState = 7;
          }
          else {
            //very nasty for loop.
            sVar6 = 0;
            do {
              iVar11 = uVar5 * 2;
              pAVar13 = gDefaultFileName + uVar5;
              uVar5++;
              if (*(uint16_t *)
                   ((int)gFileNames +
                   iVar11 + ((uint)gSaveSlotIndex * 0xc - (uint)gSaveSlotIndex) * 2) != *pAVar13) {
                sVar6 = sVar6 + 1;
              }
            } while (uVar5 < 0xb);
            if (sVar6 == 0) {
              NameEntry_Setup(1);
              gGameSubState++;
            }
            else {
              u16_80171b22 = 0x3a;
              gGameSubState = 0x1e;
            }
          }
        }
      }
      break;
    case 2: //confirm name
      if (NameEntryCurrentChar == 10) {
        if ((nameEntrySelectedColumn == 1) && ((gButtonPress & gButton_DRight))) {
          SFX_Play_2(SFX_MENU_BLIP);
          nameEntrySelectedColumn = 2;
        }
        else if ((nameEntrySelectedColumn == 2) && ((gButtonPress & gButton_DLeft))) {
          SFX_Play_2(SFX_MENU_BLIP);
          nameEntrySelectedColumn = 1;
        }
      }
      else { //keyboard navigation.
#ifdef VER_JPN
      if(gButtonHold&gButton_LTrig){ //change charset
          if(NameEntryLanguage==1){
              func_80007578();
              if(func_80005b68(nameEntrySelectedColumn,nameEntrySelectedRow))nameEntrySelectedColumn--;
          }
          else if(NameEntryLanguage==2){
              NameEntry_PrintKeyboardKATA();
              if(func_80005b68(nameEntrySelectedColumn,nameEntrySelectedRow))nameEntrySelectedColumn--;
          }
      }
     if(gButtonHold&gButton_RTrig){
          if(NameEntryLanguage==0){
              NameEntry_PrintKeyboardKATA();
              if(func_80005b68(nameEntrySelectedColumn,nameEntrySelectedRow))nameEntrySelectedColumn--;
          }
          else if(NameEntryLanguage==1){
              NameEntry_PrintKeyboard();
              if(func_80005b68(nameEntrySelectedColumn,nameEntrySelectedRow))nameEntrySelectedColumn--;
          }
      }
#endif  
        if (func_800176f8(gButton_DLeft,&gActors[0xb5].unk_0xA0) == 0) 
          if (func_800176f8(gButton_DRight,&gActors[0xb6].unk_0xA0) == 0) {
            if (func_800176f8(gButton_DUp,&gActors[0xb3].unk_0xA0) == 0) {

              if (func_800176f8(gButton_DDown,&gActors[0xb4].unk_0xA0) {
                SFX_Play_2(SFX_MENU_BLIP);
                sVar8 = nameEntrySelectedRow + 1;
                nameEntrySelectedRow++;
                if (func_80005b68(nameEntrySelectedColumn,sVar8)) {
                  nameEntrySelectedRow++;
                }
                if (nameEntrySelectedRow == 6) nameEntrySelectedRow = 0;
                if (nameEntrySelectedRow == 0) {
                  if (nameEntrySelectedColumn == 0) nameEntrySelectedColumn = 0xc;
                  else if (nameEntrySelectedColumn == 1) nameEntrySelectedColumn = 0xe;
                  else if (nameEntrySelectedColumn == 2) nameEntrySelectedColumn = 0x10;
                }
                else if (nameEntrySelectedRow == 5) {
                  if (nameEntrySelectedColumn < 10) nameEntrySelectedRow = 0;
                  else {
                    nameEntrySelectedRow = 5;
                    if (nameEntrySelectedColumn < 0xd) nameEntrySelectedColumn = 0;
                    else if (nameEntrySelectedColumn < 0xf) nameEntrySelectedColumn = 1;
                    else nameEntrySelectedColumn = 2;
                  }
                }
              }
            }
            else {
              SFX_Play_2(SFX_MENU_BLIP);
              sVar8 = nameEntrySelectedRow - 1;
              nameEntrySelectedRow--;
              if (func_80005b68(nameEntrySelectedColumn,sVar8)) nameEntrySelectedRow--;
              if (nameEntrySelectedRow == 4) {
                if (nameEntrySelectedColumn == 0) nameEntrySelectedColumn = 0xc;
                else if (nameEntrySelectedColumn == 1) nameEntrySelectedColumn = 0xe;
                else if (nameEntrySelectedColumn == 2) nameEntrySelectedColumn = 0x10;
              }
              else if (nameEntrySelectedRow == 0xff) {
                if (nameEntrySelectedColumn < 10) nameEntrySelectedRow = 4;
                else {
                  nameEntrySelectedRow = 5;
                  if (nameEntrySelectedColumn < 0xd) nameEntrySelectedColumn = 0;
                  else if (nameEntrySelectedColumn < 0xf) nameEntrySelectedColumn = 1;
                  else nameEntrySelectedColumn = 2;
                }
              }
            }
          }
          else {
            SFX_Play_2(SFX_MENU_BLIP);
            sVar8 = nameEntrySelectedColumn + 1;
            nameEntrySelectedColumn++;
            if (func_80005b68(sVar8,nameEntrySelectedRow)) nameEntrySelectedColumn++;
            if (nameEntrySelectedRow == 5) {
              if (nameEntrySelectedColumn == 3) nameEntrySelectedColumn = 0;
            }
            else if (nameEntrySelectedColumn == 0x11) nameEntrySelectedColumn = 0;
          }
        }
        else {
          SFX_Play_2(SFX_MENU_BLIP);
          sVar8 = nameEntrySelectedColumn - 1;
          nameEntrySelectedColumn--;
          if (func_80005b68(sVar8,nameEntrySelectedRow)) nameEntrySelectedColumn--;
          if (nameEntrySelectedRow == 5) {
            if (nameEntrySelectedColumn == 0xff) nameEntrySelectedColumn = 2;
          }
          else if (nameEntrySelectedColumn == 0xff) nameEntrySelectedColumn = 0x10;
          if (func_80005b68(nameEntrySelectedColumn,nameEntrySelectedRow)) {
            nameEntrySelectedColumn--;
          }
        }
      }
    
      func_80006df4(1);
      iVar11 = ((uint)gActors[183].unk_0xA0 * 0xc + (uint)gActors[183].unk_0xA0) * 4 -
               (uint)gActors[183].unk_0xA0;
      (&D_800ef3f8)[iVar11 * 2] = (&D_800ef3f8)[iVar11 * 2] ^ 1;
      if (nameEntrySelectedRow == 5) {
        gActors[1].pos.x = (ushort)nameEntrySelectedColumn * 0x20 + 0x38;
        gActors[1].pos.y = -0x20;
        gActors[2].pos.x = (ushort)nameEntrySelectedColumn * 0x20 + 0x38;
        gActors[2].pos.y = -0x20;
      }
      else {
        gActors[1].pos.x = nameEntrySelectedColumn * 0x10 + -0x80;
        gActors[1].pos.y = nameEntrySelectedRow * -0x10 + 0x30;
        gActors[2].pos.x = nameEntrySelectedColumn * 0x10 + -0x80;
        gActors[2].pos.y = nameEntrySelectedRow * -0x10 + 0x30;
      }
      if (gButtonPress & gButton_A) { //add selected character.
        switch(nameEntrySelectedRow) {
        case 0:
          NameEntry_EnterChar(gNameEntryRow0HIRA,&gNameEntryRow0KATA,gNameEntryRow0ENG);
          break;
        case 1:
          NameEntry_EnterChar(gNameEntryRow1HIRA,&gNameEntryRow1KATA,gNameEntryRow1ENG);
          break;
        case 2:
          NameEntry_EnterChar(gNameEntryRow2HIRA,&gNameEntryRow2KATA,gNameEntryRow2ENG);
          break;
        case 3:
          NameEntry_EnterChar(gNameEntryRow3HIRA,gNameEntryRow3KATA,gNameEntryRow3ENG);
          break;
        case 4:
          NameEntry_EnterChar(gNameEntryRow4HIRA,&gNameEntryRow4KATA,gNameEntryRow4ENG);
          break;
        case 5:
          if (nameEntrySelectedColumn == 0) {
            if (NameEntryCurrentChar < 10) {
              gNameEntrySpace[NameEntryCurrentChar++] = 0;
              NameEntry_IsMaxed();
              SFX_Play_1(0x10f);
            }
            else {
              SFX_Play_1(wrong answer);
            }
          }
          else if (nameEntrySelectedColumn == 1) {
            if (NameEntryCurrentChar == 0) SFX_Play_1(wrong answer);
            else {
              uVar5 = (uint)NameEntryCurrentChar;
              uVar9 = uVar5 - 1 & 0xff;
              gNameEntrySpace[uVar9] = 0;
              NameEntryCurrentChar = (u8)uVar9;
              *(undefined4 *)
               ((int)gActors +
               (((uint)gActors[183].unk_0xA0 * 0xc + (uint)gActors[183].unk_0xA0) * 4 -
               (uint)gActors[183].unk_0xA0) * 8 + (uVar5 - 1 & 0xff) * 0x198 + 0x80) = 0;
              SFX_Play_1(0x10f);
            }
          }
          else if (nameEntrySelectedColumn == 2) NameEntry_ConfirmName();
        }
      }
      if ((gButtonPress & gButton_B)) { //backspace.
        uVar5 = (uint)NameEntryCurrentChar;
        if (NameEntryCurrentChar == 0) SFX_Play_1(wrong answer);
        else {
          uVar9 = uVar5 - 1 & 0xff;
          gNameEntrySpace[uVar9] = 0;
          NameEntryCurrentChar = (u8)uVar9;
          *(undefined4 *)
           ((int)gActors +
           (((uint)gActors[183].unk_0xA0 * 0xc + (uint)gActors[183].unk_0xA0) * 4 -
           (uint)gActors[183].unk_0xA0) * 8 + (uVar5 - 1 & 0xff) * 0x198 + 0x80) = 0;
          SFX_Play_1(0x10f);
        }
      }
      if (gButtonPress & gButton_Start) NameEntry_ConfirmName();
      (&D_800ef400)
      [(((uint)gActors[183].unk_0xA0 * 0xc + (uint)gActors[183].unk_0xA0) * 4 -
       (uint)gActors[183].unk_0xA0) * 4] = (ushort)NameEntryCurrentChar * 0x10 + -0x48;
      uVar7 = (ushort)gActors[183].unk_0xA0;
      if (uVar7 < (ushort)(gActors[183].unk_0xA0 + 10)) {
        do {
          func_80005c3c();
          uVar7++;
        } while (uVar7 < (ushort)(gActors[183].unk_0xA0 + 10));
      }
      break;
    case 3:
      func_80006df4(1);
      func_80006cc8(1,0x2e);
      uVar7 = (ushort)gActors[183].unk_0xA0;
      if (uVar7 < (ushort)(gActors[183].unk_0xA0 + 10)) {
        do {
          func_80005c3c();
          uVar7++;
        } while (uVar7 < (ushort)(gActors[183].unk_0xA0 + 10));
      }
      if (((gButtonPress & gButton_A)) || ((gButtonPress & gButton_Start))) {
        SFX_Play_1(SFX_MENU_DING);
        if (gActors[186].unk_0xA0 == 0) {
          uVar5 = gActors[183].unk_0xA0 + 10;
          if (uVar5 < gActors[183].unk_0xA0 + 0x1a) {
            do {
              uVar9 = uVar5 + 1 & 0xffff;
              gActors[uVar5].flag = 0;
              uVar5 = uVar9;
            } while (uVar9 < gActors[183].unk_0xA0 + 0x1a);
          }
          gGameSubState++;
        }
        else {
          uVar5 = 4;
          if (4 < gActors[183].unk_0xA0 + 0x1a) {
            do {
              uVar9 = uVar5 + 1 & 0xffff;
              gActors[uVar5].flag = 0;
              uVar5 = uVar9;
            } while (uVar9 < gActors[183].unk_0xA0 + 0x1a);
          }
          D_800c5000 = 0;
          gNameEntrySpace[NameEntryCurrentChar] = ALPHA_NULL;
          GameSave_SelectedAge = 0;
          func_8000607c(1);
          gGameSubState++;
        }
      }
      break;
    case 4:
      func_80006df4(1);
      if (((gButtonPress & gButton_DLeft)) && (D_800c5000 == 1)) {
        SFX_Play_2(SFX_MENU_BLIP);
        D_800c5000 = 0;
      }
      if (((gButtonPress & gButton_DRight)) && (D_800c5000 == 0)) {
        SFX_Play_2(SFX_MENU_BLIP);
        D_800c5000 = 1;
      }
      if (D_800c5000 == 0) {
        gActors[1].pos.x = -0x20;
        gActors[2].pos.x = -0x20;
      }
      else {
        gActors[1].pos.x = 0;
        gActors[2].pos.x = 0;
      }
      if (((gButtonPress & gButton_Start)) || ((gButtonPress & gButton_A))) {
        SFX_Play_1(SFX_MENU_DING);
        if (D_800c5000 == 0) {
          *(undefined2 *)((uint)gActors[183].unk_0xA0 * 0x198 + -0x7ff11260) = 0xffe0;
          *(undefined4 *)((uint)gActors[183].unk_0xA0 * 0x198 + -0x7ff110d0) = 0;
        }
        else {
          (&D_800eef38)[(uint)gActors[183].unk_0xA0 * 0xcc] = 0xffe0;
          *(undefined4 *)((uint)gActors[183].unk_0xA0 * 0x198 + -0x7ff11268) = 0;
        }
        gActors[187].unk_0xA0 = 0;
        gActors[1].pos.x = -0x2c;
        gActors[2].pos.x = -0x2c;
        gActors[1].pos.y = -0x10;
        gActors[2].pos.y = -0x10;
        Text_PrintAlphaAtColor(4,Alpha_Age_Question,0xffd0,0x58,0,0x80,0,0x80);
        gGameSubState++;
      }
      break;
    case 5:
      func_80006df4(1);
      if (((gButtonPress & gButton_DLeft)) || ((gButtonPress & gButton_DRight))) {
        SFX_Play_2(SFX_MENU_BLIP);
        gActors[187].unk_0xA0 = gActors[187].unk_0xA0 ^ 1;
      }
      if (func_800176f8(gButton_DDown,&gActors[0xb4].unk_0xA0)) {
        SFX_Play_2(SFX_MENU_BLIP);
        if (gActors[187].unk_0xA0 == 0) {
          uVar5 = (uint)GameSave_SelectedAge;
          bVar14 = GameSave_SelectedAge + 90;
          GameSave_SelectedAge-=10;
          if (uVar5 / 10 == 0) GameSave_SelectedAge = bVar14;
        }
        else {
          uVar5 = (uint)GameSave_SelectedAge;
          bVar14 = GameSave_SelectedAge + 9;
          GameSave_SelectedAge--;
          if (uVar5 % 10 == 0) GameSave_SelectedAge = bVar14;
        }
      }
      if (func_800176f8(gButton_DUp,&gActors[0xb3].unk_0xA0)) {
        SFX_Play_2(SFX_MENU_BLIP);
        if (gActors[187].unk_0xA0 == 0) {
          uVar5 = (uint)GameSave_SelectedAge;
          bVar14 = GameSave_SelectedAge + 0xa6;
          GameSave_SelectedAge+=10;
          if (uVar5 / 10 == 9) {
            GameSave_SelectedAge = bVar14;
          }
        }
        else {
          uVar5 = (uint)GameSave_SelectedAge;
          bVar14 = GameSave_SelectedAge - 9;
          GameSave_SelectedAge++;
          if (uVar5 % 10 == 9) GameSave_SelectedAge = bVar14;
        }
      }
      Text_Print2Digits((ushort)gActors[183].unk_0xA0,(ushort)GameSave_SelectedAge,-0x20,0xfff0,0
                        ,u16_ARRAY_ARRAY_800d1788[3]);
      if (gActors[187].unk_0xA0 == 0) {
        uVar5 = gSceneFramesReal & 1;
        if ((false) && ((gSceneFramesReal & 1))) {
          uVar5 = uVar5 - 2;
        }
        if (uVar5) {
          iVar11 = (((uint)gActors[183].unk_0xA0 * 0xc + (uint)gActors[183].unk_0xA0) * 4 -
                   (uint)gActors[183].unk_0xA0) * 8;
          *(uint *)((int)gActors + iVar11 + 0x80) =
               *(uint *)((int)gActors + iVar11 + 0x80) & 0xfffffffe;
        }
        iVar11 = (((uint)gActors[183].unk_0xA0 * 0xc + (uint)gActors[183].unk_0xA0) * 4 -
                 (uint)gActors[183].unk_0xA0) * 8;
        *(uint *)((int)gActors + iVar11 + 0x218) = *(uint *)((int)gActors + iVar11 + 0x218) | 1;
      }
      else {
        iVar11 = (((uint)gActors[183].unk_0xA0 * 0xc + (uint)gActors[183].unk_0xA0) * 4 -
                 (uint)gActors[183].unk_0xA0) * 8;
        *(uint *)((int)gActors + iVar11 + 0x80) = *(uint *)((int)gActors + iVar11 + 0x80) | 1;
        uVar5 = gSceneFramesReal & 1;
        if ((false) && ((gSceneFramesReal & 1))) { //what, Ghidra?
          uVar5 = uVar5 - 2;
        }
        if (uVar5) {
          iVar11 = (((uint)gActors[183].unk_0xA0 * 0xc + (uint)gActors[183].unk_0xA0) * 4 -
                   (uint)gActors[183].unk_0xA0) * 8;
          *(uint *)((int)gActors + iVar11 + 0x218) =
               *(uint *)((int)gActors + iVar11 + 0x218) & 0xfffffffe;
        }
      }
      if (((gButtonPress & gButton_Start)) || ((gButtonPress & gButton_A))) {
        SFX_Play_1(SFX_MENU_DING);
        gActors[gActors[183].unk_0xA0].flag |= ACTOR_FLAG_DRAW;
        gActors[gActors[183].unk_0xA0 + 1].flag |= ACTOR_FLAG_DRAW;
        gActors[2].pos.y = -0x50;
        gActors[1].flag|= ACTOR_FLAG_DRAW;
        gActors[2].flag|= ACTOR_FLAG_DRAW;
        gActors[1].pos.y = -0x50;
        gActors[186].unk_0xA0 = 1;
        gActors[2].pos.x = 0x2e;
        gActors[1].pos.x = 0x2e;
        Text_PrintAlphaAt(gActors[183].unk_0xA0 + 4,&Alphabet_800c526c,0xffa0,0xffb0,0);
        gGameSubState++;
      }
      break;
    case 6:
      func_80006df4(1);
      func_80006cc8(1,0x2e);
      if (((gButtonPress & gButton_A)) || ((gButtonPress & gButton_Start))) {
        if (gActors[186].unk_0xA0 == 0) {
          func_8000607c(1);
          gGameSubState-=2;
        }
        else {
          SFX_Play_1(SFX_MENU_DING);
          gActors[2].flag = 0;
          gActors[1].flag = 0;
          u16_80171b22 = 0x3a;
          gGameSubState = 0x14;
        }
      }
      break;
    case 8:
      func_80006df4(0xac);
      func_80006cc8(0xac,0x28);
      func_80006edc(1);
      if (((gButtonPress & gButton_Start)) || ((gButtonPress & gButton_A))) {
        SFX_Play_1(SFX_MENU_DING);
        if (gActors[186].unk_0xA0 == 0) func_80006b1c(1);
        else {
          uVar5 = Text_PrintAlphaAtColor(0xae,&Alphabet_800c5250,0xffac,0x58,0,0,0xff,0xff);
          Text_PrintAlphaAtColor((u16)uVar5,&Alphabet_800c5294,0x1e,0x58,0,0,0xff,0xff);
          gGameSubState++;
          gActors[186].unk_0xA0 = 1;
        }
      }
      break;
    case 9:
      func_80006df4(0xac);
      func_80006cc8(0xac,0x28);
      func_80006edc(1);
      if (((gButtonPress & gButton_Start)) || ((gButtonPress & gButton_A))) {
        SFX_Play_1(SFX_MENU_DING);
        if (gActors[186].unk_0xA0 == 0) {
          func_80006b1c(1);
        }
        else {
          uVar5 = Text_PrintAlphaAtColor(0xae,&Alphabet_800c5260,0xffac,0x58,0,0,0xff,0xff);
          Text_PrintAlphaAtColor((u16)uVar5,&Alphabet_800c5294,0x1e,0x58,0,0,0xff,0xff);
          gGameSubState++;
          gActors[186].unk_0xA0 = 1;
        }
      }
      break;
    case 10:
      func_80006df4(0xac);
      func_80006cc8(0xac,0x28);
      func_80006edc(1);
      if (((gButtonPress & gButton_Start)) || ((gButtonPress & gButton_A))) {
        if (gActors[186].unk_0xA0 == 0) {
          SFX_Play_1(SFX_MENU_DING);
          gGameSubState++;
          u16_80171b22 = 0x3a;
        }
        else {
          SFX_Play_1(SFX_MENU_DING);
          func_80006b1c(1);
        }
      }
      break;
    case 0xb:
      func_80006df4(0xac);
      func_80006cc8(0xac,0x28);
      func_80006edc(1);
      if ((u16_80171b22 & 3) == 2) {
        gActors[43].flag^= ACTOR_FLAG_DRAW;
      }
      if (u16_80171b22-- == 0) {
        GameSave_Erase();
        func_80006b1c(1);
      }
      break;
    case 0x14:
      if ((u16_80171b22 & 3) == 0) {
        uVar9 = u16_80171b1c;
        for (uVar5 = u16_80171b1a; uVar5 < uVar9; uVar5++) {
          gActors[uVar5].flag^= ACTOR_FLAG_DRAW;
        }
        if (D_800c5000 == 0) {
          gActors[u16_80171b1e].flag^=1;
        }
        else {
          iVar11 = (((uint)u16_80171b1e * 0xc + (uint)u16_80171b1e) * 4 - (uint)u16_80171b1e) * 8;
          *(uint *)((int)gActors + iVar11 + 0x218) = *(uint *)((int)gActors + iVar11 + 0x218) ^ 1;
        }
        iVar11 = (((uint)u16_80171b20 * 0xc + (uint)u16_80171b20) * 4 - (uint)u16_80171b20) * 8;
        gActors[u16_80171b20].flag^=1;
        *(uint *)((int)gActors + iVar11 + 0x218) = *(uint *)((int)gActors + iVar11 + 0x218) ^ 1;
      }
      bVar2 = gSaveSlotIndex;
      bVar14 = D_800c5000;
      uVar12 = u16_80171b22 - 1;
      bVar1 = u16_80171b22 == 2;
      u16_80171b22 = uVar12;
      if (bVar1) { //create the new save file.
        uVar9 = (uint)gSaveSlotIndex;
        uVar10 = (uint)gSaveSlotIndex;
        uVar5 = 0;
        do {
          iVar11 = uVar5 * 2;
          pAVar13 = gNameEntrySpace + uVar5;
          uVar5 = uVar5 + 1 & 0xffff;
          *(uint16_t *)((int)gFileNames + iVar11 + (uVar9 * 0xc - uVar10) * 2) = *pAVar13;
        } while (uVar5 < 0xb);
        gFileAges[gSaveSlotIndex] = GameSave_SelectedAge;
        gFileSexes[gSaveSlotIndex] = bVar14;
        gFileRedGems[gSaveSlotIndex] = 0x1e;
        gFileYellowGems[gSaveSlotIndex] = 0;
        gFilePlayTimes[gSaveSlotIndex]._lo = 0;
        gFilePlayTimes[gSaveSlotIndex]._hi = 0;
        GameSave_SetDefaults();
        gRedGems = 0x1e;
        gPlayTime = 0;
        GameSave_SaveRecords();
        func_80006e60();
      }
      break;
    case 0x1e:
      if ((u16_80171b22 & 3) == 0) {
        gActors[43].flag^= ACTOR_FLAG_DRAW;
      }
      uVar12 = u16_80171b22 - 1;
      bVar1 = u16_80171b22 == 2;
      u16_80171b22 = uVar12;
      if (bVar1) {
        GameSave_LoadRecords();
        gRedGems = gFileRedGems[gSaveSlotIndex];
        gPlayTime = gFilePlayTimes[gSaveSlotIndex]._lo;
        func_80006e60();
      }
    }
  }
  return;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/GameSave/FileSelect_Tick.s")
#endif