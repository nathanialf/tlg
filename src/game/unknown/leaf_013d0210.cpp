/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_math.h"

/* derived names: slot 2 of the vtables at 0x16d3798 and 0x16d3c08 (and one
 * more pointer): the vector at +0x10 of the entry the index selects in the
 * 144-byte entries the record at +0x8 points to at +0x18, or zero when the
 * index is not below the record's count at +0x20. Class and method unknown. */
struct Entry013d0210 { /* derived name */
    u8 unknown0[0x10];
    Float4A unknown10;
    u8 unknown20[0x70];
};

struct Record013d0210 { /* derived name */
    u8 unknown0[0x18];
    Entry013d0210 *unknown18;
    u32 unknown20;
};

struct Object013d0210 { /* derived name */
    u8 unknown0[0x8];
    Record013d0210 *unknown8;
};

Float4A FUN_013d0210(const Object013d0210 *self, int index) /* derived name */
{
    const Record013d0210 *record = self->unknown8;
    if (index < record->unknown20) {
        return record->unknown18[index].unknown10;
    }
    return Float4A(0.0f, 0.0f, 0.0f, 0.0f);
}
