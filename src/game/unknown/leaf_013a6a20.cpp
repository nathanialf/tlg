/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: allocates its size rounded up to a multiple of 32 with
 * malloc, as a tail call; the object is unused; slot 14 of the vtable at
 * 0x16b9cb0 (its pointer at 0x16b9d30); slot 14 of the vtable at 0x16c8090
 * (its pointer at 0x16c8110). Class and method unknown. */
#include "stdlib.h"

struct Object013a6a20; /* derived name */

void *FUN_013a6a20(Object013a6a20 *, u32 size) /* derived name */
{
    return malloc((static_cast<size_t>(size) + 31) & ~static_cast<size_t>(31));
}
