/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the texture's image, a new source over its file name. */
ImageSource *hkMemoryMeshTexture::FUN_000ad7c0() const
{
    return new FileImageSource(filename);
}
