/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: 16 for the byte values 0x23 to 0x29 its argument points
 * to, 8 for 0x3b and 0x3c, else 1 (as the switch of FUN_012fd5b0, cookbook
 * 1110); called from twelve sites (FUN_001a5ff0, FUN_001a61e0, FUN_001ada10,
 * FUN_001add40 and more). The kinds are not traced. */
int FUN_012fd360(const u8 *kind) /* derived name */
{
    switch (*kind) {
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
        return 16;
    case 0x3b:
    case 0x3c:
        return 8;
    default:
        return 1;
    }
}
