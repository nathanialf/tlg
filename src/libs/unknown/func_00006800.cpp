/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the lock made, then put in place of the previous instance,
 * whose reference goes. */
void FUN_00006800() /* derived name */
{
    hkReferencedObjectLock *lock = new hkReferencedObjectLock();
    if (D_57b7b50) {
        D_57b7b50->removeReference();
    }
    D_57b7b50 = lock;
}
