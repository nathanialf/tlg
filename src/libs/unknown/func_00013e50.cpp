/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

/* The class allocator's delete: the object goes back to the calling
 * thread's heap at its size. */
inline void Runner00016350::operator delete(void *object, unsigned long numBytes)
{
    if (object) {
        D_16dc070->temp58->blockFree(object, int(numBytes));
    }
}

/* Nothing to destroy; the deleting destructor (0x13e50, slot 1 of the
 * vtable 0x168e7d0) is the one emitted with it. */
Runner00016350::~Runner00016350() {}
