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
// NONMATCHING: an inline-cost margin at the link stage: the base calls FUN_00a07850 (192 bytes), the
// link's inliner takes it: the call costs 210 to 214 against the threshold 225 (opt -std-link-opts
// -inline-threshold over this unit and the append's linked). Built alone the function is the base's
// through the lock's loop (both `pushfq; pop rax; push rax; popfq` pairs among them).
void FUN_00a07550(Object00a07550 *holder, Counted00a07850 *object)
{
    holder->array28.lock.lock();
    FUN_00a07850(&holder->array28, Ref00503fb0<Counted00a07850>(object));
    holder->array28.lock.unlock();
}
