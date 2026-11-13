/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: an object counted by the references an array holds (the
 * count at +0x8, tlg_game_node.h's Ref00503fb0); FUN_001b59d0 appends a
 * reference to the array (tlg_game_array.h's push; the growth is the
 * header's). Called from 4 sites in 2 functions (FUN_001b51c0, FUN_01331d20). */
struct Counted001b59d0 {
    u8 unknown0[8];
    int references; /* +0x8 */
};

void FUN_001b59d0(Array05943280<Ref00503fb0<Counted001b59d0>> *array,
                  const Ref00503fb0<Counted001b59d0> &value) /* derived name */
{
    array->push(value);
}
