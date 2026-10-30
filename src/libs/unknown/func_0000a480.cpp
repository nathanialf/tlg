/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The archive's array write (0xa520), `inline` in its own file: the writes
 * of one value below hold it. */
inline void hkOArchive::writeArrayGeneric(const void *array, int elemSize, int arraySize)
{
    if (byteSwap) {
        char buffer[512];
        const int elemsPerBuffer = 512 / elemSize;
        int numBytes = arraySize * elemSize;
        const int lastBytes = numBytes % 512;
        const int lastElems = lastBytes / elemSize;
        const char *src = static_cast<const char *>(array);
        while (numBytes > 0) {
            int chunkBytes = 512;
            int chunkElems = elemsPerBuffer;
            if (numBytes < 512) {
                chunkBytes = lastBytes;
                chunkElems = lastElems;
            }
            FUN_00017e70(buffer, src, chunkBytes);
            char *p = buffer;
            switch (elemSize) {
            case 8:
                for (int i = 0; i < chunkElems; i++, p += 8) {
                    char t0 = p[0];
                    p[0] = p[7];
                    p[7] = t0;
                    char t1 = p[1];
                    p[1] = p[6];
                    p[6] = t1;
                    char t2 = p[2];
                    p[2] = p[5];
                    p[5] = t2;
                    char t3 = p[3];
                    p[3] = p[4];
                    p[4] = t3;
                }
                break;
            case 4:
                for (int i = 0; i < chunkElems; i++, p += 4) {
                    char t0 = p[0];
                    p[0] = p[3];
                    p[3] = t0;
                    char t1 = p[1];
                    p[1] = p[2];
                    p[2] = t1;
                }
                break;
            case 2:
                for (int i = 0; i < chunkElems; i++, p += 2) {
                    char t0 = p[0];
                    p[0] = p[1];
                    p[1] = t0;
                }
                break;
            }
            writer->write(buffer, chunkBytes);
            src += chunkBytes;
            numBytes -= chunkBytes;
        }
    } else {
        writer->write(array, elemSize * arraySize);
    }
}

void hkOArchive::FUN_0000a480(u16 value)
{
    writeArrayGeneric(&value, sizeof(value), 1);
}

void hkOArchive::FUN_0000a7a0(int value)
{
    writeArrayGeneric(&value, sizeof(value), 1);
}

// NONMATCHING: 20 of 85 (docs/NOTES.md, Round 64A): the base keeps the last
// chunk's element count as its own value (`lastBytes / 2`, spilled with the
// byte count) and selects it against 256 in the loop; here the inlined
// write's chunk count is folded into the byte count's select halved
// (`sdiv (select c, lastBytes, 512), 2`), one value fewer live.
void hkOArchive::FUN_0000a8d0(const u16 *array, int numElements)
{
    writeArrayGeneric(array, sizeof(u16), numElements);
}
