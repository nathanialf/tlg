/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the cell index of the record's second body's motion, from
 * FUN_0002afd0 in another file, returned as an int (beside FUN_00034990,
 * the first body's, at 0x76f34). */
int FUN_000349a0(const hknpWorld *world, const Pair08Owner *self) /* derived name */
{
    return FUN_0002afd0(world, self);
}
