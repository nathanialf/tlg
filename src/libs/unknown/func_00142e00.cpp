/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 7 of the 0xa0-byte object of vtable 0x16a3f50: the
 * broad phase's tasks made on first use, then set up. */
void BroadPhaseLayers00142a40::FUN_00142e00(void *argument1, void *argument2, void *argument3,
                                            void *argument4)
{
    if (!tasks) {
        tasks = new BroadPhaseTasks0018d640();
    }
    tasks->FUN_0018d960(argument1, argument2, argument3, argument4);
}
