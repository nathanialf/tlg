/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_compiler00da5b20.h"

/* derived name: slot 253 of the vtable at 0x16bb0c0: records event 100
 * with the float argument (recordEvent) and, when FUN_00db5690 takes it, passes them
 * on to the listener's event 100 (tlg_game_compiler00da5b20.h) */
void FUN_013c5af0(Compiler00da5b20 *self, float argument) /* derived name */
{
    if (recordEvent(self, 100, argument))
        self->listener->event100(argument);
}
