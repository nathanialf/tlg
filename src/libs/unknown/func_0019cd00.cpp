/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 8 of the vtables at 0x16a6970 and 0x16a6480 adds a
 * pair to the pointer map at +0x40. */
void Object0019c150::FUN_0019cd00(const void *key, const void *value) /* derived name */
{
    map40.FUN_000138a0(hkContainerHeapAllocator::get(), reinterpret_cast<hkUlong>(key),
                       reinterpret_cast<hkUlong>(value));
}
