/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: sets the object of a type in the modifier manager's table
 * at +0x4e0, stopping on a type out of range. The type is an enum: it is
 * compared as an int (its values fit one) and indexes the table unsigned
 * (its underlying type is unsigned int), hence `jl` and `movl %esi, %eax`. */
void hknpModifierManager::FUN_00066770(Type4e0 type, void *object) /* derived name */
{
    if (type >= NUM_TYPES_4E0) {
        HK_BREAKPOINT(0);
    }
    objects4e0[type] = object;
}
