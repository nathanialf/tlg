/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the reader moved to the next block, the elements still to
 * read shared out to it. */
const void *hkBlockStreamReader::FUN_00093bf0()
{
    if (numElementsToReadInOtherBlocks == 0) {
        currentByteLocation = 0;
        currentBlock = 0;
        return 0;
    }
    currentBlock = currentBlock->next;
    if (currentBlock) {
        const int numElements =
            hkMath::min2(int(currentBlock->header.numElements), numElementsToReadInOtherBlocks);
        if (numElements > 0) {
            numElementsToReadInThisBlock = numElements;
            numElementsToReadInOtherBlocks -= numElements;
            currentByteLocation = currentBlock->data;
            return currentByteLocation;
        }
    }
    currentByteLocation = 0;
    return 0;
}
