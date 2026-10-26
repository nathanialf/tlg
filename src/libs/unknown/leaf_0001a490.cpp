/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived name: waits for one count of the semaphore, with no timeout (the
 * callers at 0x5490 and 0x72a8 to 0x7423). */
void hkSemaphore::FUN_0001a490() /* derived name */
{
    sceKernelWaitSema(semaphore, 1, 0);
}
