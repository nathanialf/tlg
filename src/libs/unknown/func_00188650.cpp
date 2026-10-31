/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void FUN_00188650(u8 **pixels, const RawImage &image) /* derived name */
{
    if (!*pixels) {
        return;
    }
    const int rowBytes = image.width * (FUN_001a0780(&image) / 8);
    hkArray<u8> row(rowBytes);
    const int numSwaps = image.height / 2;
    u8 *top = *pixels;
    u8 *bottom = top + (image.height - 2) * rowBytes;
    for (int i = 0; i < numSwaps; i++) {
        FUN_00017e70(row.data, bottom, rowBytes);
        FUN_00017e70(bottom, top, rowBytes);
        FUN_00017e70(top, row.data, rowBytes);
        bottom -= rowBytes;
        top += rowBytes;
    }
}
