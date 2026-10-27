/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the reader starts at the stream's first block, with as many
 * elements left in the others as an int holds (the reader stops at the
 * last block instead); an empty first block leaves nothing to read. */
void hkBlockStreamReader::FUN_000937c0(const hkBlockStream *stream)
{
    const hkBlockStreamBlock *block = stream->blocks.data[0];
    currentBlock = block;
    currentByteLocation = block->data;
    u16 numElements = block->header.numElementsAndBytesUsed;
    numElementsToReadInThisBlock = numElements;
    numElementsToReadInOtherBlocks = 0x7fffffff;
    if (!numElements) {
        currentByteLocation = 0;
    }
}

/* derived name: the consumer starts at the stream's first block, the
 * stream marked partly freed, every element of the block to free. */
void hkBlockStreamConsumer::FUN_00093a70(BlockCache *cache, hkBlockStream *stream)
{
    stream->partiallyFreed = true;
    FUN_000937c0(stream);
    this->stream = stream;
    this->cache = cache;
    numElementsToFreeInThisBlock = numElementsToReadInThisBlock;
}
