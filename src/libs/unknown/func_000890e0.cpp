/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkxMesh::UserChannelInfo's type info
 * (its reflection initializer passes it at 0x8920e): construct the object in
 * place from a loaded image, its two strings finished. */
void FUN_000890e0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxMesh::UserChannelInfo(flag);
}
