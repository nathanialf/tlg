/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING (NOTES Round 64B): the inner sweep, its masks, pairs and counts are the base's;
// left, the outer loop: the base keeps it unrotated (the count's `dec; test; jle` at its head,
// the box advanced before the sweep, `jmp` back from the sweep's end), where LoopRotate rotates
// this one behind a guard.
int FUN_0019f550(const hkAabb16 *boxes, int numBoxes, hkKeyPair *pairsOut, int maxNumPairs,
                 int &numPairsSkippedOut) /* derived name */
{
    numPairsSkippedOut = 0;
    hkKeyPair *pairs = pairsOut;
    hkKeyPair *const pairsEnd = pairsOut + maxNumPairs;
    const hkAabb16 *a = boxes;
    while (--numBoxes > 0) {
        const hkAabb16 *b = a + 1;
        const u16 maxX = a->max[0];
        while (b[0].min[0] <= maxX) {
            const u32 aMin = *reinterpret_cast<const u32 *>(&a->min[1]);
            const u32 aMax = *reinterpret_cast<const u32 *>(&a->max[1]);
            const u32 mask0 = (*reinterpret_cast<const u32 *>(&b[0].max[1]) - aMin) |
                              (aMax - *reinterpret_cast<const u32 *>(&b[0].min[1]));
            const u32 mask1 = ((*reinterpret_cast<const u32 *>(&b[1].max[1]) - aMin) |
                               (aMax - *reinterpret_cast<const u32 *>(&b[1].min[1]))) &
                              0x80008000;
            if ((mask0 & mask1) == 0) {
                if ((mask0 & 0x80008000) == 0) {
                    if (pairs < pairsEnd) {
                        pairs->keyA = a->getKey();
                        pairs->keyB = b[0].getKey();
                        pairs++;
                    } else {
                        numPairsSkippedOut++;
                    }
                }
                if (mask1 == 0 && b[1].min[0] <= maxX) {
                    if (pairs < pairsEnd) {
                        pairs->keyA = a->getKey();
                        pairs->keyB = b[1].getKey();
                        pairs++;
                    } else {
                        numPairsSkippedOut++;
                    }
                }
            }
            b += 2;
        }
        a++;
    }
    return int(pairs - pairsOut);
}
