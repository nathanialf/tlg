/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void FUN_0019f110(const hkClass *klass, PointerMap *visited, int mark,
                  MemberCallback0019f110 callback) /* derived name */
{
    const int marks = int(visited->FUN_00013b30(hkUlong(klass), 0));
    if (marks & mark) {
        return;
    }
    visited->FUN_000138a0(hkContainerHeapAllocator::get(), hkUlong(klass), marks | mark);
    for (int i = 0; i < klass->FUN_00004440(); i++) {
        const hkClassMember &member = klass->FUN_00004450(i);
        const hkClass *memberClass = FUN_00004250(&member);
        if (memberClass) {
            FUN_0019f110(memberClass, visited, mark, callback);
        }
        callback(member);
    }
    if (FUN_00004250(klass)) {
        FUN_0019f110(FUN_00004250(klass), visited, mark, callback);
    }
}
