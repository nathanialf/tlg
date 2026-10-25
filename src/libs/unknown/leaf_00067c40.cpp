/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: sets hknpMalleableConstraintData's strength; the game code
 * (0xea7a2b, 0xea82b0, 0xeb179c) calls it right after constructing one. */
void hknpMalleableConstraintData::FUN_00067c40(float newStrength) /* derived name */
{
    strength = newStrength;
}
