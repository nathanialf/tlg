/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* The kernel semaphore deleted (Class168e810's destructor calls it at
 * 0x17010 before freeing the object; 0x5bbc and 0x5d21 likewise). */
hkSemaphore::~hkSemaphore()
{
    sceKernelDeleteSema(semaphore);
}
