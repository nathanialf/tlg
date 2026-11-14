/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <xmmintrin.h>

#include "tlg_game_pair00777d30.h"
#include "tlg_math.h"

/* derived names: an object takes a new target: the pair it had at +0x100
 * is kept at +0x130 with its distance, the pair is set from the reference at
 * +0x78 and the 64-bit value at +0x80 of the source (both read and the
 * reference held before the pair's is exchanged, then the value stored), and the distance from the source's position to the given one and
 * that position are stored. The square root is the estimated reciprocal
 * refined once and multiplied by the argument, 0 for 0. The classes are not
 * traced. */
class Value00797b10 : public Node00503fb0 /* derived name */
{
};

struct Source00797b10 { /* derived name */
    Float4A position;   /* +0x0 */
    u8 unknown10[0x68];
    Ref00503fb0<Value00797b10> object; /* +0x78 */
    u64 unknown80;                     /* +0x80 */
};

struct Target00797b10 { /* derived name */
    Pair00777d30 pair;  /* +0x0 */
    float distance;     /* +0x10 */
    Float4A position;   /* +0x20 */
};

struct Object00797b10 { /* derived name */
    u8 unknown0[0x100];
    Target00797b10 target;  /* +0x100 */
    Pair00777d30 previous;  /* +0x130 */
    float previousDistance; /* +0x140 */
};

static inline void set(Pair00777d30 *pair, u64 value,
                       Ref00503fb0<Value00797b10> object) /* derived name */
{
    pair->unknown8.set(object.get());
    pair->unknown0 = value;
}

static inline float squareRoot(float value) /* derived name */
{
    float estimate = _mm_cvtss_f32(_mm_rsqrt_ss(_mm_set_ss(value)));
    float root = (estimate * value * estimate - 3.0f) * (estimate * -0.5f * value);
    return value == 0.0f ? 0.0f : root;
}

// NONMATCHING: the same size and 123 of 136 instructions; (1) exchanged spill slots: the base
// keeps the position at -0x30 and the 64-bit value at -0x40, this the reverse; (2) the order of
// two float operations' operands and the schedule that follows: the base adds the squares as
// y*y + x*x after loading the three components first and multiplies (e*e*v - 3) by (e*-0.5*v),
// where Reassociate's rank order gives x*x + y*y and the product the other way round here
// whatever is written.
void FUN_00797b10(Object00797b10 *self, const Source00797b10 *source,
                  const Float4A *position) /* derived name */
{
    FUN_00777d30(&self->previous, &self->target.pair);
    self->previousDistance = self->target.distance;
    set(&self->target.pair, source->unknown80, source->object);
    float x = position->x - source->position.x;
    float y = position->y - source->position.y;
    float z = position->z - source->position.z;
    self->target.distance = squareRoot(x * x + y * y + z * z);
    self->target.position = *position;
}
