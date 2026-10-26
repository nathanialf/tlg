/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the class test "hasRootLevelContainer" (built at 0x17de70):
 * passes when the object's class is the root level container. */
bool FUN_0017de40(const void *object, const hkClass *klass) /* derived name */
{
    return FUN_00017f40(klass->FUN_00004200(), "hkRootLevelContainer") == 0;
}

/* The test's registration, a file-local record its static initializer
 * (0x17de70, `_GLOBAL__I_a`) constructs on the tests' list: id 20, the
 * test's name, the test. Nothing changes it once registered: a const
 * object, for which clang marks the storage invariant after the
 * constructor (`llvm.invariant.start`), and the constructor's call is then
 * not the last thing before the return (no tail call). */
static const ClassTest D_57c8848(20, "hasRootLevelContainer", FUN_0017de40);
