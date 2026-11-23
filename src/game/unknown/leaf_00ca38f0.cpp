/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b8d40.h"
#include "tlg_game_object016cc398.h"
#include "tlg_game_object01388080.h"
#include "tlg_game_table00ca41c0.h"

/* derived names: the complete destructor: the object registered under the
 * name of this object's type (the table at +0xf8 of the object at
 * 0x5938c40) is told through its slot 8 that this object goes, then the
 * root's destructor follows (its two names, inlined by the link).
 * FUN_00ca39b0, slot 1, is the deleting one, holding the same body. The
 * destructor is the class's key function, so this file emits the
 * vtable. */
Object016b8d40::~Object016b8d40()
{
    Object016cc398 *owner =
        static_cast<Object016cc398 *>(D_5938c40->objects->find(type->name.index));
    if (owner)
        owner->slot8(this);
}
