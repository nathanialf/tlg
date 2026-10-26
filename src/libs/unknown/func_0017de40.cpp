/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the class test "hasRootLevelContainer" (built at 0x17de70):
 * passes when the object's class is the root level container. */
bool FUN_0017de40(const void *object, const hkClass *klass) /* derived name */
{
    return FUN_00017f40(klass->FUN_00004200(), "hkRootLevelContainer") == 0;
}
