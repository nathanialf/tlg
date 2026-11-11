/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: FUN_001a3e00 with a null first argument and its own six after
 * it, its result returned (the sixth goes on the stack). No direct caller or
 * pointer to it is found. The types are not traced. */
int FUN_001a3e00(void *context, void *a, u32 b, u32 c, u32 d, u32 e, u32 f); /* derived name */

int FUN_001a4100(void *a, u32 b, u32 c, u32 d, u32 e, u32 f) /* derived name */
{
    return FUN_001a3e00(0, a, b, c, d, e, f);
}
