/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: the base keeps `not v` in the match block before the capacity test and `and`
// after the push (no andn), and leaves the loop through a separate bits test whose exit
// stores a constant 0; this compile forms andn (sunk after the push) and folds the two loop
// conditions into one branch (NOTES Round 61B).
hkResult hkClassEnum::FUN_00014ce0(int flagValue, hkArray<const char *> &bitsOut,
                                   int &bitsOver) const /* derived name */
{
    bitsOut.clear();
    int bits = flagValue;
    for (int i = numItems - 1; bits && i >= 0; i--) {
        const Item &item = items[i];
        if ((item.getValue() & bits) == item.getValue()) {
            bits &= ~item.getValue();
            bitsOut.pushBack(item.getName());
        }
    }
    bitsOver = bits;
    return bits ? HK_FAILURE : HK_SUCCESS;
}
