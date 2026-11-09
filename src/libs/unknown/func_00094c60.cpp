/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING (NOTES Round 64B, 94A): 283 bytes against 273, the same under D42's compiler.
// Round 94A: the count read as the header's word masked (`mov ecx, [rax]; movzx ecx, cx`, x86
// does not narrow an i32 load to i16) and blockIndex declared before numElements give the scan
// every instruction and register of the base's but the order of blockIndex's zero and increment
// against kept's. Left: the array's address kept in r15 across the new block's calls (`lea r15,
// [r14+0x20]`, the scan's `gep this, 0, 6` kept unmerged by its two users, the data read and the
// grow's argument, and CSE'd to the append), where the base forms it at the grow call, as in
// 0x94880; and the join's data load folded into the sub after the count's store, where the base
// loads it first (a local for the kept count computed before the store gives that load and moves
// greedy's assignment in the scan, measured).
void hkBlockStream::FUN_00094c60(BlockCache *cache)
{
    if (!partiallyFreed) {
        return;
    }
    hkBlockStreamBlock *const *block = blocks.data;
    hkBlockStreamBlock **kept = blocks.data;
    const int numBlocks = blocks.size;
    int blockIndex = 0;
    int numElements = 0;
    hkBlockStreamBlock *previous = HK_NULL;
    for (int i = 0; i < numBlocks; i++, block++) {
        hkBlockStreamBlock *const current = *block;
        if (current) {
            if (previous) {
                previous->next = current;
            }
            *kept = current;
            numElements += current->header.numElementsAndBytesUsed & 0xffff;
            current->header.blockIndexInStream = blockIndex;
            blockIndex++;
            kept++;
            previous = current;
        }
    }
    if (previous) {
        previous->next = HK_NULL;
    }
    numTotalElements = numElements;
    blocks.size = int(kept - blocks.data);
    if (blocks.size == 0) {
        hkBlockStreamBlock *newBlock = cache->FUN_0008eec0();
        if (zeroNewBlocks) {
            hkString::FUN_00018250(newBlock, sizeof(hkBlockStreamBlock));
        } else {
            hkString::memSet16(newBlock, &D_14b2060[2], 2);
        }
        const int newIndex = blocks.getSize();
        newBlock->pointer10 = allocator;
        newBlock->header.blockIndexInStream = newIndex;
        blocks.pushBack(newBlock);
    }
    partiallyFreed = false;
}
