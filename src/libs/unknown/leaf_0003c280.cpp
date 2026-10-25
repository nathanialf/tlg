/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: sets hknpBreakableConstraintData's threshold; the game code
 * (0xea7a8b, 0xea8318, 0xeb17c3) calls it right after constructing one. */
void hknpBreakableConstraintData::FUN_0003c280(float newThreshold) /* derived name */
{
    threshold = newThreshold;
}
