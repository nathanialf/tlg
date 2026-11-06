/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The timers' names by job type. derived name. */
extern const char *const D_168ca70[15];

int Object00005fc0::FUN_00005fc0(bool addTimers)
{
    Job job;
    int jobStatus = FUN_000061a0(HK_NULL, job, 0);
    if (jobStatus != 0) {
        return jobStatus;
    }
    if (addTimers) {
        do {
            const int jobType = job.jobType;
            const char *timerName = jobType < 15 ? D_168ca70[jobType] : "TtOther";
            ThreadBuffer &stream = *D_16dc078;
            stream.timerBegin(timerName);
            if (profiler) {
                profiler->onStartJob(jobType, job.jobSubType);
            }
            jobStatus = jobFuncs[jobType].funcs[job.jobSubType](*this, job);
            if (profiler) {
                profiler->onEndJob(jobType);
            }
            stream.timerEnd("Et");
        } while (jobStatus == 0);
    } else {
        do {
            const int jobType = job.jobType;
            if (profiler) {
                profiler->onStartJob(jobType, job.jobSubType);
            }
            jobStatus = jobFuncs[jobType].funcs[job.jobSubType](*this, job);
            if (profiler) {
                profiler->onEndJob(jobType);
            }
        } while (jobStatus == 0);
    }
    return jobStatus;
}
