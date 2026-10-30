/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The class's own fix of version 1, once (flag 4 in the done map):
 * hkpConstraintInstance's third member a struct by its subtype. derived
 * name. */
static void fixClassVersion1(const hkClass *klass, PointerMap &done)
{
    const int flags = int(done.FUN_00013b30(hkUlong(klass), 0));
    if (flags & 4) {
        return;
    }
    done.FUN_000138a0(hkContainerHeapAllocator::get(), hkUlong(klass), hkUlong(flags | 4));
    if (FUN_00017f40(klass->FUN_00004200(), "hkpConstraintInstance") != 0) {
        return;
    }
    hkClassMember *member = const_cast<hkClass *>(klass)->FUN_00004450(2);
    const hkClassMember &subtype = D_57b7d18.FUN_00004370(4);
    reinterpret_cast<char *>(member)[subtype.offset] = hkClassMember::TYPE_STRUCT;
}

/* derived name: from version 1, the class's own fixes; then the members'
 * fixes of versions to 3 and to 4. */
void FUN_0019eee0(const hkClass *klass, PointerMap &done, int classVersion)
{
    if (classVersion == 1) {
        FUN_0019efc0(klass, done);
        fixClassVersion1(klass, done);
    }
    if (classVersion <= 3) {
        FUN_0019f110(klass, done, 2, FUN_0019f1f0);
    }
    if (classVersion <= 4) {
        FUN_0019f110(klass, done, 8, FUN_0019f210);
    }
}
