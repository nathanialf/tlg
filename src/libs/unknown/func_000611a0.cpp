/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void FlaggedPoints00060c70::FUN_000611a0(int numBodies, const hkAabb &aabb)
{
    if (numBodies == 0) {
        return;
    }
    const int total = unknown24 + numBodies;
    const int share = numCells * numBodies / total;
    unknown24 = total;
    const int numMoved = hkMath::min2(share, numBodies >> 3);
    if (numMoved <= 0) {
        return;
    }
    const int bodiesEach = numBodies / numMoved;
    const Vec4 diagonal = _mm_sub_ps(aabb.max, aabb.min);
    const float numSteps = float(numMoved + 1);
    for (int i = 0; i < numMoved; i++) {
        int leastUsed = -1;
        int leastCount = unknown24;
        for (int j = 0; j < numCells; j++) {
            if (flags[j] < leastCount) {
                leastCount = flags[j];
                leastUsed = j;
            }
        }
        const float t = (float(i) + 1.0f) / numSteps;
        points[leastUsed] = _mm_add_ps(_mm_mul_ps(diagonal, _mm_set1_ps(t)), aabb.min);
        flags[leastUsed] = bodiesEach;
    }
}
