/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether bits 8 to 12 of the int at +0x2c are 0x12
 * (the masked value 0x1200), as an int (the bool widened, movzbl); called by
 * FUN_001adf20 and FUN_001ae0b0. Class and method unknown. */
struct Object012fd770 { /* derived name */
    u8 unknown0[0x2c];
    int unknown2c;
};

int FUN_012fd770(const Object012fd770 *self) /* derived name */
{
    return (self->unknown2c & 0x1f00) == 0x1200;
}
