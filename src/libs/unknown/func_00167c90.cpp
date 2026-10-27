/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void ModifierSharedData::FUN_00167c90(const hknpWorld *world)
{
    solverInfo = &world->solverInfo;
    vector20 = world->vector250;
    pointer8 = world->pointer1d8;
    object0 = world->enabled278 ? world->unknown280 : 0;
}
