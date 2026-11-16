/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_hks.h"
#include "tlg_sce_kernel.h"

/* derived names: the script C function "RBRelocater_AllDo" ("rigid bodies
 * Do in all RBRelocateExt."; FUN_00a07af0 registers it, lea at 0xa07ba2),
 * the RBSnooper_All ones' form (leaf_00cf2ab0.cpp): with the object at
 * +0x118 of the record the pointer at 0x57c9390 holds, under its mutex at
 * +0x10 and with its word at +0x18 set meanwhile, FUN_00b48a80 runs on each
 * relocater of its array at +0x38; no results. */
struct Object00b48a80; /* derived name */

struct Relocaters00a08c80 { /* derived name */
    u8 unknown0[0x10];
    pthread_mutex_t mutex; /* +0x10 */
    int busy;              /* derived name: +0x18 */
    u8 unknown1c[0x1c];
    Array05943280<Object00b48a80 *> relocaters; /* +0x38 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x118];
    Relocaters00a08c80 *relocaters118; /* +0x118 */
};

extern Object057c9390 *D_57c9390;

void FUN_00b48a80(Object00b48a80 *relocater); /* derived name */

int FUN_00a08c80(lua_State *) /* derived name: RBRelocater_AllDo */
{
    if (D_57c9390) {
        if (Relocaters00a08c80 *relocaters = D_57c9390->relocaters118) {
            scePthreadMutexLock(&relocaters->mutex);
            relocaters->busy = 1;
            for (unsigned i = 0; i < relocaters->relocaters.size(); ++i)
                FUN_00b48a80(relocaters->relocaters.at(i));
            relocaters->busy = 0;
            scePthreadMutexUnlock(&relocaters->mutex);
        }
    }
    return 0;
}
