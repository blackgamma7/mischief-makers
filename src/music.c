#include "music.h"
#include "common.h"
// While this script contains general sound functions, it is named music.c after Assert found in code.

ALCSPlayer gSFXPlayers[4];
ALCSPlayer* gSFXPlayersp[4];

#pragma GLOBAL_ASM("asm/nonmatchings/music/Audio_dmaCallBack.s")

// TODO: Figure out D_8016D9A8 and D_8016D9B8 types
#ifdef NON_MATCHING
void Audio_DmaNew(void** arg0) {
    ALLink* phi_s0;
    ALLink* phi_s1;

    if (D_8016D9A8.unk0 == 0) {
        D_8016D9A8.unk8 = &D_8016D9B8;
        D_8016D9B8.unk4 = 0;
        D_8016D9B8.unk0 = 0;

        for (phi_s0 = &D_8016D9CC, phi_s1 = &D_8016D9B8; phi_s0 != 0x8016DEB8; phi_s0 += 2, phi_s1 += 2) {
            alLink(phi_s0, phi_s1);
            phi_s1->next = alHeapDBAlloc(NULL, 0, &gALHeap, 1, 0x270);
        }

        phi_s1[2].next = alHeapDBAlloc(0, 0, &gALHeap, 1, 0x270);
        D_8016D9A8.unk0 = 1U;
    }
    *arg0 = &D_8016D9A8;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/music/Audio_DmaNew.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/music/func_80001A80.s")
#ifdef NON_MATCHING
void Sound_InitPlayers(void){
uint8_t i;
  
  osCreateMesgQueue(&Sound_DMAmesgQA,D_80137800,0x30);
  osCreateMesgQueue(&Sound_DMAmesgQB,&D_8016E740,1);
  gBgmInited = 1;
  gBGM_pALCPlayer = &BGM_ALCPlayer;
  D_8016E2E0 = &D_8016E1E8;
  gBgmState = 0;
  for(i=0;i<4;i++){
    gSFXPlayersp[i] = gSFXPlayers[i];
    D_8016E6C8[i] = D_8016E2E8[i];
    gSFX_ChannelStates[i] = 0;
  }
  alHeapInit(&gALHeap,gALHeapBase,ALHEAPSIZE);
  Sound_Acmdps[0] =alHeapDBAlloc(NULL,0,&gALHeap,1,0x3800);
  Sound_Acmdps[1] =alHeapDBAlloc(NULL,0,&gALHeap,1,0x3800);
  Sound_osTaskps[0] =alHeapDBAlloc(NULL,0,&gALHeap,1,0x40);
  Sound_osTaskps[1] =alHeapDBAlloc(NULL,0,&gALHeap,1,0x40);
  gAIBuffers[0] = alHeapDBAlloc(NULL,0,&gALHeap,1,0xa00);
  gAIBuffers[1] = alHeapDBAlloc(NULL,0,&gALHeap,1,0xa00);
  gAIBuffers[2] = alHeapDBAlloc(NULL,0,&gALHeap,1,0xa00);
  gSoundDMAlength = 0x11790;
  Sound_AlBankFilep = alHeapDBAlloc(NULL,0,&gALHeap,1,0x11790);
  Sound_DMA(0x4b9990,Sound_AlBankFilep,gSoundDMAlength);
  gSoundDMAlength = 4;
  gALSeqFile = alHeapDBAlloc(NULL,0,&gALHeap,1,4);
  Sound_DMA(0x6413b0,gALSeqFile,gSoundDMAlength);
  gSoundDMAlength = gALSeqFile->seqCount * 8 + 4;
  gALSeqFile = alHeapDBAlloc(NULL,0,&gALHeap,1,gSoundDMAlength);
  Sound_DMA(0x6413b0,gALSeqFile,gSoundDMAlength);
  alSeqFileNew(gALSeqFile,(u8 *)0x6413b0);
  ALGlobals_ALsynConfig.outputrate = osAiSetFrequency(0x5622);
  gSound_OutputRateF = ((float)ALGlobals_ALsynConfig.outputrate * 1.0) / 60.0;
  gSound_OutputRateI = gSound_OutputRateF;
  if (gSound_OutputRateI < gSound_OutputRateF) gSound_OutputRateI++;
  if (gSound_OutputRateI & 0xf) gSound_OutputRateI = (gSound_OutputRateI & 0xfffffff0U) + 0x10;
  INT_8016e720 = gSound_OutputRateI + -0x10;
  ALGlobals_ALsynConfig.maxVVoices = 0x14;
  ALGlobals_ALsynConfig.maxPVoices = 0x14;
  ALGlobals_ALsynConfig.maxUpdates = 0x90;
  ALGlobals_ALsynConfig.dmaproc = Audio_DmaNew;
  ALGlobals_ALsynConfig.fxType = AL_FX_CUSTOM;
  ALGlobals_ALsynConfig.heap = &gALHeap;
  ALGlobals_ALsynConfig.params = gAlFX_params;
  alInit(&gALGlobals,&ALGlobals_ALsynConfig);
  Sound_ALSeqPConfig.maxVoices = 0x1e;
  Sound_ALSeqPConfig.maxEvents = 0x40;
  Sound_ALSeqPConfig.maxChannels = 0x14;
  Sound_ALSeqPConfig.heap = &gALHeap;
  Sound_ALSeqPConfig.initOsc = NULL;
  Sound_ALSeqPConfig.updateOsc = NULL;
  Sound_ALSeqPConfig.stopOsc = NULL;
  alCSPNew(gBGM_pALCPlayer,&Sound_ALSeqPConfig);
  for(i=0;i<4;i++){
    alCSPNew(gSFXPlayersp[i],&Sound_ALSeqPConfig);
  }
  alBnkfNew(Sound_AlBankFilep,(u8 *)0x4cb120);
  Sound_ALBankps[0] = Sound_AlBankFilep->BankArray[0];
  Sound_ALBankps[1] = Sound_AlBankFilep->BankArray[1];
  Sound_ALBankps[2] = Sound_AlBankFilep->BankArray[2];
  Sound_ALBankps[3] = Sound_AlBankFilep->BankArray[3];
  alSeqpSetBank((ALSeqPlayer *)gBGM_pALCPlayer,Sound_ALBankps[0]);
  for(i=0;i<4;i++) {
    alSeqpSetBank((ALSeqPlayer *)gSFXPlayersp[i],Sound_ALBankps[1]);
  }
  PTR_8016e6d8 = alHeapDBAlloc(NULL,0,&gALHeap,1,0x3400);
  for(i=0;i<4;i++) {
    D_8016E6E0[i] = alHeapDBAlloc(NULL,0,&gALHeap,1,0x500);
  }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/music/Sound_InitPlayers.s")
#endif
void Sound_SetEventMesg(void) {
    osCreateMesgQueue(&D_801377D0, &D_801378C0, 1);
    osSetEventMesg(OS_EVENT_SP, &D_801377D0, 0);
    osSendMesg(&D_801377D0, 0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/music/Sound_Tick.s")

#ifdef NON_MATCHING
void Sound_NextBuffer(void) {
    uint8_t index;

    osRecvMesg(&D_801377D0, 0, 1);
    gSound_currentBuffer = (D_800C3838 - 1) % 3;
    osAiSetNextBuffer(gAIBuffers[gSound_currentBuffer], D_800C383C[gSound_currentBuffer] << 2);
    for (index = 0; index < D_800C3830; index++) {
        if (D_800C3830 > 0) {
            for (index = 0; index < D_800C3830; index++) {
                osRecvMesg(&Sound_DMAmesgQA, 0, 0);
            }
        }
    }

    func_80001A80();
    D_800C3830 = 0;
    D_800C3834 ^= 1;
    D_800C3838++;
    D_8016DEB8++;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/music/Sound_NextBuffer.s")
#endif

void Sound_StartTask(void) {
    osWritebackDCacheAll();
    osSpTaskLoad(Sound_OSTaskp);
    osSpTaskStartGo(Sound_OSTaskp);
}

#pragma GLOBAL_ASM("asm/nonmatchings/music/Sound_RomCopy.s")

void Sound_DMA(uint32_t devaddr, void* vaddr, uint32_t nbytes) {
    osWritebackDCacheAll();
    osPiStartDma(&D_801378C8, 0, 0, devaddr, vaddr, nbytes, &Sound_DMAmesgQA);
    osRecvMesg(&Sound_DMAmesgQA, 0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/music/BGM_Play.s")

#ifdef NON_MATCHING
void SFX_Set(uint8_t chan, void* player, int16_t SFX_ID, int16_t arg3, s8 arg4, uint8_t state, uint16_t arg6, uint16_t arg7) {
    gSFX_ChannelStates[chan] = state;
    D_80108DE0[chan] = arg6;
    gSFXCurrentIndex[chan] = SFX_ID;
    D_80104090[chan] = gSFX_2ByteArray[SFX_ID][1];
    D_8010CDE8[chan] = arg7;
    D_801069D8[chan] = arg4;
    if ((-1 < arg3) && (arg3 < 257)) {
        gSFX_Volumes[chan] = gSFX_2ByteArray[SFX_ID][0] * arg3;
    }
    else gSFX_Volumes[chan] = gSFX_2ByteArray[SFX_ID][0] << 8;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/music/SFX_Set.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/music/SFX_Play_0.s")


int32_t SFX_Stop(int32_t id)  {
  u8 i;
  for(i=0; i<4; i++){
    if ((gSFX_ChannelStates[i]) && (id == gSFXCurrentIndex[i])) {
      alSeqpStop(gSFXPlayersp[i]);
      return i;
    }
  }
  return -1;
}

// main SFX playing wrapper
int32_t SFX_Play_1(uint32_t id) {
    SFX_Play_0(id, -1, -1, 0x81, 0xFF, 0);
}

int32_t SFX_Play_2(uint32_t id) {
    SFX_Play_0(id, -1, -1, 0x91, 0xFF, 0);
}

int32_t SFX_Play_3(uint32_t id, int16_t arg1) {
    SFX_Play_0(id, arg1, -1, 0x81, 0xFF, 0);
}

int32_t SFX_Play_4(uint32_t id, int8_t arg1) {
    return SFX_Play_0(id, -1, arg1, 0x81U, 0xFFU, 0U);
}

int32_t SFX_Play_5(uint32_t id, int16_t arg1, int8_t arg2) {
    return SFX_Play_0(id, arg1, arg2, 0x81, 0xFF, 0);
}

int32_t SFX_Play_6(uint32_t id, int16_t arg1, int8_t arg2) {
    return SFX_Play_0(id, arg1, arg2, 0x91, 0xFF, 0);
}

int32_t SFX_Play_7(uint32_t id, int16_t arg1, int8_t arg2) {
    return SFX_Play_0(id, arg1, arg2, 0x92, 0xFF, 0);
}

int32_t SFX_Play_8(uint32_t id, int16_t arg1, int8_t arg2) {
    return SFX_Play_0(id, arg1, arg2, 0x93, 0xFF, 0);
}

void func_80003540(int16_t arg0, int16_t arg1, int8_t* arg2, int16_t* arg3) {
    int32_t phi_v1;
    int32_t phi_v0;
    int16_t temp;

    if (arg0 < -0x80) *arg2 = 0;
    else if (arg0 >= 0x80)
        *arg2 = 0x7F;
    else
        *arg2 = ((arg0 / 2) + 0x40);

    // looks like inlined abs?
    if (arg0 > 0) phi_v0 = arg0;
    else
        phi_v0 = -arg0;

    if (arg1 > 0) phi_v1 = arg1;
    else
        phi_v1 = -arg1;

    temp = phi_v1 + phi_v0;
    if (temp < 0x100) *arg3 = 0x100;
    else if (temp < 0x200)
        *arg3 = (0x200 - temp);
    else
        *arg3 = 0;
}

int32_t SFX_ActorPanXY(uint32_t SFX_ID, uint16_t i) {
    int8_t val_a;
    int16_t val_b;

    if ((gActors[i].pos.x < -0x90) || (gActors[i].pos.x >= 0x90)) {
        return -1;
    }

    if ((gActors[i].pos.y < -0x60) || (gActors[i].pos.y >= 0x60)) {
        return -1;
    }

    func_80003540(gActors[i].pos.x, gActors[i].pos.y, &val_a, &val_b);

    if (val_b < 128) {
        return -1;
    }
    else {
        return SFX_Play_0(SFX_ID, val_b, val_a, 0x81, 0xFF, 0);
    }
}

int32_t SFX_ActorPanX(uint32_t SFX_ID, uint16_t i) {
    int8_t val_a;
    int16_t val_b;

    if ((gActors[i].pos.x < -383) || (gActors[i].pos.x >= 384)) {
        return -1;
    }

    func_80003540(gActors[i].pos.x, gActors[i].pos.y, &val_a, &val_b);

    if (val_b < 128) {
        return -1;
    }
    else {
        return SFX_Play_0(SFX_ID, val_b, val_a, 0x81, 0xFF, 0);
    }
}

int32_t SFX_ActorPanX2(uint32_t SFX_ID, uint16_t i) {
    int8_t val_a;
    int16_t val_b;

    if ((gActors[i].pos.x < -383) || (gActors[i].pos.x >= 384)) {
        return -1;
    }

    func_80003540(gActors[i].pos.x, gActors[i].pos.y, &val_a, &val_b);

    if (val_b < 128) {
        return -1;
    }
    else {
        return SFX_Play_0(SFX_ID, val_b, val_a, 0x91, 0xFF, 0);
    }
}
//used for gem collision func.
int32_t SFX_GemX(uint32_t SFX_ID, uint16_t i){
    int8_t val_a;
    int16_t val_b;

    if ((gStaticGems[i].pos.x < -383) || (gStaticGems[i].pos.x >= 384)) {
        return -1;
    }

    func_80003540(gStaticGems[i].pos.x, gStaticGems[i].pos.y, &val_a, &val_b);

    if (val_b < 128) {
        return -1;
    }
    else {
        return SFX_Play_0(SFX_ID, val_b, val_a, 0x81, 0xFF, 0);
    }
}

int32_t func_800038C8(uint32_t SFX_ID, uint16_t index, uint16_t arg2) {
    int8_t val_a;
    int16_t val_b;

    if ((thisActor.pos.x < -383) || (thisActor.pos.x >= 384))
        return -1;
    func_80003540(thisActor.pos.x, thisActor.pos.y, &val_a, &val_b);

    if (val_b < 128) {
        return -1;
    }
    else {
        return SFX_Play_0(SFX_ID, val_b, val_a, 0xA1, 0xFF, arg2);
    }
}

void SFX_ActorPanCont(uint32_t arg0, uint16_t arg1) {
    SFX_Play_0(arg0, -1, -1, 0xC1, arg1, 0);
}

int32_t func_800039B8(uint32_t SFX_ID, uint32_t arg1, uint32_t arg2) { // 2 unused args?
    int i = SFX_Play_0(SFX_ID, -1, -1, 0x89, 0xFF, 0);
    D_8011CDF0[i] = 127;
    D_8011CF18[i] = 64;
    return i;
}

void BGM_SFX_Stop(void) {
    BGM_Stop();
    SFX_StopAll();
}

void BGM_Stop(void) {
    alSeqpStop((ALSeqPlayer*)gBGM_pALCPlayer);
    gBgmState = 0;
}

void SFX_StopAll(void) {
    uint8_t index;
    for (index = 0; index < 4; index++) {
        alSeqpStop((ALSeqPlayer*)gSFXPlayersp[index]);
        gSFX_ChannelStates[index] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/music/SFX_SetPan.s")

#pragma GLOBAL_ASM("asm/nonmatchings/music/SFX_SetPan_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/music/func_80003F24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/music/func_800040A0.s")
