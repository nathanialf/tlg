/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: an object counted by the references an array holds (the
 * count at +0x8, tlg_game_node.h's Ref00503fb0); FUN_00b1aec0 appends a
 * reference to the array (tlg_game_array.h's push; the growth is the
 * header's); the body is FUN_001b59d0's byte for byte. Called from 3 sites in 1 function (FUN_00b15960). A caller forms the array's address at +0x2b0 and +0x2e0 of its object. */
struct Counted00b1aec0 {
    u8 unknown0[8];
    int references; /* +0x8 */
};

void FUN_00b1aec0(Array05943280<Ref00503fb0<Counted00b1aec0>> *array,
                  const Ref00503fb0<Counted00b1aec0> &value) /* derived name */
{
    array->push(value);
}
