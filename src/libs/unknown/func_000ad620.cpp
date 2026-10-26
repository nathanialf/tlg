/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: slot 5 of hkMemoryMeshTexture's vtable (0x16a39f0) hands
 * out its data: the bytes, their count and the format they are in. */
void hkMemoryMeshTexture::FUN_000ad620(u8 *&dataOut, int &sizeOut, Format &formatOut)
{
    dataOut = data.data;
    sizeOut = data.size;
    formatOut = format;
}
