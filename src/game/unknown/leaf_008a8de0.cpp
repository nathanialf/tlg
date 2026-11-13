/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: an object counted by the references an array holds (the
 * count at +0x8, tlg_game_node.h's Ref00503fb0); FUN_008a8de0 appends a
 * reference to the array (tlg_game_array.h's push; the growth is the
 * header's); the body is FUN_001b59d0's byte for byte. Called from 12 sites in 5 functions (FUN_00880c00, FUN_0088b4e0, FUN_00c32940, FUN_00d6f0f0 and others). */
struct Counted008a8de0 {
    u8 unknown0[8];
    int references; /* +0x8 */
};

void FUN_008a8de0(Array05943280<Ref00503fb0<Counted008a8de0>> *array,
                  const Ref00503fb0<Counted008a8de0> &value) /* derived name */
{
    array->push(value);
}
