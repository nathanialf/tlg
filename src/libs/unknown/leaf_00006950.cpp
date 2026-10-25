/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: sets the reference-count lock mode on the
 * hkReferencedObjectLock singleton (called with 1 at 0x70c6 when the thread
 * pool starts and with 0 at 0x7499 when it stops; also at 0x9aed). */
void FUN_00006950(int lockMode) /* derived name */
{
    D_57b7b50->lockMode = lockMode;
}
