/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 2 of the vtable at 0x16d3a30 (its pointer at 0x16d3a50): stores
 * the reciprocal of the float its argument points to at +0x1c of the record
 * the object points to at +0x8, 0 when the float is zero or unordered. Class and method
 * unknown. */
struct Record013d6330 { /* derived name */
    u8 unknown0[0x1c];
    float unknown1c;
};

struct Object013d6330 { /* derived name */
    u8 unknown0[0x8];
    Record013d6330 *unknown8;
};

void FUN_013d6330(Object013d6330 *self, const float *value) /* derived name */
{
    float v = *value;
    Record013d6330 *record = self->unknown8;
    record->unknown1c = (v < 0.0f || v > 0.0f) ? 1.0f / v : 0.0f;
}
