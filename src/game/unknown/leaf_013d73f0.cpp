/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a virtual method returning the int at +0x1c, slot 3 of the
 * vtables at 0x16d3c70 and 0x16d3cb8 (both stored by FUN_00f7baf0). The 32-bit
 * load gives the width; int is not traced further. Class and field unknown. */
struct Object013d73f0 {
    u8 unknown0[0x1c];
    int unknown1c;
};

int FUN_013d73f0(const Object013d73f0 *self) /* derived name */
{
    return self->unknown1c;
}
