/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The object pointer and the links are left as loaded; the name's finish
 * constructor is out of line. */
hkMemoryResourceHandle::hkMemoryResourceHandle(hkFinishLoadedObjectFlag flag)
    : hkResourceHandle(flag), references(flag)
{
    FUN_0000e5c0(&name, flag);
}
