/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: sets a rate from the float its argument points at: the
 * reciprocal (0 for a rate of 0) stored at +0xf04 and +0xf3c of the record
 * the owner's object holds at +0x248 (the record read again for the second
 * store). The owner is reached through the pointer at +0x8. Class and method
 * unknown. */
struct Record01064150 { /* derived name */
    u8 unknown0[0xf04];
    float unknownf04; /* +0xf04 */
    u8 unknownf08[0xf3c - 0xf08];
    float unknownf3c; /* +0xf3c */
};

struct Object01064150_0 { /* derived name */
    u8 unknown0[0x248];
    Record01064150 *unknown248; /* +0x248 */
};

struct Owner01064150 {          /* derived name */
    Object01064150_0 *unknown0; /* +0x0 */
};

struct Object01064150 { /* derived name */
    u8 unknown0[8];
    Owner01064150 *unknown8; /* +0x8 */
};

// NONMATCHING: two stores in two arms where the build sinks one: the base
// stores the reciprocal at +0xf04 in its arm and an immediate 0 in the other
// (`movl $0, 0xf04(%rcx)`), this build selects the value and stores once;
// the compare without `jp` and the record read before it are landed
// (fabsf(x) > 0, cookbook 1222; the record into a local, 1209).
void FUN_01064150(Object01064150 *self, const float *rate) /* derived name */
{
    Owner01064150 *owner = self->unknown8;
    float value = *rate;
    Record01064150 *record = owner->unknown0->unknown248;
    float period = fabsf(value) > 0.0f ? 1.0f / value : 0.0f;
    record->unknownf04 = period;
    owner->unknown0->unknown248->unknownf3c = period;
}
