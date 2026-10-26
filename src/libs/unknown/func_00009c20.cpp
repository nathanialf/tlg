/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the create function of hkDummySingleton's singleton record:
 * a new instance. */
hkReferencedObject *FUN_00009c20() /* derived name */
{
    return new hkDummySingleton();
}
