/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived name: signals the semaphore by the given count (the callers at
 * 0x5201 to 0x55bd pass 1). */
void hkSemaphore::FUN_0001a4a0(int count) /* derived name */
{
    sceKernelSignalSema(semaphore, count);
}
