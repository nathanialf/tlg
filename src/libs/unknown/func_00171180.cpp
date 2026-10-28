/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 12 of the vtable at 0x16a5870, the body's command
 * built and executed at once. */
void FUN_00171180(void *self, CommandOwner00171180 *owner, const u32 &bodyId)
{
    BodyCommand00171180 command(bodyId);
    owner->dispatcher->exec(command);
}
