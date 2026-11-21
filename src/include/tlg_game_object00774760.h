/* derived names: the object the overrides of slot 6 of the classes over
 * the vtable at 0x16acd78 (Object00774560) set, as their bodies read it:
 * slot 6's own body (FUN_00774760, func_00775420.cpp) and the overrides
 * that call it. Class and fields unknown; the fields' meaning is not
 * traced. */
#ifndef TLG_GAME_OBJECT00774760_H
#define TLG_GAME_OBJECT00774760_H

#include "tlg_game_object00774560.h"
#include "tlg_math.h"
#include "tlg_types.h"

/* derived names: the object at +0x58 of the argument: an int at +0x13c
 * tested by Object016ad480's slot 6 (FUN_00785d40) */
struct Mode00785d40 { /* derived name */
    u8 unknown0[0x13c];
    int unknown13c; /* +0x13c */
};

struct Start00774760 { /* derived name */
    u8 unknown0[0x8];
    float length; /* +0x8 */
    u8 unknownc[0x4c];
    Mode00785d40 *unknown58; /* +0x58 */
    u8 unknown60[0x80];
    Float4A unknowne0; /* +0xe0: a point, copied by FUN_00799ae0 */
};

/* derived names: the body at +0x68 as the overrides of slot 6 read it */
struct Body00774760 { /* derived name */
    u8 unknown0[0x678];
    int unknown678; /* +0x678 */
    u8 unknown67c[0x45d];
    u8 unknownad9; /* +0xad9: its bit 2 read by FUN_00785d40 */
    u8 unknownada[0x1e];
    int unknownaf8; /* +0xaf8 */
    int unknownafc; /* +0xafc */
    int unknownb00; /* +0xb00 */
    u8 unknownb04[0x4];
    int unknownb08; /* +0xb08 */
    int unknownb0c; /* +0xb0c */
    u8 unknownb10[0xf0];
    State00774760 *unknownc00; /* +0xc00 */
    u8 unknownc08[0x48];
    Float4A unknownc50; /* +0xc50 */
    u8 unknownc60[0xfb8];
    int unknown1c18; /* +0x1c18: a mode: 3 to 8 read by FUN_00785d40 */
    u8 unknown1c1c[0x504];
    Float4A unknown2120; /* +0x2120 */
    u8 unknown2130[0x198];
    int unknown22c8; /* +0x22c8 */
    u8 unknown22cc[0x165c];
    int unknown3928; /* +0x3928 */
};

/* derived names: the block at +0x24 slot 6 clears, with the ints the
 * overrides set after it */
struct Block00774760 { /* derived name */
    int unknown0;      /* +0x24 */
    int unknown4;      /* +0x28 */
    int unknown8;      /* +0x2c */
    int unknownc;      /* +0x30 */
    u8 unknown10[0x4];
    int unknown14; /* +0x38 */
    u8 unknown18[0x8];
    int unknown20; /* +0x44 */
    int unknown24; /* +0x48 */
    int unknown28; /* +0x4c */
    int unknown2c; /* +0x50 */
    int unknown30; /* +0x54 */
    int unknown34; /* +0x58 */
    u8 unknown38[0x4];
    int unknown3c; /* +0x60 */
};

struct Object00774760 { /* derived name */
    u8 unknown0[0x24];
    Block00774760 unknown24; /* +0x24 */
    u8 unknown64[0x4];
    Body00774760 *unknown68;   /* +0x68 */
    Object0136b6f0 *unknown70; /* +0x70 */
    int unknown78;             /* +0x78 */
    float unknown7c;           /* +0x7c */
    float length;              /* +0x80 */
    float unknown84;           /* +0x84 */
    float unknown88;           /* +0x88 */
    int unknown8c;             /* +0x8c */
    int unknown90;             /* +0x90 */
    int unknown94;             /* +0x94 */
    u8 unknown98[0x8];
    Float4A rotation;  /* +0xa0 */
    Float4A unknownb0; /* +0xb0 */
    u8 unknownc0[0x34];
    int unknownf4;   /* +0xf4 */
    float unknownf8; /* +0xf8 */
};

/* the body of slot 6 of the vtable at 0x16acd78 (func_00775420.cpp) */
void FUN_00774760(Object00774760 *self, const Start00774760 *start); /* derived name */

#endif
