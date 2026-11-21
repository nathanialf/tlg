/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_compiler00da5b20.h"

/* derived names: slot 131 of the vtable at 0x16bb0c0 (its pointer at
 * 0x16bb4e8; also at 0x5812b20): pushes an expression and fills nothing */
void FUN_00da5b20(Compiler00da5b20 *self) /* derived name */
{
    pushExpression(self->funcState);
}

int recordEvent(Compiler00da5b20 *self, int kind, int argument) /* derived name */
{
    Source016bb0c0 *source = self->source;
    int unknown4 = source->slot4();
    int unknown8 = source->slot6();
    const Token016bb0c0 *token = source->slot8();
    return FUN_00db5690(
        self, Event016bb0c0(kind, unknown4, unknown8, token->type, token->value, argument));
}

int recordEvent(Compiler00da5b20 *self, int kind, u64 argument) /* derived name */
{
    Source016bb0c0 *source = self->source;
    int unknown4 = source->slot4();
    int unknown8 = source->slot6();
    const Token016bb0c0 *token = source->slot8();
    return FUN_00db5690(
        self, Event016bb0c0(kind, unknown4, unknown8, token->type, token->value, argument));
}

int recordEvent(Compiler00da5b20 *self, int kind, float argument) /* derived name */
{
    Source016bb0c0 *source = self->source;
    int unknown4 = source->slot4();
    int unknown8 = source->slot6();
    const Token016bb0c0 *token = source->slot8();
    return FUN_00db5690(
        self, Event016bb0c0(kind, unknown4, unknown8, token->type, token->value, argument));
}

int recordEvent(Compiler00da5b20 *self, int kind, int argument, int argument2) /* derived name */
{
    Source016bb0c0 *source = self->source;
    int unknown4 = source->slot4();
    int unknown8 = source->slot6();
    const Token016bb0c0 *token = source->slot8();
    return FUN_00db5690(self, Event016bb0c0(kind, unknown4, unknown8, token->type, token->value,
                                            argument, argument2));
}

int recordEvent(Compiler00da5b20 *self, int kind, u64 argument, int argument2) /* derived name */
{
    Source016bb0c0 *source = self->source;
    int unknown4 = source->slot4();
    int unknown8 = source->slot6();
    const Token016bb0c0 *token = source->slot8();
    return FUN_00db5690(self, Event016bb0c0(kind, unknown4, unknown8, token->type, token->value,
                                            argument, argument2));
}

int recordEvent(Compiler00da5b20 *self, int kind, u64 argument, u64 argument2) /* derived name */
{
    Source016bb0c0 *source = self->source;
    int unknown4 = source->slot4();
    int unknown8 = source->slot6();
    const Token016bb0c0 *token = source->slot8();
    return FUN_00db5690(self, Event016bb0c0(kind, unknown4, unknown8, token->type, token->value,
                                            argument, argument2));
}
