/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_locked_array.h"
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
    LockedArray0081a930<Ref00503fb0<Counted009f5bc0>> array28; /* +0x28 */
};

/* derived name: appends a reference to the object to the holder's array
 * under the array's lock: the lock taken (`xor eax, eax; lock cmpxchg
 * [r15+0x3c], r14d` at 0x9f5a31, the creation lock's wait), the reference, held
 * for the call, appended by FUN_009f5bc0, the lock given back. */
// NONMATCHING: an inline-cost margin: the base calls FUN_009f5bc0 (192 bytes), the whole module inlines
// it (564 bytes against 434). Built alone the function is the base's through the lock's loop (the
// first 57 instructions, both `pushfq; pop rax; push rax; popfq` pairs among them).
void FUN_009f5a00(Object009f5a00 *holder, Counted009f5bc0 *object)
{
    holder->array28.lock.lock();
    FUN_009f5bc0(&holder->array28, Ref00503fb0<Counted009f5bc0>(object));
    holder->array28.lock.unlock();
}
