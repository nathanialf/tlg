/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 5 of hkTypeInfoRegistry's vtable (address point
 * 0x16a60c0): registers a type info under its type name. */
void hkTypeInfoRegistry::FUN_0017d8b0(const hkTypeInfo *info) /* derived name */
{
    map.FUN_00091690(info->typeName, reinterpret_cast<hkUlong>(info));
}
