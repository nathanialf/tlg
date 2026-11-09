/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the exponent of its float argument, the bits above
 * bit 22 shifted down (shr, so the sign bit is not masked) less the bias 127.
 * No caller in the executable references it. */
int FUN_001a6f20(float value) /* derived name */
{
    u32 bits = *reinterpret_cast<const u32 *>(&value);
    return static_cast<int>(bits >> 23) - 127;
}
