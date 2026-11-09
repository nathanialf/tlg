/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback FUN_001f4f10 passes (lea at 0x1f4f2e, in rsi):
 * calls FUN_0082eee0 on its first argument with 0 and returns 1. The 32-bit
 * zero is written int; the types are not traced. Class and method unknown. */
struct Object0082f320; /* derived name */

struct Target0082eee0; /* derived name */

void FUN_0082eee0(Object0082f320 *self, Target0082eee0 *target); /* derived name */

int FUN_0082f320(Object0082f320 *self) /* derived name */
{
    FUN_0082eee0(self, 0);
    return 1;
}
