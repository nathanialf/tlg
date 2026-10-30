/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkResult hkBufferedStreamWriter::FUN_000092a0(int offset, int whence) /* derived name */
{
    if (stream) {
        flushBuffer();
        return stream->seek(offset, whence);
    }
    int absoluteOffset = -1;
    switch (whence) {
    case 0:
        absoluteOffset = offset;
        break;
    case 1:
        absoluteOffset = bufferSize + offset;
        break;
    case 2:
        absoluteOffset = bufferSize - offset;
        break;
    }
    hkResult result = HK_FAILURE;
    int newSize = 0;
    if (absoluteOffset >= 0) {
        result = HK_SUCCESS;
        if (absoluteOffset > bufferCapacity) {
            absoluteOffset = bufferCapacity;
            result = HK_FAILURE;
        }
        newSize = absoluteOffset;
    }
    bufferSize = newSize;
    return result;
}
