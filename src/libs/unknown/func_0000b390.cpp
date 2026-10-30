/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 69 of 78: the key's sign extension: the base extends it in
// each branch (`movsxd rsi` before 0x13d10, `movsxd rdx` before 0x138a0)
// and keeps the id in r15 and the flag in r12; here SimplifyCFG's
// HoistThenElseCodeToIf hoists the identical sext above the branch (one
// `movsxd rdx` after the lock) and the two registers swap (docs/NOTES.md,
// Round 62A).
void Object0000b330::FUN_0000b390(int id, bool enabled)
{
    criticalSection.enter();
    if (enabled) {
        map.FUN_00013d10(hkUlong(id));
    } else {
        map.FUN_000138a0(hkContainerHeapAllocator::get(), hkUlong(id), 1);
    }
    criticalSection.leave();
}
