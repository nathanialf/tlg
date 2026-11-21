/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_compiler00da5b20.h"

/* derived name: slot 275 of the vtable at 0x16bb0c0: records event 122
 * with the argument (recordEvent) and, when FUN_00db5690 takes it, passes the
 * argument on to the listener's event 122 (tlg_game_compiler00da5b20.h) */
void FUN_013c6ed0(Compiler00da5b20 *self, int argument) /* derived name */
{
    if (recordEvent(self, 122, argument))
        self->listener->event122(argument);
}
