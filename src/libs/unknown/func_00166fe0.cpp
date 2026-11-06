/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the entry emptied, then the run it sat in closed up: each
 * later entry of the run whose home slot is not between the run's start
 * and its own slot moves into the hole, which moves to it. */
void hknpPairCollisionFilterMapPairFilterKeyOverrideType::FUN_00166fe0(hkUlong it)
{
    u32 i = u32(it);
    numElems -= 1;
    invalidateKey(elem[i].key);

    u32 lo = (i + hashMod) & hashMod;
    while (!isEmptyKey(elem[lo].key)) {
        lo = (lo + hashMod) & hashMod;
    }
    lo = (lo + 1) & hashMod;

    u32 empty = i;
    for (i = (i + 1) & hashMod; !isEmptyKey(elem[i].key); i = (i + 1) & hashMod) {
        const u32 home = u32(hash(elem[i].key, hashMod));
        if (i >= lo && home > empty) {
            continue;
        } else if (i < empty && (home > empty || home <= i)) {
            continue;
        } else if (home > empty && home < lo) {
            continue;
        }
        elem[empty].key = elem[i].key;
        elem[empty].value = elem[i].value;
        invalidateKey(elem[i].key);
        empty = i;
    }
}
