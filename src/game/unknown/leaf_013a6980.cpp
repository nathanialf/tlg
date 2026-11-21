/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 5 of the vtable at 0x16d1348 (its pointer at
 * 0x16d1380, stored by FUN_00c3e2a0), one of the vtables whose slot 0 is the
 * destructor of Object013a6a50 (FUN_013a6a50): clears the int at +0x31efc of
 * the view the object the pointer at 0x5938c40 holds in its array at +0x58 at
 * the index at +0x88, hands the view to FUN_00b91220, then spins until the
 * view's int at +0x31ef8 is 2 or more, counting the turns in a volatile local
 * (incremented in memory, `inc dword [rbp-0x1c]`, and the int reread each
 * turn). The object itself is not read. */
class Object013a6a50; /* derived name */

struct View013a6980 { /* derived name */

    /* derived name: spins until the state is 2 or more, counting the turns
     * in a volatile local (a delay the optimiser must keep) */
    void wait()
    {
        volatile int turns = 0; /* volatile: the turns are the delay, kept in memory */
        while (state < 2)
            ++turns;
    }

    u8 unknown0[0x31ef8];
    /* +0x31ef8: stored 3, 2 and 0 by FUN_00b97280, FUN_00b98890 and
     * FUN_00d25a10 (0xb980a5, 0xb9946f, 0xd25eb7) and 1 by FUN_013a68e0; read
     * only here and in FUN_013a68e0, anew each turn of the wait */
    volatile int state;
    int unknown31efc; /* +0x31efc */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x58];
    View013a6980 *views[6]; /* +0x58: how many not traced */
    u32 current;            /* +0x88 */
};

extern Object05938c40 *D_5938c40;

void FUN_00b91220(View013a6980 *view); /* derived name */

void FUN_013a6980(Object013a6a50 *) /* derived name */
{
    View013a6980 *view = D_5938c40->views[D_5938c40->current];
    view->unknown31efc = 0;
    FUN_00b91220(view);
    view->wait();
}
