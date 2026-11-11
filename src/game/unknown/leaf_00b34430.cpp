/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_log.h"

/* derived names: calls the variadic FUN_00c831d0 with the object, the format
 * "%s" and its third argument (al zeroed, no vector arguments), as a tail
 * call, its second unused; slot 3 of the vtable at 0x16b5670 (its pointer at
 * 0x16b5698), the vtable stored by FUN_00b33e00. FUN_00c831d0 formats into a
 * 0x10e0-byte frame. The types and the return type are not traced. Class and
 * method unknown. */
struct Object00b34430; /* derived name */

void FUN_00b34430(Object00b34430 *self, void *, const char *text) /* derived name */
{
    FUN_00c831d0(self, "%s", text);
}
