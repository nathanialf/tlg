/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkClass *ClassCopies0019a880::FUN_0019a880(const hkClass *klass, const Layout00180ef0 &layout)
{
    hkClass *copy;
    if (copies.get(klass, &copy) == HK_SUCCESS) {
        return copy;
    }
    copy = static_cast<hkClass *>(FUN_0019b2b0(klass, D_57b77f0, &copies, HK_NULL, HK_NULL, 0));
    allCopies.pushBack(copy);
    layout.FUN_00180f00(*copy, classesDone, 1);
    return copy;
}
