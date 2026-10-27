/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hknpExternMeshShapeData's type info
 * (registered at 0x355ab): the object constructed in place from a loaded
 * image, its inline finish constructor running the simd tree's. */
void FUN_000354c0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpExternMeshShapeData(flag);
}
