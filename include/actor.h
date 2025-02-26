#ifndef ACTOR_H
#define ACTOR_H

#include "structs.h"

enum {
    ACTOR_FLAG_DRAW = (1 << 0),   // if this bit is unset, the actor does not get drawn (however, it can still be active)
    ACTOR_FLAG_ACTIVE = (1 << 1), // if this bit is unset, the relative slot on the actor stack is considered to be free (the actor is inactive)
    ACTOR_FLAG_ONSCREEN_ONLY = (1 << 2), //deactivate if off-camera?
    ACTOR_FLAG_UNK3 = (1 << 3), //don't move with screen?
    ACTOR_FLAG_UNK4 = (1 << 4),
    ACTOR_FLAG_FLIPPED = (1 << 5), // if this bit is set, the actor will face left, as seen in func_8006C5A4, it sets unk_0x148 (which is probably x scale) to -unk_0xB4 (which is probably initial x
                                   // scale, in this context?)
    ACTOR_FLAG_UNK6 = (1 << 6),  //seems related to actor linking?
    ACTOR_FLAG_UNK7 = (1 << 7),  //7-12 seem to deal with collision checks.
    ACTOR_FLAG_UNK8 = (1 << 8),  //and whether or not the hitboxA or B fields
    ACTOR_FLAG_UNK9 = (1 << 9),  //are used for damage/physics
    ACTOR_FLAG_UNK10 = (1 << 10), 
    ACTOR_FLAG_UNK11 = (1 << 11),
    ACTOR_FLAG_UNK12 = (1 << 12),
    ACTOR_FLAG_UNK13 = (1 << 13),
    ACTOR_FLAG_UNK14 = (1 << 14),
    ACTOR_FLAG_UNK15 = (1 << 15), //something with damage (instakill if set?)
    ACTOR_FLAG_UNK16 = (1 << 16),
    ACTOR_FLAG_UNK17 = (1 << 17),
    ACTOR_FLAG_UNK18 = (1 << 18), //3d platfom actor?
    ACTOR_FLAG_UNK19 = (1 << 19),
    ACTOR_FLAG_UNK20 = (1 << 20),
    ACTOR_FLAG_UNK21 = (1 << 21),
    ACTOR_FLAG_UNK22 = (1 << 22), //something with physics?
    ACTOR_FLAG_UNK23 = (1 << 23), //something with physics?
    ACTOR_FLAG_UNK24 = (1 << 24), //unused?
    ACTOR_FLAG_ATTACHED = (1 << 25),      // might be holding, or held. This bit is on for Marina when she is holding an actor (see ActorTick_Marina)
    ACTOR_FLAG_ALWAYS_UPDATE = (1 << 26), // if this bit is set, the actor will always update, despite the state of D_800BE670
    ACTOR_FLAG_UNK27 = (1 << 27), //set but not checked?
    ACTOR_FLAG_UNK28 = (1 << 28), //set but not checked?
    ACTOR_FLAG_UNK29 = (1 << 29), //set but not checked?
    ACTOR_FLAG_UNK30 = (1 << 30), //set but not checked?
    ACTOR_FLAG_UNK31 = (1 << 31)
};

enum{
    ACTOR_GFLAG_0 = (1 << 0), //scale/rotate effected by feild 0x120 (player only?)
    ACTOR_GFLAG_ROTX = (1 << 1), //effected by rotateX
    ACTOR_GFLAG_ROTY = (1 << 2), //effected by rotateY
    ACTOR_GFLAG_ROTZ = (1 << 3), //effected by rotateZ
    ACTOR_GFLAG_4 = (1 << 4), //changes "G_SETCOMBINE" used?
    ACTOR_GFLAG_5 = (1 << 5), //unused?
    ACTOR_GFLAG_6 = (1 << 6), //changes if effected by perspective?
    ACTOR_GFLAG_7 = (1 << 7), //unused?
    ACTOR_GFLAG_8 = (1 << 8), //effects z positioning?
    ACTOR_GFLAG_RGB16 = (1 << 9), //use &feild0x18C as a palette?
    ACTOR_GFLAG_A = (1 << 10), //effects animation
    ACTOR_GFLAG_B = (1 << 11), //seems to effect translate mtx.
    ACTOR_GFLAG_C = (1 << 12),//use feild 0x12C as z scale.
    ACTOR_GFLAG_D = (1 << 13), //3d objects? 
    ACTOR_GFLAG_E = (1 << 14), //unused?
    ACTOR_GFLAG_F = (1 << 15), //a change in blending?
};
// Common combined flags
#define ACTOR_FLAG_ENABLED (ACTOR_FLAG_DRAW | ACTOR_FLAG_ACTIVE)

typedef void (*ActorFunc)(uint16_t index);


/*
 * Struct notes from 1.0 (99% based on observation and not code)
 * Observation is primarily on Marina and Teran, so other actors are likely to be espescially different
 * However, all actors are 0x198 in size, probably uses a unioned structure
 * Larger entities (such as bosses) are generally made up of multiple actors
 * I am not using these names in the struct to avoid mislabeling stuff that is not really confirmed
 *  offset, name,                   size
 *  0x018: pos_x_0,                 16
 *  0x01A: pos_y_0,                 16
 *  0x01C: pos_z_0,                 32
 *  0x058: pos_x_1,                 16
 *  0x05A: pos_y_1,                 16
 *  0x05C: pos_z_1,                 32
 *  0x080: mode,                    32 // we call this flag here, since it is probably some sort of bitfield
 *  0x084: current_sprite,          16 // not sure what this actually represents, but it is connected to the sprite
 *  0x088: pos,                     64 // much like in our current struct, I was confused about the u16 values that are sometimes u32?
 *  0x090: pos_z,                   16
 *  0x094: render_flags             16 // not entirely accurate, might be a bitfield for some settings
 *  0x098: flags,                   32 // probably the "state" a particular actor uses, instead of the generic "flag"
 *  0x09C: rgba,                    32
 *  0x0A0: impact                   08 // probably incorrect
 *  0x0A2: effect                   16 // probably incorrect
 *  0x0B4: scale_x                  32 // float
 *  0x0B8: scale_y                  32 // float
 *  0x0C8: pos_x_3                  16
 *  0x0CA: pos_y_3                  16
 *  0x0CC: pos_x_4                  16
 *  0x0CE: pos_y_4                  16
 *  0x0D0: status                   16 // hope code can describe this better than I can
 *  0x0D2: type                     16 // effects the function of the actor, and what actor it is. Marina is 0x16; you can have multiple Marinas if you initialize more actors with this type (this is how I made Mischief Makers Online) I want to properly document these.
 *  0x0D4: iframes                  16
 *  0x0D6: last_held_sprite         16 // might actually be index, we will see
 *  0x0D8: flags_2                  32 // unsure
 *  0x0E0: hit_points               16
 *  0x0E2: damage_queue             16 // probably incorrect
 *  0x0E4: strength                 16 // probably incorrect
 *  0x0E8: pointer                  32
 *  0x0EC: vel                      64 // uses same union type as pos
 *  0x0F4: vel_z                    32
 *  0x120: scale_xy                 32 // float
 *  0x124: scale_x_1                32 // float
 *  0x128: scale_y_1                32 // float
 *  0x12C: physics_state            16 // probably incorrect
 *  0x13C: grab_flag                64 // probably incorrect
 *  0x150: frames_idle              32
 *  0x154: reg_gem_value            32 // probably incorrect
 *  0x158: direction                08
 *  0x158: deviation                08
 *  0x16C: aim_angle                16
 *  0x170: anim_state               08 // likely misinterpreted
 *  0x171: anim_frame               08 // likely misinterpreted
 *  0x173: anim_current             08 // likely misinterpreted
 *  0x17C: flags_3                  32
 *  0x180: anim_frame_attached      08 // likely misinterpreted
 *  0x181: anim_current_attached    08 // likely misinterpreted
 *  0x182: launch_type              08
 */

typedef struct {
    /* 0x000 */ Mtx translateMtxs[2]; //one for each FB
    /* 0x080 */ int32_t flag;
    /* 0x084 */ uint16_t graphic;
    /* 0x086 */ uint16_t unk_0x86; //align.
    /* 0x088 */ vec3Fixed pos; //fixed point, relative to screen center
    /* 0x094 */ uint16_t gFlag;
    /* 0x096 */ uint16_t unk_0x96; //align.
    /* 0x098 */ int32_t flag3;
    /* 0x09C */ RGBA32 rgba;
    /* 0x0A0 */ uint8_t unk_0xA0;
    /* 0x0A1 */ uint8_t unk_0xA1;  //align.
    /* 0x0A2 */ int16_t hitboxAX0;  //physics hitboxx?
    /* 0x0A4 */ int16_t hitboxAX1;
    /* 0x0A6 */ int16_t hitboxAY0;
    /* 0x0A8 */ int16_t hitboxAY1;
    /* 0x0AA */ int16_t hitboxBX0; //damage hitbox?
    /* 0x0AC */ int16_t hitboxBX1;
    /* 0x0AE */ int16_t hitboxBY0;
    /* 0x0B0 */ int16_t hitboxBY1;
    /* 0x0B2 */ int16_t unk_0xB2; //align.
    /* 0x0B4 */ float scaleX;
    /* 0x0B8 */ float scaleY;
    /* 0x0BC */ float rotateX;
    /* 0x0C0 */ float rotateY; 
    /* 0x0C4 */ float rotateZ;
    /* 0x0C8 */ int16_t unk_0xC8;
    /* 0x0CA */ int16_t unk_0xCA;
    /* 0x0CC */ uint16_t unk_0xCC;
    /* 0x0CE */ uint16_t unk_0xCE;
    union {
        /* 0x0D0 */ uint16_t actorState; //used by each actor to determine behavior.
        /* 0x0D0 */ uint8_t actorState_b[2];
    };
    /* 0x0D2 */ uint16_t actorType;
    /* 0x0D4 */ uint16_t unk_0xD4;
    /* 0x0D6 */ uint16_t actorLink; //index to another actor (parent/child)?
    /* 0x0D8 */ uint16_t unk_0xD8;
    /* 0x0DA */ uint8_t unk_0xDA;
    /* 0x0DB */ uint8_t unk_0xDB;
    /* 0x0DC */ uint8_t unk_0xDC;
    /* 0x0DD */ uint8_t unk_0xDD;
    /* 0x0DE */ uint8_t unk_0xDE;
    /* 0x0DF */ uint8_t unk_0xDF;
    union {
        /* 0x0E0 */ int16_t health;
        /* 0x0E0 */ uint16_t healthu;
    };
    /* 0x0E2 */ int16_t healthDelta; 
    /* 0x0E4 */ int16_t attackDmg;
    /* 0x0E6 */ int16_t graphicTime; //change graphic when 0
    union {
        /* 0x0E8 */ uint16_t* graphicList; //indecies of {graphic,graphicTime}
        /* 0x0E8 */ uint16_t** graphicLists; //some actors, like Marina, use an array
    };
    /* 0x0EC */ vec3Fixed vel; //position delta
    /* 0x0F8 */ fixed32 speedX; //actual velocity?
    /* 0x0FC */ fixed32 speedY; 
    /* 0x100 */ uint32_t unk_0x100; //zeroed by Actor_Spawn, never used(speed z?)
    /* 0x104 */ vec3Fixed pos2; //origin? teleport?
    /* 0x110 */ float unk_0x110; //sometimes timer, sometimes another GP var
    /* 0x114 */ float unk_0x114; 
    /* 0x118 */ float unk_0x118; 
    /* 0x11C */ float unk_0x11C;
    /* 0x120 */ float unk_0x120;
    /* 0x124 */ float unk_0x124;
    /* 0x128 */ float unk_0x128;
    /* 0x12C */ word_u unk_0x12C;
    //beyond this seems to be unions for purposes that vary between actor types.
    /* 0x130 */ float unk_0x130;
    /* 0x134 */ float unk_0x134;
    /* 0x138 */ float unk_0x138;
    /* 0x13C */ word_u unk_0x13C;
    /* 0x138 */ word_u unk_0x140;
    /* 0x144 */ float unk_0x144;
    /* 0x148 */ float unk_0x148;
    /* 0x14C */ float unk_0x14C;
    //these are most commonly used for feilds that vary greatly between actor types
    /* 0x150 */ word_u gp0;
    /* 0x154 */ word_u gp1;
    /* 0x158 */ fixed32 gp2;
    /* 0x15C */ word_u gp3;
    /* 0x160 */ fixed32 gp4;
    /* 0x164 */ fixed32 gp5;
    /* 0x168 */ word_u gp6;
    /* 0x168 */ word_u gp7;
    /* 0x170 */ word_u unk_0x170;
    /* 0x174 */ uint32_t unk_0x174;
    /* 0x178 */ word_u unk_0x178;
    union{
      /* 0x17C */ word_u unk_0x17C; 
      /* 0x17C */ ActorFunc colorFunc; 
      /* 0x17C */ Gfx* dList; // used by 3d objects
    };
    /* 0x180 */ word_u unk_0x180; 
    /* 0x184 */ word_u unk_0x184; 
    /* 0x188 */ word_u unk_0x188;
    union{
        /* 0x18C */ word_u unk_0x18C; //sometimes a GP feild
        /* 0x18C */ uint16_t* palletteP; //..but more often a RGBA5551 pallette pointer.
    };
    union{
    /* 0x190 */ void* unk_0x190;
    /* 0x190 */ ActorFunc func_0x190;
    };
    /* 0x194 */ uint8_t unk_0x194[4]; //align?
} Actor; /* sizeof = 0x198 */

typedef struct {
    /* 0x00 */ int16_t unk_0x0;
    /* 0x02 */ int16_t unk_0x2;
    /* 0x04 */ int16_t unk_0x4;
    /* 0x06 */ int16_t unk_0x6;
    /* 0x08 */ uint16_t health;
    /* 0x0A */ int16_t unk_0xA;
    /* 0x0C */ uint16_t unk_0xC;
} ActorInit; /* sizeof = 0x0E */


typedef void (*ActorFunc_2Arg)(uint16_t, uint16_t);

extern Actor gActors[0xD0];
extern ActorFunc gActorFuncTable[];
extern ActorFunc_2Arg gKnockbackFuncTable[];
typedef union{
    ActorFunc oneArg;
    ActorFunc_2Arg twoArg;
}ActorFunc_u;

//todo: populate with all confirmed actor types
//note: The following actor types have NOOPS as ticks, and may be unused:
//0x0A, 0x0F-0x14, 0x17, 0x19-0x1B, 0x1D, 0x1E, 0x25, 0x2B, 0x41, 0x47, 0x53
#define ACTORTYPE_ZERO 0X00
#define ACTORTYPE_DIZZYSTAR 0X06
#define ACTORTYPE_GEM 0X08
#define ACTORTYPE_PARTICLE 0X09
#define ACTORTYPE_3DICON 0X15
#define ACTORTYPE_MARINA 0X16
#define ACTORTYPE_CLANPOT 0X18
#define ACTORTYPE_GRAPHICONLY 0X1D
#define ACTORTYPE_PORTRAIT 0X27
#define ACTORTYPE_MARINAAFTERIMAGE 0x2e
#define ACTORTYPE_WARPSTAR 0x32
#define ACTORTYPE_TEXTBUBBLE 0X35 //used in Japan version. all others, used by the coach in "the day before".
#define ACTORTYPE_FLOWER 0X43
#define ACTORTYPE_CLANBOMB 0X45
#define ACTORTYPE_DIGGINGSPOT 0X57
#define ACTORTYPE_AREACLEAR 0X6B
#define ACTORTYPE_MARINAOHNO 0X70
#define ACTORTYPE_CROSSHAIR 0X71
#define ACTORTYPE_STAGECLEAR 0X74
#define ACTORTYPE_LEVELCLEAR 0X75
#define ACTORTYPE_CLANPOTMENU 0X79
#define ACTORTYPE_MSHINT 0X7A
#define ACTORTYPE_REDGEMRING 0X7B

//flags used by Gem_ActorSpawn
#define GEMFLAG_RED 0
#define GEMFLAG_BLUE 1
#define GEMFLAG_YELLOW 2
#define GEMFLAG_GREEN 3
#define GEMFLAG_BOUNCE 0X10
#define GEMFLAG_FINITE 0X20


#define gPlayerActorp (gActors)
#define gPlayerActor  gActors[0]
#define gPlayerActorScale  gActors[0].unk_0x120
#define ACTOR_COUNT0  0x90
#define ACTOR_COUNT1  0xC0
#define ACTOR_COUNT2  0xD0

#define ACTORINIT(i,t)\
        gActors[i].actorType=t;\
        Actor_Spawn(i)
#define GLISTINIT(i,g)\
        gActors[i].graphicList=g;\
        gActors[i].graphicTime=1
#define thisActor gActors[index]
//common enough for macro.
#define FACINGLEFT(i) gActors[i].flag&ACTOR_FLAG_FLIPPED
#define FACINGRIGHT(i) (gActors[i].flag&ACTOR_FLAG_FLIPPED)==0
#define IFFACINGLEFT(i) if(FACINGLEFT(i)) 
#define IFFACINGRIGHT(i) if(FACINGRIGHT(i)) 

#endif
