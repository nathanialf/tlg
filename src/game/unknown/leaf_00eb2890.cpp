/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a virtual method returning the int at +0x2c, slot 5 of the
 * vtable at 0x16c9fe8 (its pointer at 0x16ca020) stored by FUN_00e9a5f0,
 * FUN_00ea53a0 and FUN_00ea5be0. The 32-bit load gives the width; int is not
 * traced further. Class and field unknown. */
struct Object00eb2890 {
    u8 unknown0[0x2c];
    int unknown2c;
};

int FUN_00eb2890(const Object00eb2890 *self) /* derived name */
{
    return self->unknown2c;
}
