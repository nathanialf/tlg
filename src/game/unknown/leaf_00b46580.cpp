/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: FUN_00b46580 appends a counted reference to the array at
 * 0x58339c0 (tlg_game_array.h's push), which the function reaches directly:
 * the file's own object (D17). The array is destroyed at exit, so the
 * counted class is one the references can release; it is this unit's own
 * (the count at +0x8; not traced further): the array's append over it has
 * this one caller, and the link inlines it here, where the append over a
 * class other units append too stays a call (FUN_0138e360). */
struct Counted00b46580 { /* derived name */
    u8 unknown0[8];
    int references; /* +0x8 */
};

static Array05943280<Ref00503fb0<Counted00b46580>> D_58339c0;

void FUN_00b46580(const Ref00503fb0<Counted00b46580> &value) /* derived name */
{
    D_58339c0.push(value);
}
