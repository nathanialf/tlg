/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the cleanup callback of hkcdStaticMeshTreeBase::Connectivity's
 * type info (registered at 0x21098): the connectivity destroyed in place. */
void FUN_000209b0(void *object)
{
    static_cast<hkcdStaticMeshTreeBase::Connectivity *>(object)->~Connectivity();
}
