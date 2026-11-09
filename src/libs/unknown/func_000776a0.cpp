/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_freelist.h"
#include "tlg_lib_unknown.h"

/* A shared material equal to one in the library, name and values, is that one, marked shared; a
 * material whose name is in use is refused; otherwise a copy goes in the first free entry and the
 * added signal fires with its id. */
// NONMATCHING: two known classes. The inline-cost margin: the base inlines the entries' allocate
// (the growth with it), priced 395 against 393 here (`-debug-only=inline`); 620 bytes against 924.
// Inlined for a diagnostic (-inline-threshold=400): 901 bytes, 100 lines apart, the first search
// equal but for `this` in r13 (r14 in the base); the name search is one loop here and two in the
// base, chosen by the name's null test before it (D21's unswitch shape: the null name's loop
// tests only `entry.name < 2`, the other holds `name ? -1 : 0` hoisted in r12d).
hknpMaterialId hknpMaterialLibrary::FUN_000776a0(const hknpMaterial &material)
{
    hknpMaterial newMaterial(material);
    newMaterial.FUN_0006c740();

    if (!newMaterial.isExclusive) {
        int index = -1;
        const int numEntries = entries.elements.getSize();
        for (int i = 0; i < numEntries; i++) {
            const hknpMaterial &entry = entries.elements[i];
            if (compareStrings(entry.name.cString(), newMaterial.name.cString()) == 0 &&
                FUN_00018180(&entry.isExclusive, &newMaterial.isExclusive,
                             HK_OFFSET_OF(hknpMaterial, isShared) -
                                 HK_OFFSET_OF(hknpMaterial, isExclusive)) == 0) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            const hknpMaterialId id(index);
            entries[id].isShared = true;
            return id;
        }
    }

    if (material.name.FUN_0000e770() > 0) {
        const char *name = material.name.cString();
        hknpMaterialId existing(0xffff);
        for (int i = 0; i < entries.elements.getSize(); i++) {
            const hknpMaterialId id(i);
            const hknpMaterial &entry = entries[id];
            if (!hknpMaterialFreeListArrayOperations::isEmpty(entry) &&
                compareStrings(entry.name.cString(), name) == 0) {
                existing = id;
                break;
            }
        }
        if (existing.value != 0xffff) {
            return hknpMaterialId(0xffff);
        }
    }

    const hknpMaterialId id = entries.allocate(newMaterial);
    materialAddedSignal.fire(id);
    return id;
}
