/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: the vector loop and the scalar loop's guard are the base's,
// but LSR gives the scalar loop two pointer IVs and a 32-bit counter where
// the base indexes both arrays from one 64-bit IV whose low half is compared
// (`inc rsi; cmp esi, ecx`); the size the loop rereads leaves no trip count,
// so the compare's 32-bit recurrence does not extend to the widened IV
// (docs/NOTES.md, Round 54).
void FUN_00066080(const Object00065f20 *self, hkBitField &bitsOut) /* derived name */
{
    bitsOut.FUN_00047b30(0, self->records[0].bits.storage.numBits, 0);
    for (int i = 0; i < self->numRecords; i++) {
        bitsOut.orWith(self->records[i].bits);
    }
}
