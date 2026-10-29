/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 29 of hknpLodShape's vtable (address point 0x1699c10)
 * forwards to the shape of the level of detail the argument asks for, the
 * coarsest one when it asks for more levels than there are. */
int hknpLodShape::FUN_00068960(const Slot29Argument *argument1, void *argument2) const
{
    int level = hkMath::min2(argument1->levelOfDetail, numLevelsOfDetail - 1);
    return shapes[level]->unknownVirtual29(argument1, argument2);
}
