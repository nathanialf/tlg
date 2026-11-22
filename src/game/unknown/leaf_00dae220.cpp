/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 52 of the vtable at 0x16bb0c0 (its pointer at 0x16bb270):
 * FUN_00dae0a0's body with the entry's kind 2 */
void FUN_00dae220(CodeGen016bb0c0 *self, void *name) /* derived name */
{
    Entry016bb0c0 *entry = self->entries.push();
    entry->value = name;
    entry->unknown8 = 2;
    Expression016bb0c0 *top = self->function->expressions.top;
    FUN_00da8700(self, top);
    Expression016bb0c0 key;
    initExpression(&key, 4, stringConstant(self, name), 4);
    FUN_00da88a0(self, top, &key);
}
