/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

/* The class allocator's delete (tlg_lib_unknown.h's reference-counted
 * form). */
inline void hknpPrepareConstraintsTask::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

/* Nothing to destroy; the deleting destructor (0x383f0, slot 1 of the vtable
 * 0x16a4640 and of fourteen other 0x30-byte classes') is the one emitted
 * with it. */
hknpPrepareConstraintsTask::~hknpPrepareConstraintsTask() {}
