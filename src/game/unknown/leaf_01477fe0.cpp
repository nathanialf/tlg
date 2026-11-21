/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 12 of the vtable at 0x16c1dc8 (its pointer at
 * 0x16c1e38), the vtable stored by FUN_0120a920 FUN_0120af30: of the record
 * at +0x260 of the object at +0x8, picks by its argument (0 or 1) one of the
 * floats at +0x8f0 and +0x928 and one of those at +0xa40 and +0xa44 (each
 * pair in turn in one local array, `mov [rbp-0x10]` and `vmovss xmm,
 * [rbp+rdx*4-0x10]` twice),
 * and returns the first times one less the second. Class and method
 * unknown. */
struct Record01477fe0 { /* derived name */
    u8 unknown0[0x8f0];
    float unknown8f0; /* +0x8f0 */
    u8 unknown8f4[0x34];
    float unknown928; /* +0x928 */
    u8 unknown92c[0x114];
    float unknowna40; /* +0xa40 */
    float unknowna44; /* +0xa44 */
};

struct Member01477fe0 { /* derived name */
    u8 unknown0[0x260];
    Record01477fe0 *record; /* +0x260 */
};

struct Object01477fe0 { /* derived name */
    u8 unknown0[8];
    Member01477fe0 *unknown8; /* +0x8 */
};

float FUN_01477fe0(const Object01477fe0 *self, int which) /* derived name */
{
    const Record01477fe0 *record = self->unknown8->record;
    float values[2] = {record->unknown8f0, record->unknown928};
    float scale = values[which];
    values[0] = record->unknowna40;
    values[1] = record->unknowna44;
    float part = values[which];
    return (1.0f - part) * scale;
}
