/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b54b8.h"

/* derived names: the complete destructor of Object016b54b8 (vtable
 * 0x16b54b8): it stores the vtable, deletes the record it owns at +0x108 and clears the pointer, tears down its member at +0xc0, then
 * tail-calls its base's destructor FUN_00ca38f0. FUN_00b20670, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b54b8::~Object016b54b8()
{
    if (owned108 != 0) {
        delete owned108;
        owned108 = 0;
    }
    FUN_01392bf0(&unknownc0);
}
