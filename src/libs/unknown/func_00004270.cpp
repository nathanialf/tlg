/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the list walked for an entry naming the class. */
bool hkClass::FUN_00004270(const NameList00004270 *list) const
{
    for (const NameList00004270 *entry = list; entry; entry = entry->next) {
        if (FUN_00017f40(entry->name, name) == 0) {
            return true;
        }
    }
    return false;
}
