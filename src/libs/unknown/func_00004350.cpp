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

/* derived name: the same lookup written from the class's own members out:
 * the index made local to the class, then the parents walked, each count
 * added until it is not negative. */
// NONMATCHING: the base tests `this` for null after the count loop (`test
// rdi, rdi; je` to the first-member fallback, on the path where the class
// has a parent) and places the parents' walk before the hit; this form has
// no such test. Equal in size (102 bytes) and in every other instruction.
const hkClassMember &hkClass::FUN_000043d0(int index) const
{
    int localIndex = index - FUN_00004350();
    const hkClass *c = this;
    localIndex += numDeclaredMembers;
    while (localIndex < 0) {
        c = c->parent;
        if (!c) {
            return declaredMembers[0];
        }
        localIndex += c->numDeclaredMembers;
    }
    return c->declaredMembers[localIndex];
}
