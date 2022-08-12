#include "common.h"

typedef struct{
u16 actorIndex;
s16 playerNumber;
u16 unk_0x04;
u16 unk_0x06;
u32 actorField0x174;
u32 rand;
u16 unk_0x10;
u16 unk_0x12;
}FestivalStruct;

extern u16 gFestivalEventState; 
extern u16 D_80178222;
extern u16 gFestivalCurrentEvent,gFestivalCompetitors;
extern u16 gFestivalFouls;
extern u16 D_80178230[4];
extern FestivalStruct gFestivalStructs[4];
extern void* D_80178288;
extern u8 gFestivalEventsComplete;
extern u16 gFestivalPointsRed; 
extern u16 gFestivalPointsWhite;
extern u8 D_80178292;
extern u8 gIsFestivalTimeBeat;
extern s32 gFestivalTimeCurrrent;
extern s32 gFestivalTimeToBeat;
extern u8 gFestivalEventsBools[10];