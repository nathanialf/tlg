/* src/include/tlg_game_object0141ebc0.h: the class whose vtable is at
 * 0x16d5d08, as its slots 2 (FUN_0141ebc0) and 3 (FUN_0141e7f0) read it
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT0141EBC0_H
#define TLG_GAME_OBJECT0141EBC0_H

#include "tlg_game_fade013e7030.h"

/* derived names: the object at +0x460 of the owner of the class whose
 * vtable is at 0x16d5d08: a state at +0x4 (1 restarts the fade of slot 3)
 * and two weights read at +0x1d90 and +0x1dc8. The rest is not traced. */
struct Part0141ebc0 { /* derived name */
    u8 unknown0[0x4];
    int state; /* +0x4 */
    u8 unknown8[0x1d88];
    float weight1d90; /* +0x1d90 */
    u8 unknown1d94[0x34];
    float weight1dc8; /* +0x1dc8 */
};

/* derived names: the owner: the direction of slot 3's fade at +0x1b4 and
 * the part at +0x460. The rest is not traced. */
struct Owner0141ebc0 { /* derived name */
    u8 unknown0[0x1b4];
    int direction; /* +0x1b4 */
    u8 unknown1b8[0x2a8];
    Part0141ebc0 *part; /* +0x460 */
};

/* derived names: the fields slots 2 and 3 of the class whose vtable is at
 * 0x16d5d08 read and write: the owner at +0x8, the control at +0x10 (its
 * step), slot 3's fade at +0x60 (Object013e7030's fields), two and seven
 * weights through the pointers at +0x140 and +0x160, slot 2's level at +0x1c0
 * and whether it is at 1 at +0x1c4, and a phase at +0x1d8 that slot 3 turns
 * by a quarter of the step. The class is not traced. */
struct Object0141ebc0 { /* derived name */
    u8 unknown0[0x8];
    Owner0141ebc0 *owner;         /* +0x8 */
    FadeControl013e7030 *control; /* +0x10 */
    u8 unknown18[0x48];
    float value;    /* +0x60 */
    float time;     /* +0x64 */
    float duration; /* +0x68 */
    int restarted;  /* +0x6c */
    u8 unknown70[0xd0];
    float *weights140; /* +0x140: two */
    u8 unknown148[0x18];
    float *weights160; /* +0x160: seven */
    u8 unknown168[0x58];
    float level; /* +0x1c0 */
    int full;    /* +0x1c4 */
    u8 unknown1c8[0x10];
    float phase; /* +0x1d8 */
};

#endif
