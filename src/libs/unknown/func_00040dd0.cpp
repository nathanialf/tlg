/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the cleanup callback of hknpMinMaxQuadTree's type info
 * (registered by its file's initializer 0x40ea0): the tree destroyed in
 * place, each level's data freed from the last, then the levels'. */
void FUN_00040dd0(void *object)
{
    static_cast<hknpMinMaxQuadTree *>(object)->~hknpMinMaxQuadTree();
}
