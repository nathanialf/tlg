/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 0 of its vtable (0x16a61f0) and of hkDefaultClassNameRegistry's
 * (0x16a6170), the complete destructor: the map's destructor is out of
 * line, the name is not owned. */
hkDynamicClassNameRegistry::~hkDynamicClassNameRegistry()
{
    FUN_000915e0(&map);
}
