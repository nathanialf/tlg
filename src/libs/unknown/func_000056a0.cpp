/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the job queue's default finish function (stored at +0x20 by
 * its constructor, 0x5825): finish through the function of the job's type. */
int FUN_000056a0(hkJobQueue &queue, void *data, const hkJobQueueJob &jobIn,
                 void *newJobOut) /* derived name */
{
    return queue.customJobs[jobIn.jobType].finishJobFunc(queue, data, jobIn, newJobOut);
}
