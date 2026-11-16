/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"

/* derived names: an object counted by the references an array holds
 * (leaf_00c238c0.cpp's, here with the node's slots: its last reference
 * destroys it through slot 2, `call [rax+0x10]` at 0xc20d65) */
class Counted00c238c0 : public Object016b9108 /* derived name */
{
};

void FUN_00c238c0(Array05943280<Ref00503fb0<Counted00c238c0>> *array,
                  const Ref00503fb0<Counted00c238c0> &value); /* derived name */

struct Object00c20c00 { /* derived name */
    u8 unknown0[0x18];
    Array01343a80<Ref00503fb0<Counted00c238c0>> array18; /* +0x18 */
};

/* derived name: appends a reference to the object to the holder's array
 * under the array's lock: the lock taken (`xor eax, eax; lock cmpxchg
 * [r15+0x2c], r14d` at 0xc20c31, the creation lock's wait), the reference, held
 * for the call, appended by FUN_00c238c0, the lock given back. */
// NONMATCHING: 112 of 118 equal under the link at 175 (D85: the call kept) with the count raised by a
// relaxed add (tlg_game_node.h): the release's count compared at `[r14+8]` where the base reuses the
// raise's address (`cmp [rbx], 0xdeadc0de`): two GEPs of the count survive the link (the reference's
// reload folded by the link's one GVN, the phi left for InstCombine), so the near `je` and the loop's
// padding follow. The append in this unit is inlined at stage 1 (225), so it is not one unit.
void FUN_00c20c00(Object00c20c00 *holder, Counted00c238c0 *object)
{
    holder->array18.lock.lock();
    FUN_00c238c0(&holder->array18, Ref00503fb0<Counted00c238c0>(object));
    holder->array18.lock.unlock();
}
