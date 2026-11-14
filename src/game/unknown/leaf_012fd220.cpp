/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: packs its arguments into a 32-bit word: bit 0 whether the
 * first is 1, bits 8 to 11 the second, over the constant bits 0x924000; called
 * by FUN_001ae0b0. The meaning of the fields is not traced. */
u32 FUN_012fd220(int a, u32 b) /* derived name */
{
    return (a == 1) | ((b & 0xf) << 8) | 0x924000;
}
