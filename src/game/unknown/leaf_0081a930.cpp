/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"

/* derived names: an object counted by the references an array holds
 * (leaf_00751ca0.cpp's, here with the node's slots: its last reference
 * destroys it through slot 2, `call [rax+0x10]` at 0x81aa95) */
class Counted00751ca0 : public Object016b9108 /* derived name */
{
};

void FUN_00751ca0(Array05943280<Ref00503fb0<Counted00751ca0>> *array,
                  const Ref00503fb0<Counted00751ca0> &value); /* derived name */

struct Object0081a930 { /* derived name */
    u8 unknown0[0x10];
    Array01343a80<Ref00503fb0<Counted00751ca0>> array10; /* +0x10 */
};

/* derived name: appends a reference to the object to the holder's array
 * under the array's lock: the lock taken (`xor eax, eax; lock cmpxchg
 * [r15+0x24], r14d` at 0x81a961, the creation lock's wait), the reference, held
 * for the call, appended by FUN_00751ca0, the lock given back. */
// NONMATCHING: 112 of 118 equal under the link at 175 (D85: the call kept) with the count raised by a
// relaxed add (tlg_game_node.h): the release's count compared at `[r14+8]` where the base reuses the
// raise's address (`cmp [rbx], 0xdeadc0de`): two GEPs of the count survive the link (the reference's
// reload folded by the link's one GVN, the phi left for InstCombine), so the near `je` and the loop's
// padding follow. The append in this unit is inlined at stage 1 (225), so it is not one unit.
/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: cost 415 at the
 * link, over its threshold of 175: one signature changes no row) */
void FUN_0081a930(Object0081a930 *holder, Counted00751ca0 *object)
{
    holder->array10.lock.lock();
    FUN_00751ca0(&holder->array10, Ref00503fb0<Counted00751ca0>(object));
    holder->array10.lock.unlock();
}
