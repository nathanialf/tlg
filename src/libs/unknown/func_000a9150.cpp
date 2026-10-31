/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The filter rebuilt: a bit for each of the tree's nodes after eight words
 * for each section, all clear, then each section's primitives' two bits
 * set; the tree's leaf bits are then made from them (0xa92c0, a tail
 * call). */
void hknpCompressedMeshShapeTree::FUN_000a9150(hkArray<u32> &filter) const
{
    const int numNodeWords = (nodes.size + 31) / 32;
    const int numSectionWords = sections.getSize() * 8;
    filter.clearAndDeallocate();
    filter.setSize(hkContainerHeapAllocator::get(), numSectionWords + numNodeWords, 0);
    for (int i = 0; i < sections.getSize(); i++) {
        u32 *const words = filter.data + i * 8;
        for (int j = 0; j < int(sections[i].primitives.data & 0xff); j++) {
            const int bit = j * 2;
            u32 &word = words[bit / 32];
            word = (word & ~(3u << (bit & 31))) | (3u << (bit & 31));
        }
    }
    FUN_000a92c0(filter);
}
