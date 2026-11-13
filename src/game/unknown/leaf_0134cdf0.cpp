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

// NONMATCHING: the growth is the base's; the loop's count: the base tests the 32-bit count,
// loads the other array's block and only then widens the count into the register that held
// the other array (`test ecx, ecx; je; mov rbx, [r14]; mov r14d, ecx; shl r14, 3`); the build
// widens it above the test into a fifth saved register (`mov r12d, ecx; test ecx, ecx`). An
// index loop over a local count gives a 32-bit countdown (`dec r12d`), further away.
void FUN_0134cdf0(Array05943280<Ref00503fb0<Counted003441e0>> *self,
                  const Array05943280<Ref00503fb0<Counted003441e0>> *other) /* derived name */
{
    self->reserve(self->size() + other->size());
    const Ref00503fb0<Counted003441e0> *end = other->end();
    for (const Ref00503fb0<Counted003441e0> *it = other->begin(); it != end; ++it)
        FUN_003441e0(self, *it);
}
