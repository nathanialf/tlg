/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 7 of hkpStiffSpringConstraintData's vtable (address
 * point 0x169cff0): invalid when the spring's length is not positive or
 * exceeds its maximum. The bytes test those two failures (unordered passes
 * both), not the conditions for validity. */
hkBool hkpStiffSpringConstraintData::FUN_0007d710() const /* derived name */
{
    return !(atoms.spring.length <= 0.0f || atoms.spring.length > atoms.spring.maxLength);
}
