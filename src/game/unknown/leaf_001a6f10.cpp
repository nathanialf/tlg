/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether its argument is a power of two (non-zero, and
 * no bit left by value & (value - 1)); called by FUN_001a3c50 and
 * FUN_001a3e00. Class and method unknown. */
bool FUN_001a6f10(unsigned value) /* derived name */
{
    return value != 0 && (value & (value - 1)) == 0;
}
