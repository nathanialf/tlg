/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_compiler00da5b20.h"

/* derived name: slot 239 of the vtable at 0x16bb0c0: records event 86
 * with two int arguments (recordEvent) and, when FUN_00db5690 takes it, passes them
 * on to the listener's event 86 (tlg_game_compiler00da5b20.h) */
void FUN_013c4e80(Compiler00da5b20 *self, int argument, int argument2) /* derived name */
{
    if (recordEvent(self, 86, argument, argument2))
        self->listener->event86(argument, argument2);
}
