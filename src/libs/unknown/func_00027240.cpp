/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkVertexFormat::SharingType hkVertexFormat::FUN_00027240() const
{
    const int num = numElements;
    int numNotShared = 0;
    for (int i = 0; i < num; i++) {
        if (elements[i].flags & FLAG_NOT_SHARED) {
            numNotShared++;
        }
    }
    if (numNotShared == 0) {
        return SHARING_ALL_SHARED;
    }
    return numNotShared == num ? SHARING_ALL_NOT_SHARED : SHARING_MIXTURE;
}
