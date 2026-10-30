/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpWorldObject4f8::FUN_000656e0(int indexA, int indexB)
{
    const int firstB = unknown18[indexB]->firstId; /* derived name */
    const int firstA = unknown18[indexA]->firstId; /* derived name */
    if (firstA != firstB) {
        Entry18 *last; /* derived name */
        int id = firstA;
        do {
            last = unknown18[id];
            id = last->nextId;
        } while (id != 0x7fffffff);
        last->nextId = firstB;

        setGroupFirstId(firstB, firstA);
    }
    if (unknown18[indexA]->flag61 || unknown18[indexB]->flag61) {
        activateGroup(unknown18[indexA]);
    }
}
