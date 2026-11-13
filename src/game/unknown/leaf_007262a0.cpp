/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: an object counted by the references an array holds (the
 * count at +0x8, tlg_game_node.h's Ref00503fb0); FUN_007262a0 appends a
 * reference to the array (tlg_game_array.h's push; the growth is the
 * header's); the body is FUN_001b59d0's byte for byte. Called from 4 sites in 3 functions (FUN_007204d0, FUN_0084a0a0, FUN_00858110). */
struct Counted007262a0 {
    u8 unknown0[8];
    int references; /* +0x8 */
};

void FUN_007262a0(Array05943280<Ref00503fb0<Counted007262a0>> *array,
                  const Ref00503fb0<Counted007262a0> &value) /* derived name */
{
    array->push(value);
}
