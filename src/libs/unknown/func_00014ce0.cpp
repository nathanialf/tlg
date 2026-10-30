/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: equal but for the outer loop's shape (NOTES Round 64B). The name pushed
// before the bits are cleared, the mask computed before the push, gives the base's frame and
// its `not` before the capacity test with the `and` after the push. Left: the base's outer
// loop is unrotated (the numItems load in the entry, one bits test shared by the entry and the
// push, its zero on a split edge); here the inner scan's bits test is hoisted by LICM and
// trivially unswitched into the outer header before the outer loop is visited, which LoopRotate
// then rotates with a guard.
hkResult hkClassEnum::FUN_00014ce0(int flagValue, hkArray<const char *> &bitsOut,
                                   int &bitsOver) const /* derived name */
{
    bitsOut.clear();
    int bits = flagValue;
    int i = numItems;
    while (bits && i-- > 0) {
        const Item &item = items[i];
        int value = item.getValue();
        if ((value & bits) == value) {
            int mask = ~value;
            bitsOut.pushBack(item.getName());
            bits &= mask;
        }
    }
    bitsOver = bits;
    return bits == 0 ? HK_SUCCESS : HK_FAILURE;
}
