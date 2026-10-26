/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkRootLevelContainer::NamedVariant's finish constructor: the name and the
 * class name finish; the variant is left as loaded. */
hkRootLevelContainer::NamedVariant::NamedVariant(hkFinishLoadedObjectFlag flag)
{
    FUN_0000e5c0(&name, flag);
    FUN_0000e5c0(&className, flag);
}
