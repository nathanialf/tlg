/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The cell pairs put in batches: each batch holds at most half as many
 * pairs as there are cells and no cell twice (a bit per batch and cell);
 * each pair goes to the first batch with room where both its cells are
 * free, else to the last batch with room, and the pairs are written batch
 * after batch, each batch's room apart. */
// NONMATCHING (D21's unswitch shape, reported, not worked): the base holds two copies of the
// pairs' walk split on the invariant `numCells >= 0`, the inner walk over the batches present
// only in the first (0x607b1 `js 0x60910`; the second, 0x60910 to 0x6097d, places every pair
// in batch -1's slot). The guard is the inner loop's, not a loop exit, so 3.3's LoopUnswitch
// takes it as non-trivial and refuses it in a pass built for size (LoopUnswitch.cpp:651,
// PassManagerBuilder.cpp:189), as for 0x605b0's constructor in the same region. The first
// copy's blocks follow this walk (the probes, the placing, the fallback to the last batch with
// room); not compared further.
void FUN_000606d0(int numCells, int numPairs, const CellPair00060a10 *pairs, u16 *pairsOut)
{
    const int numBatches = numCells + 1;
    hkBitField used;
    used.FUN_00047b30(0, numBatches * numCells, 0);
    const int maxPairsPerBatch = numCells / 2;
    hkArray<int> numPairsInBatch;
    numPairsInBatch.setSize(numBatches);
    for (int i = 0; i < numPairsInBatch.getSize(); i++) {
        numPairsInBatch[i] = 0;
    }

    for (int p = 0; p < numPairs; p++) {
        const CellPair00060a10 &pair = pairs[p];
        int batch = -1;
        int batchStart = 0;
        for (int b = 0; b < numBatches; b++) {
            const int count = numPairsInBatch[b];
            if (count < maxPairsPerBatch) {
                const int bitA = b * numCells + pair.offset;
                if (!used.get(bitA)) {
                    const int bitB = b * numCells + pair.cell;
                    if (!used.get(bitB)) {
                        pairsOut[batchStart + count] = *reinterpret_cast<const u16 *>(&pair);
                        numPairsInBatch[b]++;
                        used.set(bitA);
                        used.set(bitB);
                        goto placed;
                    }
                }
                batch = b;
            }
            batchStart += maxPairsPerBatch;
        }
        pairsOut[batch * maxPairsPerBatch + numPairsInBatch[batch]] =
            *reinterpret_cast<const u16 *>(&pair);
        numPairsInBatch[batch]++;
        used.set(batch * numCells + pair.offset);
        used.set(batch * numCells + pair.cell);
    placed:;
    }
}
