/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: hands the argument to FUN_0005d6b0 for this object's entry
 * of the object it belongs to, with 0. */
void FUN_00178580(Object00178580 *self, const void *argument)
{
    FUN_0005d6b0(self->world, self->index, argument, 0);
}
