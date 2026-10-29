/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void FUN_0019f270(const hkClass *const *classes, int classVersion) /* derived name */
{
    PointerMap done;
    for (const hkClass *const *klass = classes; *klass; klass++) {
        FUN_0019eee0(*klass, done, classVersion);
    }
    done.FUN_00013db0(hkContainerHeapAllocator::get());
    FUN_0000e5c0(&done);
}
