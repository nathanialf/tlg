/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"

/* derived names: an object counted by the references an array holds
 * (leaf_001b59d0.cpp's, here with the node's slots: its last reference
 * destroys it through slot 2, `call [rax+0x10]` at 0x1331e85) */
class Counted001b59d0 : public Node00503fb0 /* derived name */
{
};

void FUN_001b59d0(Array05943280<Ref00503fb0<Counted001b59d0>> *array,
                  const Ref00503fb0<Counted001b59d0> &value); /* derived name */

struct Object01331d20 { /* derived name */
    u8 unknown0[0x38];
    Array01343a80<Ref00503fb0<Counted001b59d0>> array38; /* +0x38 */
};

/* derived name: appends a reference to the object to the holder's array
 * under the array's lock: the lock taken (`xor eax, eax; lock cmpxchg
 * [r15+0x4c], r14d` at 0x1331d51, the creation lock's wait), the reference, held
 * for the call, appended by FUN_001b59d0, the lock given back. */
// NONMATCHING: an inline-cost margin: the base calls FUN_001b59d0 (192 bytes), the whole module inlines
// it (564 bytes against 434). Built alone the function is the base's through the lock's loop (the
// first 57 instructions, both `pushfq; pop rax; push rax; popfq` pairs among them).
void FUN_01331d20(Object01331d20 *holder, Counted001b59d0 *object)
{
    holder->array38.lock.lock();
    FUN_001b59d0(&holder->array38, Ref00503fb0<Counted001b59d0>(object));
    holder->array38.lock.unlock();
}
