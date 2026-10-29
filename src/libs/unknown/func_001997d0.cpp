/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: the loops' shapes are the base's; left are the iterator's
// validity compares, (hashMod, it) here and (it, hashMod) in the base
// (InstCombine orders the inline isValid's compare of its argument against
// the loaded mask by complexity before it is inlined), and the next slot's
// key load, folded here (docs/NOTES.md, Round 55).
void BitFieldMap00199770::FUN_001997d0(int bitIndex)
{
    for (int it = fields.getIterator(); fields.isValid(it); it = fields.getNext(it)) {
        hkBitField &bits = reinterpret_cast<Block *>(fields.getValue(it))->bits;
        if (u32(bitIndex) < u32(bits.storage.numBits)) {
            bits.clear(bitIndex);
        }
    }
}
