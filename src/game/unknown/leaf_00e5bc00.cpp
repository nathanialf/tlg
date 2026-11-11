/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: whether the file its second argument names can be opened for
 * reading ("rb"): opened and closed again; slot 6 of the vtable at 0x16bdb40
 * (its pointer at 0x16bdb80), stored by FUN_00c4fdb0 and the destructors
 * FUN_00e5b7e0 and FUN_00e5b830. The object itself is not read. */
struct Object00e5bc00; /* derived name */

int FUN_00e5bc00(Object00e5bc00 *, const char *path) /* derived name */
{
    int exists = 0;
    FILE *file = fopen(path, "rb");
    if (file) {
        fclose(file);
        exists = 1;
    }
    return exists;
}
