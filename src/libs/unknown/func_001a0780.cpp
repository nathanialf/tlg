/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A part's size in bytes by its type, -1 for an unknown one (a switch the
 * compiler turns into the table at 0x14cd220). derived name. */
static inline int partSize(int type)
{
    switch (type) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 4;
    case 3:
        return 4;
    default:
        return -1;
    }
}

/* derived name: the bits a pixel of the raw image takes (0x188686 halves
 * them to bytes for the rows it swaps): -1 when a part's start does not lie
 * below every part's end, else the parts' sizes summed. */
int FUN_001a0780(const RawImage &image)
{
    const int numParts = image.pixels.getSize();
    for (int i = numParts - 1; i >= 0; i--) {
        const RawImagePart &part = image.pixels[i];
        const int end = part.value4 * image.height + part.value0;
        for (int j = numParts - 1; j >= 0; j--) {
            if (image.pixels[j].value0 >= end) {
                return -1;
            }
        }
    }
    int size = 0;
    for (int i = 0; i < numParts; i++) {
        size += partSize(image.pixels[i].type);
    }
    return size * 8;
}
