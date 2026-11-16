/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"

/* derived names: an object counted by the references an array holds
 * (leaf_00c23980.cpp's, here with the node's slots: its last reference
 * destroys it through slot 2, `call [rax+0x10]` at 0xc20f25) */
class Counted00c23980 : public Node00503fb0 /* derived name */
{
};

void FUN_00c23980(Array05943280<Ref00503fb0<Counted00c23980>> *array,
                  const Ref00503fb0<Counted00c23980> &value); /* derived name */

struct Object00c20dc0 { /* derived name */
    u8 unknown0[0x30];
    Array01343a80<Ref00503fb0<Counted00c23980>> array30; /* +0x30 */
};

/* derived name: appends a reference to the object to the holder's array
 * under the array's lock: the lock taken (`xor eax, eax; lock cmpxchg
 * [r15+0x44], r14d` at 0xc20df1, the creation lock's wait), the reference, held
 * for the call, appended by FUN_00c23980, the lock given back. */
// NONMATCHING: an inline-cost margin at the link stage: the base calls FUN_00c23980 (192 bytes), the
// link's inliner takes it: the call costs 210 to 214 against the threshold 225 (opt -std-link-opts
// -inline-threshold over this unit and the append's linked). Built alone the function is the base's
// through the lock's loop (both `pushfq; pop rax; push rax; popfq` pairs among them).
void FUN_00c20dc0(Object00c20dc0 *holder, Counted00c23980 *object)
{
    holder->array30.lock.lock();
    FUN_00c23980(&holder->array30, Ref00503fb0<Counted00c23980>(object));
    holder->array30.lock.unlock();
}
