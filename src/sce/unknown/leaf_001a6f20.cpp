/* src/sce/unknown/: functions of the Sony SDK objects linked at the head of the game region (0x1a3a70 to 0x1afa60, one CIE each in .eh_frame), built by the game compiler and outside the game module, matched before their library is known. */
#include "tlg_types.h"

/* derived names: returns the exponent of its float argument, the bits above
 * bit 22 shifted down (shr, so the sign bit is not masked) less the bias 127.
 * No caller in the executable references it. */
int FUN_001a6f20(float value) /* derived name */
{
    u32 bits = *reinterpret_cast<const u32 *>(&value);
    return static_cast<int>(bits >> 23) - 127;
}
