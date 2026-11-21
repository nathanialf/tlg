/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_compiler00da5b20.h"

/* derived name: slot 287 of the vtable at 0x16bb0c0: records event 141
 * with two 64-bit arguments (recordEvent) and, when FUN_00db5690 takes it, passes them
 * on to the listener's event 141 (tlg_game_compiler00da5b20.h) */
void FUN_013c7970(Compiler00da5b20 *self, u64 argument, u64 argument2) /* derived name */
{
    if (recordEvent(self, 141, argument, argument2))
        self->listener->event141(argument, argument2);
}
