/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_hks.h"
#include "tlg_sce_kernel.h"

/* derived names: the script C functions "RBSnooper_AllSuspend" ("rigid
 * bodies suspend in all RBSnoopExt.") and "RBSnooper_AllResume" (FUN_00cf1c10
 * registers them, lea at 0xcf1ca5 and 0xcf1cc2): with the object at +0xf78 of
 * the record the pointer at 0x5938c40 holds, under its mutex at +0x10 and
 * with its word at +0x18 set meanwhile, each snooper of its array at +0x38
 * is suspended (FUN_00cf14d0) or resumed (FUN_00cf1630); no results. */
struct Object00cf14d0; /* derived name: leaf_00cf14d0.cpp */

struct Snoopers00cf2ab0 { /* derived name */
    u8 unknown0[0x10];
    pthread_mutex_t mutex; /* +0x10 */
    int busy;              /* derived name: +0x18 */
    u8 unknown1c[0x1c];
    Array05943280<Object00cf14d0 *> snoopers; /* +0x38 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0xf78];
    Snoopers00cf2ab0 *snoopersf78; /* +0xf78 */
};

extern Object05938c40 *D_5938c40;

void FUN_00cf14d0(Object00cf14d0 *snooper); /* derived name */
void FUN_00cf1630(Object00cf14d0 *snooper); /* derived name */

int FUN_00cf2ab0(lua_State *) /* derived name: RBSnooper_AllSuspend */
{
    if (D_5938c40) {
        if (Snoopers00cf2ab0 *snoopers = D_5938c40->snoopersf78) {
            scePthreadMutexLock(&snoopers->mutex);
            snoopers->busy = 1;
            for (unsigned i = 0; i < snoopers->snoopers.size(); ++i)
                FUN_00cf14d0(snoopers->snoopers.at(i));
            snoopers->busy = 0;
            scePthreadMutexUnlock(&snoopers->mutex);
        }
    }
    return 0;
}

int FUN_00cf2b30(lua_State *) /* derived name: RBSnooper_AllResume */
{
    if (D_5938c40) {
        if (Snoopers00cf2ab0 *snoopers = D_5938c40->snoopersf78) {
            scePthreadMutexLock(&snoopers->mutex);
            snoopers->busy = 1;
            for (unsigned i = 0; i < snoopers->snoopers.size(); ++i)
                FUN_00cf1630(snoopers->snoopers.at(i));
            snoopers->busy = 0;
            scePthreadMutexUnlock(&snoopers->mutex);
        }
    }
    return 0;
}
