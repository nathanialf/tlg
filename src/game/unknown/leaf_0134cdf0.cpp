/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: FUN_0134cdf0 appends every reference of another array to
 * an array of counted references (tlg_game_array.h; leaf_003441e0.cpp has
 * the append of one and the counted object): the block grows once to the
 * sum of the counts, then the references are appended one by one. */
struct Counted003441e0;

void FUN_003441e0(Array05943280<Ref00503fb0<Counted003441e0>> *array,
                  const Ref00503fb0<Counted003441e0> &value); /* derived name */

void FUN_0134cdf0(Array05943280<Ref00503fb0<Counted003441e0>> *self,
                  const Array05943280<Ref00503fb0<Counted003441e0>> *other) /* derived name */
{
    self->reserve(self->size() + other->size());
    const Ref00503fb0<Counted003441e0> *end = other->end();
    for (const Ref00503fb0<Counted003441e0> *it = other->begin(); it != end; ++it)
        FUN_003441e0(self, *it);
}
