/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

int hkBufferedStreamWriter::write(const void *memory, int memorySize)
{
    int bytesLeft = memorySize;
    int spaceLeft = bufferCapacity - bufferSize;
    const char *source = static_cast<const char *>(memory);
    while (bytesLeft > spaceLeft) {
        FUN_00017e70(buffer + bufferSize, source, spaceLeft);
        bufferSize += spaceLeft;
        const int bytesBuffered = bufferSize;
        source += spaceLeft;
        bytesLeft -= spaceLeft;
        if (flushBuffer() != bytesBuffered) {
            return memorySize - bytesLeft;
        }
        spaceLeft = bufferCapacity - bufferSize;
    }
    FUN_00017e70(buffer + bufferSize, source, bytesLeft);
    bufferSize += bytesLeft;
    return memorySize;
}
