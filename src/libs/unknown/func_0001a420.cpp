/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* The kernel semaphore does not spin. */
hkSemaphore::hkSemaphore(int initialCount, int maxCount, int numSpinIterations)
{
    sceKernelCreateSema(&semaphore, "hkSemaphore", 1, initialCount, maxCount, 0);
}
