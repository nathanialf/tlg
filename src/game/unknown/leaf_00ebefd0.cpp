/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"

#include "tlg_game_node.h"

/* derived names: the counted references of the array at +0x2c8 (count
 * +0x2d0) removed last to first: each one dropped, the references behind
 * it moved down by memmove and the count lowered. The owner is not
 * traced. */
struct Object00ebefd0 { /* derived name */

    /* removes the reference at `index` */
    void remove(unsigned index) /* derived name */
    {
        references[index].release();
        memmove(references + index, references + index + 1,
                (referenceCount - index - 1) * unsigned(sizeof(Ref00503fb0<Node00503fb0>)));
        --referenceCount;
    }

    u8 unknown0[0x2c8];
    Ref00503fb0<Node00503fb0> *references; /* +0x2c8 */
    unsigned referenceCount;               /* +0x2d0 */
};

void FUN_00ebefd0(Object00ebefd0 *self) /* derived name */
{
    for (int i = self->referenceCount - 1; i >= 0; --i)
        self->remove(i);
}
