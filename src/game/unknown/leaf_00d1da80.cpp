/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"

/* derived names: an object counted by the references an array holds
 * (leaf_00d1dec0.cpp's, here with the node's slots: its last reference
 * destroys it through slot 2, `call [rax+0x10]` at 0xd1dbe5) */
class Counted00d1dec0 : public Node00503fb0 /* derived name */
{
};

void FUN_00d1dec0(Array05943280<Ref00503fb0<Counted00d1dec0>> *array,
                  const Ref00503fb0<Counted00d1dec0> &value); /* derived name */

struct Object00d1da80 { /* derived name */
    u8 unknown0[0x8];
    Array01343a80<Ref00503fb0<Counted00d1dec0>> array8; /* +0x8 */
};

/* derived name: appends a reference to the object to the holder's array
 * under the array's lock: the lock taken (`xor eax, eax; lock cmpxchg
 * [r15+0x1c], r14d` at 0xd1dab1, the creation lock's wait), the reference, held
 * for the call, appended by FUN_00d1dec0, the lock given back. */
// NONMATCHING: 112 of 118 equal under the link at 175 (D85: the call kept) with the count raised by a
// relaxed add (tlg_game_node.h): the release's count compared at `[r14+8]` where the base reuses the
// raise's address (`cmp [rbx], 0xdeadc0de`): two GEPs of the count survive the link (the reference's
// reload folded by the link's one GVN, the phi left for InstCombine), so the near `je` and the loop's
// padding follow. The append in this unit is inlined at stage 1 (225), so it is not one unit.
void FUN_00d1da80(Object00d1da80 *holder, Counted00d1dec0 *object)
{
    holder->array8.lock.lock();
    FUN_00d1dec0(&holder->array8, Ref00503fb0<Counted00d1dec0>(object));
    holder->array8.lock.unlock();
}
