/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 10 of the world's object at +0x380: each record's first
 * pointer set from the matching entry of the second array. */
void hknpWorldObject380::FUN_000311b0(hknpWorldObject380Record **records, void *const *pointers,
                                      int count) /* derived name */
{
    for (int i = 0; i < count; i++) {
        hknpWorldObject380Record *record = records[i];
        record->pointer0 = pointers[i];
    }
}
