/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Owner0016d360::FUN_0016df30(unsigned int edgeIndex)
{
    EdgeRecord0017a290 &edge = edges[edgeIndex];
    EdgeRecord0017a290 *const records = edges;
    if (world) {
        edgeLists.FUN_0017a2d0(edgeIndex, records, edge.nodeA);
        edgeLists.FUN_0017a2d0(edgeIndex, records, edge.nodeB);
    }
    if (hkUlong(edge.block) > 1) {
        D_16dc070->temp58->blockFree(edge.block, edge.blockSize);
    }
    edge.object = HK_NULL;
    edge.nodeA = 0x7fffffff;
    edge.nodeB = int18;
    int18 = edgeIndex;
    int48--;
}
