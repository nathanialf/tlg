/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the create function of hkHardwareInfo's singleton record
 * (built at 0x8fdc0): a new instance. */
hkReferencedObject *FUN_0008faf0() /* derived name */
{
    return new hkHardwareInfo();
}
