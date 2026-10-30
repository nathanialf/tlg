/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Pool00007880::FUN_00007280(int workerIndex, hkWorkerThreadContext &context)
{
    WorkerRecord &record = workers[workerIndex];
    record.workerStart.FUN_0001a490();
    while (!record.killThread) {
        if (record.timersCleared) {
            D_16dc078->FUN_0000eca0();
            record.monitorStreamEnd = D_16dc078->end;
            record.timersCleared = false;
        }
        callback(callbackArgument);
        record.monitorStreamEnd = D_16dc078->end;
        if (flag330) {
            FUN_00006c50()->garbageCollectThread(context.memoryRouter);
        }
        workerDone.FUN_0001a4a0(1);
        record.workerStart.FUN_0001a490();
    }
}
