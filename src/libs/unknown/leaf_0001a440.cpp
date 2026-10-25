/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived name: deletes the kernel semaphore (called by 0x5bbc and 0x5d21 on
 * a semaphore they then free). */
void hkSemaphore::FUN_0001a440() /* derived name */
{
    sceKernelDeleteSema(semaphore);
}
