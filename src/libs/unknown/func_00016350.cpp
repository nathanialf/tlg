/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

inline void *WaitingSemaphore00016d40::operator new(unsigned long numBytes)
{
    return D_16dc070->temp58->blockAlloc(int(numBytes));
}

/* The ready queue's entry at an index removed, the heap restored (0x16190).
 * derived name. */
void FUN_00016190(hkArray<ReadyEntry00017540> *readyQueue, int index);

/* Under the lock: a finished node marked done, its successors counted down
 * and the ones that reach zero pushed on the ready queue, the threads
 * waiting for it signalled; the number made ready back. derived name. */
static int finishTask(Class168e810 *self, TaskNode000172c0 *task, ThreadBuffer &stream)
{
    task->counter = -1;
    TempArray<TaskNode000172c0 *> nowReady;
    const int numSuccessors = task->successors.getSize();
    for (int i = 0; i < numSuccessors; i++) {
        TaskNode000172c0 *successor = task->successors[i];
        if (--successor->counter == 0) {
            nowReady.pushBack(hkContainerTempAllocator::get(), successor);
        }
    }
    task->successors.clear();
    if (u64 waitingThreads = task->waitingThreads) {
        for (int i = 0; waitingThreads; i++, waitingThreads >>= 1) {
            if ((waitingThreads & 1) && self->semaphores[i]->waiting) {
                self->semaphores[i]->waiting = false;
                WaitingSemaphore00016d40 *waiting = self->semaphores[i];
                stream.timerBegin("TtReleaseSemaphore");
                waiting->semaphore.FUN_0001a4a0(1);
                stream.timerEnd("Et");
            }
        }
        task->waitingThreads = 0;
    }
    for (int i = 0; i < nowReady.getSize(); i++) {
        TaskNode000172c0 *node = nowReady[i];
        ReadyEntry00017540 entry;
        entry.key = (int(node->priority) << 16) | -int(node->sequence);
        entry.node = node;
        int child = self->readyQueue.getSize();
        self->readyQueue.pushBack(entry);
        for (int parent = (child - 1) >> 1; parent >= 0; parent = (child - 1) >> 1) {
            if (self->readyQueue[parent].key > self->readyQueue[child].key) {
                break;
            }
            hkAlgorithm::swap(self->readyQueue[child], self->readyQueue[parent]);
            child = parent;
        }
    }
    return nowReady.getSize();
}

void FUN_00016350(Class168e810 *self, int mode, TaskNode000172c0 *waitFor) /* derived name */
{
    ThreadBuffer &stream = *D_16dc078;

    /* A free slot taken off the list's head; the tag in the head's upper
     * bits advances with each take. */
    int slot;
    int oldHead, newHead;
    do {
        oldHead = self->firstFreeSlot;
        slot = oldHead & 0x7f;
        const int next = self->nextFreeSlot[slot];
        newHead = ((oldHead + 0x80) & ~0x7f) | next;
    } while (__sync_val_compare_and_swap(&self->firstFreeSlot, oldHead, newHead) != oldHead);
    self->nextFreeSlot[slot] = 0x7f;

    WaitingSemaphore00016d40 *semaphore = self->semaphores[slot];
    if (!semaphore) {
        semaphore = new WaitingSemaphore00016d40(self->spinCount);
        semaphore->index = slot;
        self->semaphores[slot] = semaphore;
    }

    hkInplaceArray<WaitingSemaphore00016d40 *, 16> toRelease;
    const bool returnWhenIdle = mode == 1 && !waitFor;
    TaskNode000172c0 *task = HK_NULL;
    for (;;) {
        stream.timerBegin("Tt/FinishTaskAndGetNext");
        self->lock.enter();
        int numReady = 0;
        if (task) {
            numReady = finishTask(self, task, stream);
        }

        const u64 bit = u64(1) << semaphore->index;
        TaskNode000172c0 *next;
        for (;;) {
            if (waitFor && waitFor->counter == -1) {
                next = HK_NULL;
                break;
            }
            if (self->readyQueue.getSize()) {
                next = self->readyQueue[0].node;
                FUN_00016190(&self->readyQueue, 0);
                break;
            }
            if (self->released || returnWhenIdle) {
                next = HK_NULL;
                break;
            }
            if (waitFor) {
                waitFor->waitingThreads |= bit;
            }
            semaphore->waiting = true;
            self->lock.leave();
            stream.timerBegin("TtWaitForSignal");
            semaphore->semaphore.FUN_0001a490();
            stream.timerEnd("Et");
            self->lock.enter();
            if (waitFor) {
                waitFor->waitingThreads &= ~bit;
            }
        }

        /* One semaphore signalled for each node made ready that this thread
         * does not take itself. */
        if (numReady > 0) {
            if (next) {
                numReady--;
            }
            for (int k = 0; k < 64 && numReady > 0; k++) {
                WaitingSemaphore00016d40 *waitingSemaphore = self->semaphores[k];
                if (!waitingSemaphore) {
                    break;
                }
                if (waitingSemaphore->waiting) {
                    waitingSemaphore->waiting = false;
                    toRelease.pushBack(waitingSemaphore);
                    numReady--;
                }
            }
        }
        self->lock.leave();
        stream.timerEnd("Et");
        if (toRelease.getSize()) {
            for (int i = 0; i < toRelease.getSize(); i++) {
                WaitingSemaphore00016d40 *waitingSemaphore = toRelease[i];
                stream.timerBegin("TtReleaseSemaphore");
                waitingSemaphore->semaphore.FUN_0001a4a0(1);
                stream.timerEnd("Et");
            }
            toRelease.clear();
        }

        task = next;
        if (!task) {
            break;
        }
        task->runner->unknownVirtual2();
    }

    /* The slot back at the head of the free list, the tag kept. */
    do {
        oldHead = self->firstFreeSlot;
        self->nextFreeSlot[slot] = oldHead & 0x7f;
        newHead = (oldHead & ~0x7f) | slot;
    } while (__sync_val_compare_and_swap(&self->firstFreeSlot, oldHead, newHead) != oldHead);
}
