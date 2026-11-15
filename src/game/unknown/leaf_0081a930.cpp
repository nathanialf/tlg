/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_locked_array.h"
#include "tlg_game_node.h"

/* derived names: an object counted by the references an array holds
 * (leaf_00751ca0.cpp's, here with the node's slots: its last reference
 * destroys it through slot 2, `call [rax+0x10]` at 0x81aa95) */
class Counted00751ca0 : public Node00503fb0 /* derived name */
{
};

void FUN_00751ca0(Array05943280<Ref00503fb0<Counted00751ca0>> *array,
                  const Ref00503fb0<Counted00751ca0> &value); /* derived name */

struct Object0081a930 { /* derived name */
    u8 unknown0[0x10];
    LockedArray0081a930<Ref00503fb0<Counted00751ca0>> array10; /* +0x10 */
};

/* derived name: appends a reference to the object to the holder's array
 * under the array's lock: the lock taken (`xor eax, eax; lock cmpxchg
 * [r15+0x24], r14d` at 0x81a961, the creation lock's wait), the reference, held
 * for the call, appended by FUN_00751ca0, the lock given back. */
// NONMATCHING: an inline-cost margin: the base calls FUN_00751ca0 (192 bytes), the whole module inlines
// it (564 bytes against 434). Built alone the function is the base's through the lock's loop (the
// first 57 instructions, both `pushfq; pop rax; push rax; popfq` pairs among them).
void FUN_0081a930(Object0081a930 *holder, Counted00751ca0 *object)
{
    holder->array10.lock.lock();
    FUN_00751ca0(&holder->array10, Ref00503fb0<Counted00751ca0>(object));
    holder->array10.lock.unlock();
}
