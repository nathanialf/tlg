/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The record holds the worker's index plus one. */
void *FUN_00007180(void *argument) /* derived name */
{
    Pool00007880::WorkerRecord *record = static_cast<Pool00007880::WorkerRecord *>(argument);
    record->pool->FUN_000071a0(record->threadId - 1);
    return 0;
}
