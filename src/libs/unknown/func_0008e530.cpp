/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkRootLevelContainer::NamedVariant's type info (0x57c8400):
 * construct the object in place from a loaded image through its
 * out-of-line finish constructor. */
void FUN_0008e530(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_0017dde0(static_cast<hkRootLevelContainer::NamedVariant *>(object), flag);
}
