/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 5 of hkVtableClassRegistry's vtable (address point
 * 0x16a6580) registers the class of a vtable. */
void hkVtableClassRegistry::FUN_00184520(const void *vtable,
                                         const hkClass *klass) /* derived name */
{
    map.FUN_000138a0(hkContainerHeapAllocator::get(), reinterpret_cast<hkUlong>(vtable),
                     reinterpret_cast<hkUlong>(klass));
}
