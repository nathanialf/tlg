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

/* derived name: the member at an index counted over the parents' members
 * first, then the class's own; the class's first member when the index
 * is past them all. The count above is inline here, one file. */
const hkClassMember &hkClass::FUN_00004370(int index) const
{
    int localIndex = index - FUN_00004350();
    for (const hkClass *c = this; c; c = c->parent) {
        localIndex += c->numDeclaredMembers;
        if (localIndex >= 0) {
            return c->declaredMembers[localIndex];
        }
    }
    return declaredMembers[0];
}
