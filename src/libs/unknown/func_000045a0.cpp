/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: whether a class has a vtable, which its root class tells:
 * the root implements an interface (FUN_0019b2b0 and FUN_0019c3c0 ask it of
 * a member's class). */
bool FUN_000045a0(const hkClass *self) /* derived name */
{
    const hkClass *c = self;
    while (c->parent) {
        c = c->parent;
    }
    return c->numImplementedInterfaces != 0;
}
