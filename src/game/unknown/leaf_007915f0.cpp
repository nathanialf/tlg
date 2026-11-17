/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_pair00777d30.h"
#include "tlg_libc.h"
#include "tlg_math.h"

/* derived names: an object takes a new target: the pair it had at +0x100
 * is kept at +0x140 with its distance, the pair is set from the reference at
 * +0x78 and the 64-bit value at +0x80 of the source (both read and the
 * reference held before the pair's is exchanged, then the value stored), and the distance from the source's position to the given one and
 * that position are stored. The distance is sqrtf's: under -ffast-math
 * LLVM 3.7 makes it the reciprocal square root estimate refined once and
 * multiplied by the argument, 0 for 0 (DAGCombiner::BuildRsqrtEstimate). The classes are not
 * traced. */
class Value007915f0 : public Object016b9108 /* derived name */
{
};

struct Source007915f0 { /* derived name */
    Float4A position;   /* +0x0 */
    u8 unknown10[0x68];
    Ref00503fb0<Value007915f0> object; /* +0x78 */
    u64 unknown80;                     /* +0x80 */
};

struct Target007915f0 { /* derived name */
    Pair00777d30 pair;  /* +0x0 */
    float distance;     /* +0x10 */
    Float4A position;   /* +0x20 */
};

struct Object007915f0 { /* derived name */
    u8 unknown0[0x100];
    Target007915f0 target; /* +0x100 */
    u8 unknown130[0x10];
    Pair00777d30 previous;  /* +0x140 */
    float previousDistance; /* +0x150 */
};

static inline void set(Pair00777d30 *pair, u64 value,
                       Ref00503fb0<Value007915f0> object) /* derived name */
{
    pair->unknown8.set(object.get());
    pair->unknown0 = value;
}

void FUN_007915f0(Object007915f0 *self, const Source007915f0 *source,
                  const Float4A *position) /* derived name */
{
    FUN_00777d30(&self->previous, &self->target.pair);
    self->previousDistance = self->target.distance;
    set(&self->target.pair, source->unknown80, source->object);
    float x = position->x - source->position.x;
    float y = position->y - source->position.y;
    float z = position->z - source->position.z;
    self->target.distance = sqrtf(x * x + y * y + z * z);
    self->target.position = *position;
}
