/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00501450(self), then sets the byte at +0x250.
 * Unknown owner. */
struct Owner4eee50 {
    u8 unknown0[0x250];
    u8 flag;
};

void FUN_00501450(Owner4eee50 *); /* derived name */

void FUN_004eee50(Owner4eee50 *self) /* derived name */
{
    FUN_00501450(self);
    self->flag = 1;
}
