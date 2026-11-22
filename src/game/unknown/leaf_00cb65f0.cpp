/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the complete destructor of Object016b9108 (vtable
 * 0x16b9108): the body is empty and the two names are destroyed, +0x10 then
 * +0xc. FUN_00cb6670, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. */
Object016b9108::~Object016b9108() {}

/* derived name: one reference more for a copy of a counted reference
 * (tlg_game_node.h's Ref00503fb0), the count the counted base's. Its body
 * has no address in the executable: every call was inlined by the link and
 * the copy discarded, as func_00cbb000.cpp's threadMayUse was. */
void raiseReference(Counted00c14bc0 *object)
{
    addReference(object);
}
