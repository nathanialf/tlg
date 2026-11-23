/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_task00ce9460.h"

/* derived name: the task's range of the list (the object eight places on
 * fetched ahead, `prefetchnta`), each object's slot6 given the
 * argument's value, then the task counted finished (`lock inc`) */
// NONMATCHING: 38/40, register assignment only: the base loads the object's vptr into rax (`mov rax, [rdi]; call
// [rax+0x30]`), this build into rcx; FUN_00ce94d0 and FUN_00ce61d0, the same loop with the argument's member, are
// equal (round 484D: the value read into a local first moves the loop's registers away)
// Round 507D: the vptr's load is defined while the argument's pointer (rax) is live, its value
// read after it (clang forms the virtual callee before the arguments, CGExprCXX.cpp); the base
// reads the value before the vptr, so rax is free for it.
void FUN_00ce9460(Task00ce9460 *task)
{
    const unsigned end = task->end;
    for (unsigned i = task->begin, ahead = i + 8; i < end; ++i, ++ahead) {
        if (ahead < end)
            _mm_prefetch(reinterpret_cast<const char *>(task->list->at(ahead)), _MM_HINT_NTA);
        task->list->at(i)->slot6(task->argument->value);
    }
    __sync_fetch_and_add(task->finished, 1);
}
