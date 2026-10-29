/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the create function of hkUuidPseudoRandomGenerator's
 * singleton record: a new, seeded instance. */
hkReferencedObject *FUN_0000daf0() /* derived name */
{
    return new hkUuidPseudoRandomGenerator();
}
