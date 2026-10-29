/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Object0019c150::FUN_0019cc80(const void *key, const void *value) /* derived name */
{
    const int index = int(map20.FUN_00013b30(reinterpret_cast<hkUlong>(key), hkUlong(-1)));
    if (index >= 0) {
        array10.data[index].index20 = -2;
    }
    map20.FUN_000138a0(hkContainerHeapAllocator::get(), reinterpret_cast<hkUlong>(key),
                       hkUlong(-2));
    map30.FUN_000138a0(hkContainerHeapAllocator::get(), reinterpret_cast<hkUlong>(key),
                       reinterpret_cast<hkUlong>(value));
}
