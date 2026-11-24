/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016c81c0.h"
#include "tlg_game_creation.h"

/* derived name: a short wait while another thread holds on: a 100000 ns
 * timer on the thread's queue and a wait for its event, or, where the timer
 * cannot be armed, a sleep of one microsecond (Lock059458a4::lock's wait) */
static inline void waitBriefly() /* derived name */
{
    SceKernelTimespec time;
    time.tv_sec = 0;
    time.tv_nsec = 100000;
    SceKernelUseconds timeout = 1;
    SceKernelEqueue queue = D_16dc0a8;
    if (sceKernelAddHRTimerEvent(queue, 0, &time, 0) == 0) {
        SceKernelEvent event;
        int count = 0;
        sceKernelWaitEqueue(queue, &event, 1, &count, &timeout);
    } else {
        sceKernelUsleep(1);
    }
}

/* 0xd687e0: in mode 3 a spin until one count is left, else the wait for the
 * count to reach zero (FUN_013baf50); then the condition variable and the
 * mutex destroyed (render/ps4/util's reports, lines 119 and 126), the
 * members released last first and the base's destructor in line */
// NONMATCHING: registers only, 198/199 instructions in the module (893 bytes, base 895): the base
// keeps the condition variable's address in r14 (`lea r14, [rbx+0x58]` after the join, `mov rdi, r14`
// at the first Destory and at the member's destructor after the mutex's), the build makes it again at
// each (`lea rdi, [rbx+0x58]`). Round 571E: everything else is the base's (the mode and the spinning
// count read volatile, the report and the base's destructor inlined by the link). Round 574E: the
// count is a volatile field (tlg_game_object013bb3f0.h; no function of the module changes). The link
// IR forms the address once per user, in the Destory's block and in ~ConditionVariable's (two GEPs
// of %this, 4, 0, 0, neither dominating the other), where the base's lea is in the join block
// before the flag's branch (0xd688eb): the base's IR has one address at the join. Next: what keeps
// one GEP at the join (a model, not compiled: a common pointer in the source is merged by
// InstCombine into each user's GEP, so it needs a use at the join itself).
Object016c81c0::~Object016c81c0()
{
    if (mode == 3) {
        /* other threads take the count down while this spins (`mov eax,
         * [rbx+0x78]; cmp eax, 2`) */
        while (waiter.count > 1)
            waitBriefly();
    } else {
        FUN_013baf50(&waiter);
    }
    waiter.conditionVariable.Destory();
    waiter.mutex.Destory();
}
