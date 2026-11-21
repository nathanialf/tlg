/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_compiler00da5b20.h"

/* derived name: slot 267 of the vtable at 0x16bb0c0: records event 114
 * with the argument (recordEvent) and, when FUN_00db5690 takes it, passes the
 * argument on to the listener's event 114 (tlg_game_compiler00da5b20.h) */
void FUN_013c67a0(Compiler00da5b20 *self, int argument) /* derived name */
{
    if (recordEvent(self, 114, argument))
        self->listener->event114(argument);
}
