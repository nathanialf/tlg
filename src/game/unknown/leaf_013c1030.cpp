/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_compiler00da5b20.h"

/* derived name: slot 169 of the vtable at 0x16bb0c0: records event 16 (with
 * the source's two ints and its current token) and, when FUN_00db5690 takes
 * it, passes the event on to the listener (tlg_game_compiler00da5b20.h) */
void FUN_013c1030(Compiler00da5b20 *self) /* derived name */
{
    Source016bb0c0 *source = self->source;
    int unknown4 = source->slot4();
    int unknown8 = source->slot6();
    const Token016bb0c0 *token = source->slot8();
    Event016bb0c0 event;
    event.kind = 16;
    event.unknown4 = unknown4;
    event.unknown8 = unknown8;
    event.tokenType = token->type;
    EventValue016bb0c0 value;
    value.tokenValue = token->value;
    event.value = value;
    if (FUN_00db5690(self, event))
        self->listener->event16();
}
