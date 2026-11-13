/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: an object counted by the references an array holds (the
 * count at +0x8, tlg_game_node.h's Ref00503fb0); FUN_004af640 appends a
 * reference to the array (tlg_game_array.h's push; the growth is the
 * header's); the body is FUN_001b59d0's byte for byte. Called from 6 sites in 4 functions (FUN_004ac3d0, FUN_008218b0, FUN_00c573b0, _ZN14Object00c55550D1Ev). A caller forms the array's address at +0x58 of its object. */
struct Counted004af640 {
    u8 unknown0[8];
    int references; /* +0x8 */
};

void FUN_004af640(Array05943280<Ref00503fb0<Counted004af640>> *array,
                  const Ref00503fb0<Counted004af640> &value) /* derived name */
{
    array->push(value);
}
