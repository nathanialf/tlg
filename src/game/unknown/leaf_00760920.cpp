/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: an object counted by the references an array holds (the
 * count at +0x8, tlg_game_node.h's Ref00503fb0); FUN_00760920 appends a
 * reference to the array (tlg_game_array.h's push; the growth is the
 * header's); the body is FUN_001b59d0's byte for byte. Called from 11 sites in 6 functions (FUN_0075d990, FUN_0075de10, FUN_0075e570, FUN_009fa9f0 and others). A caller forms the array's address at +0x180 and +0x28 of its object. */
struct Counted00760920 {
    u8 unknown0[8];
    int references; /* +0x8 */
};

void FUN_00760920(Array05943280<Ref00503fb0<Counted00760920>> *array,
                  const Ref00503fb0<Counted00760920> &value) /* derived name */
{
    array->push(value);
}
