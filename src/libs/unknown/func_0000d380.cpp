/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the cleanup callback of hkRefCountedProperties' type info
 * (0x57b85f0): destroy the object in place through its out-of-line
 * destructor. */
void FUN_0000d380(void *object) /* derived name */
{
    FUN_0001c1f0(static_cast<hkRefCountedProperties *>(object));
}
