/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The thread count from the hardware info, an empty list of thread ids. */
JobQueueCinfo::JobQueueCinfo()
{
    unknown0 = 1;
    numCpuThreads = D_57c8728->numThreads;
    unknown8 = 0;
    unknown4 = true;
}
