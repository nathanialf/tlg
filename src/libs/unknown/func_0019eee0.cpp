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

/* hkClass's own class as version 1 described it, built by this file's
 * static initializer (0x19f788): its members name the fields fixed below.
 * derived name. */
extern const hkClass D_57c8a20; /* derived name */

/* derived name: once per class (flag 1 in the done map), then its parent
 * the same way (the tail call a loop): each class but the root loses the field version 1
 * called hasVtable, the root counts one more implemented interface when it
 * had it and loses it too; then the classes the declared members hold,
 * recursively. */
// NONMATCHING: 0x19efc0, 17 of 93: the parent's tail call becomes the loop
// (TailCallElim), which LoopRotate then rotates here, the map lookup
// duplicated into the latch; the base keeps the loop unrotated (the entry
// jumps to the lookup, the second parent call at the loop's top). Everything
// inside the loop is the base's (docs/NOTES.md, Round 66A).
void FUN_0019efc0(const hkClass *klass, PointerMap &done)
{
    const int flags = int(done.FUN_00013b30(hkUlong(klass), 0));
    if (flags & 1) {
        return;
    }
    done.FUN_000138a0(hkContainerHeapAllocator::get(), hkUlong(klass), hkUlong(flags | 1));
    const int hasVtable = D_57c8a20.FUN_00004470("hasVtable")->offset;
    const hkClass *c = klass;
    while (FUN_00004250(c)) {
        *reinterpret_cast<void **>(reinterpret_cast<hkUlong>(c) + hasVtable) = HK_NULL;
        c = FUN_00004250(c);
    }
    void **field = reinterpret_cast<void **>(reinterpret_cast<hkUlong>(c) + hasVtable);
    if (*reinterpret_cast<const hkBool *>(field)) {
        const int numInterfaces = D_57c8a20.FUN_00004470("numImplementedInterfaces")->offset;
        (*reinterpret_cast<int *>(reinterpret_cast<hkUlong>(c) + numInterfaces))++;
    }
    *field = HK_NULL;
    for (int i = 0; i < klass->FUN_00004440(); i++) {
        hkClassMember *member = const_cast<hkClass *>(klass)->FUN_00004450(i);
        if (member->structClass) {
            FUN_0019efc0(FUN_00004250(member), done);
        }
    }
    if (FUN_00004250(klass)) {
        FUN_0019efc0(FUN_00004250(klass), done);
    }
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
