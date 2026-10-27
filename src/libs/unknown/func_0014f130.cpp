/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

/* The class allocator's delete (tlg_lib_unknown.h's reference-counted
 * form). */
inline void hknpCleanInactiveCachesTask::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

/* Nothing to destroy; emitted with it, the deleting destructor (the shared
 * 0x8a210) and its thunk for the task interface at +0x10 (0x14f130), the
 * deleting destructor inlined. */
hknpCleanInactiveCachesTask::~hknpCleanInactiveCachesTask() {}
