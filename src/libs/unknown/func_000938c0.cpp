/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the writer continues the stream's last block. */
void hkBlockStreamWriter::FUN_000938c0(BlockCache *blockCache, hkBlockStream *stream)
{
    hkBlockStreamBlock *block = stream->blocks.data[stream->blocks.size - 1];
    cache = blockCache;
    blockStream = stream;
    currentByteOffset = block->header.numElementsAndBytesUsed >> 16;
    currentNumElements = block->header.numElementsAndBytesUsed & 0xffff;
    stream->numTotalElements -= currentNumElements;
    currentBlock = block;
}
