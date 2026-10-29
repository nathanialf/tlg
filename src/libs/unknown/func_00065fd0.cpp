/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void FUN_00065fd0(Object00065f20 *self, const hkBlockStream *edges,
                  const hkArray<UnionFindRange> &ranges) /* derived name */
{
    hkBlockStreamReader reader;
    reader.FUN_000937c0(edges);
    for (const UnionFindEdge *edge = static_cast<const UnionFindEdge *>(reader.access()); edge;
         edge = static_cast<const UnionFindEdge *>(reader.advance(sizeof(UnionFindEdge)))) {
        self->unionFind->FUN_0008f710(edge->nodeA + ranges[edge->rangeA].firstNode,
                                      edge->nodeB + ranges[edge->rangeB].firstNode);
    }
}
