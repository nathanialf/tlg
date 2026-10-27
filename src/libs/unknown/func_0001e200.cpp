/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the cleanup callback of hkcdStaticTree::DefaultTreeStorage5's
 * type info (registered by 0x1e340): destroy the storage in place, which
 * frees its nodes. */
void hkcdStaticTree::DefaultTreeStorage5::FUN_0001e200(void *object)
{
    static_cast<DefaultTreeStorage5 *>(object)->nodes.clearAndDeallocate();
}
