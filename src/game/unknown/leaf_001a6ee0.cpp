/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived name: the smallest power of two not below the value (the bits below
 * the highest set bit of value - 1 filled, plus one); FUN_001a44e0 calls it
 * for each dimension. */
u32 FUN_001a6ee0(u32 value) /* derived name */
{
    --value;
    value |= value >> 1;
    value |= value >> 2;
    value |= value >> 4;
    value |= value >> 8;
    value |= value >> 16;
    return value + 1;
}
