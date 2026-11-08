/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 166 of 194 (781 bytes, the size equal). Two classes. (1) The mean's loop: LSR
// walks the sums and the points on one register stepped by 8 (`rax*4`, `rax*2`, 0x60e40 to
// 0x60ec7), where the base steps it by 4 (`rax*8`, `rax*4`): both solutions cost 4 registers
// with the same addrec cost, and LoopStrengthReduce's SolveRecurse keeps the first one it
// meets; the uses are visited in the IV's use-list order (IVUsers), so the base's source
// creates them in another order. (2) The scan's registers: greedy gives the used points' count
// r11d and the least used index r10d where the base has them the other way round, and the
// scan's index and its truncated copy edx and eax the other way round (0x60f27 to 0x60f67).
// The declaration order of the scan's locals moves both (alloca order, so phi order and the
// virtual registers' numbering) and orders the cmovs (the larger count tested first and the
// indexes declared before their counts give the base's `cmovle r13d; cmovle r11d`); no order
// tried gives the registers.
void FlaggedPoints00060c70::FUN_00060d50(const CellSumsBlock00060d50 *blocks, int numBlocks,
                                         const hkIntSpaceUtil &intSpace)
{
    CellSums00060d50 sums[16];
    for (int i = 0; i < numCells; i++) {
        memset(&sums[i], 0, sizeof(sums[i]));
    }
    for (int b = 0; b < numBlocks; b++) {
        for (int i = 0; i < numCells; i++) {
            const CellSums00060d50 cell = blocks[b].cells[i];
            sums[i].x += cell.x;
            sums[i].y += cell.y;
            sums[i].z += cell.z;
            sums[i].count += cell.count;
        }
    }

    unknown24 = 0;
    for (int i = 0; i < numCells; i++) {
        const int count = int(sums[i].count);
        flags[i] = count;
        if (count == 0) {
            points[i] = _mm_setzero_ps();
        } else {
            unknown24 += count;
            const Vec4 sum = _mm_setr_ps(float(sums[i].x), float(sums[i].y), float(sums[i].z),
                                         float(sums[i].count));
            const Vec4 n = _mm_shuffle_ps(sum, sum, _MM_SHUFFLE(3, 3, 3, 3));
            const Vec4 r = _mm_rcp_ps(n);
            const Vec4 invCount =
                _mm_mul_ps(r, _mm_sub_ps(_mm_load_ps(D_14b4380), _mm_mul_ps(r, n)));
            points[i] = _mm_sub_ps(_mm_mul_ps(_mm_mul_ps(sum, invCount), intSpace.bitScaleInv),
                                   intSpace.bitOffsetLow);
        }
    }

    const int numPoints = numCells;
    int numUsed = 0;
    int leastUsed = -1;
    int leastCount = 0x7fffffff;
    int mostUsed = -1;
    int mostCount = 0;
    int emptyPoint = -1;
    int numBodies = 0;
    for (int i = numPoints - 1; i >= 0; i--) {
        const int count = flags[i];
        if (count <= 0) {
            emptyPoint = i;
            continue;
        }
        if (count > mostCount) {
            mostCount = count;
            mostUsed = i;
        }
        if (count <= leastCount) {
            leastCount = count;
            leastUsed = i;
        }
        numBodies += count;
        numUsed++;
    }
    const int wanted = hkMath::max2(hkMath::min2(numBodies >> 3, numPoints), 1);
    if (numUsed > wanted) {
        const int moved = flags[leastUsed];
        flags[leastUsed] = 0;
        flags[mostUsed] += moved;
    } else if (numUsed < wanted && mostCount >= 15) {
        points[emptyPoint] = _mm_add_ps(_mm_mul_ps(D_14b2060[14], D_14b2060[35]), points[mostUsed]);
        const int half = mostCount >> 1;
        flags[mostUsed] = half;
        flags[emptyPoint] = half;
    }
    for (int i = 0; i < numPoints; i++) {
        if (flags[i] == 0) {
            points[i] = D_14b2060[15];
        }
    }
}
