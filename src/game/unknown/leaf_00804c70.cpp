/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the counted reference at +0x80 of each object the pointer
 * array at +0x298 (count +0x2a0) holds is emptied by compare-and-swap. The
 * counter is unsigned (`inc r12d; cmp r12d, [r14+0x2a0]; jb`) and the
 * array's index a signed int (`movsxd rax, r12d` at each turn). The owner
 * and the objects' class are not traced. */
struct Item00804c70 { /* derived name */
    u8 unknown0[0x80];
    AtomicRef0045c470<Node00503fb0> unknown80; /* +0x80 */
};

struct Object00804c70 { /* derived name */

    Item00804c70 *item(int index) /* derived name */
    {
        return items[index];
    }

    u8 unknown0[0x298];
    Item00804c70 **items; /* +0x298 */
    unsigned itemCount;   /* +0x2a0 */
};

// NONMATCHING: CodeGenPrepare's preheader protection (held beside D63, round 202B): 63/68; the base has
// `mov edx, 0xdeadc0de` in the flag's block right after the thread-local's address (0x804d06), the build in a
// preheader block of the exchange loop behind the `jne`
void FUN_00804c70(Object00804c70 *self) /* derived name */
{
    for (unsigned i = 0; i < self->itemCount; ++i)
        self->item(i)->unknown80.clear();
}
