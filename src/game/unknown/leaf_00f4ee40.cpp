/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <algorithm>

#include "tlg_types.h"

/* derived names: slot of the vtable at 0x16bf150 (its pointer there): below
 * a step of 1e-5, the two values at +0x60 and +0xc0 are scaled by one less
 * five times the rate at +0x14 of the owner's parameters (at most 1): the
 * parameters of the table's entry whose id is the owner's at +0x70, else the
 * table's own at +0x148. The classes are not traced. */
struct Parameters00f4ee40 { /* derived name */
    u8 unknown0[0x14];
    float rate; /* +0x14 */
    u8 unknown18[0x4];
    int id; /* +0x1c */
};

struct Table00f4ee40 { /* derived name */
    u8 unknown0[0x148];
    Parameters00f4ee40 defaults; /* +0x148 */
    u8 unknown168[0x8];
    Parameters00f4ee40 **entries; /* +0x170 */
    int count;                    /* +0x178 */
};

struct Owner00f4ee40 { /* derived name */
    u8 unknown0[0x68];
    Table00f4ee40 *table; /* +0x68 */
    int id;               /* +0x70 */
};

struct Object00f4ee40 { /* derived name */
    u8 unknown0[0x8];
    Owner00f4ee40 *owner; /* +0x8 */
    u8 unknown10[0x50];
    float unknown60; /* +0x60 */
    u8 unknown64[0x5c];
    float unknownc0; /* +0xc0 */
};

void FUN_00f4ee40(Object00f4ee40 *self, float step) /* derived name */
{
    if (step < 1e-5f) {
        Table00f4ee40 *table = self->owner->table;
        const Parameters00f4ee40 *parameters = 0;
        for (int i = 0; i < table->count; ++i) {
            if (table->entries[i]->id == self->owner->id) {
                parameters = table->entries[i];
                break;
            }
        }
        if (!parameters)
            parameters = &table->defaults;
        const float scale = 1.0f - std::min(parameters->rate * 5.0f, 1.0f);
        self->unknown60 *= scale;
        self->unknownc0 *= scale;
    }
}
