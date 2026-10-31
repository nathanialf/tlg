/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the finish callback of hkxVertexAnimation's type info
 * (registered at 0x8cd9f): construct the object in place from a loaded image.
 * The vtable and the inline destructor's three variants (0x8c930, 0x8c940,
 * 0x8c990) are emitted here. */
void FUN_0008cb10(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxVertexAnimation(flag);
}
