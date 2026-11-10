/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_types.h"

/* derived names: fseek of the stream its argument holds at +0x0 to the given
 * offset from the start, returning 1 when it succeeded and 0 otherwise (an
 * int: the base widens the sete); the object is unused; slot 13 of the vtable
 * at 0x16bdb40 (its pointer at 0x16bdbb8) (the vtable whose slot 14 is
 * FUN_00e5be70). The offset is unsigned 32-bit (movl into the long). Class
 * and method unknown. */
struct Object00e5be50; /* derived name */

struct File00e5be50 { /* derived name */
    FILE *unknown0;
};

int FUN_00e5be50(Object00e5be50 *, File00e5be50 *file, u32 offset) /* derived name */
{
    return fseek(file->unknown0, offset, SEEK_SET) == 0;
}
