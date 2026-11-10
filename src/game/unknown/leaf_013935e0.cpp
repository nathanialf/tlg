/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: copies its count of bytes from its first argument to its
 * third with memcpy, stores the count where its fifth argument points, and
 * returns 0x40000000; the fourth argument is unused; slot 1 of the vtable at
 * 0x16cede8 (its pointer at 0x16cee00); slot 2 of the vtable at 0x16cede8 (its
 * pointer at 0x16cee08). The types are not traced. Class and method unknown. */
#include "tlg_libc.h"

struct Object013935e0; /* derived name */

int FUN_013935e0(Object013935e0 *, const void *source, int size, void *destination, void *,
                 int *copied) /* derived name */
{
    *copied = size;
    memcpy(destination, source, size);
    return 0x40000000;
}
