/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the reader starts at the range's first element, in its
 * first block; a range with nothing in its first block (or nothing at all)
 * leaves nothing to read there. */
void hkBlockStreamReader::FUN_000937f0(const hkBlockStreamRange *range)
{
    const int numElements = range->numElements;
    if (numElements) {
        currentBlock = range->startBlock;
        currentByteLocation = currentBlock->data + range->startByteOffset;
        numElementsToReadInThisBlock = range->startBlockNumElements;
        numElementsToReadInOtherBlocks = numElements - numElementsToReadInThisBlock;
        if (numElementsToReadInThisBlock == 0) {
            currentByteLocation = 0;
        }
    } else {
        currentByteLocation = 0;
    }
}

/* derived name: the consumer starts at the range's first element, the
 * stream marked partly freed, the elements of the first block to free
 * (none without a block); an empty range leaves nothing to read. */
void hkBlockStreamConsumer::FUN_00093ab0(BlockCache *cache, hkBlockStream *stream,
                                         hkBlockStream *argument3, const hkBlockStreamRange *range)
{
    const int numElements = range->numElements;
    if (numElements) {
        stream->partiallyFreed = true;
        currentBlock = range->startBlock;
        currentByteLocation = currentBlock->data + range->startByteOffset;
        numElementsToReadInThisBlock = range->startBlockNumElements;
        numElementsToReadInOtherBlocks = numElements - numElementsToReadInThisBlock;
        if (numElementsToReadInThisBlock == 0) {
            currentByteLocation = 0;
        }
        this->stream = stream;
        this->cache = cache;
        numElementsToFreeInThisBlock = currentBlock ? numElementsToReadInThisBlock : 0;
    } else {
        currentByteLocation = 0;
    }
}
