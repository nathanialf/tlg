/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_lib_unknown.h"

/* Slot 9 of the primary vtable; it overrides slot 6 of the second base, so
 * its this-adjusting thunk (0x17910, a jump: -0x10 to the object) is emitted
 * with it. */
void Class168e810::FUN_00017540(TaskNode000172c0 *const *nodes, int numNodes) /* derived name */
{
    hkInplaceArray<WaitingSemaphore00016d40 *, 16> toRelease;
    lock.enter();
    int numReady = 0;
    for (int i = 0; i < numNodes; i++) {
        u16 next = u16(sequence + 1);
        if (next == 0) {
            next = u16(sequence + 2);
        }
        TaskNode000172c0 *node = nodes[i];
        sequence = next;
        node->sequence = next;
        if (--node->counter == 0) {
            ReadyEntry00017540 entry;
            entry.key = (int(node->priority) << 16) | -int(next);
            entry.node = node;
            int child = readyQueue.getSize();
            readyQueue.pushBack(entry);
            for (int parent = (child - 1) >> 1; parent >= 0; parent = (child - 1) >> 1) {
                if (readyQueue[parent].key > readyQueue[child].key) {
                    break;
                }
                hkAlgorithm::swap(readyQueue[child], readyQueue[parent]);
                child = parent;
            }
            numReady++;
        }
    }
    for (int k = 0; k < 64 && numReady > 0; k++) {
        WaitingSemaphore00016d40 *waitingSemaphore = semaphores[k];
        if (!waitingSemaphore) {
            break;
        }
        if (waitingSemaphore->waiting) {
            waitingSemaphore->waiting = false;
            toRelease.pushBack(waitingSemaphore);
            numReady--;
        }
    }
    lock.leave();
    if (toRelease.getSize()) {
        ThreadBuffer &stream = *D_16dc078;
        for (int i = 0; i < toRelease.getSize(); i++) {
            WaitingSemaphore00016d40 *waitingSemaphore = toRelease[i];
            stream.timerBegin("TtReleaseSemaphore");
            waitingSemaphore->semaphore.FUN_0001a4a0(1);
            stream.timerEnd("Et");
        }
    }
}
