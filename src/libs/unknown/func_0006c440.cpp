/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hknpExternMeshShape's type info
 * (0x57c28e8): construct the object in place from a loaded image through
 * its out-of-line finish constructor. */
void FUN_0006c440(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_001660e0(static_cast<hknpExternMeshShape *>(object), flag);
}
