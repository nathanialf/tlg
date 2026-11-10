/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns 4, 1 or 8 for the kinds 3 to 15 and 1 for any other:
 * a switch of returns that SimplifyCFG turns into a lookup table (0x14d2e20,
 * thirteen ints, after `kind - 3` and an unsigned range test). FUN_001a3c50,
 * FUN_001a3e00 and FUN_001a44e0 call it; FUN_001a3e00 passes 0x20 for 0x60.
 * The kinds' meaning is not traced. */
int FUN_001a7000(int kind) /* derived name */
{
    switch (kind) {
    case 3:
    case 7:
    case 9:
    case 10:
    case 13:
    case 15:
        return 4;
    case 8:
    case 14:
        return 8;
    default:
        return 1;
    }
}
