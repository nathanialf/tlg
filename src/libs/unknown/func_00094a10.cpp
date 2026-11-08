/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the other stream's blocks appended to this one's and the
 * other left empty. An empty other only gives its blocks back to the cache
 * (0x94990's statements, written out), this stream given a first block
 * when it has none (0x947f0's). Otherwise this stream's last block is
 * linked to the other's first, or its one empty block given back first,
 * the other's block pointers are inserted at the end, each block from
 * there takes its new index and the elements are counted over. */
// NONMATCHING: 113 of 167, size 592 against 591: the renumbering loop's guard. The base
// compares the first index with the new size it just stored (`cmp [rbp-0x2c], eax`, the
// stored value forwarded past the store `other->blocks.size = 0`) and leaves the compare
// unfolded; here GVN's MemoryDependence finds that store a clobber (BasicAA: two
// hkBlockStream pointers, MayAlias) and the guard reloads the size, which costs the cache
// its callee-saved register (spilled to [rbp-0x38]). Forwarded (the other's size cleared
// after the loop, or `other` restrict) the last InstCombine folds `first < first + n` to
// `n > 0` once SimplifyCFG has merged the size's PRE phi with the first index's (debug
// opt -print-after-all, a79/94r.all.txt), which the base did not (NOTES Round 79A).
void hkBlockStream::FUN_00094a10(BlockCache *cache, hkBlockStream *other)
{
    const int numElements = other->numTotalElements;
    if (numElements == 0) {
        if (blocks.getSize() == 0) {
            hkBlockStreamBlock *block = cache->FUN_0008eec0();
            if (zeroNewBlocks) {
                hkString::FUN_00018250(block, sizeof(hkBlockStreamBlock));
            } else {
                hkString::memSet16(block, &D_14b2060[2], 2);
            }
            const int blockIndex = blocks.getSize();
            block->pointer10 = allocator;
            block->header.blockIndexInStream = blockIndex;
            blocks.pushBack(block);
        }
        int numBlocks = other->blocks.size;
        if (other->partiallyFreed) {
            hkBlockStreamBlock *const *block = other->blocks.data;
            hkBlockStreamBlock **kept = other->blocks.data;
            for (int i = 0; i < numBlocks; i++, block++) {
                if (*block) {
                    *kept = *block;
                    kept++;
                }
            }
            numBlocks = int(kept - other->blocks.data);
            other->partiallyFreed = false;
        }
        if (numBlocks) {
            cache->FUN_0008efa0(other->blocks.data, numBlocks);
        }
        other->blocks.size = 0;
        other->numTotalElements = 0;
        return;
    }

    int firstIndex = 0;
    if (blocks.getSize()) {
        if (numTotalElements == 0) {
            cache->FUN_0008ef10(blocks[0]);
            blocks.size = 0;
        } else {
            blocks[blocks.getSize() - 1]->next = other->blocks[0];
            firstIndex = blocks.getSize();
        }
    }
    blocks.insertAt(blocks.getSize(), other->blocks.data, other->blocks.getSize());
    other->blocks.size = 0;
    for (int i = firstIndex; i < blocks.getSize(); i++) {
        blocks.data[i]->header.blockIndexInStream = i;
    }
    numTotalElements += numElements;
    other->numTotalElements = 0;
}
