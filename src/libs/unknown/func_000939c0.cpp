/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the current block closed (its element count and used bytes
 * in its header, the new block after it, its elements added to the
 * stream's count) and a new block opened, its data returned. */
void *hkBlockStreamWriter::FUN_000939c0()
{
    hkBlockStreamBlock *nextBlock = blockStream->FUN_000947f0(cache);
    const int numElements = currentNumElements;
    const int bytesUsed = currentByteOffset;
    hkBlockStreamBlock *block = currentBlock;
    block->next = nextBlock;
    block->header.numElementsAndBytesUsed = u16(numElements) | (u32(bytesUsed) << 16);
    blockStream->numTotalElements += numElements;
    currentBlock = nextBlock;
    currentByteOffset = 0;
    currentNumElements = 0;
    return nextBlock->data;
}

void hkBlockStreamWriter::FUN_000938f0(int numElements, int elementSize)
{
    const int blockSize = int(sizeof(currentBlock->data));
    const int numFitting = hkMath::min2(numElements, (blockSize - currentByteOffset) / elementSize);
    if (numFitting > 0) {
        currentByteOffset += numFitting * elementSize;
        currentNumElements += numFitting;
        numElements -= numFitting;
    }
    const int numPerBlock = blockSize / elementSize;
    while (numElements > 0) {
        FUN_000939c0();
        const int numInBlock = hkMath::min2(numElements, numPerBlock);
        numElements -= numInBlock;
        currentByteOffset = numInBlock * elementSize;
        currentNumElements = numInBlock;
    }
}
