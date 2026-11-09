/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the int at +0xc is 10, as an int (sete, then
 * movzx to eax); slot 4 of the secondary vtable at 0x16abb60 (offset to top
 * -400) of the vtable at 0x16abb00 (its pointer at 0x16abb90), stored by
 * FUN_005b05b0 FUN_005b14b0; slot 11 of the secondary vtable at 0x16abcb8
 * (offset to top -400) of the vtable at 0x16abc58 (its pointer at 0x16abd20),
 * stored by FUN_005c6060 FUN_005c6620; slot 4 of the vtable at 0x16cb1a0 (its
 * pointer at 0x16cb1d0), the vtable stored by FUN_005b05b0 FUN_005b14b0; slot
 * 11 of the vtable at 0x16cb260 (its pointer at 0x16cb2c8), the vtable stored
 * by FUN_005c6060 FUN_005c6620. The function is a base class's own method: the
 * vtable 0x16cb1a0 holds it, and the secondary vtable at 0x16abb60 (the base
 * at +400 of the object whose vtable is 0x16abb00) holds it unadjusted. Class
 * and method unknown. */
struct Object0135e290 { /* derived name */
    u8 unknown0[0xc];
    int unknown0c; /* compared by FUN_0135e2a0, FUN_0135e2d0, FUN_0135e330, FUN_0135e460, FUN_0135e470 and FUN_0135e480 */
    u8 unknown10[0x14 - 0x10];
    int unknown14; /* compared by FUN_0135e290 */
};

int FUN_0135e2d0(const Object0135e290 *self) /* derived name */
{
    return self->unknown0c == 10;
}
