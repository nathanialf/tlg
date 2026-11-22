/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 95 of the vtable at 0x16bb0c0 (its pointer at 0x16bb3c8):
 * a list item of the table constructor (Lua's listfield): the
 * count of list items checked against its limit, the expression on top
 * copied as the last item and popped, the counts of list items and items
 * to store raised */
void FUN_00daa6f0(CodeGen016bb0c0 *self) /* derived name */
{
    Constructor016bb0c0 *cc = self->constructors.top;
    checkLimit(self, cc->listItems, 0x7fffffff, "array items in a table constructor.");
    cc->item = *self->functions.top->expressions.top;
    FUN_013bdca0(&self->functions.top->expressions);
    ++cc->listItems;
    ++cc->toStore;
}
