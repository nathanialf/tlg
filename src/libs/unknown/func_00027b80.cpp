/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkSkinnedMeshShape::BoneSection's type info (0x57bdc18):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
void FUN_00027b80(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_000add70(static_cast<hkSkinnedMeshShapeBoneSection *>(object), flag);
}
