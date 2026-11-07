/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void FUN_00001d70(u64 blockSize, TwoBaseAllocatorCinfo &cinfo)
{
    cinfo.preferredBlockSize = blockSize;
    cinfo.addInfo(512, 128, blockSize);
    cinfo.addInfo(256, 32, blockSize);
    cinfo.addInfo(0, 8, blockSize);
    cinfo.addInfo(640, 128, blockSize);
    for (int size = 512; size > 31; size -= 32) {
        u64 elementSize = size;
        if (elementSize >= 256) {
            elementSize &= ~u64(127);
        } else if (elementSize > 128) {
            elementSize &= ~u64(63);
        }
        elementSize = (elementSize + 31) & ~u64(31);
        if (cinfo.findInfo(elementSize) < 0) {
            cinfo.addInfo(elementSize, 32, blockSize);
        }
    }
}
