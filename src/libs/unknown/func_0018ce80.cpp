/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

/* The class allocator's delete: the task goes back to the calling thread's
 * heap at its size. */
inline void BroadPhaseCollideTask::operator delete(void *object, unsigned long numBytes)
{
    if (object) {
        D_16dc070->temp58->blockFree(object, int(numBytes));
    }
}

/* The collide task's destructor (slot 0 of its vtable): the array's
 * storage given back when it outgrew the object. */
BroadPhaseCollideTask::~BroadPhaseCollideTask() {}
