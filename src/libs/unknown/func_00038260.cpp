/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpBodyCinfo's loaded-object cleanup (its type info 0x57bedf8): the cinfo
 * destroyed in place, its local frame and mass distribution released, then
 * its name. */
void FUN_00038260(void *object)
{
    static_cast<hknpBodyCinfo *>(object)->~hknpBodyCinfo();
}
