/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

int hkArrayStreamWriter::FUN_00090000(const void *data, int numBytes)
{
    const int spaceLeft = array->getSize() - offset;
    if (spaceLeft < numBytes) {
        const int newSize = array->getSize() + numBytes - spaceLeft;
        array->reserve(*allocator, newSize + 1);
        array->size = newSize;
        array->data[newSize] = 0;
    } else if (array->getCapacity() > array->getSize()) {
        array->data[array->getSize()] = 0;
    }
    FUN_00017e70(array->data + offset, data, numBytes);
    offset += numBytes;
    return numBytes;
}
