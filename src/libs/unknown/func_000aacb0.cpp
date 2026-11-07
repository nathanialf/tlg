/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* numBytes of each of count items copied from one stride to another: one
 * memcpy when both strides are the item's size, else item by item, in
 * words for items of one to four words. The walk stops at count source
 * strides from the start. */
void FUN_000aacb0(const void *src, int srcStride, void *dst, int dstStride, int numBytes, int count)
{
    if (numBytes == 0) {
        return;
    }
    if (srcStride == dstStride && srcStride == numBytes) {
        FUN_00017e70(dst, src, numBytes * count);
        return;
    }
    const char *in = static_cast<const char *>(src);
    const char *end = in + srcStride * count;
    char *out = static_cast<char *>(dst);
    if ((numBytes & 3) == 0) {
        switch (numBytes >> 2) {
        case 1:
            for (; in != end; in += srcStride, out += dstStride) {
                const u32 *from = reinterpret_cast<const u32 *>(in);
                u32 *to = reinterpret_cast<u32 *>(out);
                to[0] = from[0];
            }
            return;
        case 2:
            for (; in != end; in += srcStride, out += dstStride) {
                const u32 *from = reinterpret_cast<const u32 *>(in);
                u32 *to = reinterpret_cast<u32 *>(out);
                to[0] = from[0];
                to[1] = from[1];
            }
            return;
        case 3:
            for (; in != end; in += srcStride, out += dstStride) {
                const u32 *from = reinterpret_cast<const u32 *>(in);
                u32 *to = reinterpret_cast<u32 *>(out);
                to[0] = from[0];
                to[1] = from[1];
                to[2] = from[2];
            }
            return;
        case 4:
            for (; in != end; in += srcStride, out += dstStride) {
                const u32 *from = reinterpret_cast<const u32 *>(in);
                u32 *to = reinterpret_cast<u32 *>(out);
                to[0] = from[0];
                to[1] = from[1];
                to[2] = from[2];
                to[3] = from[3];
            }
            return;
        }
    }
    for (; in != end; in += srcStride, out += dstStride) {
        FUN_00017e70(out, in, numBytes);
    }
}
