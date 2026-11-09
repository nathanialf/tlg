/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the thread-local int at 0x16dc0b0 (tp offset -32;
 * read also by FUN_00d69cc0, FUN_00d6d090 and FUN_00d6db10); the object is
 * unused; slot 38 of the vtable at 0x16b9cb0 (its pointer at 0x16b9df0); slot
 * 10 of the vtable at 0x16c8208 (its pointer at 0x16c8268). Class and method
 * unknown. */
struct Object00d6a930; /* derived name */

extern __thread int D_16dc0b0;

int FUN_00d6a930(Object00d6a930 *) /* derived name */
{
    return D_16dc0b0;
}
