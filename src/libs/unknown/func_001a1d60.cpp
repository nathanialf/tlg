/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: an array of pointer-sized values written in the target's
 * pointer size (0x1a0b40 passes its layout's, 0x1a2030 too): as they are for
 * eight bytes, else each narrowed to 32 bits in a buffer on the thread's
 * stack first. */
// NONMATCHING (NOTES Round 64B): the base calls the archive's array write out of line (0xa520,
// twice, the first a tail jump); the header defines writeArrayGeneric inline in the class, so
// this file inlines it. The fix is the archive's (its write out of line, inline only in its own
// file, 0xa7a0), which round 62A's hkOArchive rename holds.
void FUN_001a1d60(hkOArchive &archive, int pointerSize, int numValues,
                  const hkUlong *values) /* derived name */
{
    if (pointerSize == 8) {
        archive.writeArrayGeneric(values, 8, numValues);
        return;
    }
    LocalBuffer<u32> narrowed(numValues);
    for (int i = 0; i < numValues; i++) {
        narrowed.data[i] = u32(values[i]);
    }
    archive.writeArrayGeneric(narrowed.data, pointerSize, numValues);
}
