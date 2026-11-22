/* src/sce/unknown/: functions of the Sony SDK objects linked at the head of the game region (0x1a3a70 to 0x1afa60, one CIE each in .eh_frame), built by the game compiler and outside the game module, matched before their library is known. */
#include "tlg_types.h"

/* derived names: a value for a mode of 1 to 12 stored through its output
 * argument, 0 returned: 0 for the mode 1, 1 for 2, 6, 7, 9, 10 and 12, 2 for
 * 4 and 5, 4 for 8 and 11; 0x80d30000 for no output, the mode 3 or another
 * mode (a jump table over the modes). The first argument is not read. Owner and meaning unknown. */
struct Object001a3b60; /* derived name */

int FUN_001a3bb0(const Object001a3b60 *self, u32 *out, u32 mode) /* derived name */
{
    if (!out) {
        return 0x80d30000;
    }
    switch (mode) {
    case 1:
        *out = 0;
        return 0;
    case 2:
    case 6:
    case 7:
    case 9:
    case 10:
    case 12:
        *out = 1;
        return 0;
    case 4:
    case 5:
        *out = 2;
        return 0;
    case 8:
    case 11:
        *out = 4;
        return 0;
    default:
        return 0x80d30000;
    }
}
