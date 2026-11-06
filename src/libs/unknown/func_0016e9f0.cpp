/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

/* The solve data task's destructor (the compiler's D0 at 0x16e9f0 and D1 at
 * 0x16eaa0, each followed by its thunk from the task interface at +0x10,
 * 0x16ea40 and 0x16ec20): the solve data, the threads' blocks and the
 * union-find given back to the thread's heap, then the arrays. */
hknpSolveDataTask::~hknpSolveDataTask()
{
    delete solveData;
    D_16dc070->temp58->blockFree(threadBlocks, numThreads * 512);
    delete unionFind;
}
