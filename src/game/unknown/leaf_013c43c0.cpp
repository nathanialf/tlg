/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_compiler00da5b20.h"

/* derived name: slot 227 of the vtable at 0x16bb0c0: records event 74
 * with the 64-bit argument (recordEvent) and, when FUN_00db5690 takes it, passes the
 * argument on to the listener's event 74 (tlg_game_compiler00da5b20.h) */
void FUN_013c43c0(Compiler00da5b20 *self, u64 argument) /* derived name */
{
    if (recordEvent(self, 74, argument))
        self->listener->event74(argument);
}
