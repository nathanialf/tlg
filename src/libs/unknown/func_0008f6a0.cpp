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

/* derived name: two nodes joined: their roots found (and their paths
 * compressed), then the root of higher index hung under the other, which
 * takes both sizes (a root's negative parent). */
void UnionFind::FUN_0008f710(int nodeA, int nodeB)
{
    const int rootA = findRootOfNode(nodeA);
    const int rootB = findRootOfNode(nodeB);
    if (rootA != rootB) {
        const int size = parents->data[rootA] + parents->data[rootB];
        if (rootA < rootB) {
            parents->data[rootA] = size;
            parents->data[rootB] = rootA;
        } else {
            parents->data[rootB] = size;
            parents->data[rootA] = rootB;
        }
    }
}
