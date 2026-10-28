/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the values of the extra rows a record of type 3 or 4
 * carries after its entries scaled by the two factors; the rows' byte
 * offset is one sum, the owner's size and the entries' (the base adds it to
 * the record as `[rax + rdi]`). */
void FUN_0002b040(Pair08Owner *self, float scaleA, float scaleB) /* derived name */
{
    if (self->type >= 3) {
        const unsigned long offset = sizeof(Pair08Owner) + self->count * sizeof(Pair08Entry);
        Pair08Extra *extra =
            reinterpret_cast<Pair08Extra *>(reinterpret_cast<char *>(self) + offset);
        lane(extra->rows[0].vectorB, 3) *= scaleA;
        lane(extra->rows[1].vectorB, 3) *= scaleA;
        lane(extra->rows[2].vectorA, 3) *= scaleA;
        lane(extra->rows[0].vectorA, 3) *= scaleB;
        lane(extra->rows[1].vectorA, 3) *= scaleB;
        lane(extra->rows[2].vectorB, 3) *= scaleB;
    }
}
