/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00c57940 with its second argument and 1, as a tail
 * call; the object is unused. The types and the return type are not traced;
 * slot 8 of the vtable at 0x16a8030 (its pointer at 0x16a8080), the vtable
 * stored by FUN_002bf920 FUN_002bfaa0 FUN_002bfb60. Class and method unknown. */
struct Object002bfd80; /* derived name */
struct Target00c57940; /* derived name */

void FUN_00c57940(Target00c57940 *target, int); /* derived name */

void FUN_002bfd80(Object002bfd80 *, Target00c57940 *target) /* derived name */
{
    FUN_00c57940(target, 1);
}
