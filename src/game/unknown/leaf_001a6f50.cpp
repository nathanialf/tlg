/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: 8 for the kinds 10 and 12, 16 for 18, else 0; called by
 * FUN_001a44e0, FUN_001a5cb0, FUN_001a6330 and FUN_001ac870. The kinds are
 * not traced. */
int FUN_001a6f50(int kind) /* derived name */
{
    switch (kind) {
    case 10:
    case 12:
        return 8;
    case 18:
        return 16;
    default:
        return 0;
    }
}
