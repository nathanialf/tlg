/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a code from two small counts (the first in the high nibble
 * of the key, the second in the low one): thirteen pairs from 0x10 to 0x43
 * give 0x442c to 0x4438 (the eight cases from 0x30 a twenty-entry jump table,
 * 0x155c904), any other pair 0x4400; ored with 0x220000, and with 0x8000 and
 * 0x40000 when the first count is 4. What the codes name is not traced. */
// NONMATCHING: under D72 the table (0x30 to 0x43) and every constant are the base's (the code
// or'd last keeps 0x220000 out of the cases' constants); left: the low cases' block order (the
// base falls through to 0x11's block and to the default's before the tail: the switch-weight
// class) and the tail's or order (Reassociate: sete before cmove in the base)
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
    return 0x220000 | (first == 4 ? 0x8000 : 0) | static_cast<u32>(first == 4) << 18 | code;
}
