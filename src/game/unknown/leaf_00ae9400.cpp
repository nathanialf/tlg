/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b3f50.h"

/* derived names: the complete destructor FUN_00ae9400: the array at +0x80
 * emptied (each reference released, then the block given back with no
 * capacity), then the members and the base torn down. The class's
 * key function: this unit emits the vtable and the deleting destructor
 * FUN_00ae95f0. */
// NONMATCHING: equal but for two instructions in the clear()'s reallocation block: the base forms
// D_5943280's address (`lea rax`) before the split copy of `this` (`mov rbx, rdi`), the build after
// it. The build's IR is the matched siblings' (0xae9b90) but for the offsets; with the array at
// +0x78 or more `this` stays in rdi, and greedy's split copy lands after the two loads and
// before the LEA, which the post-RA list scheduler then keeps first (NodeNum tie-break).
Object016b3f50::~Object016b3f50()
{
    array80.clear();
}
