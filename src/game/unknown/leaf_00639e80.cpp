/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: four ints, 16-byte aligned (copied whole: `vmovaps`) */
struct alignas(16) Int4_00639e80 { /* derived name */
    int x, y, z, w;
};

/* derived names: the argument of slot 12 of Object016abfe8: an int at
 * +0x400 and the two records at +0xf0 and +0x110 handed on (not traced) */
struct Argument00639e80 { /* derived name */
    u8 unknown0[0xf0];
    u8 unknownf0[0x20];   /* +0xf0 */
    u8 unknown110[0x2f0]; /* +0x110 */
    int unknown400;       /* +0x400 */
};

/* derived name: 0x2c bytes at +0x3100, cleared whole (its fields not
 * traced) */
struct Record00639e80 { /* derived name */
    u8 unknown0[0x2c];
};

/* derived names: the class whose vtable is at 0x16abfe8
 * (config/vtables.derived.base.txt), as far as slot 12 reads it: the
 * one-bit flags 5 of its bytes at +0x2422 and +0x2426 (`test byte, 0x20`),
 * an int at +0x2410, three rows from +0x30d0, 0x2c bytes from +0x3100 and
 * a three-bit field at +0x3138 */
struct Object00639e80 { /* derived name */
    u8 unknown0[0x2410];
    int unknown2410; /* +0x2410 */
    u8 unknown2414[0xe];
    bool unknown2422_0 : 1;
    bool unknown2422_1 : 1;
    bool unknown2422_2 : 1;
    bool unknown2422_3 : 1;
    bool unknown2422_4 : 1;
    bool unknown2422_5 : 1;
    u8 unknown2423[3];
    bool unknown2426_0 : 1;
    bool unknown2426_1 : 1;
    bool unknown2426_2 : 1;
    bool unknown2426_3 : 1;
    bool unknown2426_4 : 1;
    bool unknown2426_5 : 1;
    u8 unknown2427[0xca9];
    Int4_00639e80 unknown30d0;  /* +0x30d0 */
    Int4_00639e80 unknown30e0;  /* +0x30e0 */
    Int4_00639e80 unknown30f0;  /* +0x30f0 */
    Record00639e80 unknown3100; /* +0x3100 */
    u8 unknown312c[0xc];
    unsigned unknown3138_0 : 3; /* +0x3138: the word's other bits not traced */
    unsigned unknown3138_3 : 29;
};

/* derived name: the body slot 12 ends in (2194 bytes, not written) */
void FUN_00639f20(Object00639e80 *self, void *first, void *second, int unknown);

/* derived names: slot 12 of the vtable at 0x16abfe8: unless either flag is
 * set, takes the argument's int at +0x400 into +0x2410 and the first of
 * three rows (the rest of each zero), clears the 0x2c bytes at +0x3100,
 * sets the field at +0x3138 to 3 and hands on to FUN_00639f20 */
void FUN_00639e80(Object00639e80 *self, Argument00639e80 *argument) /* derived name */
{
    if (self->unknown2422_5 || self->unknown2426_5)
        return;
    self->unknown2410 = argument->unknown400;
    self->unknown30d0 = Int4_00639e80();
    self->unknown30d0.x = self->unknown2410;
    self->unknown30e0 = self->unknown30d0;
    self->unknown30f0 = self->unknown30e0;
    self->unknown3100 = Record00639e80();
    self->unknown3138_0 = 3;
    FUN_00639f20(self, argument->unknownf0, argument->unknown110, 0);
}
