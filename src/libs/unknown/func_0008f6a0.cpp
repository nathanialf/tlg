/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the union-find's root of a node, with path compression: the
 * root found first, then every node on the path pointed at it. The parents'
 * storage is read again after each store (the library is built without
 * strict aliasing, so the int stored may be the pointer). */
int UnionFind::findRootOfNode(int node)
{
    int root = node;
    while (parents->data[root] >= 0) {
        root = parents->data[root];
    }
    while (parents->data[node] >= 0) {
        const int next = parents->data[node];
        parents->data[node] = root;
        node = next;
    }
    return node;
}
