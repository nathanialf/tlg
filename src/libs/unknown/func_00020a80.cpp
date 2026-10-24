/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the cleanup callback of hkcdStaticMeshTreeBase's type info (0x57bc360):
 * destroy the object in place through its out-of-line destructor. */
void FUN_00020a80(void *object) /* derived name */
{
    FUN_00020700(static_cast<hkcdStaticMeshTreeBase *>(object));
}
