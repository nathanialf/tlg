/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void CommandStreams00167f70::FUN_00167f70(void *argument1, BlockCache *streamCache)
{
    commands.FUN_00094880(streamCache);
    if (commandWriter) {
        commandWriter->writer.FUN_000938a0(cache, &commands);
        const hkBlockStreamWriter &writer = commandWriter->writer;
        const hkBlockStreamBlock *block = writer.currentBlock;
        const int byteOffset = writer.currentByteOffset;
        const int numElementsInBlock = writer.currentNumElements;
        const int numWritten = writer.blockStream->numTotalElements + numElementsInBlock;
        commandRange.startBlock = block;
        commandRange.startByteOffset = u16(byteOffset);
        commandRange.startBlockNumElements = u16(numElementsInBlock);
        commandRange.numElements = -numWritten;
    }
}
