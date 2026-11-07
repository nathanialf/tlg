/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A callback still running is waited out, one count of the done semaphore
 * per worker, then the workers are killed and signalled, all of them before
 * the first is joined; the reference lock's mode is set back to 0 (0x6950)
 * before the members go. The deleting destructor (0x7390) is emitted ahead
 * of it. */
Pool00007880::~Pool00007880()
{
    if (running) {
        for (int i = 0; i < count; i++) {
            workerDone.FUN_0001a490();
        }
        flag330 = false;
        running = false;
    }
    for (int i = 0; i < count; i++) {
        workers[i].killThread = true;
        workers[i].workerStart.FUN_0001a4a0(1);
    }
    for (int i = 0; i < count; i++) {
        workers[i].thread.joinThread();
    }
    FUN_00006950(0);
}
