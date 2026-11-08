/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: 37 of 139 (498 bytes against 518; round 79A's reading): the base keeps the
// copy's address in r14 from the entry to the destructor's call (0x77a85 to 0x77c39, the name's
// assignment at 0x77b04 included) and spills the signal's address (+0x18) to the frame, where
// this compile rematerializes the copy's `lea` at each use and keeps the signal's address in a
// register: the base's address is a value greedy does not rematerialize. Round 77A's reading
// (the index and the data pointer's order) holds for rbx and r13.
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
