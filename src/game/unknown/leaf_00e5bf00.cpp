/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: fwrite of its buffer and byte count (size 1) on the stream
 * its argument holds at +0x0, as a tail call, returning the count; the object
 * is unused; slot 18 of the vtable at 0x16bdb40 (its pointer at 0x16bdbe0)
 * (the vtable whose slot 5 is FUN_00e5bbf0). Class and method unknown. */
#include "tlg_libc.h"

struct Object00e5bf00; /* derived name */

struct File00e5bf00 { /* derived name */
    FILE *unknown0;
};

size_t FUN_00e5bf00(Object00e5bf00 *, File00e5bf00 *file, const void *buffer,
                    size_t size) /* derived name */
{
    return fwrite(buffer, 1, size, file->unknown0);
}
