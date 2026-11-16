/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a level between 0 and 1 moved towards one end by the
 * clock's step over its length, the direction set by each call */
struct Clock01490450 { /* derived name */
    u8 unknown0[0x14];
    float step; /* +0x14 */
};

struct Owner01490450 { /* derived name */
    u8 unknown0[0x10];
    Clock01490450 *clock; /* +0x10 */
};

struct Level01490450 { /* derived name */
    u8 unknown0[0x8];
    Owner01490450 *owner; /* +0x8 */
    int rising;           /* +0x10: 1 towards 1, 0 towards 0 */
    int started;          /* +0x14: set when it starts rising from rest */
    float level;          /* +0x18 */
    float length;         /* +0x1c */
};

/* derived name: the smaller of two values, by value */
template <typename T> inline T minimum(T a, T b)
{
    return a < b ? a : b;
}

/* derived name: one step of the level; a level already outside [0, 1] is
 * only brought back into it */
void FUN_01490450(Level01490450 *self, int rising) /* derived name */
{
    self->started = self->rising == 0 && rising == 1;
    self->rising = rising;
    float level = self->level;
    if (level < 0.0f) {
        level = 0.0f;
    } else if (level > 1.0f) {
        level = 1.0f;
    } else {
        float delta = self->owner->clock->step / self->length;
        if (rising == 0)
            delta = -delta;
        level += delta;
        if (level < 0.0f)
            level = 0.0f;
        else
            level = minimum(level, 1.0f);
    }
    self->level = level;
}
