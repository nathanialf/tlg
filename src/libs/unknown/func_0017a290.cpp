/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the edge's link at that node's end takes the node's first
 * edge, and the edge becomes the node's first. */
// NONMATCHING: the end test: the base loads the edge's first node into a
// register and compares (`movl 4(%rdx,%rax),%eax; cmpl %ecx,%eax`); this folds
// the load into the compare (docs/NOTES.md, Round 30).
void NodeEdgeLists::FUN_0017a290(unsigned int edgeIndex, const EdgeRecord0017a290 *edges, int node)
{
    const EdgeRecord0017a290 &edge = edges[edgeIndex];
    EdgeLinks &links = nextEdge.data[edge.linkIndex];
    int *next = edge.nodeA == node ? &links.next[0] : &links.next[1];
    *next = firstEdge.data[node];
    firstEdge.data[node] = edgeIndex;
}
