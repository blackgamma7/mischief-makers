#ifndef COMMON_INCLUDE_H
#define COMMON_INCLUDE_H


//all common header files in one #include
#include "Alphabet.h"
#include "SFX.h"
#include "Scene.h"
#include "inttypes.h"
#include "data_symbols.h"
#include "function_symbols.h"
#include "actor.h"

//macros for common func patterns. save on typing.
#define MODi(x,y,z) x=ModInRange_i(x,y,z)
#define MODf(x,y,z) x=ModInRange_f(x,y,z)

//in case you're too lazy for GPACK_RGBA5551
#define COL16(r,g,b) (r<<11)+(g<<6)+(b<<1)+1 //used by Text_ConvertColor
#define COL16_BLANK GPACK_RGBA5551(0,0,0,0)
#define COL16_BLACK GPACK_RGBA5551(0,0,0,1)
#define COL16_WHITE GPACK_RGBA5551(255,255,255,1)
//common RNG func
#define RNG(x) Rand()&x 

#define ARRAYLENGTH(arr) (sizeof(arr)/sizeof(arr[0]))
#define ARRAYEND(arr) arr+ARRAYLENGTH(arr) //for stacks and a few while loops.
//in case we want to change the cosine table.
#define COSLEN ARRAYLENGTH(gCosineLookup)-1
#define COSPiOver2 ARRAYLENGTH(gCosineLookup)/4
#define COS(x) gCosineLookup[x&COSLEN]
#define SIN(x) gCosineLookup[x-COSPiOver2&COSLEN] //cos(x-pi/2)=sin(x)
#define NEGSIN(x) gCosineLookup[x+COSPiOver2&COSLEN]//cos(x+pi/2)=-sin(x)
//for overlay code and their tables. TODO: rename applicable subsegments before testing.
#define SEGMENT_CODETABLE(name) \
[(uint32_t)_##name##_Table##SegmentRomStart,(uint32_t)_##name##_Table##SegmentRomEnd, \
 (uint32_t)_##name##SegmentRomStart,(uint32_t)_##name##SegmentRomStart]
//many segment addresses have some "mask" that obfuscates their offset.
#define SEGMENT_CODEMASK(name,mask)\
[(uint32_t)_##name##SegmentRomStart+mask,(uint32_t)_##name##SegmentRomStart+mask]
#endif
