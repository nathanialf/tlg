/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The functions a job type gets until one is registered (static, the
 * file's, derived names): its pop asks nothing of the queue (folded by the
 * linker into the shared 0x42d0) and its finish reports one job done (kept
 * here, 0x58a0, the body 359 vtable slots share). */
static int defaultPopJob(hkJobQueue &queue, void *data, hkJobQueueJob &jobIn, hkJobQueueJob &jobOut)
{
    return 0;
}

static int defaultFinishJob(hkJobQueue &queue, void *data, const hkJobQueueJob &jobIn,
                            void *newJobOut)
{
    return 1;
}

hkJobQueue::hkJobQueue(const JobQueueCinfo &cinfo)
    : criticalSection(0), numCustomJobTypes(cinfo.maxNumJobTypes), unknown328(HK_NULL)
{
    D_16dc068 = 0;

    DynamicData *newData =
        static_cast<DynamicData *>(D_16dc070->temp58->blockAlloc(sizeof(DynamicData)));
    memset(newData, 0, sizeof(DynamicData));
    data = newData;
    unknown80 = false;
    data->unknown28 = false;
    data->unknown24 = 0;

    hwSetup = cinfo.hwSetup;

    data->jobTypesMask = 0;
    for (int i = 0; i < numCustomJobTypes; i++) {
        customJobs[i].unknown8 = 0;
        customJobs[i].unknown0 = 0;
        customJobs[i].popJobFunc = defaultPopJob;
        customJobs[i].finishJobFunc = defaultFinishJob;
        data->unknown0[i] = 0;
        data->jobTypesMask |= 1 << i;
    }
    popJobFunc = FUN_00005680;
    finishJobFunc = FUN_000056a0;
    unknown310 = 0;
    memset(waitingThreadSemaphores, 0, sizeof(waitingThreadSemaphores) + sizeof(int));
    FUN_000058b0();
}
