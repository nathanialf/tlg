/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the job queue's default pop function (stored at +0x18 by
 * its constructor, 0x581a): pop through the function of the job's type. */
int FUN_00005680(hkJobQueue &queue, void *data, hkJobQueueJob &jobIn,
                 hkJobQueueJob &jobOut) /* derived name */
{
    return queue.customJobs[jobIn.jobType].popJobFunc(queue, data, jobIn, jobOut);
}
