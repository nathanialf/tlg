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
/* derived name: the member at an index for a class being edited: the
 * const lookup above, inline. */
hkClassMember &hkClass::FUN_000043d0(int index)
{
    return const_cast<hkClassMember &>(FUN_00004370(index));
}

/* A zero default, as large as any member's (64 bytes at 0x14b2b50, after
 * the reflection strings): the value written for a member whose default
 * offset is -2. derived name. */
static const Vec4 D_14b2b50[4] = {};

/* derived name: a member's default written to a stream. The index is made
 * local to the class that declares the member as the lookup above makes
 * it; the class's defaults are an offset per member from the defaults
 * themselves. */
hkResult hkClass::FUN_00004940(int memberIndex, hkStreamWriter *writer) const
{
    int localIndex = memberIndex - FUN_00004350();
    const hkClass *c = this;
    if (!c) {
        return HK_FAILURE;
    }
    localIndex += c->numDeclaredMembers;
    while (localIndex < 0) {
        c = c->parent;
        if (!c) {
            return HK_FAILURE;
        }
        localIndex += c->numDeclaredMembers;
    }
    const int *defaultOffsets = static_cast<const int *>(c->defaults);
    if (defaultOffsets) {
        const int offset = defaultOffsets[localIndex];
        if (offset >= 0 || offset == -2) {
            const void *value = offset == -2
                                    ? static_cast<const void *>(D_14b2b50)
                                    : reinterpret_cast<const char *>(defaultOffsets) + offset;
            writer->write(value, c->declaredMembers[localIndex].FUN_00007d60());
            return HK_SUCCESS;
        }
    }
    return HK_FAILURE;
}
