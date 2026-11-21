/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_compiler00da5b20.h"

/* derived name: the event of a kind with the source's two ints, its current
 * token and one int argument, returned by value */
static inline Event016bb0c0 eventWith(Compiler00da5b20 *self, int kind, int argument)
{
    Source016bb0c0 *source = self->source;
    int unknown4 = source->slot4();
    int unknown8 = source->slot6();
    const Token016bb0c0 *token = source->slot8();
    Event016bb0c0 event;
    event.kind = kind;
    event.unknown4 = unknown4;
    event.unknown8 = unknown8;
    event.tokenType = token->type;
    event.value.tokenValue = token->value;
    event.value.arguments[0] = argument;
    return event;
}

/* derived name: slot 176 of the vtable at 0x16bb0c0: records event 23 (with
 * the source's two ints, its current token and the argument) and, when
 * FUN_00db5690 takes it, passes the event and the argument on to the
 * listener (tlg_game_compiler00da5b20.h) */
// NONMATCHING: the base tail-calls the listener (`jmp rax` after the canary
// check), so the record is not an escaping alloca when the unit marks tail calls
// (TailRecursionElimination.cpp:198-243: the byval call of FUN_00db5690 is an
// escape point); the event slots without an argument call it. The record built
// as a returned value gives the base's stores straight into the outgoing copy
// and its frame (0x68); left: the token type's load after the kind's store and
// the call kept, 46/73 single-file (round 399C).
void FUN_013c1650(Compiler00da5b20 *self, int argument) /* derived name */
{
    if (FUN_00db5690(self, eventWith(self, 23, argument)))
        self->listener->event23(argument);
}
