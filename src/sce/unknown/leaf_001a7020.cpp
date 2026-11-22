/* src/sce/unknown/: functions of the Sony SDK objects linked at the head of the game region (0x1a3a70 to 0x1afa60, one CIE each in .eh_frame), built by the game compiler and outside the game module, matched before their library is known. */
#include "tlg_types.h"

/* derived names: whether its 32-bit unsigned argument is below 2 (`cmp edi, 2;
 * setb al`). FUN_001a3e00 (twice) and FUN_001a44e0 call it and test al. Owner
 * and meaning unknown. */
bool FUN_001a7020(u32 value) /* derived name */
{
    return value < 2;
}
