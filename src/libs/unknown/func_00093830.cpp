/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the reader moved to the next block, as FUN_00093bf0 does,
 * with the block after it and the new block's second cache line
 * prefetched. */
const void *hkBlockStreamReader::FUN_00093830()
{
    if (numElementsToReadInOtherBlocks == 0) {
        currentByteLocation = 0;
        currentBlock = 0;
        return 0;
    }
    const hkBlockStreamBlock *block = currentBlock->next;
    currentBlock = block;
    const int numElements =
        block ? hkMath::min2(int(block->header.numElements), numElementsToReadInOtherBlocks) : 0;
    if (numElements <= 0) {
        currentByteLocation = 0;
        return 0;
    }
    numElementsToReadInThisBlock = numElements;
    numElementsToReadInOtherBlocks -= numElements;
    const u8 *data = block->data;
    currentByteLocation = data;
    _mm_prefetch(reinterpret_cast<const char *>(block->next), _MM_HINT_NTA);
    _mm_prefetch(reinterpret_cast<const char *>(block) + 128, _MM_HINT_NTA);
    return data;
}

/* derived name: the consumer's next block, the reader's move above inline,
 * then the block it left handed back as far as it was consumed. */
const void *hkBlockStreamConsumer::FUN_00093b10()
{
    hkBlockStreamBlock *block = const_cast<hkBlockStreamBlock *>(currentBlock);
    const int numToFree = numElementsToFreeInThisBlock;
    const void *data = FUN_00093830();
    numElementsToFreeInThisBlock = numElementsToReadInThisBlock;
    const hkBlockStreamBlock::Header header = block->getHeader();
    if (int(header.numElementsAndBytesUsed & 0xffff) == numToFree) {
        stream->FUN_00094df0(cache, block, header.blockIndexInStream);
    } else {
        __sync_fetch_and_sub(&block->header.numElementsAndBytesUsed, numToFree);
    }
    return data;
}
