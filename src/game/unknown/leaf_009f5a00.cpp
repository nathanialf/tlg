/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"

/* derived names: an object counted by the references an array holds
 * (leaf_009f5bc0.cpp's, here with the node's slots: its last reference
 * destroys it through slot 2, `call [rax+0x10]` at 0x9f5b65) */
class Counted009f5bc0 : public Node00503fb0 /* derived name */
{
};

void FUN_009f5bc0(Array05943280<Ref00503fb0<Counted009f5bc0>> *array,
                  const Ref00503fb0<Counted009f5bc0> &value); /* derived name */

struct Object009f5a00 { /* derived name */
    u8 unknown0[0x28];
    Array01343a80<Ref00503fb0<Counted009f5bc0>> array28; /* +0x28 */
};

/* derived name: appends a reference to the object to the holder's array
 * under the array's lock: the lock taken (`xor eax, eax; lock cmpxchg
 * [r15+0x3c], r14d` at 0x9f5a31, the creation lock's wait), the reference, held
 * for the call, appended by FUN_009f5bc0, the lock given back. */
// NONMATCHING: an inline-cost margin at the link stage: the base calls FUN_009f5bc0 (192 bytes), the
// link's inliner takes it: the call costs 210 to 214 against the threshold 225 (opt -std-link-opts
// -inline-threshold over this unit and the append's linked). Built alone the function is the base's
// through the lock's loop (both `pushfq; pop rax; push rax; popfq` pairs among them).
void FUN_009f5a00(Object009f5a00 *holder, Counted009f5bc0 *object)
{
    holder->array28.lock.lock();
    FUN_009f5bc0(&holder->array28, Ref00503fb0<Counted009f5bc0>(object));
    holder->array28.lock.unlock();
}
