/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_009f0260 with its second argument and its third and
 * fourth (32-bit) as a tail call and returns its result, 0 when the second
 * argument is null; the object is unused; slot 8 of the vtable at 0x16d4e10
 * (its pointer at 0x16d4e60); slot 8 of the vtable at 0x16d4e70 (its pointer
 * at 0x16d4ec0); and 10 more pointers. The argument types are not traced.
 * Class and method unknown. */
struct Object013eb1f0; /* derived name */
struct Target009f0260; /* derived name */

int FUN_009f0260(Target009f0260 *target, int a, int b); /* derived name */

int FUN_013eb1f0(Object013eb1f0 *, Target009f0260 *target, int a, int b) /* derived name */
{
    if (target) {
        return FUN_009f0260(target, a, b);
    }
    return 0;
}
