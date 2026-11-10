/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears the pointer at +0x210 and the int at +0x218; slot 2 of
 * the vtable at 0x16bf1b8 (its pointer at 0x16bf1d8); slot 2 of the vtable at
 * 0x16c1f60 (its pointer at 0x16c1f80). Class and method unknown. */
struct Object013d1b10 { /* derived name */
    u8 unknown0[0x210];
    void *unknown210;
    int unknown218;
};

void FUN_013d1b10(Object013d1b10 *self) /* derived name */
{
    self->unknown210 = 0;
    self->unknown218 = 0;
}
