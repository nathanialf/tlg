/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkMemoryMeshVertexBuffer's type info (0x57bdde8):
 * construct the object in place from a loaded image (the finish constructor
 * is out of line). */
void FUN_0002ae10(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkMemoryMeshVertexBuffer(flag);
}
