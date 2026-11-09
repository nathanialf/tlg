/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00b41780 with the object and the pointer at +0xa0,
 * as a tail call; slot 56 of the vtable at 0x16cfb98 (its pointer at
 * 0x16cfd68), the vtable stored by FUN_00b40f10. FUN_00b41780 tests the
 * pointer for null and reads its count at +0x70 and pointer at +0x68. The
 * pointee's type and the return type are not traced. Class and method unknown. */
struct Target01398700; /* derived name */

struct Object01398700 { /* derived name */
    u8 unknown0[0xa0];
    Target01398700 *unknowna0;
};

void FUN_00b41780(Object01398700 *self, Target01398700 *value); /* derived name */

void FUN_01398700(Object01398700 *self) /* derived name */
{
    FUN_00b41780(self, self->unknowna0);
}
