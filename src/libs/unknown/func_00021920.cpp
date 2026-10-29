/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The class allocator's delete: the tree goes back to the calling thread's
 * heap at its size. */
inline void hkcdSimdTree::operator delete(void *object, unsigned long numBytes)
{
    if (object) {
        D_16dc070->temp58->blockFree(object, int(numBytes));
    }
}

/* hkcdSimdTree's finish constructor: a finished tree with fewer than two
 * nodes gets its two root nodes, cleared. Its vtable comes with it, and the
 * inline destructor's two copies the vtable cites (0x21920, 0x21980). */
hkcdSimdTree::hkcdSimdTree(hkFinishLoadedObjectFlag flag) : nodes(flag)
{
    if (flag.finishing && nodes.size < 2) {
        nodes.setSize(2);
        nodes[0].clear();
        nodes[1].clear();
    }
}
