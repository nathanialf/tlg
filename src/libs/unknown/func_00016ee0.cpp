/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

inline void Class168e810::operator delete(void *object, unsigned long numBytes)
{
    freeReferencedObject(object, numBytes);
}

inline void Object00015700::operator delete(void *object, unsigned long numBytes)
{
    D_16dc070->temp58->blockFree(object, int(numBytes));
}

inline void WaitingSemaphore00016d40::operator delete(void *object, unsigned long numBytes)
{
    D_16dc070->temp58->blockFree(object, int(numBytes));
}

/* The class's key function: its vtable 0x168e800 and the deleting destructor
 * 0x16ee0 are emitted here, each with its thunk for the interface at +0x10
 * (0x16f30, 0x170c0). */
Class168e810::~Class168e810()
{
    FUN_000170d0();
    delete object18;
    for (int i = 0; i < 64; i++) {
        delete semaphores[i];
    }
}
