/* src/sce/unknown/: functions of the Sony SDK objects linked at the head of the game region (0x1a3a70 to 0x1afa60, one CIE each in .eh_frame), built by the game compiler and outside the game module, matched before their library is known. */
#include "tlg_types.h"

/* derived names: a count for a mode of 1 to 12 stored through its second
 * argument, 0 returned: 4 for the modes 1, 2, 4, 5 and 6, 3 for 8 and 11,
 * for 7, 9, 10 and 12 4 when the fourth argument is above 1 and 2 otherwise
 * (bit tests of 0x76, 0x1680 and 0x900); 0x80d30000 for no output or another
 * mode. The first argument is not read. Owner and meaning unknown. */
struct Object001a3b60; /* derived name */

int FUN_001a3b60(const Object001a3b60 *self, u32 *out, u32 mode, u32 count) /* derived name */
{
    if (!out) {
        return 0x80d30000;
    }
    switch (mode) {
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
        *out = 4;
        return 0;
    case 7:
    case 9:
    case 10:
    case 12:
        *out = count > 1 ? 4 : 2;
        return 0;
    case 8:
    case 11:
        *out = 3;
        return 0;
    default:
        return 0x80d30000;
    }
}
