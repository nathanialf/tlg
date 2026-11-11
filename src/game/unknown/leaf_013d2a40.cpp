/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 2 of the vtable at 0x16d36e0 (its pointer at 0x16d3700): stores
 * the reciprocal of the float at +0x2c of the record the object points to at
 * +0x8 at +0x1c of the same record, 0 when it is zero or unordered. Class and method
 * unknown. */
struct Record013d2a40 { /* derived name */
    u8 unknown0[0x1c];
    float unknown1c;
    u8 unknown20[0xc];
    float unknown2c;
};

struct Object013d2a40 { /* derived name */
    u8 unknown0[0x8];
    Record013d2a40 *unknown8;
};

void FUN_013d2a40(Object013d2a40 *self) /* derived name */
{
    Record013d2a40 *record = self->unknown8;
    float v = record->unknown2c;
    record->unknown1c = (v < 0.0f || v > 0.0f) ? 1.0f / v : 0.0f;
}
