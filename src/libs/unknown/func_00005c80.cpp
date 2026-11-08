/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkJobQueue::~hkJobQueue()
{
    delete data;
    if (unknown80) {
        for (int i = 0; i < 5; i++) {
            delete waitingThreadSemaphores[i];
        }
    }
}
