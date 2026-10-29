/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkMemoryMeshTexture::FUN_000ad640(u8 *newData, int numBytes, Format newFormat)
{
    format = newFormat;
    if (newFormat == RAW) {
        data.clear();
        data.append(newData, numBytes);
    } else {
        data.setDataUserFree(newData, numBytes, numBytes);
    }
}
