/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the int at +0xc is 3 or 27, as an int; slot
 * 19 of the vtable at 0x16abb00 (its pointer at 0x16abba8); slot 7 of the
 * vtable at 0x16cb1a0 (its pointer at 0x16cb1e8); its siblings FUN_0135e2a0
 * and others compare the same int. Class and method unknown. */
struct Object0135e290 { /* derived name */
    u8 unknown0[0xc];
    int unknown0c;
};

int FUN_0135e310(const Object0135e290 *self) /* derived name */
{
    return self->unknown0c == 27 || self->unknown0c == 3;
}
