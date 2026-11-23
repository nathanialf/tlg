/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* The render library's utilities as this unit includes them, from props
 * (0x15b8147, 0x15b8188). */
#define RENDER_UTIL_DIR /* derived name */                                                         \
    "D:\\trico\\engine\\anzu\\engine_src\\props\\..\\render/ps4/util/"

#include "tlg_game_render_mutex.h"

/* derived names: the static mutexes and condition variables at 0x58b6000
 * (destroyed by 0x139ddf0 and 0x139ded0, registered at 0xb98702), and the
 * request the first pair hands over (0x5835fb8). */
extern Mutex D_58b6000;
extern ConditionVariable D_58b6010;
extern void *D_5835fb8;

/* derived name: a request handed over: once the previous one is taken (the
 * slot null), the new one stored and the waiter signalled. */
/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: cost 440 at the
 * link, over its threshold of 175: one signature changes no row) */
void FUN_00b91220(void *request)
{
    D_58b6000.Lock();
    while (D_5835fb8 != nullptr)
        D_58b6010.Wait(D_58b6000);
    D_5835fb8 = request;
    D_58b6010.Signal();
    D_58b6000.Unlock();
}
