/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the 16-bit value at +0x6 of entry i (20 bytes each)
 * of the array the pointer at +0x20 holds, plus one, as 16 bits; slot 7 of the
 * vtable at 0x16c9fe8 (its pointer at 0x16ca030). Class and method unknown. */
struct Entry00eb2930 { /* derived name */
    u8 unknown0[6];
    u16 unknown6;
    u8 unknown8[0xc];
};

struct Object00eb2930 { /* derived name */
    u8 unknown0[0x20];
    Entry00eb2930 *unknown20;
};

int FUN_00eb2930(const Object00eb2930 *self, int i) /* derived name */
{
    return static_cast<u16>(self->unknown20[i].unknown6 + 1);
}
