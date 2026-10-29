/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void NodeEdgeLists::FUN_0017a2d0(unsigned int edgeIndex, const EdgeRecord0017a290 *edges, int node)
{
    int &first = firstEdge.data[node];
    int *link = &first;
    unsigned int previous;
    unsigned int current = 0x7fffffff;
    do {
        previous = current;
        current = *link;
        const EdgeRecord0017a290 &edge = edges[current];
        EdgeLinks &links = nextEdge.data[edge.linkIndex];
        link = edge.nodeA == node ? &links.next[0] : &links.next[1];
    } while (current != edgeIndex);
    if (previous == 0x7fffffff) {
        first = *link;
    } else {
        int *previousLink = linkAt(previous, edges, node);
        *previousLink = *link;
    }
    *link = 0x7fffffff;
}
