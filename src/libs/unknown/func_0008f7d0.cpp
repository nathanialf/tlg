/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: each node that is not a root pointed at its root, the
 * roots counted; the parents' storage is read again after each store (the
 * library is built without strict aliasing). */
int UnionFind::FUN_0008f7d0()
{
    if (state) {
        return numRoots;
    }
    int roots = numNodes;
    int *const end = parents->data + numNodes;
    for (int *node = parents->data; node != end; node++) {
        if (*node >= 0) {
            roots--;
            while (parents->data[*node] >= 0) {
                *node = parents->data[*node];
            }
        }
    }
    state = 1;
    numRoots = roots;
    return roots;
}
