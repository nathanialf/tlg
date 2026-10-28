/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 19 of 20 instructions in the base's order; the last two
// stores (length and maxLength, 0 at +0x70 and +0x74) merge into one
// `mov qword [rdi+0x70], 0` where the base keeps two 4-byte stores, while
// the -1 pair at +0x78 merges as in the base (docs/NOTES.md Round 46).
hkpStiffSpringConstraintData::hkpStiffSpringConstraintData()
{
    atoms.pivots.type = hkpConstraintAtom::TYPE_SET_LOCAL_TRANSLATIONS;
    atoms.setupStabilization.type = hkpConstraintAtom::TYPE_SETUP_STABILIZATION;
    atoms.setupStabilization.maxLinImpulse = HK_REAL_MAX;
    atoms.setupStabilization.maxAngImpulse = HK_REAL_MAX;
    atoms.setupStabilization.maxAngle = HK_REAL_HIGH;
    atoms.spring.type = hkpConstraintAtom::TYPE_STIFF_SPRING;
    atoms.spring.springConstant = -1.0f;
    atoms.spring.springDamping = -1.0f;
    atoms.pivots.translationA = _mm_setzero_ps();
    atoms.pivots.translationB = _mm_setzero_ps();
    atoms.setupStabilization.enabled = true;
    atoms.spring.length = 0.0f;
    atoms.spring.maxLength = 0.0f;
}
