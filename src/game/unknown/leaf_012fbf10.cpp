/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: FUN_012fd020 of three bit fields of the word at +0x10 (bits 2
 * to 6, 8 to 10 and 11 to 12), its result returned. Called by FUN_001a6890 and
 * FUN_001add40, which read the word at +0x14 of the same record. */
struct Object012fbf10 { /* derived name */
    u8 unknown0[0x10];
    u32 unknown10;
};

int FUN_012fd020(u32 a, u32 b, u32 c); /* derived name */

int FUN_012fbf10(const Object012fbf10 *self) /* derived name */
{
    u32 bits = self->unknown10;
    return FUN_012fd020((bits >> 2) & 0x1f, (bits >> 8) & 7, (bits >> 11) & 3);
}
