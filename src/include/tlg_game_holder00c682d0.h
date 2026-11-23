/* src/include/tlg_game_holder00c682d0.h: a holder's list of 0x90-byte
 * entries that FUN_00a5ede0 adds to through FUN_00c682d0 and FUN_00c68410
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_HOLDER00C682D0_H
#define TLG_GAME_HOLDER00C682D0_H

#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: 0x48 bytes copied whole (`vmovups ymm0, [r13]`, `[r13+0x20]`
 * and the word at +0x40); the fields are not traced */
struct Shape00c682d0 { /* derived name */
    u8 unknown0[0x48];
};

/* derived names: 0x24 bytes copied whole (`vmovups ymm0, [r15]` and the
 * word at +0x20; FUN_00c68410); the fields are not traced */
struct Extra00c68410 { /* derived name */
    u8 unknown0[0x24];
};

/* derived names: a 0x90-byte entry of the list: the shape, a point of the
 * four floats and the int the caller passes, a flag, and the record at +0x68
 * FUN_00c68410 copies in */
struct Entry00c682d0 {   /* derived name */
    Shape00c682d0 shape; /* +0x0 */
    u8 unknown48[0x8];
    Float4A point; /* +0x50 */
    int value;     /* +0x60 */
    bool flag;     /* +0x64 */
    u8 unknown65[0x3];
    Extra00c68410 extra; /* +0x68 */
    u8 unknown8c[0x4];
};

struct Holder00c682d0 { /* derived name */
    u8 unknown0[0x18];
    Array05943280<Entry00c682d0> *entries; /* +0x18 */
    int added;                             /* +0x20 */
};

#endif
