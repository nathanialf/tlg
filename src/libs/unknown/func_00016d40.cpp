/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

inline void *Object00015700::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(int(numBytes));
}

inline void *WaitingSemaphore00016d40::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(int(numBytes));
}

Class168e810::Class168e810(int spinCount) : lock(spinCount), sequence(0), spinCount(spinCount)
{
    object18 = new Object00015700(spinCount);
    readyQueue.reserve(hkContainerHeapAllocator::get(), 256);
    released = false;
    for (int i = 0; i < 64; i++) {
        if (i < 4) {
            WaitingSemaphore00016d40 *semaphore = new WaitingSemaphore00016d40(this->spinCount);
            semaphores[i] = semaphore;
            semaphore->index = i;
        } else {
            semaphores[i] = HK_NULL;
        }
    }
}
