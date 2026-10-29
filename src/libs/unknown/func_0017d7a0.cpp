/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 8 of hkTypeInfoRegistry's vtable (address point
 * 0x16a60c0): each entry of the other registry's map set in this one. */
void hkTypeInfoRegistry::FUN_0017d7a0(const hkTypeInfoRegistry *other) /* derived name */
{
    const StringMap &otherMap = other->map;
    for (StringMap::Iterator it = otherMap.FUN_00091600(); otherMap.FUN_00013890(it);
         it = otherMap.FUN_00091650(it)) {
        map.FUN_00091690(otherMap.FUN_00091630(it), otherMap.FUN_00091640(it));
    }
}
