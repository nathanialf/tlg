/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_mutex.h"

/* derived names: the destructor FUN_009f43e0 registers with __cxa_atexit for
 * its static object (lea at 0x9f4665): when the int at +0x14 is set, destroys
 * the mutex at +0x0 and clears both (tlg_game_mutex.h). Class unknown. */
Mutex013847e0::~Mutex013847e0()
{
    if (created) {
        scePthreadMutexDestroy(&mutex);
        mutex = 0;
        created = 0;
    }
}
