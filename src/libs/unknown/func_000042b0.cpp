/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the number of implemented interfaces of a class, its own and its
 * parents'. */
int hkClass::FUN_000042b0() const
{
    int count = numImplementedInterfaces;
    for (const hkClass *c = parent; c; c = c->parent) {
        count += c->numImplementedInterfaces;
    }
    return count;
}
