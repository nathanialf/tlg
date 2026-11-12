/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: four floats copied whole, the fourth never computed with
 * (`mov ecx, [rdi + 0x15c]`) */
struct Vector00762bd0 { /* derived name */
    float x, y, z, w;
};

struct State00762bd0 { /* derived name */
    u8 unknown0[0xba4];
    float step; /* +0xba4 */
    u8 unknownba8[0x1540];
    int unknown20e8; /* +0x20e8 */
    u8 unknown20ec[0x44];
    Vector00762bd0 offset; /* +0x2130 */
    u8 unknown2140[0x188];
    float total; /* +0x22c8 */
    u32 unknown22cc;
    int unknown22d0; /* +0x22d0 */
};

struct Object00762bd0 { /* derived name */
    u8 unknown0[0x68];
    State00762bd0 *state; /* +0x68 */
    u8 unknown70[0xd0];
    int unknown140; /* +0x140 */
    u8 unknown144[0xc];
    Vector00762bd0 position; /* +0x150 */
    u8 unknown160[0x4c];
    int unknown1ac; /* +0x1ac */
};

struct Other00762bd0 { /* derived name */
    u8 unknown0[0x180];
    Vector00762bd0 position; /* +0x180 */
};

/* derived name: 1 or -1 by the float's sign bit (`sar 0x1f; or 1`) */
static inline int signOf(const float &value)
{
    return (*reinterpret_cast<const int *>(&value) >> 31) | 1;
}

/* derived name: adds the state's step to its total, the total starting
 * again from zero when the two differ in sign; when the state's int at
 * +0x20e8 is set, stores the object's position less the other's and marks
 * the object; then copies the object's int at +0x1ac into the state */
// NONMATCHING: 25/37, a register exchange: the base keeps the total in r8d and
// the step in r9d and compares `cmp ecx, edx` (the total's sign first); the
// build has r9d and r8d. Comparing the step's sign first gives the base's
// registers and `cmp edx, ecx` (30/37); the step read into a local first and
// the sign as `< 0 ? -1 : 1` give this build.
void FUN_00762bd0(Object00762bd0 *self, const Other00762bd0 *other) /* derived name */
{
    State00762bd0 *state = self->state;
    if (signOf(state->total) != signOf(self->state->step)) {
        state->total = 0.0f;
    }
    state->total += self->state->step;
    if (state->unknown20e8) {
        Vector00762bd0 offset = self->position;
        offset.x -= other->position.x;
        offset.y -= other->position.y;
        offset.z -= other->position.z;
        state->offset = offset;
        self->unknown140 = 1;
    }
    state->unknown22d0 = self->unknown1ac;
}
