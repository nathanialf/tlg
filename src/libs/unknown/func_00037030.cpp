/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_freelist.h"
#include "tlg_lib_unknown.h"

/* derived name: whether two properties hold the same sixteen words. */
static inline bool sameWords(const hknpMotionProperties &a, const hknpMotionProperties &b)
{
    const u32 *wordsA = reinterpret_cast<const u32 *>(&a);
    const u32 *wordsB = reinterpret_cast<const u32 *>(&b);
    for (int j = 0; j < 16; j++) {
        if (wordsA[j] != wordsB[j]) {
            return false;
        }
    }
    return true;
}

/* derived name: the entry equal to the properties, -1 when none is. */
static inline int findEntry(const hkArray<hknpMotionProperties> &elements,
                            const hknpMotionProperties &properties)
{
    for (int i = 0; i < elements.getSize(); i++) {
        if (sameWords(elements[i], properties)) {
            return i;
        }
    }
    return -1;
}

// NONMATCHING: 65 of 165, size 598 against 599: every instruction equal but for two live
// ranges in each other's callee-saved registers: the id (the search's index, firstFree, the
// id fired and returned) in r12 where the base has r14, the added signal's address (and the
// grow loop's counter) in r14 where the base has r12; greedy assigns the signal's range
// (vreg34) R14 freed by `this` (vreg44) before the id (vreg102) is placed (debug llc
// -debug-only=regalloc, a79/37.ra.txt); the search written inline or through a helper
// compiles the same. NOTES Round 79A.
hknpMotionPropertiesId
hknpMotionPropertiesLibrary::FUN_00037030(const hknpMotionProperties &properties)
{
    if (!properties.isExclusive) {
        const int index = findEntry(entries.elements, properties);
        if (index != -1) {
            hknpMotionPropertiesId id;
            id.value = u16(index);
            return id;
        }
    }
    const hknpMotionPropertiesId id = entries.allocate(properties);
    entryAddedSignal.fire(id);
    return id;
}
