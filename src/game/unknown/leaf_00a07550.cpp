/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"

/* derived names: an object counted by the references an array holds
 * (leaf_00a07850.cpp's, here with the node's slots: its last reference
 * destroys it through slot 2, `call [rax+0x10]` at 0xa076b5) */
class Counted00a07850 : public Node00503fb0 /* derived name */
{
};

void FUN_00a07850(Array05943280<Ref00503fb0<Counted00a07850>> *array,
                  const Ref00503fb0<Counted00a07850> &value); /* derived name */

struct Object00a07550 { /* derived name */
    u8 unknown0[0x28];
    Array01343a80<Ref00503fb0<Counted00a07850>> array28; /* +0x28 */
};

/* derived name: appends a reference to the object to the holder's array
 * under the array's lock: the lock taken (`xor eax, eax; lock cmpxchg
 * [r15+0x3c], r14d` at 0xa07581, the creation lock's wait), the reference, held
 * for the call, appended by FUN_00a07850, the lock given back. */
// NONMATCHING: 112 of 118 equal under the link at 175 (D85: the call kept) with the count raised by a
// relaxed add (tlg_game_node.h): the release's count compared at `[r14+8]` where the base reuses the
// raise's address (`cmp [rbx], 0xdeadc0de`): two GEPs of the count survive the link (the reference's
// reload folded by the link's one GVN, the phi left for InstCombine), so the near `je` and the loop's
// padding follow. The append in this unit is inlined at stage 1 (225), so it is not one unit.
void FUN_00a07550(Object00a07550 *holder, Counted00a07850 *object)
{
    holder->array28.lock.lock();
    FUN_00a07850(&holder->array28, Ref00503fb0<Counted00a07850>(object));
    holder->array28.lock.unlock();
}
