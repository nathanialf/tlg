/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A bit field map's block (derived name): the header, the words, padding
 * to 16 bytes and the elements, in one allocation from the thread's
 * temporary allocator, cleared; the words and elements copied from
 * another block when one is given. The words and the elements are placed
 * by byte offsets (hkAddByteOffset), the words copied through
 * hkString::memCpy4 when there are any. */
BitFieldMap00199770::Block *FUN_00199600(int elementSize, int numElements,
                                         const BitFieldMap00199770::Block *copyFrom)
{
    typedef BitFieldMap00199770::Block Block;
    const int numWords = (numElements + 31) >> 5;
    const int headerSize = int(sizeof(Block)) + numWords * int(sizeof(u32));
    const int padding = (16 - headerSize % 16) % 16;
    const int numBytes = numElements * elementSize + headerSize + padding;
    Block *block = static_cast<Block *>(D_16dc070->temp58->blockAlloc(numBytes));
    FUN_00018160(block, 0, numBytes);
    u32 *const words = hkAddByteOffset(reinterpret_cast<u32 *>(block), sizeof(Block));
    block->numBytes = numBytes;
    block->elementSize = elementSize;
    block->bits.storage.words.setDataUserFree(words, numWords, numWords);
    block->bits.storage.numBits = numElements;
    u32 *const wordsEnd = hkAddByteOffset(words, numWords * int(sizeof(u32)));
    block->elements = reinterpret_cast<void **>(hkAddByteOffset(wordsEnd, padding));
    if (copyFrom) {
        const int first = hkMath::max2(0, 0);
        const int end = hkMath::min2(numWords, copyFrom->bits.storage.words.size);
        const int numCopied = end - first;
        if (numCopied > 0) {
            hkString::memCpy4(words + first, copyFrom->bits.storage.words.data + first, numCopied);
        }
        const int numElementsCopied =
            hkMath::min2(block->bits.storage.numBits, copyFrom->bits.storage.numBits);
        FUN_00017e70(block->elements, copyFrom->elements, numElementsCopied * elementSize);
    }
    return block;
}
