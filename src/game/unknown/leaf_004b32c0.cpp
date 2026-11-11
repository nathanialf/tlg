/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_math.h"

/* derived names: a vtable slot (its pointer at 0x16aa218, no row), written as
 * a free function: gives the two vectors of the record the pointer at +0x60
 * holds (at +0x50 and +0x70), the first replaced, while the flag at +0x68 is
 * set, by the object's own vector at +0x450 with the record's second
 * component. The vectors' meaning is not traced. */
struct Record004b32c0 /* derived name */
{
    u8 unknown0[0x50];
    Float4A unknown50; /* +0x50 */
    u8 unknown60[0x10];
    Float4A unknown70; /* +0x70 */
};

struct Object004b32c0 /* derived name */
{
    u8 unknown0[0x60];
    Record004b32c0 *unknown60; /* +0x60 */
    bool unknown68;            /* +0x68 */
    u8 unknown69[0x3e7];
    Float4A unknown450; /* +0x450 */
};

// NONMATCHING: the record pointer at +0x60, loaded by both arms, is hoisted above the
// flag's test (one load in the entry), where the base loads it in each arm; the
// stores and the rest are the base's.
void FUN_004b32c0(const Object004b32c0 *self, Float4A *first, Float4A *second) /* derived name */
{
    if (self->unknown68)
        first->set(self->unknown450.x, self->unknown60->unknown50.y, self->unknown450.z,
                   self->unknown450.w);
    else
        *first = self->unknown60->unknown50;
    *second = self->unknown60->unknown70;
}
