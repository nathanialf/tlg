/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_hks.h"
#include "tlg_sce_kernel.h"

/* derived names: a script C function on the record FUN_001b3a80 reads
 * ("PlayGoIsDialogOpen"): when the int at +0xc is clear and the int at +0x48
 * not yet set, sets +0x48 and signals the semaphore at +0x38 once; pushes
 * whether it did and returns one result. Its registration is not traced. */
struct Member05938c40_f58 { /* derived name */
    u8 unknown0[0xc];
    int unknownc; /* +0xc */
    u8 unknown10[0x28];
    SceKernelSema unknown38; /* +0x38 */
    u8 unknown40[0x8];
    int unknown48; /* +0x48 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0xf58];
    Member05938c40_f58 *unknownf58;
};

extern Object05938c40 *D_5938c40;

int FUN_001b3940(lua_State *state) /* derived name */
{
    Member05938c40_f58 *record = D_5938c40->unknownf58;
    bool signalled = false;
    if (record->unknownc == 0 && record->unknown48 == 0) {
        record->unknown48 = 1;
        sceKernelSignalSema(record->unknown38, 1);
        signalled = true;
    }
    HksObject *top = state->top;
    top->value.boolean = signalled;
    top->type = 1;
    state->top = top + 1;
    return 1;
}
