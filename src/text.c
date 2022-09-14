#include "common.h"

uint16_t gASCIIAlphaIndecies[92]={ //starts at 0x20(space char), ends at 0x7B({)
/* */  ALPHA_SPACE, //
/*!*/  ALPHA_BOLD_EXCLAMAION,
/*"*/  ALPHA_BOLD_QUOTE,
/*$*/  ALPHA_SPACE,
/*%*/  ALPHA_BOLD_PERCENT,
/*&*/  ALPHA_SPACE,
/*'*/  ALPHA_BOLD_APOSTROPHE,
/*(*/  ALPHA_BOLD_PARENTESISLEFT,
/*)*/  ALPHA_BOLD_PARENTESISRIGHT,
/***/  ALPHA_BOLD_TIMES,
/*+*/  ALPHA_BOLD_PLUS,
/*,*/  ALPHA_BOLD_COMMA,
/*-*/  ALPHA_BOLD_MINUS,
/*.*/  ALPHA_BOLD_PERIOD,
/*/*/  ALPHA_BOLD_SLASH,
/*0*/  ALPHA_BOLD_0, //=0x0000. the 2 ASCII interpreter funcs specifically look for the space char
/*1*/  ALPHA_BOLD_1,
/*2*/  ALPHA_BOLD_2,
/*3*/  ALPHA_BOLD_3,
/*4*/  ALPHA_BOLD_4,
/*5*/  ALPHA_BOLD_5,
/*6*/  ALPHA_BOLD_6,
/*7*/  ALPHA_BOLD_7,
/*8*/  ALPHA_BOLD_8,
/*9*/  ALPHA_BOLD_9,
/*:*/  ALPHA_BOLD_COLON,
/*;*/  ALPHA_SPACE,
/*<*/  ALPHA_SPACE,
/*=*/  ALPHA_SPACE,
/*>*/  ALPHA_SPACE,
/*?*/  ALPHA_BOLD_QUESTION,
/*@*/  ALPHA_BOLD_COPYRIGHT, //©
/*A*/  ALPHA_UPPER_A,
/*B*/  ALPHA_UPPER_B,
/*C*/  ALPHA_UPPER_C,
/*D*/  ALPHA_UPPER_D,
/*E*/  ALPHA_UPPER_E,
/*F*/  ALPHA_UPPER_F,
/*G*/  ALPHA_UPPER_G,
/*H*/  ALPHA_UPPER_H,
/*I*/  ALPHA_UPPER_I,
/*J*/  ALPHA_UPPER_J,
/*K*/  ALPHA_UPPER_K,
/*L*/  ALPHA_UPPER_L,
/*M*/  ALPHA_UPPER_M,
/*N*/  ALPHA_UPPER_N,
/*O*/  ALPHA_UPPER_O,
/*P*/  ALPHA_UPPER_P,
/*Q*/  ALPHA_UPPER_Q,
/*R*/  ALPHA_UPPER_R,
/*S*/  ALPHA_UPPER_S,
/*T*/  ALPHA_UPPER_T,
/*U*/  ALPHA_UPPER_U,
/*V*/  ALPHA_UPPER_V,
/*W*/  ALPHA_UPPER_W,
/*X*/  ALPHA_UPPER_X,
/*Y*/  ALPHA_UPPER_Y,
/*Z*/  ALPHA_UPPER_Z,
/*[*/  ALPHA_BOLD_BRACKETLEFT,
/*\*/  ALPHA_SPACE,
/*]*/  ALPHA_BOLD_BRACKETRIGHT,
/*^*/  ALPHA_SPACE,
/*_*/  ALPHA_SPACE,
/*`*/  ALPHA_SPACE,
/*a*/  ALPHA_LOWER_A,
/*b*/  ALPHA_LOWER_B,
/*c*/  ALPHA_LOWER_C,
/*d*/  ALPHA_LOWER_D,
/*e*/  ALPHA_LOWER_E,
/*f*/  ALPHA_LOWER_F,
/*g*/  ALPHA_LOWER_G,
/*h*/  ALPHA_LOWER_H,
/*i*/  ALPHA_LOWER_I,
/*j*/  ALPHA_LOWER_J,
/*k*/  ALPHA_LOWER_K,
/*l*/  ALPHA_LOWER_L,
/*m*/  ALPHA_LOWER_M,
/*n*/  ALPHA_LOWER_N,
/*o*/  ALPHA_LOWER_O,
/*p*/  ALPHA_LOWER_P,
/*q*/  ALPHA_LOWER_Q,
/*r*/  ALPHA_LOWER_R,
/*s*/  ALPHA_LOWER_S,
/*t*/  ALPHA_LOWER_T,
/*u*/  ALPHA_LOWER_U,
/*v*/  ALPHA_LOWER_V,
/*w*/  ALPHA_LOWER_W,
/*x*/  ALPHA_LOWER_X,
/*y*/  ALPHA_LOWER_Y,
/*z*/  ALPHA_LOWER_Z,
/*{*/  ALPHA_SPACE
};
uint16_t gTextPalettes[8][4]={
    {0x0000,0x0000,0x0000,COL16_BLACK}, 
    {0x0000,0x0000,0x0000,COL16_BLACK},
    {0x0000,0x0000,0x0000,COL16_BLACK},
    {0x0000,0x0000,0x0000,COL16_BLACK},
    {0x0000,0x0000,0x0000,COL16_BLACK},
    {0x0000,0x0000,0x0000,COL16_BLACK},
    {0x0000,0x0000,0x0000,COL16_BLACK},
    {0x0000,0x0000,0x0000,COL16_BLACK}
};
#ifndef VER_JPN
uint8_t gEngTextKerning[52]={
// a b c d e f g h i j k l m n o p q r s t u v w x y z
   6,5,5,5,5,4,5,5,2,5,5,2,7,5,5,5,5,5,5,5,5,5,6,5,5,5,
// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
   6,6,6,6,6,6,6,6,3,6,6,5,8,6,6,6,6,6,6,6,6,7,8,6,6,6
};
#endif
uint16_t D_800D17FC[4]={ //palette set in Text_PrintAlphaAt2()
    0x0000,COL16_BLACK,GPACK_RGBA5551(0x3f,0x3f,0x3f,1),GPACK_RGBA5551(0x7f,0x7f,0x7f,1) //blank, black, 75% gray, 50% gray
};
void Text_SpawnAt(uint16_t index, uint16_t pos_x, uint16_t pos_y, uint16_t pos_z) {
    ACTORINIT(index,ACTORTYPE_ZERO);
    thisActor.flag2 |= 0x800;
    thisActor.unk_0x188._w = 0;
    thisActor.pos.x = pos_x;
    thisActor.pos.y = pos_y;
    thisActor.pos.z = pos_z;
}

void Text_SpawnAt2(uint16_t index, uint16_t arg1, uint16_t pos_x, uint16_t pos_y, uint16_t pos_z) {
    Text_SpawnAt(index, pos_x, pos_y, pos_z);
    thisActor.graphic = arg1;
}

void Text_SpawnLetter(uint16_t index, uint16_t arg1, uint16_t pos_x, uint16_t pos_y, uint16_t pos_z, uint8_t r, uint8_t g, uint8_t b) {
    Actor* actor;

    Text_SpawnAt(index, pos_x, pos_y, pos_z);
    actor = &thisActor;
    actor->graphicTime = 0;
    actor->graphic = arg1;

    if ((r | g | b)) {
        actor->rgba.r = r;
        actor->flag2 |= 0x10;
        actor->rgba.g = g;
        actor->rgba.b = b;
    }
}

void Text_SpawnIcon(uint16_t index, void* g, uint16_t pos_x, uint16_t pos_y, uint16_t pos_z) {
    Actor* actor;

    Text_SpawnAt(index, pos_x, pos_y, pos_z);
    actor = &thisActor;
    actor->graphicList = g;
    actor->graphicTime = 1;
}

uint16_t* Text_ConvertColor(uint16_t index, uint8_t r,uint8_t g,uint8_t b){
    gTextPalettes[index][1]=COL16(r/2,g/2,b/2);
    gTextPalettes[index][2]=COL16(r,g,b);
    return gTextPalettes[index];
}
//#pragma GLOBAL_ASM("asm/nonmatchings/text/Text_ConvertColor.s")

void func_80027644(uint16_t index, uint16_t arg1, uint16_t pos_x, uint16_t pos_y, uint16_t pos_z, void* arg5) {
    Actor* actor;

    Text_SpawnAt2(index, arg1, pos_x, pos_y, pos_z);
    actor = &thisActor;
    actor->flag2 |= 0x200;
    actor->flag |= ACTOR_FLAG_UNK3;
    actor->palletteP = arg5;
}

#pragma GLOBAL_ASM("asm/nonmatchings/text/Text_PrintASCII.s") 

#ifdef NON_MATCHING
uint16_t Text_Print2Digits(uint16_t index, uint16_t N, uint16_t pos_x, uint16_t pos_y, uint16_t pos_z, int32_t arg5){
    uint16_t N2=0;
    for(;9<N;N-=10) N2++;
    func_80027644(index,ALPHAINDEX(N2),pos_x,pos_y,pos_z,arg5);
    func_80027644(index+1,ALPHAINDEX(N),pos_x+9,pos_y,pos_z,arg5);
    return index+2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/text/Text_Print2Digits.s")
#endif
#ifdef NON_MATCHING
uint16_t Text_Print3Digits(uint16_t index, uint16_t N, uint16_t pos_x, uint16_t pos_y, uint16_t pos_z, int32_t arg5){
    uint16_t N2=0;
    uint16_t N1=0;
    for(;99<N;N-=100) N1++;
    for(;9<N;N-=10) N2++;
    func_80027644(index,ALPHAINDEX(N1),pos_x,pos_y,pos_z,arg5);
    func_80027644(index+1,ALPHAINDEX(N2),pos_x+9,pos_y,pos_z,arg5);
    func_80027644(index+2,ALPHAINDEX(N),pos_x+18,pos_y,pos_z,arg5);
    return index+3;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/text/Text_Print3Digits.s")
#endif
//all text in Japanese is monospaced(?)
#ifndef VER_JPN
#ifdef NON_MATCHING
uint8_t Text_GetWidth(uint16_t* TXT) {
    if (ALPHA_KERNED_LOWER_A > *TXT)
        return 6;
    if (*TXT == ALPHA_BOLD_SPACE)
        return 7;
    return gEngTextKerning[*TXT-ALPHA_KERNED_LOWER_A];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/text/Text_GetWidth.s")
#endif
#ifdef NON_MATCHING
uint16_t Text_getKerning(uint16_t* TXT){
    return Text_GetWidth(TXT+1)+Text_GetWidth(TXT);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/text/Text_getKerning.s")
#endif
#endif

uint16_t Text_ZeroFlagActors(uint16_t index, uint16_t* TXT){
    uint16_t C = *TXT;
    while(C!=ALPHA_NULL){
        if(C)gActors[index++].flag=0;
        C=*++TXT;
    }
    return index;
}
//TODO: add #ifdef for monospace japanese
uint16_t Text_PrintAlphaAt(uint16_t index, uint16_t* TXT, uint16_t pos_x, uint16_t pos_y,uint16_t pos_z){
    uint16_t C = *TXT;
    while(C!=ALPHA_NULL){
        if(C){
            Text_SpawnAt(index, pos_x, pos_y, pos_z);
            thisActor.flag|=ACTOR_FLAG_UNK3;
            gActors[index++].graphic = ALPHAINDEX(*TXT);
#ifdef VER_JPN
        }
        pos+=16;
#else            
            pos_x+= Text_getKerning(TXT);
        }
        else pos_x+=14;
#endif
        C=*++TXT;
    }
    return index;
}

uint16_t Text_PrintAlphaAtColor(uint16_t index,uint16_t *TXT,uint16_t pos_x,uint16_t pos_y,uint16_t pos_z,uint8_t r,uint8_t g,uint8_t b){
    uint16_t C = *TXT;
    while(C!=ALPHA_NULL){
        if(C){
            Text_SpawnAt(index, pos_x, pos_y, pos_z);
            thisActor.flag|=ACTOR_FLAG_UNK3;
            thisActor.graphic = ALPHAINDEX(*TXT);
                if ((r | g | b)) {
                    thisActor.rgba.r = r;
                    thisActor.flag2 |= 0x10;
                    thisActor.rgba.g = g;
                    thisActor.rgba.b = b;
                }
            index++;
#ifdef VER_JPN
        }
        pos+=16;
#else            
            pos_x+= Text_getKerning(TXT);
        }
        else pos_x+=14;
#endif
        C=*++TXT;
    }
    return index;
}

#pragma GLOBAL_ASM("asm/nonmatchings/text/Text_PrintAlphaAtColorScale.s")

#pragma GLOBAL_ASM("asm/nonmatchings/text/Text_PrintAlphaAt2.s")

uint16_t Text_PrintAlphaAt3(uint16_t index, uint16_t* TXT, uint16_t pos_x, uint16_t pos_y,uint16_t pos_z){
    uint16_t C = *TXT;
    while(C!=ALPHA_NULL){
        if(C){
            Text_SpawnAt(index, pos_x, pos_y, pos_z);
            thisActor.flag|=ACTOR_FLAG_UNK3;
            thisActor.graphic = ALPHAINDEX(*TXT);
        }
        else thisActor.flag=0;
        index++;
        C=*++TXT;
        pos_x+=16;
    }
    return index;
}
#ifdef NON_MATCHING
void func_80028260(uint16_t arg0,uint16_t index,uint8_t r, uint8_t g, uint8_t b){
    uint16_t* p;
    switch(arg0):{
        case 0:
        case 1:
        case 2:
        p=0x80380400;
    }
    p[index]=GPACK_RGBA5551(r,g,b,1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/text/func_80028260.s")
#endif