/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the cleanup callback of hkcdStaticPvs's type info (0x57ba5e0):
 * destroy the object in place through its out-of-line destructor. */
void FUN_0001db00(void *object) /* derived name */
{
    FUN_0001d9e0(static_cast<hkcdStaticPvs *>(object));
}
