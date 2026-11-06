/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* numBytes of each of count items zeroed: one memset when the items are
 * packed, else item by item, in words for items of one to four words. The
 * walk stops at numBytes * count bytes from the start, as the base does,
 * not at count strides. */
void FUN_000aafd0(void *dst, int stride, int numBytes, int count)
{
    if (numBytes == 0) {
        return;
    }
    const int totalBytes = numBytes * count;
    if (stride == numBytes) {
        FUN_00018160(dst, 0, totalBytes);
        return;
    }
    char *start = static_cast<char *>(dst);
    char *end = start + totalBytes;
    if ((numBytes & 3) == 0) {
        switch (numBytes >> 2) {
        case 1:
            for (char *p = start; p != end; p += stride) {
                u32 *words = reinterpret_cast<u32 *>(p);
                words[0] = 0;
            }
            return;
        case 2:
            for (char *p = start; p != end; p += stride) {
                u32 *words = reinterpret_cast<u32 *>(p);
                words[0] = 0;
                words[1] = 0;
            }
            return;
        case 3:
            for (char *p = start; p != end; p += stride) {
                u32 *words = reinterpret_cast<u32 *>(p);
                words[0] = 0;
                words[1] = 0;
                words[2] = 0;
            }
            return;
        case 4:
            for (char *p = start; p != end; p += stride) {
                u32 *words = reinterpret_cast<u32 *>(p);
                words[0] = 0;
                words[1] = 0;
                words[2] = 0;
                words[3] = 0;
            }
            return;
        }
    }
    for (char *p = start; p != end; p += stride) {
        FUN_00018160(p, 0, numBytes);
    }
}
