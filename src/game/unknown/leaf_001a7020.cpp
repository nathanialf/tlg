/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: whether its 32-bit unsigned argument is below 2 (`cmp edi, 2;
 * setb al`). FUN_001a3e00 (twice) and FUN_001a44e0 call it and test al. Owner
 * and meaning unknown. */
bool FUN_001a7020(u32 value) /* derived name */
{
    return value < 2;
}
