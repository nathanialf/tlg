/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the mass the volume has at the density, set through the
 * inline mass setter. */
void hkMassProperties::FUN_0002a560(const Vec4 &density)
{
    scaleToMass(_mm_mul_ps(_mm_set1_ps(volume), density));
}
