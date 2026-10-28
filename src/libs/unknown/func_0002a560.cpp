/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the mass the volume has at the density; the inertia scaled
 * by the new mass over the old.
 * NONMATCHING: the base forms the inertia's address with `lea rdi, [rdi+0x20]`
 * and the scale's with `lea rsi` before the divide; this compiles to `add rdi,
 * 0x20` with the `lea rsi` after the scale's store (docs/NOTES.md, Round 41). */
void hkMassProperties::FUN_0002a560(const Vec4 &density)
{
    const Vec4 newMass = _mm_mul_ps(_mm_set1_ps(volume), density);
    const Vec4 scale = _mm_div_ps(newMass, _mm_set1_ps(mass));
    mass = _mm_cvtss_f32(newMass);
    inertiaTensor.FUN_0001ac70(scale);
}
