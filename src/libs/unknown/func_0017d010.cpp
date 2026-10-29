/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* A direction under a rotation: its x, y and z broadcast and scaling the
 * columns, summed x and y first. derived name. */
static inline Vec4 rotateDirection(const hkMatrix3 &r, const Vec4 &v) /* derived name */
{
    const Vec4 c0 = r.col0;
    const Vec4 c1 = r.col1;
    const Vec4 c2 = r.col2;
    const Vec4 x = _mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, 0));
    const Vec4 y = _mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1));
    const Vec4 z = _mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2));
    return _mm_add_ps(_mm_add_ps(_mm_mul_ps(c0, x), _mm_mul_ps(c1, y)), _mm_mul_ps(c2, z));
}

/* A float in every lane: loaded alone, then its lane shuffled across.
 * derived name. */
static inline Vec4 broadcast(const float &value) /* derived name */
{
    const Vec4 v = _mm_load_ss(&value);
    return _mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, 0));
}

void hkpWheelFrictionConstraintData::FUN_0017d010(const hkMatrix3 *rotation, const void *argument2,
                                                  const hkpSolverResults *results, Vec4 &out) const
{
    const hkMatrix3 &frame = atoms.transforms.transformA.rotation;
    const Vec4 forward = rotateDirection(*rotation, frame.col1);
    const Vec4 side = rotateDirection(*rotation, frame.col2);
    const hkpWheelFrictionConstraintAtom &friction = atoms.friction;
    out = _mm_add_ps(_mm_add_ps(_mm_mul_ps(broadcast(friction.frictionImpulse[0]), forward),
                                _mm_mul_ps(broadcast(friction.frictionImpulse[1]), side)),
                     _mm_add_ps(_mm_mul_ps(forward, broadcast(friction.slipImpulse[0])),
                                _mm_mul_ps(side, broadcast(friction.slipImpulse[1]))));
}
