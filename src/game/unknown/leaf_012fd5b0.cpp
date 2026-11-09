/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the first byte its argument points to is one
 * of 0x23 to 0x29 (35 to 41): a switch over the byte, which SimplifyCFG folds
 * to one range test on the int it promotes to (movzbl, add -0x23, cmp 7 in 32
 * bits; a two-sided compare narrows to an 8-bit add instead). FUN_001a3e00
 * calls it at 0x1a3e9a and tests al. The pointee's type is not traced. Owner
 * and meaning unknown. */
struct Value012fd5b0 { /* derived name */
    u8 unknown0;
};

bool FUN_012fd5b0(const Value012fd5b0 *value) /* derived name */
{
    switch (value->unknown0) {
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
        return true;
    default:
        return false;
    }
}
