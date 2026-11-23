/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_sce_kernel.h"
#include "tlg_game_block.h"
#include "tlg_game_creation.h"
#include "tlg_game_object05989c08.h"

/* derived name: the thread-local int FUN_00d6a930 returns (tp -32) */
extern __thread int D_16dc0b0;

/* derived names: what a game thread is started with: its function and the
 * argument it takes, and the word set when the function has returned */
struct ThreadStart00d6db10 { /* derived name */
    u8 unknown0[0x8];
    void (*function)(void *argument); /* +0x8 */
    void *argument;                   /* +0x10 */
    int finished;                     /* +0x18 */
};

/* derived name: the entry of the game's threads (no direct caller): the
 * thread's event queue "ThreadSleep" made, its int -3 and no heap of its
 * own, the start hook of the object at 0x5989c08 called, the function run,
 * the end hook called, the start marked finished, the queue destroyed and
 * the thread ended */
void *FUN_00d6db10(ThreadStart00d6db10 *start) /* derived name */
{
    sceKernelCreateEqueue(&D_16dc0a8, "ThreadSleep");
    Object05989c08 *system = D_5989c08;
    D_16dc0b0 = -3;
    D_16dc090 = 0;
    if (system->threadStarted)
        system->threadStarted(scePthreadSelf(), D_16dc0b0);
    start->function(start->argument);
    if (system->threadEnded)
        system->threadEnded(scePthreadSelf());
    start->finished = 1;
    sceKernelDeleteEqueue(D_16dc0a8);
    scePthreadExit(0);
}
