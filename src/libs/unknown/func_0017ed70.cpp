/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 9 of the dynamic class name registry's and
 * hkDefaultClassNameRegistry's vtables (address points 0x16a6200 and
 * 0x16a6180): the class is registered under the name, or under its own. */
void hkDynamicClassNameRegistry::FUN_0017ed70(const hkClass *klass, const char *className)
{
    if (!className) {
        className = klass->FUN_00004200();
    }
    map.FUN_00091690(className, reinterpret_cast<hkUlong>(klass));
}
