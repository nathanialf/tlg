/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 12 of seven vtables from 0x16c1d50 to 0x16d6870 (the
 * classes the constructors FUN_011f8030, FUN_012010e0 and FUN_0120fe90 build),
 * the shape of FUN_013d1b30 over another record:
 * returns one of two floats of the record two pointers away (+0x8, then
 * +0x260), the one at +0x8f0 for index 0 and the one at +0x928 for index 1,
 * through a two-element local array. The record's other fields are not
 * traced. */
struct Record01477a70 { /* derived name */
    u8 unknown0[0x8f0];
    float unknown8f0; /* +0x8f0 */
    u8 unknown8f4[0x34];
    float unknown928; /* +0x928 */
};

struct Owner01477a70 { /* derived name */
    u8 unknown0[0x260];
    Record01477a70 *record; /* +0x260 */
};

struct Object01477a70 { /* derived name */
    void *vtable;
    Owner01477a70 *owner; /* +0x8 */
};

// NONMATCHING: list-ilp order, the base sign-extends the index after the
// second element's store, the build before the second load (the array
// initialised either way, the same).
float FUN_01477a70(const Object01477a70 *self, int index) /* derived name */
{
    const Record01477a70 *record = self->owner->record;
    float values[2] = {record->unknown8f0, record->unknown928};
    return values[index];
}
