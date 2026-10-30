/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Pool00007880::FUN_000071a0(int workerIndex)
{
    WorkerRecord &record = workers[workerIndex];
    hkWorkerThreadContext context(record.threadId);
    if (timerBufferSize > 0) {
        D_16dc078->FUN_0000eb90(timerBufferSize);
    }
    record.monitorStreamBegin = D_16dc078->start;
    record.monitorStreamEnd = D_16dc078->end;
    FUN_00007280(workerIndex, context);
}
