/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: equal under D42's compiler; claimed when the patch lands (round
// 94A: the index tested before the bits, so the bits test does not dominate the
// exit and EarlyCSE leaves the return its own compare; the scan's invariant bits
// test is unswitched out of it). Under the live compiler 15 of 69, 211 bytes.
hkResult hkClassEnum::FUN_00014ce0(int flagValue, hkArray<const char *> &bitsOut,
                                   int &bitsOver) const /* derived name */
{
    bitsOut.clear();
    int bits = flagValue;
    for (int i = numItems - 1; (i >= 0) && (bits != 0); --i) {
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
