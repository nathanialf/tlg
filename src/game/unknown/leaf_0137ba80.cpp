/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16cc728 (+0x68 from the vtable stored at
 * 0x16cc6c0): when the float at +0x160 of its argument is negative, sets the
 * floats at +0x160 and +0x164 to the one at +0x158 and those at +0x168 and
 * +0x16c to the one at +0x15c. The object itself is not read; the classes are
 * not traced. */
struct Object0137ba80; /* derived name */

struct Argument0137ba80 { /* derived name */
    u8 unknown0[0x158];
    float unknown158;
    float unknown15c;
    float unknown160;
    float unknown164;
    float unknown168;
    float unknown16c;
};

void FUN_0137ba80(Object0137ba80 *, Argument0137ba80 *argument) /* derived name */
{
    if (argument->unknown160 < 0.0f) {
        argument->unknown160 = argument->unknown158;
        argument->unknown164 = argument->unknown158;
        argument->unknown168 = argument->unknown15c;
        argument->unknown16c = argument->unknown15c;
    }
}
