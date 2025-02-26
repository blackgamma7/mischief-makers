#include "BGM.h"
#include "common.h"
//camera functions, some that are level-specific.
void Camera_RotateReset(void) {
    gCameraRot = 0;
    gCameraRotDelta = 0;
}

void Camera_ApplyRotate(void){
    gCameraRot+=gCameraRotDelta;
    gUpX =SIN(gCameraRot/0x10000);
    gUpY =COS(gCameraRot/0x10000);
}

void CameraInit_Scene63(void) {}
void CameraTick_Scene63(void) {}

void CameraInit_World1(void) {
    D_800BE578 = 2;
    D_800BE6FC = 1;
    D_800BE584 = -0xC;
}

#pragma GLOBAL_ASM("asm/nonmatchings/Scenes/CameraTick_World1.s")

void CameraInit_World2(void) {
    D_800BE578 = (int16_t)((int32_t)gScreenPosCurrentX._hi / 2);
    D_800BE580 = -0xC;
    gEyeY = 32.0f;
    D_800BE6A8 = 1;
    D_800BE70C = 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/Scenes/CameraTick_World2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/Scenes/CameraTick_WesternWorld.s")

void CameraInit_TightropeRide(void) {
    D_800BE580 = -0xC;
    gEyeY = 32.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/Scenes/CameraTick_TightropeRide.s")

void CameraInit_MagmaRafts(void) {
    D_800BE580 = -0xC;
    gEyeY = 32.0f;
    D_800BE70C = 2;
}

void CameraTick_MagmaRafts(void) {
    CameraTick_World2();
    if ((gDebugBitfeild & 0xA400) == 0) { //this freezes the camera otherwise
        gCameraScrollFlags = 0x8000;
        gScreenPosTargetX._w = (gPlayerPosXMirror._w + 0x200000);
        gScreenPosTargetY._w = gPlayerPosYMirror._w;
        gCameraScrollThrottleX = 1;
    }
}

void CameraInit_scene02(void){
    HealthBar.flags=0;
    HealthFace.flags=0;
    gIsPlayerInactive=1;
}

void CameraTick_scene02(void) {}
void CameraInit_Scene03(void){
    D_800BE57C=0;
    D_800BE584=0;
    HealthBar.flags=0;
    HealthFace.flags=0;
    gIsPlayerInactive=1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/Scenes/CameraTick_scene03.s")

void CameraInit_Scene04(void){
    D_800BE57C=2;
    D_800BE584=-12;
    HealthBar.flags=0;
    HealthFace.flags=0;
    gIsPlayerInactive=1;
}

void CameraTick_Scene04(void) {}

void cameraInit_MigenBrawl(void) {
    D_800BE578 = 2;
    D_800BE57C = 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/Scenes/cameraTick_MigenBrawl.s")

void CameraInit_Scene07(void) {
    gCameraScrollFlags = 0x30;
    D_800BE57C = 2;
    D_800BE584 = -0xC;
}

void CameraTick_Scene07(void) {
    D_800BE578 = gScreenPosCurrentX._hi;
    D_800BE580 = gScreenPosCurrentY._hi + 0x60;
}

void func_80023D98(void) {
    D_800BE578 = 2;
    D_800BE580 = -0xC;
}

void func_80023DB4(void) {}

void func_80023DBC(void) {
    gCameraScrollFlags = 0x30;
    D_800BE57C = 2;
    D_800BE584 = -0xC;
    D_800BE674 = 1;
}

void CameraTick_Lunar(void) {}

void CameraInit_Intro(void) {
    D_800BE578 = 2;
    D_800BE580 = -0xC;
}

void CameraTick_Intro(void) {}

void CameraInit_World3B(void) {
    D_800BE57C = 2;
    D_800BE584 = -0xC;
}

void CameraTick_World3B(void) {}

void CameraInit_TheDayBefore(void) {}

void CameraTick_TheDayBefore(){
    D_800BE73C = (gScreenPosCurrentX._hi - gScreenPosNextX._hi) << 0x10;
}

void CameraInit_Scene34(void) {}

void CameraTick_Scene34(void) {
    D_800BE73C = (gScreenPosCurrentX._hi - gScreenPosNextX._hi) << 0x10;
}

void CameraInit_World3(void) {
    D_800BE57C = 2;
    D_800BE584 = -0xC;
}

void CameraInit_SnowstormMaze(void) {
    CameraInit_World3();
    D_800BE674 = 1;
}
//2 of the Mt. Snow levels
void func_80023EDC(void){
        if ((gDebugBitfeild & 0xA400) == 0) {
        gCameraScrollFlags = 0x8000;
        if(gPlayerActor.flag&0x20)gScreenPosTargetX._w = gPlayerPosXMirror._w - 0x300000;
        else gScreenPosTargetX._w = gPlayerPosXMirror._w +0x300000;
        gScreenPosTargetY._w = gPlayerPosYMirror._w+0x280000;
    }
}

void func_80023F5C(void){
    if ((gDebugBitfeild & 0xA400) == 0) {
        gCameraScrollFlags = 0x8000;
        gScreenPosTargetX._w = gPlayerPosXMirror._w;
        if((gPlayerActor.actorLink==0x31)&&(gActors[48].actorType == 0x907)&&(gActors[50].unk_0x180._w & 0x8000)){
            gCameraScrollFlags = 0x8000;
            gScreenPosTargetY._w = gActors[48].pos.y_w+gScreenPosCurrentY._w + 0x180000;
            }
        else gScreenPosTargetY._w = gPlayerPosYMirror._w+0x280000;    
    }
}

void CameraTick_ClanballLift(void){
    if ((gDebugBitfeild & 0xA400) == 0) {
        gCameraScrollFlags = 0x8000;
        if(D_800D28E8<3)gScreenPosTargetY._w = (gPlayerPosYMirror._w + 0x280000);
        else gScreenPosTargetY._w = gPlayerPosYMirror._w;
        gScreenPosTargetX._w = gPlayerPosXMirror._w;
    }
}


void CameraInit_SeasickClimb(void) {
    int32_t temp_v0 = 1;
    D_800BE70C = 3;
    D_800BE6A8 = 2;
    // fake match? This doesn't seem very human
    gCameraScrollThrottleY = *((int32_t*)&temp_v0);
    D_800BE710 = *((int32_t*)&temp_v0);
    D_800BE71C = 0x1000000;
    D_800BE720 = 0;
    D_800BE724 = 0x1C00000;
    D_800BE728 = 0xFFFF0000;
    gCameraRot = 0;
    gCameraRotDelta = 0;
    D_800BE638 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/Scenes/CameraTick_SeasickClimb_Rocking.s")

#pragma GLOBAL_ASM("asm/nonmatchings/Scenes/CameraTick_SeasickClimb.s")

void CameraInit_Vertigo(void) {
    D_800BE70C = 3;
    D_800BE6A8 = 2;
    D_800BE710 = 1;
    gCameraRot = 0;
}
#ifdef NON_MATCHING
void CameraTick_Vertigo(){
    int32_t rot=gCameraRot;
    if(gCameraRot<0) rot=gCameraRot+0xFFFF;
    rot=rot>>0x10;
    gUpX=gCosineLookup[rot - 0x100 & 0x3FF];
    gUpY=gCosineLookup[rot & 0x3FF];

}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/Scenes/CameraTick_Vertigo.s")
#endif

void CameraInit_Freefall(void) {
    D_800BE70C = 3;
    D_800BE6A8 = 2;
    D_800BE710 = 1;
}

void CameraTick_Freefall(void) {}

void func_800245B4(void){
    D_800BE578 = 2;
    D_800BE580 = -0xc;
    D_800BE57C = 2;
    D_800BE584 = -0xc;
    HealthBar.flags=0;
    HealthFace.flags=0;
}

void func_800245F0(void) {}

void func_800245F8(void) {}

void CameraTick_AthleticGames(){
    D_800BE73C=(gScreenPosCurrentX._hi-gScreenPosNextX._hi)<<0x10;
}


void CameraInit_Beastector(void) {
    D_800BE588 = 2;
    gCameraScrollThrottleX = 1;
    gCameraScrollThrottleY = 1;
    gLetterboxMode = 1U;
    Camera_RotateReset();
}

#pragma GLOBAL_ASM("asm/nonmatchings/Scenes/CameraTick_Beastector.s")

void CameraInit_CounterAttack(void) {
    gCameraScrollFlags = 0x8000;
    gCameraScrollThrottleX = 1;
    gCameraScrollThrottleY = 1;
    D_800BE588 = 3;
    D_800CC428 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/Scenes/func_8002488C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/Scenes/CameraTick_CounterAttack.s")

void CameraInit_ClanceWar2(void) {
    D_800BE588 = 3;
}

void CameraTick_ClanceWar2(){
    D_800BE73C=(gScreenPosCurrentX._hi-gScreenPosNextX._hi)*0x10000;
    func_8002488C();
}

void CameraInit_BeesTheOne(void) {
    gCameraScrollFlags = 0x8000;
    gCameraScrollThrottleX = 1;
    gCameraScrollThrottleY = 1;
    D_800BE588 = 3;
}

#ifdef NON_MATCHING
void func_80024DD8(void) {
    uint16_t* x = D_800CC228;
    uint16_t* y = D_80380400;
    uint16_t i;
    for (i = 0; i < 256; i++) {
        *y = *x;
        x++;
        y++;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/Scenes/func_80024DD8.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/Scenes/func_80024E18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/Scenes/CameraTick_BeesTheOne.s")

void CameraInit_Splashscreen(void) {}

void CameraTick_Splashscreen(void) {}

void CameraInit_Merco_Trapped(void) {
    D_800BE588 = 0;
    D_800BE58C = 1;
    D_800BE584 = -0x4C;
    D_8013746C = &D_800C71A0;
    if (gCurrentScene != SCENE_TRAPPED) { 
        gEyeX = -128.0f;
        gEyeY = 128.0f;
    }
    Camera_RotateReset();
}

void CameraTick_Merco_Trapped(void) {
    Camera_ApplyRotate();
    if ((gSceneFrames & 1))
        D_800BE57C++;
}

void func_8002515C(void) {
    D_800BE580 = -0x18;
    D_800BE57C = 2;
    D_800BE584 = -0xC;
}

void func_80025184(void) {
    D_800BE578 = (int16_t)(((int32_t)gScreenPosCurrentX._hi / 4) & 0x1FF);
    D_800BE57C = (int16_t)(((int32_t)gScreenPosCurrentX._hi / 8) & 0x1FF);
}
// camera funcs for cave stages
void CameraInit_World4B(void) {
    D_800BE57C = 2;
    D_800BE584 = -0xC;
}

#pragma GLOBAL_ASM("asm/nonmatchings/Scenes/CameraTick_World4B.s")

#pragma GLOBAL_ASM("asm/nonmatchings/Scenes/CameraTick_AstersTryke.s")

void CameraInit_PhoenixGamma(void) {
    gCameraScrollThrottleX = 1;
    gCameraScrollThrottleY = 1;
    gLetterboxMode = 2;
    Camera_RotateReset();
}

void CameraTick_PhoenixGamma(void){
    Camera_ApplyRotate();
    if(gLetterboxMode == 2){
        if(gScreenPosCurrentY._hi<256){
            gScreenPosCurrentY._hi+=0x400;
            gScreenPosTargetY._hi+=0x400;
        }
        if(gScreenPosCurrentY._hi>0X500){
            gScreenPosCurrentY._hi-=0x400;
            gScreenPosTargetY._hi-=0x400;
        }
    }
}
//Camera funcs for "Monolith" Leo
void CameraInit_Leo(void) {
    D_800BE578 = 2;
    D_800BE580 = -0xC;
    D_800BE70C = 4;
}

void CameraTick_Leo(void) {}
// determines lifebar's position?
#pragma GLOBAL_ASM("asm/nonmatchings/Scenes/func_800253B0.s")

uint8_t gSceneBGMs[] = {
    BGM_ESPERANCE,
    BGM_VOLCANIC,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    BGM_YUJYA,
    0xff,
    0xff,
    BGM_YUJYA,
    BGM_OPENING_TITLE,
    BGM_ESPERANCE,
    BGM_VOLCANIC,
    BGM_TO1,
    0xff,
    0xff,
    0xff,
    0xff,
    BGM_BOSS,
    BGM_BONO,
    0xff,
    BGM_REVENGE,
    BGM_WOODS,
    BGM_GLOOMY,
    BGM_BOSS,
    BGM_BOSS,
    0xff,
    BGM_DETERMINATION,
    0xff,
    BGM_BONO,
    BGM_OUT,
    BGM_ESPERANCE,
    BGM_WOODS,
    BGM_BONO,
    BGM_BONO,
    BGM_LIKE_A_WIND,
    BGM_MARINA,
    BGM_VOLCANIC,
    BGM_OUT,
    BGM_MARINA,
    0xff,
    BGM_A_CAVE,
    BGM_A_CAVE,
    BGM_A_CAVE,
    BGM_A_CAVE,
    BGM_OUT,
    BGM_MARINA,
    BGM_OBAKESONG,
    BGM_A_CAVE,
    BGM_A_CAVE,
    BGM_A_CAVE,
    BGM_ESPERANCE,
    BGM_HURRY,
    BGM_LIKE_A_WIND,
    BGM_HURRY,
    BGM_LIKE_A_WIND,
    0xff,
    0xff,
    BGM_OUT,
    BGM_GIMMICK,
    BGM_MARINA,
    BGM_GIMMICK,
    BGM_BONO,
    0x0f,
    BGM_LETHE,
    BGM_DETERMINATION,
    BGM_HURRY,
    BGM_ESPERANCE,
    BGM_VOLCANIC,
    BGM_VOLCANIC,
    BGM_MARINA,
    BGM_BONO,
    BGM_TO1,
    BGM_TO1,
    BGM_TO1,
    BGM_TO1,
    BGM_HURRY,
    BGM_HURRY,
    0xff,
    BGM_TO1,
    BGM_TO1,
    BGM_TO1,
    BGM_TO1,
    BGM_TO1,
    BGM_YUJYA,
    BGM_REVENGE,
    BGM_TO1};

void PlaySceneBGM(void) {
    if (gSceneBGMs[gCurrentScene] != 255) {
        BGM_Play(gSceneBGMs[gCurrentScene]);
    }
}
//stage init?
#pragma GLOBAL_ASM("asm/nonmatchings/Scenes/func_800255B4.s") 
//multiple romcopy funcs
void LoadSceneFiles(void) {
    func_8002694C(gCurrentScene);
    func_80026A18(gCurrentScene);
    func_80026B04(gCurrentScene);
    func_80026BD0(gCurrentScene);
    func_80026874(gCurrentScene);
    func_80026C9C(gCurrentScene);
    func_8002729C(gCurrentScene);
    RomCopy_BaseGraphics();
}

void func_80025BFC(void) {
    uint32_t* phi_v1;
    uint32_t* phi_a0;
    uint16_t index;

    for (index = 0, phi_v1 = (uint32_t*)0x80380000, phi_a0 = (uint32_t*)0x803DA200; index < 0x180; index++) {
        *phi_a0 = *phi_v1;
        phi_a0++;
        phi_v1++;
        // though below makes more sense, above is required to match? Feels fake
        // phi_a0[index] = phi_v1[index];
    }
}
void InitScene(void){
  func_800255B4(gCurrentScene);
  RomCopy_ActorFuncs(gCurrentScene);
  RomCopy_ActorFuncs2(gCurrentScene);
  RomCopy_ActorFuncs3(gCurrentScene);
  RomCopy_ActorFuncs4(gCurrentScene);
  RomCopy_ActorFuncs5(gCurrentScene);
  RomCopy_Actors(gCurrentScene);
  func_800265FC(gCurrentScene);
  func_8002670C(gCurrentScene);
  func_80026784(gCurrentScene);
  RomCopy_Dialouge(gCurrentScene);
  Textbox_Init();
  func_8002653C();
  if (((gCurrentScene == SCENE_ASTERSTRYKE) || (gCurrentScene == SCENE_TAURUS)) ||
     ((0x2d < gCurrentScene && (gCurrentScene < SCENE_3CLANCERKIDS)))) {
    func_80026220(SCENE_RESCUEACT1);
    func_80026428(SCENE_ASTERSTRYKE);
  }
  else if (((gCurrentScene == SCENE_DEMOWORLD1) || (gCurrentScene == SCENE_DEMOWORLD5)) ||(gCurrentScene == SCENE_ENDING)) {
    func_80026220(SCENE_BLOCKMANRISES);
    func_80026494(SCENE_DEMOWORLD1,0);
    D_801376A4 = 0x80380400;
  }
  else func_80026220(gCurrentScene);
  if (((gCurrentScene == SCENE_TRAPPED) || (gCurrentScene == SCENE_MERCO)) ||(gCurrentScene == 0x56)) {
    func_80024DD8();
  }
  func_80025BFC();
  LoadSceneFiles();
  (*Scene_CameraInits[gCurrentScene])();
  (*Scene_CameraFuncs[gCurrentScene])();
  PlaySceneBGM();
}
