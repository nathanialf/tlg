/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hkTypeInfoRegistry's vtable (address point
 * 0x16a60c0): the type info registered under the name runs its finish
 * callback on the object with the registry's flag. */
const hkTypeInfo *hkTypeInfoRegistry::FUN_0017d8d0(void *object, const char *typeName) const
{
    const hkTypeInfo *typeInfo =
        reinterpret_cast<const hkTypeInfo *>(map.FUN_00091900(typeName, 0));
    if (typeInfo) {
        typeInfo->FUN_00092f90(object, finishFlag);
        return typeInfo;
    }
    return 0;
}
