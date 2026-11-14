/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_game_log.h"
#include "tlg_game_node.h"

/* derived names: the counted reference at `index` of the array at +0x238
 * (count +0x240) removed: the reference dropped, the references behind it
 * moved down by memmove and the count lowered; an index past the count is
 * reported instead (the message at 0x15b1b05). The owner is not traced. */
struct Object00c29d60 { /* derived name */
    u8 unknown0[0x238];
    Ref00503fb0<Node00503fb0> *references; /* +0x238 */
    unsigned referenceCount;               /* +0x240 */
};

void FUN_00c29d60(Object00c29d60 *self, unsigned index) /* derived name */
{
    if (index < self->referenceCount) {
        self->references[index].release();
        memmove(self->references + index, self->references + index + 1,
                (self->referenceCount - index - 1) * unsigned(sizeof(Ref00503fb0<Node00503fb0>)));
        --self->referenceCount;
    } else {
        FUN_00c831d0(self, "index out of range\n");
    }
}
