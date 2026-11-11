/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 12 of seven vtables from 0x16bef30 to 0x16d3890 (the
 * classes the constructors FUN_00f2c5d0, FUN_00f36c00 and FUN_00f4cf00 build):
 * returns one of two floats of the record two pointers away (+0x8, then
 * +0x258), the one at +0x910 for index 0 and the one at +0x948 for index 1,
 * through a two-element local array. The record's other fields are not
 * traced. */
struct Record013d1b30 { /* derived name */
    u8 unknown0[0x910];
    float unknown910; /* +0x910 */
    u8 unknown914[0x34];
    float unknown948; /* +0x948 */
};

struct Owner013d1b30 { /* derived name */
    u8 unknown0[0x258];
    Record013d1b30 *record; /* +0x258 */
};

struct Object013d1b30 { /* derived name */
    void *vtable;
    Owner013d1b30 *owner; /* +0x8 */
};

// NONMATCHING: list-ilp order, the base sign-extends the index after the
// second element's store, the build before the second load (the array
// initialised either way, the same).
float FUN_013d1b30(const Object013d1b30 *self, int index) /* derived name */
{
    const Record013d1b30 *record = self->owner->record;
    float values[2] = {record->unknown910, record->unknown948};
    return values[index];
}
