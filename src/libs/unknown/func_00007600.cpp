/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void FUN_000076c0(void *argument); /* derived name: slot 5's callback */
void FUN_00007730(void *argument); /* derived name: slot 6's callback */

void Pool00007880::FUN_00007600(WorkCallback newCallback, void *argument)
{
    running = true;
    callback = newCallback;
    callbackArgument = argument;
    for (int i = count - 1; i >= 0; i--) {
        workers[i].workerStart.FUN_0001a4a0(1);
    }
}

void Pool00007880::FUN_00007660(void *argument)
{
    FUN_00007600(FUN_000076c0, argument);
}

void Pool00007880::FUN_000076d0(void *argument)
{
    FUN_00007600(FUN_00007730, argument);
}
