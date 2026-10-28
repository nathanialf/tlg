/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 8 of the pool's vtable: wait for every worker to be
 * done with the callback it was handed, then mark the pool idle. */
void Pool00007880::FUN_00007740()
{
    if (running) {
        for (int i = 0; i < count; i++) {
            workerDone.FUN_0001a490();
        }
        flag330 = false;
        running = false;
    }
}
