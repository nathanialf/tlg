/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 15 of 69, 211 bytes against 214: Havok's loop (the bits test
// and the index test in the for condition) gives the base's unrotated outer
// loop, the entry's jump to the bits test and the push; left: the scan keeps
// the bits test in its header (SimplifyCFG joins it with the index test into
// one `and`, both exits carrying the same bits, so LoopUnswitch finds no
// trivial condition), where the base tests the bits once outside the scan
// and lands their zero exit on a block of its own (docs/NOTES.md, Round 70A).
hkResult hkClassEnum::FUN_00014ce0(int flagValue, hkArray<const char *> &bitsOut,
                                   int &bitsOver) const /* derived name */
{
    bitsOut.clear();
    int bits = flagValue;
    for (int i = numItems - 1; (bits != 0) && (i >= 0); --i) {
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
