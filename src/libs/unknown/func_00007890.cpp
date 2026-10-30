/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Pool00007880::FUN_00007890(int numThreads)
{
    const int numWanted = numThreads <= 11 ? numThreads : 11;
    while (count < numWanted) {
        const int threadId = count + 1;
        WorkerRecord &worker = workers[count];
        worker.pool = this;
        worker.threadId = threadId;
        worker.killThread = false;
        worker.timersCleared = false;
        worker.threadId1c = threadId;
        worker.thread.startThread(FUN_00007180, &worker, threadName, stackSize);
        count++;
    }
    while (count > numWanted) {
        count--;
        WorkerRecord &worker = workers[count];
        worker.killThread = true;
        worker.workerStart.FUN_0001a4a0(1);
        worker.thread.joinThread();
    }
}
