/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a89f8.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16a89f8 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_0035b770): it stores the vtable, releases its Name at +0x298, then
 * tail-calls its base's destructor (0x8227e0). FUN_0134de90, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. The other members are not traced. */
Object016a89f8::~Object016a89f8() {}
