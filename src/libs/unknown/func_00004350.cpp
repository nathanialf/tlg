/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the number of members of a class, its own and its
 * parents'. */
int hkClass::FUN_00004350() const
{
    int count = numDeclaredMembers;
    for (const hkClass *c = parent; c; c = c->parent) {
        count += c->numDeclaredMembers;
    }
    return count;
}
