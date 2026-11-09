/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hk_thread.h"

/* derived names: a callback that runs FUN_00017920 on its argument with the
 * mode 0, as the library region's FUN_00007730 does; FUN_00e99d00 passes its
 * address (lea at 0xe99d42) to FUN_00007600 with the pointer at +0x408 of its
 * record as the argument. */
void FUN_00ea2e60(void *argument) /* derived name */
{
    FUN_00017920(static_cast<Class168e810 *>(argument), 0);
}
