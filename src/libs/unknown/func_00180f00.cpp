/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: a class's member offsets computed in place under this
 * layout's rules, unless the map of classes done already holds it. */
void Layout00180ef0::FUN_00180f00(hkClass &klass, PointerMap &classesDone, int recurse) const
{
    if (!classesDone.isValid(classesDone.FUN_00013ad0(reinterpret_cast<hkUlong>(&klass)))) {
        FUN_00180f50(klass, rules, classesDone, recurse);
    }
}
