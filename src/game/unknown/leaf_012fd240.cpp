/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a code from two small counts (the first in the high nibble
 * of the key, the second in the low one): thirteen pairs from 0x10 to 0x43
 * give 0x442c to 0x4438 (the eleven-case part a twenty-entry jump table,
 * 0x155c904), any other pair 0x4400; ored with 0x220000, and with 0x8000 and
 * 0x40000 when the first count is 4. What the codes name is not traced. */
// NONMATCHING: the switch's lowering: the build makes one 52-entry table over 0x10 to 0x43
// (13 cases, 25%: 4.0's jump-table-density 10), the base a table over 0x30 to 0x43 only (8 of
// 20, 40%) and compares for the rest: 3.9's 40% minimum (NOTES round 219C, a region question)
u32 FUN_012fd240(int first, int second) /* derived name */
{
    u32 code;
    switch (first << 4 | second) {
    case 0x10:
        code = 0x442c;
        break;
    case 0x11:
        code = 0x442f;
        break;
    case 0x20:
        code = 0x442d;
        break;
    case 0x21:
        code = 0x4430;
        break;
    case 0x22:
        code = 0x4431;
        break;
    case 0x30:
        code = 0x442e;
        break;
    case 0x31:
        code = 0x4433;
        break;
    case 0x32:
        code = 0x4435;
        break;
    case 0x33:
        code = 0x4436;
        break;
    case 0x40:
        code = 0x4432;
        break;
    case 0x41:
        code = 0x4434;
        break;
    case 0x42:
        code = 0x4437;
        break;
    case 0x43:
        code = 0x4438;
        break;
    default:
        code = 0x4400;
        break;
    }
    return code | 0x220000 | (first == 4 ? 0x8000 : 0) | (first == 4 ? 0x40000 : 0);
}
