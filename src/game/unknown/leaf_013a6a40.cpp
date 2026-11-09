/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a virtual method that releases its argument with free as a
 * tail call, the object unused; slot 15 of the vtable at 0x16b9cb0 (its
 * pointer at 0x16b9d38), the vtable stored by FUN_001afd70; slot 15 counted
 * from the nearest stored vtable, at 0x16c8090 (its pointer at 0x16c8118), the
 * vtable stored by FUN_00c32190 FUN_00c324b0. Class and method unknown. */
#include <stdlib.h>

struct Object013a6a40;

void FUN_013a6a40(Object013a6a40 *self, void *block) /* derived name */
{
    free(block);
}
