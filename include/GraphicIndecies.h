//indecies used by "graphic" feild of Actor struct


#define GINDEX_LEFT 1 //odd entries are the horizontal mirror of the previous
#define GANI(g,i) g+(2*i) //when we need to declare with animation graphic.
#define GANILOOP(x) (uint16_t)-x*2,0x0000 //negative value = value*2 steps back.

#define GINDEX_MARINA  2 //the spritesheet of marina is a special case
#define GINDEX_CLANCER 6 //same with the clancers.

//each clanblock has 3-4 animation indecies following.
#define GINDEX_CLANBLOCKSQAURE 0x0046
#define GINDEX_CLANBLOCKSKINNY 0x004C
#define GINDEX_CLANBLOCKSHORT  0x0052
#define GINDEX_CLANBLOCKSMALL  0x0058
#define GINDEX_CLANBLOCKBARREL 0x005E
#define GINDEX_CLANBLOCKBUCKET 0x0064 //the smaller "barrel"
#define GINDEX_CLANBLOCKSLOPEL 0x006A
#define GINDEX_CLANBLOCKSLOPER 0x0070
#define GINDEX_CLANBLOCKRAMPL  0x0076 //the shorter slope
#define GINDEX_CLANBLOCKRAMPR  0x007C

#define GINDEX_CLANCERSTATUEA  0x0082 //the wooden sitting one
#define GINDEX_BIGBLOCK        0x0084 
#define GINDEX_CLANBLOBSTATUE  0x0086 //3 animation frames(?)
#define GINDEX_CLANCERSTATUEB  0x008C //the stone elder

#define GINDEX_CACTUS          0x0096 //3 animation frames
#define GINDEX_TAIKO           0x009C //3 animation frames. unused?

//Clanball Rails.
#define GINDEX_RAILSTRAIGHTH   0x00A2 
#define GINDEX_RAILENDHL       0x00A4
#define GINDEX_RAILENDHR       0x00A6
#define GINDEX_RAILSTRAIGHTV   0x00A8
#define GINDEX_RAILENDVT       0x00AA
#define GINDEX_RAILENDVB       0x00AC
#define GINDEX_RAILANGLEBL     0x00AE 
#define GINDEX_RAILANGLELT     0x00B0
#define GINDEX_RAILANGLETR     0x00B2
#define GINDEX_RAILANGLEBR     0x00B4
#define GINDEX_RAILSTOP        0x00B6 //rail with an (X) in it.

#define GINDEX_GEM             0x00B8 //6 animation frames

#define GINDEX_MINEROUND       0x00C6

#define GINDEX_CLANBLOB        0x00CC

#define GINDEX_BOOM1           0x00D8 //7 animation frames
#define GINDEX_BOOM2           0x00E6 //5 animation frames

#define GINDEX_LIFEBAR         0x00F0
#define GINDEX_LIFEHEAD        0x00F2
#define GINDEX_LIFEHEADBLINK   0x00F4 //3 animation frames

#define GINDEX_LIFEHEADOW      0x00FE
#define GINDEX_LIFEHEADLOOKUP  0x0100
#define GINDEX_LIFEHEADANGRY   0x0102
#define GINDEX_LIFEHEADLOOKDWN 0x0104

#define GINDEX_JOYSTICK        0x0108
#define GINDEX_DPAD            0x010A
#define GINDEX_BUTTONSTART     0x010C
#define GINDEX_BUTTONA         0x010E
#define GINDEX_BUTTONB         0x0110
#define GINDEX_BUTTONCLEFT     0x0112
#define GINDEX_BUTTONCRIGHT    0x0114
#define GINDEX_BUTTONCUP       0x0116
#define GINDEX_BUTTONCDOWN     0x0118
#define GINDEX_BUTTONL         0x011A //2 animation frames
#define GINDEX_BUTTONR         0x011E //2 animation frames
#define GINDEX_BUTTONZ         0x0122 //2 animation frames
#define GINDEX_DPADLEFT        0x0126
#define GINDEX_DPADRIGHT       0x0128
#define GINDEX_DPADUP          0x012A
#define GINDEX_DPADDOWN        0x012C
#define GINDEX_BIGARROW        0x012E
#define GINDEX_EXCLAIMBUBBLE   0x0130
#define GINDEX_HEARTBUBBLE     0x0132
#define GINDEX_SPEECHBUBBLE    0x0134
#define GINDEX_NOTEQUARTER     0x0136
#define GINDEX_NOTEEIGHTHS     0x0138
#define GINDEX_NOTEEIGHTH      0x013A
#define GINDEX_QUESTIONBUBBLE  0x013C

#define GINDEX_FLOWERRED       0x013E
#define GINDEX_FLOWERDAISY     0x0140
#define GINDEX_FLOWERTULIP     0x0142
#define GINDEX_FLOWERD         0x0144
#define GINDEX_FLOWERE         0x0146
#define GINDEX_FLOWERF         0x0148 //has a bulb and face?

#define GINDEX_CROSSHAIR       0x014A

#define GINDEX_POW             0x014C //5 animation frames
#define GINDEX_DISSOLVE        0x0156 //5 animation frames
#define GINDEX_CONE            0x0160

#define GINDEX_BLASTA          0x0166
#define GINDEX_BLASTB          0x0168 //2 animation frames

#define GINDEX_GROUNDFLAME     0x016C
#define GINDEX_MUSHROOMCLOUD   0x016E //8 animation frames

#define GINDEX_WARPSTAR        0x01A8

#define GINDEX_SPARKLESMALL    0x01AE //2 animation frames
#define GINDEX_DASHEFFECT      0x01B2 //2 animation frames

#define GINDEX_GRABEFFECT      0x01BE //emmits from hand when you brab something
#define GINDEX_SHOCKEFFECT     0x01C0 //3 animation frames
#define GINDEX_POOF            0x01C6 //8 animation frames
#define GINDEX_DIZZYSTAR       0x01D6

#define GINDEX_PORTRAITMARINAA 0x01F4
#define GINDEX_PORTRAITMARINAB 0x01F6 //happy
#define GINDEX_PORTRAITMARINAC 0x01F8 //scowling
#define GINDEX_PORTRAITMARINAD 0x01FA
#define GINDEX_PORTRAITTHEOA   0x01FC
#define GINDEX_PORTRAITTHEOB   0x01FE
#define GINDEX_PORTRAITTHEOC   0x0200
#define GINDEX_PORTRAITCAT     0x0202
#define GINDEX_PORTRAITLUNARA  0x0204
#define GINDEX_PORTRAITLUNARB  0x0206
#define GINDEX_PORTRAITLUNARC  0x0208
#define GINDEX_PORTRAITMERCOA  0x020A
#define GINDEX_PORTRAITMERCOB  0x020C
#define GINDEX_PORTRAITMERCOC  0x020C
#define GINDEX_PORTRAITMERCOD  0x020E
#define GINDEX_PORTRAITTAURUSA 0x0210
#define GINDEX_PORTRAITTAURUSB 0x0212
#define GINDEX_PORTRAITTAURUSC 0x0214
#define GINDEX_PORTRAITTAURUSD 0x0216
#define GINDEX_PORTRAITTLEOA   0x0218
#define GINDEX_PORTRAITTLEOB   0x021A
#define GINDEX_PORTRAITCLANCER 0x021C
#define GINDEX_PORTRAITCLANKID 0x021E
#define GINDEX_PORTRAITASTER   0x0220
#define GINDEX_PORTRAITCLANCR2 0x0222
#define GINDEX_PORTRAITTERAN   0x0224
#define GINDEX_PORTRAITCELES   0x0226
#define GINDEX_PORTRAITGENERAL 0x0228
#define GINDEX_PORTRAITCALINA  0x022A
#define GINDEX_PORTRAITMIGEN   0x022C
#define GINDEX_PORTRAITKING    0x022E
#define GINDEX_PORTRAITLITH    0x0230
#define GINDEX_PORTRAITCALINAZ 0x0232
#define GINDEX_HATCOWBOY       0x0234 //2 ani states
#define GINDEX_HATSTOVETOP     0x0238
#define GINDEX_HATSANTA        0x023A
#define GINDEX_HATCELES        0x023C //2 ani states
#define GINDEX_HATTERAN        0x0240 //2 ani states

#define GINDEX_BOOMERANG       0x0244
#define GINDEX_BALLSPIKE       0x0246 //not the spiked clanball
#define GINDEX_BIGRING         0x0248
#define GINDEX_SHURIKEN        0x024A

#define GINDEX_HATCHEF         0x024C
#define GINDEX_HATHARD         0x024E
#define GINDEX_HATCROWN        0x0250 //2 ani states
#define GINDEX_HATUSHANKA      0x0254 //2 ani states

#define GINDEX_MISSLE          0x025C

#define GINDEX_CLANPOT         0x0264  //3 animation frames
#define GINDEX_CLANBALL        0x026A  //3 animation frames
#define GINDEX_SPIKEBALL       0x0270  //3 animation frames
#define GINDEX_CLANBOMB        0x0276  //3 animation frames

#define GINDEX_CLANCERGHOST    0x02A2  //6 animation frames

#define GINDEX_CATHEAD         0x02CC  //6 animation frames
#define GINDEX_TEXTBOX         0x02CE //index of the textbox in cutscenes?
#define GINDEX_SOLIDSQARE      0x02D0 //used as a fill for transisions
#define GINDEX_ALPHASTART      0x02D2 //Beginning of "Alphabet" graphics

#define GINDEX_SUNGLASSES       0X1004

#define GINDEX_STAFFSAGE        0X1040

#define GINDEX_HATCALINA        0X1044 //2 ani states

#define GINDEX_HATMSHINT        0X1070

#define GINDEX_STAFFCALINA      0X1098

//graphics with an index starting in 0x2000 are pieces of the back/foreground.

#define GINDEX_ICONEXCLAMATION   0X3000
#define GINDEX_MUSTACHE          0X3002
#define GINDEX_COILSPRING        0X3004
#define GINDEX_HATBEANIERED      0X3006
#define GINDEX_BOTTLEREDSTRIPE   0X3008
#define GINDEX_HANDHOOK          0X300A
#define GINDEX_HATBANDANA        0X300C

#define GINDEX_HATPIRATE         0X3014
