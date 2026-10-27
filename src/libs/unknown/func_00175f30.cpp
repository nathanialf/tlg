/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the create function of hknpGlobals' singleton record (built
 * at 0x1760c0): a new instance. */
hkReferencedObject *FUN_00175f30() /* derived name */
{
    return new hknpGlobals();
}
