/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkSerializeDeprecated's create function (its singleton record's, 0x57c89e8):
 * the instance a static of this function, built on the first call (its guard
 * at 0x57c8a18; the empty destructor not registered for exit), returned
 * with a reference added. */
hkReferencedObject *FUN_0019a5f0() /* derived name */
{
    static hkSerializeDeprecated D_57c8a08;
    D_57c8a08.addReference();
    return &D_57c8a08;
}
