/* Havok's threading primitives over the Sony kernel. */
#ifndef TLG_HK_THREAD_H
#define TLG_HK_THREAD_H

#include "tlg_sce_kernel.h"

/* hkSemaphore: one kernel semaphore handle at +0, created under the name
 * "hkSemaphore" (0x14b4978) by FUN_0001a420 (initial and maximum counts in
 * its second and third arguments, attribute 1). FUN_0001a440 deletes it (its
 * callers then free the object), FUN_0001a490 waits for one count and
 * FUN_0001a4a0 signals the given count. */
class hkSemaphore
{
  public:
    void FUN_0001a440();          /* derived name: the destructor's body */
    void FUN_0001a4a0(int count); /* derived name: release */

    SceKernelSema semaphore; /* derived name */
};

#endif
