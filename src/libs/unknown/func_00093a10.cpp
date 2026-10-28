/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the writer finished. An empty current block of a stream
 * of two or more blocks is given back; otherwise the block is closed, its
 * element count and used bytes in its header and its elements added to
 * the stream's count. */
void hkBlockStreamWriter::FUN_00093a10()
{
    const int numElements = currentNumElements;
    if (numElements == 0 && blockStream->blocks.size >= 2) {
        blockStream->FUN_00095030(cache);
    } else {
        const int bytesUsed = currentByteOffset;
        hkBlockStreamBlock *block = currentBlock;
        block->next = 0;
        block->header.numElementsAndBytesUsed = u16(numElements) | (u32(bytesUsed) << 16);
        blockStream->numTotalElements += numElements;
    }
    currentBlock = 0;
}
