/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears the int at +0x194 and returns 1; FUN_00d8f350 takes
 * its address (lea at 0xd8fb46). Class and method unknown. */
struct Object00d90880 { /* derived name */
    u8 unknown0[0x194];
    int unknown194;
};

int FUN_00d90880(Object00d90880 *self) /* derived name */
{
    self->unknown194 = 0;
    return 1;
}
