/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback FUN_00ef4670 passes (lea at 0xef47be, in r8):
 * calls FUN_00ef8c60 on its first argument with 2 and 1, as a tail call. The
 * types and the return type are not traced. Class and method unknown. */
struct Object00ef9950; /* derived name */

void FUN_00ef8c60(Object00ef9950 *self, int, int); /* derived name */

void FUN_00ef9950(Object00ef9950 *self) /* derived name */
{
    FUN_00ef8c60(self, 2, 1);
}
