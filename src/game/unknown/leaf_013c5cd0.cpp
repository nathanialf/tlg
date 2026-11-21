/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_compiler00da5b20.h"

/* derived name: slot 255 of the vtable at 0x16bb0c0: records event 102
 * with the 64-bit argument and an int (recordEvent) and, when FUN_00db5690 takes it, passes them
 * on to the listener's event 102 (tlg_game_compiler00da5b20.h) */
void FUN_013c5cd0(Compiler00da5b20 *self, u64 argument, int argument2) /* derived name */
{
    if (recordEvent(self, 102, argument, argument2))
        self->listener->event102(argument, argument2);
}
