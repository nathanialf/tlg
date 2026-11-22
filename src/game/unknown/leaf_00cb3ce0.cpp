/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b8db8.h"

/* derived names: slot 6 of the vtable at 0x16b9048 (its pointer at
 * 0x16b9088), stored by FUN_00cb3170 and FUN_013ad610: returns the pointer
 * held at +0x48 when the object held at +0x40 is present with its ints at
 * +0x50 and +0x30 both nonzero; otherwise, of the record the pointer at
 * +0x38 holds, the pointer at +0x88 when it is not null, else the one at
 * +0x80. The pointers' types are not traced. The class's key function: this
 * file emits its vtable and destructors. */
void *Object016b9048::slot6() const
{
    if (active())
        return held48.get();
    return unknown38->current();
}
