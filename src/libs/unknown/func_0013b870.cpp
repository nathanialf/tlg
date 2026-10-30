/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_types.h"

/* A key and the index of what it was taken from, ordered by the key as an
 * unsigned word: 0x13d530 and 0x13db00 build them (the latter from a
 * 144-byte record's word at +0x6c, its top three bits cleared, skipping
 * -1) and sort them with the instantiation below (0x13d797, 0x13dbe3).
 * The same code as 0x13b6c0's sort, a second instantiation. derived
 * names. */
struct KeyIndex0013b870 /* derived name */
{
    u32 key;
    int index;

    bool operator<(const KeyIndex0013b870 &other) const
    {
        return key < other.key;
    }
};

template void
hkAlgorithm::quickSortRecursive<KeyIndex0013b870, hkAlgorithm::less<KeyIndex0013b870>>(
    KeyIndex0013b870 *, int, int, hkAlgorithm::less<KeyIndex0013b870>);
