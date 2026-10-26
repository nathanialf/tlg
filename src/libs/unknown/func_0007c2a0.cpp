/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the pivots of a ball-and-socket constraint, each in its
 * body's space, stored in the translations atom. */
void hkpBallAndSocketConstraintData::FUN_0007c2a0(const Vec4 &pivotA, const Vec4 &pivotB)
{
    atoms.pivots.translationA = pivotA;
    atoms.pivots.translationB = pivotB;
}
