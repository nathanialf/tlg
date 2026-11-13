/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: an object counted by the references an array holds (the
 * count at +0x8, tlg_game_node.h's Ref00503fb0); FUN_002e6d20 appends a
 * reference to the array (tlg_game_array.h's push; the growth is the
 * header's); the body is FUN_001b59d0's byte for byte. Called from 2 sites in 1 function (FUN_002e38f0). */
struct Counted002e6d20 {
    u8 unknown0[8];
    int references; /* +0x8 */
};

void FUN_002e6d20(Array05943280<Ref00503fb0<Counted002e6d20>> *array,
                  const Ref00503fb0<Counted002e6d20> &value) /* derived name */
{
    array->push(value);
}
