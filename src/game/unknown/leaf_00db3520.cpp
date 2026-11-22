/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 139 of the vtable at 0x16bb0c0 (its pointer at 0x16bb528):
 * a local declared with a type: the type name resolved by
 * FUN_00db3300 to a type (-1 none) and a structure, the local declared at
 * the next index of +0x17b0 with them, a record of the type (and the
 * structure for type 12, a structure) pushed on the stack at +0x1d68, the
 * index raised */
// NONMATCHING: the base reads the type and the structure once after FUN_00db3300 and keeps them
// across FUN_00daba60 and the push (its out-parameters not captured: FUN_00db3300 not written);
// the build reads them again after each call
void FUN_00db3520(CodeGen016bb0c0 *self, Name016bb0c0 *name, void *typeName) /* derived name */
{
    int type = -1;
    void *structure;
    FUN_00db3300(self, typeName, &type, &structure);
    FUN_00daba60(self, name, self->function->unknown17b0, type, structure);
    Slot016bb0c0 *slot = self->function->slots.push();
    slot->unknown8 = type == 12 ? structure : 0;
    slot->unknown0 = type;
    slot->unknown10 = 1;
    ++self->function->unknown17b0;
}
