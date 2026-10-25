/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of the dynamic class name registry's vtable (address
 * point 0x16a6200; hkDefaultClassNameRegistry's 0x16a6180 keeps it) returns
 * the class registered under a name, or null. */
const hkClass *
hkDynamicClassNameRegistry::FUN_0017ec90(const char *className) const /* derived name */
{
    return reinterpret_cast<const hkClass *>(map.FUN_00091900(className, 0));
}
