/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_math.h"

/* derived names: slot 3 of the vtables at 0x16d3798 and 0x16d3c08 (and one
 * more pointer): the vector at +0x20 of the entry the index selects in the
 * 144-byte entries the record at +0x8 points to at +0x18, or zero when the
 * index is not below the record's count at +0x20. Class and method unknown. */
struct Entry013d0240 { /* derived name */
    u8 unknown0[0x20];
    Float4A unknown20;
    u8 unknown30[0x60];
};

struct Record013d0240 { /* derived name */
    u8 unknown0[0x18];
    Entry013d0240 *unknown18;
    u32 unknown20;
};

struct Object013d0240 { /* derived name */
    u8 unknown0[0x8];
    Record013d0240 *unknown8;
};

Float4A FUN_013d0240(const Object013d0240 *self, int index) /* derived name */
{
    const Record013d0240 *record = self->unknown8;
    if (index < record->unknown20) {
        return record->unknown18[index].unknown20;
    }
    return Float4A(0.0f, 0.0f, 0.0f, 0.0f);
}
