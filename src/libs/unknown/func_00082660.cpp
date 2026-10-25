/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkp6DofConstraintData::Blueprints' type info (0x57c5a48):
 * construct the object in place from a loaded image through its
 * out-of-line finish constructor. */
void FUN_00082660(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_0017b0d0(static_cast<hkp6DofConstraintData::Blueprints *>(object), flag);
}
