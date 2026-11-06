/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The atoms' constructors' stores first (types, the stabilization's limits,
 * the spring's -1 pair), then the constructor's own: the pivots cleared, the
 * stabilization enabled, no length. The length is 16-aligned, so its zero
 * store does not merge with the maximum's. */
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
