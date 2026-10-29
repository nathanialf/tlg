/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the create function of hkProcessFactory's singleton record:
 * a new instance. */
hkReferencedObject *FUN_00183f00() /* derived name */
{
    return new hkProcessFactory();
}
