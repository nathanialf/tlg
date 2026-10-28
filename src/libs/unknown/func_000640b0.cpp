/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: each id's entry looked for among the pointers, the first
 * found ending the search. */
bool hknpWorldObject4f8::FUN_000640b0(const hkArray<int> &ids) const
{
    for (int i = 0; i < ids.getSize(); i++) {
        int k = 0;
        while (k < unknown58.getSize()) {
            if (unknown58[k++] == unknown18[ids[i]]) {
                return true;
            }
        }
    }
    return false;
}
