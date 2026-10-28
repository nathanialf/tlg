/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: per entry, the velocity of motion A relative to motion B
 * along the entry's row: the angular velocities by the entry's two angular
 * parts and the linear velocities' difference along the record's
 * direction, summed over x, y and z into every lane (row 3 of the constant
 * table is one in each lane). */
void FUN_00031740(const Pair08Owner *self, int count, const hknpMotion *motionA,
                  const hknpMotion *motionB, Vec4 *out)
{
    const Pair08Entry *entry = reinterpret_cast<const Pair08Entry *>(self + 1);
    for (int i = 0; i < count; i++, entry++) {
        Vec4 v = _mm_add_ps(_mm_mul_ps(motionA->angularVelocity, entry->vectorA),
                            _mm_mul_ps(motionB->angularVelocity, entry->vectorB));
        v = _mm_add_ps(v, _mm_mul_ps(_mm_sub_ps(motionA->linearVelocity, motionB->linearVelocity),
                                     self->direction));
        out[i] = _mm_dp_ps(v, D_14b2060[3], 0x7f);
    }
}
