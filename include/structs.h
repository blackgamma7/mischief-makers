#ifndef STRUCTS_H
#define STRUCTS_H

#include "inttypes.h"
#include <ultra64.h>

enum {
    GAMESTATE_SOFTRESET,
    GAMESTATE_INTRO,
    GAMESTATE_TITLESCREEN,
    GAMESTATE_DEBUG_SOUNDTEST,
    GAMESTATE_DEBUG_STAGESELECT,
    GAMESTATE_LOADING,
    GAMESTATE_GAMEPLAY,
    GAMESTATE_CONTINUE, // game over
    GAMESTATE_UNKNOWN0,
    GAMESTATE_UNKNOWN1,
    GAMESTATE_ATTRACT,
    GAMESTATE_FILESELECT,
    GAMESTATE_TRANSITION,
    GAMESTATE_NONE,
    GAMESTATE_UNKNOWN2 // level select (best times?)
};

//32=bit fixed number, used mainly for positioning.
typedef struct {
    union {
        struct {
            /* 0x00 */ int16_t _hi;
            /* 0x02 */ int16_t _lo;
        };
        /* 0x00 */ int32_t _w;
    };
} fixed32; /* sizeof = 0x04 */ // short[2], word

//strongly suspect this union type is what Treasure used, especially in the later part of the actor scruct.
typedef struct {
    union {
        /* 0x00 */ int32_t _w;
        /* 0x00 */ void* _p;
        /* 0x00 */ uint8_t _bu[4];
        /* 0x00 */ int8_t _b[4];
        /* 0x00 */ uint16_t _hu[2];
        /* 0x00 */ int16_t _h[2];
        /* 0x00 */ float _f;
    };
} word_u; /* sizeof = 0x04 */ 

typedef struct {
    union {
        struct {
            /* 0x00 */ uint8_t _hi;
            /* 0x01 */ uint8_t _lo;
        };
        /* 0x00 */ uint16_t _s;
    };
} b2_s;


typedef struct {
    union {
        /* 0x00 */ int16_t x;
        /* 0x00 */ int32_t x_w;
    };
    union {
        /* 0x04 */ int16_t y;
        /* 0x04 */ int32_t y_w;
    };
} vec2Fixed; /* sizeof = 0x08 */

typedef union {
    struct {
        /* 0x00 */ int32_t x_w;
        /* 0x04 */ int32_t y_w;
        /* 0x08 */ int32_t z_w;
    };
    struct {
        /* 0x00 */ int16_t x;
        /* 0x02 */ int16_t x_1;
        /* 0x04 */ int16_t y;
        /* 0x06 */ int16_t y_1;
        /* 0x08 */ int16_t z;
        /* 0x0A */ int16_t z_1;
    };
} vec3Fixed; /* sizeof = 0x0C */

typedef union {
    struct {
        /* 0x00 */ uint8_t r;
        /* 0x01 */ uint8_t g;
        /* 0x02 */ uint8_t b;
        /* 0x03 */ uint8_t a;
    };
    /* 0x00 */ uint32_t rgba;
} RGBA32; /* sizeof = 0x04 */

typedef struct {
    int16_t Active; 
    uint8_t text[80];  // 2 bytes after (align solves for it?)
    int32_t posX;
    int32_t posY;
    RGBA32 color;
    float scaleX;
    float scaleY;
} TextTransform;

//UI objects? last 2 are the health gauge and its portrait
typedef struct {
    /* 0x00 */ Mtx translateMtxs[2]; //one for each FB
    /* 0x80 */ uint16_t flags;
    /* 0x82 */ uint16_t graphic;
    /* 0x84 */ vec2Fixed pos;
    /* 0x8C */ float scaleX;
    /* 0x90 */ float scaleY;
    /* 0x94 */ int8_t alpha;
    /* 0x95 */ int8_t unk_0x95[3]; //this is Definitely align.
    /* 0x98 */ void* palette;
    /* 0x9C */ int32_t unk_0x9C; //unused?
} Portrait;/* sizeof 0xA0 */
#define HealthBar gPortraits[64]
#define HealthFace gPortraits[65]

//likely the gem objects.
typedef struct {
    /* 0x00 */ Mtx translateMtxs[2]; //one for each FB
    /* 0x80 */ uint16_t flags;
    /* 0x82 */ uint16_t unk_0x82; //may be align
    /* 0x84 */ vec2Fixed pos;
    /* 0x8C */ void* texture;
} StaticGem; /* sizeof 0x90 */

//seems to handle some of the player actor data.
typedef struct {
    /* 0x00 */ int32_t unk_0x00[2];
    /* 0x08 */ int16_t unk_0x8;
    /* 0x0A */ int8_t unk_0xA;
    /* 0x0B */ int8_t unk_0xB;
    /* 0x0C */ int16_t unk_0xC;
    /* 0x0E */ int16_t unk_0xE;
    /* 0x10 */ int8_t unk_0x10;
    /* 0x10 */ int8_t unk_0x11;
    /* 0x12 */ int8_t unk_0x12; //shake timer?
    /* 0x13 */ uint8_t unk_0x13;
    /* 0x14 */ uint8_t unk_0x14[12];
    /* 0x20 */ fixed32 buttonHold; 
    /* 0x24 */ fixed32 buttonPress;
    /* 0x28 */ uint8_t unk_0x28[24]; //unused?
    /* 0x40 */ union{
        uint32_t unk_0x40_w;
        struct{
            int16_t unk_0x40_hi;
            int8_t unk_0x42;
            uint8_t unk_0x43;
        };
    };
    /* 0x44 */ uint32_t FallBool; //"freefall" whistle flag
    /* 0x48 */ uint32_t unk_0x48;
    /* 0x4C */ uint32_t unk_0x4C;
    /* 0x50 */ uint32_t DebugPosX; // Marina position mirror
    /* 0x54 */ uint32_t DebugPosY; //if either is set, will be printed onscreen breifly.
    /* 0x58 */ uint32_t DebugValC; //same with these 2 vaules.
    /* 0x5C */ uint32_t DebugValD; //need to see if anything sets them in the rom funcs.
    /* 0x60 */ uint32_t unk_0x60;
    /* 0x64 */ uint32_t unk_0x64; //gPlayerActor.flag3
    /* 0x68 */ uint32_t actorSpeedX; //gPlayerActor.speedX._w
    /* 0x6C */ uint32_t actorSpeedY; //gPlayerActor.speedY._w
    /* 0x70 */ uint16_t playerLink; //gPlayerActor.actorLink
    /* 0x72 */ int16_t unk_0x72;
    /* 0x74 */ uint32_t unk_0x74;
    /* 0x78 */ uint32_t flags;
    /* 0x7C */ uint32_t unk_0x7C; //player actor time?
} playerManager; /* sizeof = 0x80 */

// Dunno what to call this, contains a dlist and the 0x180 byte preamble
typedef struct {
    /* 0x0000 */ Mtx mtxs[6]; //{ortho,?,lookat,ortho,?,?}
    /* 0x0180 */ Gfx dlist[3072];
} Gfx_Data; /* sizeof = 0x6180 */

//inventory of stage's clanpot. item stored from last index upward. gClanpotItems may be a {ClanpotItem[32],u16[160]} union.
typedef struct{
    /*0x00*/ uint16_t flags;
    /*0x02*/ uint16_t ActorFeild0x110;
    /*0x04*/ uint16_t ActorFeild0xD8;
    /*0x06*/ uint16_t unk_0x6;
    /*0x08*/ uint16_t ActorType;
}ClanpotItem;/* sizeof = 0x0C */

#endif
