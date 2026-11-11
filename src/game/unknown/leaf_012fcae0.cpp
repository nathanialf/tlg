/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: packs a format word from two words of a descriptor: the
 * 6-bit field at bit 20 of the word at +0x4 into bits 0 to 7, the 4-bit
 * field at bit 26 of it into bits 8 to 11, and the four 3-bit fields at bit 0
 * of the word at +0xc into bits 12 to 23; the rest zero. FUN_001ada10 calls
 * it (its result copied to the stack for FUN_012fd3d0). The descriptor's
 * other words and the fields' meaning are not traced. */
union Format012fcae0 /* derived name */
{
    u32 value;

    struct {
        u32 unknown0 : 8;
        u32 unknown8 : 4;
        u32 unknown12 : 3;
        u32 unknown15 : 3;
        u32 unknown18 : 3;
        u32 unknown21 : 3;
        u32 unknown24 : 8;
    } fields;
};

struct Descriptor012fcae0 /* derived name */
{
    u32 unknown0;
    u32 unknown4_0 : 20;
    u32 unknown4_20 : 6;
    u32 unknown4_26 : 4;
    u32 unknown4_30 : 2;
    u32 unknown8;
    u32 unknownc_0 : 3;
    u32 unknownc_3 : 3;
    u32 unknownc_6 : 3;
    u32 unknownc_9 : 3;
    u32 unknownc_12 : 20;
};

// NONMATCHING: the or of the six fields, the base a chain in field order (the
// 4-bit field with the 6-bit one first, then the four 3-bit ones, each masked
// apart), the build a balanced tree (Reassociate), the load of +0xc after +0x4;
// written also as one expression: the same.
Format012fcae0 FUN_012fcae0(const Descriptor012fcae0 *self) /* derived name */
{
    Format012fcae0 format;
    format.value = 0;
    format.fields.unknown0 = self->unknown4_20;
    format.fields.unknown8 = self->unknown4_26;
    format.fields.unknown12 = self->unknownc_0;
    format.fields.unknown15 = self->unknownc_3;
    format.fields.unknown18 = self->unknownc_6;
    format.fields.unknown21 = self->unknownc_9;
    return format;
}
