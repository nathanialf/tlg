/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"

/* derived names: prints its first variadic argument through vprintf with
 * the format "%s"; its one caller, FUN_00c831c0, passes a message. The first
 * argument is not read. */
struct Object00c831c0; /* derived name */

extern const char D_14b35d1[]; /* "%s" */

void FUN_00cfeb10(Object00c831c0 *self, ...) /* derived name */
{
    va_list args;
    va_start(args, self);
    vprintf(D_14b35d1, args);
    va_end(args);
}
