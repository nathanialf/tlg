/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the cleanup callback of hknpWorldCinfo's type info (0x57c13e0):
 * destroy the object in place through its out-of-line destructor. */
void FUN_00046c70(void *object) /* derived name */
{
    FUN_0003b650(static_cast<hknpWorldCinfo *>(object));
}
