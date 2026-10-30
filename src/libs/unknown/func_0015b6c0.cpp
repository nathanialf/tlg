/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hknpPrepareNewPairsTask::hknpPrepareNewPairsTask(void *argument1, void *argument2, void *argument3,
                                                 void *argument4, void *argument5)
    : unknown18(argument1), contextPool(static_cast<hknpWorldContextPool *>(argument2)),
      stream28(static_cast<const hkBlockStream *>(argument3)), unknown440(argument4), status(0),
      unknown45c(0), unknown460(0)
{
    unknown468[1] = argument5;
}
