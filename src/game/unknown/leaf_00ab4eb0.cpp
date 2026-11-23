/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: a line of points (FUN_00ab2fb0's local at -0x78, and
 * FUN_00317cb0's and others'), extended past its end: when the index is the
 * last point's and there are two or more, two points are appended along the
 * last segment, half its length and its whole length beyond the last point,
 * each with the last point's w */
// NONMATCHING: 117/147, 602 bytes against 604. The two tests are one `and`
// at the unit stage (`and i1 (icmp ugt count, 1), (icmp eq (count - 1),
// index)`, SimplifyCFG's FoldBranchToCommonDest), lowered in the and's
// operand order: the build tests the count first (`cmp rbx, 2; jb` on the
// widened count), the base the index first (`lea eax, [rbx-1]; cmp eax,
// esi; jne`, then `cmp ebx, 2; jb`), whichever order the tests are written
// in or the count read. Second: the half segment's three products before
// the three sums in the base (`vmulss` x3 then `vaddss` x3), interleaved
// here, and the registers after them.
void FUN_00ab4eb0(Array05943280<Float4A> *points, int index) /* derived name */
{
    if (index == int(points->size() - 1) && points->size() >= 2) {
        const Float4A &last = points->at(index);
        const Float4A &before = points->at(points->size() - 2);
        const float dx = last.x - before.x;
        const float dy = last.y - before.y;
        const float dz = last.z - before.z;
        points->push(Float4A(last.x + dx * 0.5f, last.y + dy * 0.5f, last.z + dz * 0.5f, last.w));
        const Float4A &end = points->at(index);
        points->push(Float4A(end.x + dx, end.y + dy, end.z + dz, end.w));
    }
}
