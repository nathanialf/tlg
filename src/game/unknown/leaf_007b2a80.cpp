/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016adf60.h"

/* derived name: not traced; reads the reference at +0xe8 (0x7b2c11) */
void FUN_007b2c00(Object016adf60 *self);

/* derived names: the complete destructor: FUN_007b2c00 first, then the
 * reference at +0xe8 released and the base's destructor run as a tail call;
 * FUN_007b2b40, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. */
Object016adf60::~Object016adf60()
{
    FUN_007b2c00(this);
}
