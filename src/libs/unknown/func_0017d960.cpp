/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 9 of hkTypeInfoRegistry's vtable (address point
 * 0x16a60c0) returns the type info registered under a name, or null. */
const hkTypeInfo *hkTypeInfoRegistry::FUN_0017d960(const char *typeName) const /* derived name */
{
    return reinterpret_cast<const hkTypeInfo *>(map.FUN_00091900(typeName, 0));
}
