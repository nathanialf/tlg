/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Under the lock, once: every waiting thread's semaphore signalled, each
 * under the timer "ReleaseSemaphore", up to the first slot without one. */
void Class168e810::FUN_000170d0() /* derived name */
{
    lock.enter();
    if (!released) {
        released = true;
        ThreadBuffer &stream = *D_16dc078;
        for (int i = 0; i < 64; i++) {
            WaitingSemaphore00016d40 *waitingSemaphore = semaphores[i];
            if (!waitingSemaphore) {
                break;
            }
            if (waitingSemaphore->waiting) {
                waitingSemaphore->waiting = false;
                stream.timerBegin("TtReleaseSemaphore");
                waitingSemaphore->semaphore.FUN_0001a4a0(1);
                stream.timerEnd("Et");
            }
        }
    }
    lock.leave();
}
