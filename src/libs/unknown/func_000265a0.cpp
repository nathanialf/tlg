/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the cleanup callback of hkMeshSectionCinfo's type info
 * (registered by 0x26600): destroy the section in place, which frees its
 * bone index mapping. */
void hkMeshSectionCinfo::FUN_000265a0(void *object)
{
    static_cast<hkMeshSectionCinfo *>(object)->~hkMeshSectionCinfo();
}
