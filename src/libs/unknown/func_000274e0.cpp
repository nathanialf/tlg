/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* A buffer saved big-endian is swapped to the host's order once the image
 * is finished; the members are left as loaded. */
hkMemoryMeshVertexBuffer::hkMemoryMeshVertexBuffer(hkFinishLoadedObjectFlag flag)
{
    if (flag.finishing && isBigEndian) {
        FUN_00027520();
    }
}
