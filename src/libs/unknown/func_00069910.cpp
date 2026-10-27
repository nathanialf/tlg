/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the step's thread counts from the thread pool. */
void StepInput00069910::FUN_00069910(const ThreadPool00069910 *threadPool)
{
    if (threadPool) {
        numCpuThreads = threadPool->getNumThreads() + 1;
    } else {
        numCpuThreads = 1;
    }
    numSpuThreads = 0;
}
