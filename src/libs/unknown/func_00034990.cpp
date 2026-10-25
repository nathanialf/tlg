/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the cell index of the record's first body's motion, from
 * FUN_0002afa0 in another file, returned as an int (the caller at 0x76f23
 * pairs it with the second body's, FUN_000349a0, to index a 17-by-17
 * table at 0x57c1660). */
int FUN_00034990(const hknpWorld *world, const Pair08Owner *self) /* derived name */
{
    return FUN_0002afa0(world, self);
}
