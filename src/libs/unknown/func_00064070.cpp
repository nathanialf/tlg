/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpWorldObject4f8::FUN_00064070(const hkArray<int> &ids)
{
    const int num = ids.size;
    for (int i = 0; i < num; i++) {
        FUN_00063a40(ids[i]);
    }
}
