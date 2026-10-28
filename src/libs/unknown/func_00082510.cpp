/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkpPulleyConstraintData::hkpPulleyConstraintData()
{
    atoms.translations.type = hkpConstraintAtom::TYPE_SET_LOCAL_TRANSLATIONS;
    atoms.pulley.type = hkpConstraintAtom::TYPE_PULLEY;
    atoms.translations.translationA = _mm_setzero_ps();
    atoms.translations.translationB = _mm_setzero_ps();
    atoms.pulley.fixedPivotAinWorld = _mm_setzero_ps();
    atoms.pulley.fixedPivotBinWorld = _mm_setzero_ps();
    atoms.pulley.ropeLength = 0.0f;
    atoms.pulley.leverageOnBodyB = 1.0f;
}
