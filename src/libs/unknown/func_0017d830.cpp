/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 0 of its vtable (0x16a60b0), the complete destructor: the map's
 * destructor is out of line. */
hkTypeInfoRegistry::~hkTypeInfoRegistry()
{
    FUN_000915e0(&map);
}
