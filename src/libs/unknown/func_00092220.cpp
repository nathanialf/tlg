/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the range's element count from its start to the writer's
 * position; a start at the end of a block that is not the writer's moves
 * to the next block's first element, and the start block's count becomes
 * the elements of the range in it. The writer is not the range's memory
 * (HK_RESTRICT, D9): its block and count are read once, across the range's
 * stores (0x92230, 0x9226b). */
void hkBlockStreamRange::FUN_00092220(const hkBlockStreamWriter *HK_RESTRICT writer)
{
    const int numElementsInCurrentBlock = writer->currentNumElements;
    const int count =
        writer->blockStream->numTotalElements + numElementsInCurrentBlock + numElements;
    if (count) {
        const hkBlockStreamBlock *block = startBlock;
        if (block != writer->currentBlock && block->header.numElements == startBlockNumElements) {
            block = block->next;
            startBlockNumElements = 0;
            startByteOffset = 0;
        }
        if (block != writer->currentBlock) {
            startBlockNumElements = block->header.numElements - startBlockNumElements;
        } else {
            startBlockNumElements = numElementsInCurrentBlock - startBlockNumElements;
        }
        startBlock = block;
    }
    numElements = count;
}
