/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived name: the third array's pointers given to the owner and the
 * array emptied, then each entry of the first array reset. */
void RefArrays::FUN_00092e70(RefArraysOwner *owner)
{
    owner->unknownVirtual9(array30.data, array30.size);
    array30.size = 0;
    for (int i = 0; i < array10.size; i++) {
        array10.data[i].unknownC = 0xffff;
        array10.data[i].unknownE = 0;
    }
}
