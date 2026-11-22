/* src/sce/unknown/: functions of the Sony SDK objects linked at the head of the game region (0x1a3a70 to 0x1afa60, one CIE each in .eh_frame), built by the game compiler and outside the game module, matched before their library is known. */
#include "tlg_types.h"

/* derived names: returns whether its argument is a power of two (non-zero, and
 * no bit left by value & (value - 1)); called by FUN_001a3c50 and
 * FUN_001a3e00. Class and method unknown. */
bool FUN_001a6f10(unsigned value) /* derived name */
{
    return value != 0 && (value & (value - 1)) == 0;
}
