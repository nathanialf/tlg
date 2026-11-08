/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int FUN_0019f310(const hkAabb16 *boxesA, int numBoxesA, const hkAabb16 *boxesB, int numBoxesB,
                 hkKeyPair *pairsOut, int maxNumPairs, int &numPairsSkippedOut) /* derived name */
{
    numPairsSkippedOut = 0;
    hkKeyPair *pairs = pairsOut;
    hkKeyPair *const pairsEnd = pairsOut + maxNumPairs;
    const hkAabb16 *a = boxesA;
    const hkAabb16 *b = boxesB;
    for (;;) {
        if (b->min[0] < a->min[0]) {
            /* b starts first: the boxes of the first run that start before
             * it ends. */
            const u16 maxX = b->max[0];
            const hkAabb16 *other = a;
            while (other[0].min[0] <= maxX) {
                const u32 bMin = *reinterpret_cast<const u32 *>(&b->min[1]);
                const u32 bMax = *reinterpret_cast<const u32 *>(&b->max[1]);
                const u32 mask0 = (bMax - *reinterpret_cast<const u32 *>(&other[0].min[1])) |
                                  (*reinterpret_cast<const u32 *>(&other[0].max[1]) - bMin);
                const u32 mask1 = ((bMax - *reinterpret_cast<const u32 *>(&other[1].min[1])) |
                                   (*reinterpret_cast<const u32 *>(&other[1].max[1]) - bMin)) &
                                  0x80008000;
                if ((mask0 & mask1) == 0) {
                    if ((mask0 & 0x80008000) == 0) {
                        if (pairs < pairsEnd) {
                            pairs->keyA = other[0].getKey();
                            pairs->keyB = b->getKey();
                            pairs++;
                        } else {
                            numPairsSkippedOut++;
                        }
                    }
                    if (mask1 == 0 && other[1].min[0] <= maxX) {
                        if (pairs < pairsEnd) {
                            pairs->keyA = other[1].getKey();
                            pairs->keyB = b->getKey();
                            pairs++;
                        } else {
                            numPairsSkippedOut++;
                        }
                    }
                }
                other += 2;
            }
            b++;
            if (--numBoxesB <= 0) {
                break;
            }
        } else {
            /* a starts first: the boxes of the second run that start before
             * it ends. */
            const u16 maxX = a->max[0];
            const hkAabb16 *other = b;
            while (other[0].min[0] <= maxX) {
                const u32 aMin = *reinterpret_cast<const u32 *>(&a->min[1]);
                const u32 aMax = *reinterpret_cast<const u32 *>(&a->max[1]);
                const u32 mask0 = (aMax - *reinterpret_cast<const u32 *>(&other[0].min[1])) |
                                  (*reinterpret_cast<const u32 *>(&other[0].max[1]) - aMin);
                const u32 mask1 = ((aMax - *reinterpret_cast<const u32 *>(&other[1].min[1])) |
                                   (*reinterpret_cast<const u32 *>(&other[1].max[1]) - aMin)) &
                                  0x80008000;
                if ((mask0 & mask1) == 0) {
                    if ((mask0 & 0x80008000) == 0) {
                        if (pairs < pairsEnd) {
                            pairs->keyA = a->getKey();
                            pairs->keyB = other[0].getKey();
                            pairs++;
                        } else {
                            numPairsSkippedOut++;
                        }
                    }
                    if (mask1 == 0 && other[1].min[0] <= maxX) {
                        if (pairs < pairsEnd) {
                            pairs->keyA = a->getKey();
                            pairs->keyB = other[1].getKey();
                            pairs++;
                        } else {
                            numPairsSkippedOut++;
                        }
                    }
                }
                other += 2;
            }
            a++;
            if (--numBoxesA <= 0) {
                break;
            }
        }
    }
    return int(pairs - pairsOut);
}
