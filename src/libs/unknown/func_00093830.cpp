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
    if (block) {
        const int numElements =
            hkMath::min2(int(block->header.numElements), numElementsToReadInOtherBlocks);
        if (numElements > 0) {
            numElementsToReadInThisBlock = numElements;
            numElementsToReadInOtherBlocks -= numElements;
            const u8 *data = block->data;
            currentByteLocation = data;
            _mm_prefetch(reinterpret_cast<const char *>(block->next), _MM_HINT_NTA);
            _mm_prefetch(reinterpret_cast<const char *>(block) + 128, _MM_HINT_NTA);
            return data;
        }
    }
    currentByteLocation = 0;
    return 0;
}
