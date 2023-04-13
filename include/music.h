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

extern void Audio_dmaCallBack();
extern void Audio_DmaNew();
extern void func_80001A80();
extern void Sound_InitPlayers();
extern void Sound_SetEventMesg(void);
extern void Sound_Tick();
extern void Sound_DMA(uint32_t devaddr, void* vaddr, uint32_t nbytes);
extern void BGM_Play(uint8_t BGMID);
extern int32_t SFX_Play_0(uint32_t id, int16_t arg1, int8_t arg2, UNK_TYPE arg3, UNK_TYPE arg4, uint16_t arg5);
extern int32_t SFX_Play_1(uint32_t id);
extern int32_t SFX_Play_2(uint32_t id);
extern int32_t SFX_Play_3(uint32_t id, int16_t arg1);
extern int32_t SFX_Play_4(uint32_t id, int8_t arg1);
extern int32_t SFX_Play_5(uint32_t id, int16_t arg1, int8_t arg2);
extern int32_t SFX_Play_6(uint32_t id, int16_t arg1, int8_t arg2);
extern int32_t SFX_Play_7(uint32_t id, int16_t arg1, int8_t arg2);
extern int32_t SFX_Play_8(uint32_t id, int16_t arg1, int8_t arg2);
extern void BGM_SFX_Stop(void);
extern void BGM_Stop(void);
extern void SFX_StopAll();
extern void SFX_SetPan();
extern void SFX_SetPan_2();
extern uint32_t func_80003F24(uint16_t,uint16_t);
extern void Sound_NextBuffer();
extern void Sound_StartTask(void);
extern int32_t func_80002A2C(int32_t i, void* vAddr);
extern void func_80002F48(uint8_t chan, void* player, int16_t SFX_ID, int16_t arg3, s8 arg4, uint8_t state, uint16_t arg6, uint16_t arg7);
extern int32_t SFX_Stop(int32_t ID);
extern void func_80003540(int16_t arg0, int16_t arg1, int8_t* arg2, int16_t* arg3);
extern int32_t SFX_ActorPanXY(uint32_t id, uint16_t index);
extern int32_t SFX_ActorPanX(uint32_t id, uint16_t index);
extern int32_t SFX_ActorPanX2(uint32_t id, uint16_t index);
extern int32_t SFX_GemX(uint32_t id, uint16_t index);
extern int32_t func_800038C8(uint32_t id, uint16_t index, uint16_t arg2);
extern void SFX_ActorPanCont(uint32_t id, uint16_t arg1);
extern int32_t func_800039B8(uint32_t SFX_ID, uint32_t arg1, uint32_t arg2);
extern void func_800040A0();
#endif

