/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The pair index of every two cells (derived name): entry [b][a] for the
 * cells a - 1 and b - 1, 0 meaning no cell (a missing cell paired with the
 * other one itself, none with none 0xff); read by the collide steps
 * (0x76f3c, 0x15cd73). External in the base: its readers' GOT loads are
 * relaxed to `lea`s. */
extern u8 D_57c1660[17][17];

/* The index of a pair of cells, the larger first (derived name). */
static inline u32 cellPairIndex(u32 hi, u32 lo)
{
    return (u16(hi + 1) * hi) / 2 + lo;
}

// NONMATCHING: classified with D21's unswitch shape (docs/NOTES.md "Round
// 64A"): the base holds two copies of the inner loop, one for a == 0, the
// general copy keeping the dead (a | b) == 0 test and tri(a - 1) inside the
// loop, which is LoopUnswitch's non-trivial unswitch of this loop (3.3 does
// it at -O3 only, LoopUnswitch.cpp:651); u16(hi + 1) is held as
// `shl 16; add 0x10000; shr 16`, the form of a 16-bit bitfield read, also
// at 0x18e820.
hknpSpaceSplitter::hknpSpaceSplitter(int type) : type(type)
{
    for (int a = 0; a < 17; a++) {
        for (int b = 0; b < 17; b++) {
            if (a == 0 && b == 0) {
                D_57c1660[b][a] = 0xff;
                continue;
            }
            int cellA = a - 1;
            int cellB = b - 1;
            if (a == 0) {
                cellA = cellB;
            }
            if (b == 0) {
                cellB = cellA;
            }
            if (cellA > cellB) {
                D_57c1660[b][a] = u8(cellPairIndex(cellA, cellB));
            } else {
                D_57c1660[b][a] = u8(cellPairIndex(cellB, cellA));
            }
        }
    }
}
