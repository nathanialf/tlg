/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: an object counted by the references an array holds (the
 * count at +0x8, tlg_game_node.h's Ref00503fb0); FUN_001b59d0 appends a
 * reference to the array (tlg_game_array.h). Its callers are not written. */
struct Counted001b59d0 {
    u8 unknown0[8];
    int references; /* +0x8 */
};

// NONMATCHING: the base materialises the table's address (`lea rcx, [D_5943280]`) once in the
// growth block, used by both arms, and holds the index in edx; this build (and the prebuilt 3.7.1
// module) puts a `lea` in each arm; the owner's index read before the capacity store is the base's
// (cookbook 1400). The other 101 appends of the queue are this body byte for byte (c217/g102h.txt)
void FUN_001b59d0(Array05943280<Ref00503fb0<Counted001b59d0>> *array,
                  const Ref00503fb0<Counted001b59d0> &value) /* derived name */
{
    array->push(value);
}
