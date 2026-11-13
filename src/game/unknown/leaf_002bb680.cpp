/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: an object counted by the references an array holds (the
 * count at +0x8, tlg_game_node.h's Ref00503fb0); FUN_002bb680 appends a
 * reference to the array (tlg_game_array.h's push; the growth is the
 * header's); the body is FUN_001b59d0's byte for byte. Called from 10 sites in 3 functions (FUN_002a8f50, FUN_002b67a0, FUN_002c26c0). A caller forms the array's address at +0x28 and +0x40 of its object. */
struct Counted002bb680 {
    u8 unknown0[8];
    int references; /* +0x8 */
};

void FUN_002bb680(Array05943280<Ref00503fb0<Counted002bb680>> *array,
                  const Ref00503fb0<Counted002bb680> &value) /* derived name */
{
    array->push(value);
}
