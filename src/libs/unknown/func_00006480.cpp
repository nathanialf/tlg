/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkJobQueue::FUN_00006480(DynamicData *data) /* derived name */
{
    int index;
    bool jobsAvailable = false;
    int i = cpuQueuesBegin;
    for (; i < cpuQueuesEnd; i++) {
        if (data->jobQueues[i].getSize() != 0) {
            jobsAvailable = true;
            if (data->numThreadsWaiting[i] != 0) {
                index = i;
                goto releaseThread;
            }
        }
    }
    for (; i < numJobQueues; i++) {
        if (data->jobQueues[i].getSize() != 0) {
            jobsAvailable = true;
            break;
        }
    }
    if (!jobsAvailable) {
        return;
    }
    for (index = cpuQueuesBegin; index < numWaitingThreadSemaphores; index++) {
        if (data->numThreadsWaiting[index] != 0) {
            goto releaseThread;
        }
    }
    return;

releaseThread:
    data->numThreadsWaiting[index]--;
    waitingThreadSemaphores[index]->FUN_0001a4a0(1);
}
