/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: two pairs of floats of the record at +0x258 of the object
 * at +0x8, each pair indexed by a side (0 or 1). Not traced further. */
struct Record013d27e0 { /* derived name */
    u8 unknown0[0x910];
    float unknown910; /* +0x910: side 0's weight */
    u8 unknown914[0x34];
    float unknown948; /* +0x948: side 1's weight */
    u8 unknown94c[0x114];
    float unknowna60; /* +0xa60: side 0's blend */
    float unknowna64; /* +0xa64: side 1's blend */
};

struct Owner013d27e0 { /* derived name */
    u8 unknown0[0x258];
    Record013d27e0 *record; /* +0x258 */
};

struct Object013d27e0 { /* derived name */
    u8 unknown0[0x8];
    Owner013d27e0 *owner; /* +0x8 */
};

/* derived name: one of two values by a side, from an array of the two on
 * the stack (each its own short-lived slot: the two calls share it) */
static inline float pick(const float &side0, const float &side1, int side)
{
    const float values[2] = {side0, side1};
    return values[side];
}

// NONMATCHING: instruction placement only (26/30): the blend's load is folded
// into `vsubss` before the stack check where the base keeps it a `vmovss` and
// sinks the subtraction and the 1.0 into the return block after the check.
float FUN_013d27e0(Object013d27e0 *self, int side) /* derived name */
{
    const Record013d27e0 *record = self->owner->record;
    const float weight = pick(record->unknown910, record->unknown948, side);
    const float blend = pick(record->unknowna60, record->unknowna64, side);
    return (1.0f - blend) * weight;
}
