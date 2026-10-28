/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the create function of hkDefaultClassNameRegistry's
 * singleton record (linked at 0x184fbe): a new instance. */
hkReferencedObject *FUN_00184f40() /* derived name */
{
    return new hkDefaultClassNameRegistry();
}
