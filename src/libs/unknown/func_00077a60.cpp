/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: greedy's allocation order only: the base gives the entries'
// data pointer (loaded in the entry and again in the update) rbx and the
// index (id * 0x50) r13; this compile allocates the index first (the longer
// live range, neither has a hint, RAGreedy::enqueue) and gives it rbx, the
// data pointers r13. Every instruction is the base's otherwise (round 77A).
void hknpMaterialLibrary::FUN_00077a60(hknpMaterialId id, const hknpMaterial &material)
{
    hknpMaterial newMaterial(material);
    newMaterial.FUN_0006c740();
    const hknpMaterial &entry = entries[id];
    const bool equal = compareStrings(entry.name.cString(), newMaterial.name.cString()) == 0 &&
                       FUN_00018180(&entry.isExclusive, &newMaterial.isExclusive,
                                    HK_OFFSET_OF(hknpMaterial, isShared) -
                                        HK_OFFSET_OF(hknpMaterial, isExclusive)) == 0;
    if (equal) {
        return;
    }
    entries[id] = newMaterial;
    materialModifiedSignal.fire(id);
}
