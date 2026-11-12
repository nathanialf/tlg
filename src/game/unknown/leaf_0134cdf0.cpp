/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"

/* derived names: a growable array of 8-byte counted references (FUN_003441e0
 * appends one: it raises the count at +0x8 of the object unless it is
 * 0xdeadc0de): the block at +0x0, the count at +0x8, the capacity at +0xc,
 * the index in D_5943280 of the owner of a new block at +0x10. FUN_0134cdf0
 * appends every element of another array: it grows the block once to the
 * sum of the counts, then appends them one by one. */
struct Element0134cdf0 { /* derived name */
    void *object;
};

struct Array0134cdf0 { /* derived name */
    Element0134cdf0 *data;
    unsigned count;
    unsigned capacity;
    unsigned allocator;
};

void FUN_003441e0(Array0134cdf0 *array, const Element0134cdf0 *value); /* derived name */

// NONMATCHING: leaf_013d30f0.cpp's class: the base loads the allocator index, the table's
// address and the size's shift before the null test and redefines the index from the
// header in the block's arm (the table load then copied into both arms), the build loads
// the index only in the arm without a block; the index written as a variable redefined
// in one arm (this form) gives the build's. The loop and the rest are the base's.
void FUN_0134cdf0(Array0134cdf0 *self, const Array0134cdf0 *other) /* derived name */
{
    unsigned size = self->count + other->count;
    if (self->capacity < size) {
        self->capacity = size;
        unsigned owner = self->allocator;
        if (self->data)
            owner = (reinterpret_cast<BlockHeader05943280 *>(self->data) - 1)->owner;
        if (self->data)
            self->data = static_cast<Element0134cdf0 *>(
                D_5943280[owner]->slot5(self->data, size * sizeof(Element0134cdf0), 8, 1));
        else
            self->data = static_cast<Element0134cdf0 *>(
                D_5943280[owner]->slot4(size * sizeof(Element0134cdf0), 8, 1));
    }
    const Element0134cdf0 *end = other->data + other->count;
    for (const Element0134cdf0 *it = other->data; it != end; ++it)
        FUN_003441e0(self, it);
}
