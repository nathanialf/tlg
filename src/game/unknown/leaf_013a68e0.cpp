/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 5 of the vtable at 0x16d1300 (its pointer at
 * 0x16d1338), one of the vtables whose slot 0 is the destructor of
 * Object013a6a50 (FUN_013a6a50): turns the index at +0x88 of the object the
 * pointer at 0x5938c40 holds to the other of its two views (1 - index), waits
 * while that view's state at +0x31ef8 is neither 0 nor 3 (counting the turns
 * in a volatile local, as FUN_013a6980 does), sets it to 1, hands the view to
 * FUN_00d26810 and then, with the pointer at +0xa8 of the same object, to
 * FUN_00d3b1c0 (a tail call). The object itself is not read. */
class Object013a6a50;     /* derived name */
struct Member05938c40_a8; /* derived name */

struct View013a68e0 { /* derived name */

    /* derived name: spins while the state is neither 0 nor 3, counting the
     * turns in a volatile local (a delay the optimiser must keep) */
    void wait()
    {
        volatile int turns = 0; /* volatile: the turns are the delay, kept in memory */
        if (state != 0) {
            while (state != 3)
                ++turns;
        }
    }

    u8 unknown0[0x31ef8];
    /* +0x31ef8: stored 3, 2 and 0 by FUN_00b97280, FUN_00b98890 and
     * FUN_00d25a10 (0xb980a5, 0xb9946f, 0xd25eb7); read only here and in
     * FUN_013a6980, anew each turn of the wait */
    volatile int state;
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x58];
    View013a68e0 *views[6]; /* +0x58: how many not traced */
    u32 current;            /* +0x88 */
    u8 unknown8c[0x1c];
    Member05938c40_a8 *unknowna8; /* +0xa8 */
};

extern Object05938c40 *D_5938c40;

void FUN_00d26810(View013a68e0 *view);                            /* derived name */
void FUN_00d3b1c0(Member05938c40_a8 *member, View013a68e0 *view); /* derived name */

void FUN_013a68e0(Object013a6a50 *) /* derived name */
{
    Object05938c40 *object = D_5938c40;
    object->current = 1 - object->current;
    View013a68e0 *view = object->views[object->current];
    view->wait();
    view->state = 1;
    FUN_00d26810(view);
    FUN_00d3b1c0(D_5938c40->unknowna8, view);
}
