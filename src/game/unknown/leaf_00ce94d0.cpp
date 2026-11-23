/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_task00ce9460.h"

/* derived name: the task's range of the list (the object eight places on
 * fetched ahead, `prefetchnta`), each object's slot7 given the
 * argument's member8, then the task counted finished (`lock inc`) */
void FUN_00ce94d0(Task00ce9460 *task)
{
    const unsigned end = task->end;
    for (unsigned i = task->begin, ahead = i + 8; i < end; ++i, ++ahead) {
        if (ahead < end)
            _mm_prefetch(reinterpret_cast<const char *>(task->list->at(ahead)), _MM_HINT_NTA);
        task->list->at(i)->slot7(task->argument->member8);
    }
    __sync_fetch_and_add(task->finished, 1);
}
