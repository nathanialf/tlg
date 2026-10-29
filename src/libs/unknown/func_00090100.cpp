/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkResult hkArrayStreamWriter::FUN_00090100(int relativeOffset, int whence)
{
    int absoluteOffset = offset;
    switch (whence) {
    case 0:
        absoluteOffset = relativeOffset;
        break;
    case 1:
        absoluteOffset = offset + relativeOffset;
        break;
    case 2:
        absoluteOffset = array->getSize() - relativeOffset;
        break;
    }
    if (absoluteOffset >= 0) {
        if (absoluteOffset > array->getSize()) {
            array->setSize(*allocator, absoluteOffset + 1, 0);
            array->size = absoluteOffset;
        }
        offset = absoluteOffset;
        return HK_SUCCESS;
    }
    return HK_FAILURE;
}
