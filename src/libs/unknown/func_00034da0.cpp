/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpCompressedMeshShapeData's type
 * info (the reflection initializer passes it at 0x3500a). */
void FUN_00034da0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpCompressedMeshShapeData(flag);
}
