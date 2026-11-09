/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns bit 31 of the 32-bit word at +0x10 (`shr eax, 31`,
 * the word read whole). FUN_001a5ff0 (twice) and FUN_001add40 call it and
 * store the result as a 32-bit value; they read bit fields of the record's
 * words at +0xc and +0x14 with bextr. Owner and meaning unknown. */
struct Object012fc090 { /* derived name */
    u8 unknown0[0x10];
    u32 unknown10;
};

u32 FUN_012fc090(const Object012fc090 *self) /* derived name */
{
    return self->unknown10 >> 31;
}
