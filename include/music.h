#ifndef MUSIC_H
#define MUSIC_H

#include "data_symbols.h"
#include "function_symbols.h"
#include "inttypes.h"
#include <ultra64.h>

#ifdef VER_JPN
#define ALHEAPSIZE 0x35700
#else
#define ALHEAPSIZE 0x35C00
#endif

extern ALCSPlayer gSFXPlayers[4];
extern ALCSPlayer* gSFXPlayersp[4];
extern void* gAIBuffers[3];
extern ALHeap gALHeap;
extern ALGlobals gALGlobals;
extern ALSynConfig gSynConfig;
extern ALBank* Sound_ALBankps[4];
extern OSMesgQueue Sound_DMAmesgQA;
extern OSMesgQueue D_801377D0;
extern uint8_t gBgmState; // 0x80: starting 0x01: playing
extern int16_t gBgmVolume;
extern uint8_t gSFX_ChannelStates[];
extern int16_t gSFX_Volumes[];
extern uint32_t D_80137794; //800c0ad8[x][1]<<0XC. Unused?
extern u8 D_80137798; //BGM_play() requires this to be non-zero.
extern OSMesg D_80137800[48];
extern OSMesg D_801378C0;
extern OSIoMesg D_801378C8;
extern OSIoMesg D_801378E0[48];
extern OSTask* Sound_osTaskps[2];
extern Acmd* Sound_Acmdps[2];
extern uint16_t D_80137D90;
extern uint32_t D_80137DA0; // current BGM playtime? Attact mode starts when this is >0x1140
extern uint8_t gALHeapBase[ALHEAPSIZE];
extern ALLink D_8016D9CC;
extern ALLink D_8016D9B8;
extern UNK_TYPE D_8016DEB8;
extern ALBankFile* Sound_AlBankFilep;
extern ALCSPlayer D_8016DF68;
extern ALCSeq D_8016E1E8;
extern ALCSeq* D_8016E2E0;
extern ALCSeq D_8016E2E8[4];
extern ALCSeq* D_8016E6C8[4];
extern u8* D_8016E6E0[4];
extern OSTask* Sound_OSTaskp;
extern ALInstrument* D_8016E6F8;
extern ALSound* D_8016E6FC;
extern ALEnvelope* gALEnelopeTemp;
extern ALKeyMap* D_8016E704;
extern Acmd* D_8016E708;
extern float gSound_OutputRateF; //ALGlobals_ALsynConfig.outputrate * 1 / 60.0
extern uint32_t D_8016E710; // alAudioFrame().cmdLen
extern uint32_t gSoundDMAlength; //used as siezeof in Sound_Init
extern uint32_t gSound_currentBuffer;
extern uint32_t gSound_OutputRateI;
extern uint32_t D_8016E720;
extern OSIoMesg gSoundOsIOmesgs[9];

extern char* BGMNames[33];    // BGM titles left in data.
extern char** D_800BEA4C[32];   // instrument names, and variations.
extern uint8_t* D_800C0A54[33]; //contains instrument data for each song 
extern uint8_t gBGMVolsFxs[33][18]; // Music track data {vol>>8,unknown>>0xc,instrumentFXMix[16]}
extern char* D_800C1694[294];   // could help add to SFX.h
extern uint8_t D_800C2280[223]; // looks like it's ID's for ALInstrument
extern char* gSfxSampleLabels[224];
extern uint16_t D_800C26DC[293];
extern uint8_t gSFX_2ByteArray[294][2]; // table of volume and length(?) of SFX.
extern int32_t Sound_AI_LEN_Rsh2; //AI_LEN >>2
extern u8 gSFXSampleData[325][8]; //{volume, pan, keyBase, AtkTime, AtkVol, DecayTime, DecayVol, ReleaeTime}
extern UNK_TYPE D_800C3830;
extern UNK_TYPE D_800C3834;
extern UNK_TYPE D_800C3838;
extern int16_t D_800C383C[];
extern int32_t gALFX_Params[42];
#endif

