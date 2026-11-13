/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: FUN_00c68b00 appends an entry (a pointer and two ints) to
 * the array at +0x70 of its object (tlg_game_array.h's push) unless the
 * pointer is null. The other members are not traced. */
struct Entry00c68b00 { /* derived name */

    Entry00c68b00(void *object, int first, int second)
        : unknown0(object), unknown8(first), unknownc(second)
    {
    }

    void *unknown0; /* +0x0 */
    int unknown8;   /* +0x8 */
    int unknownc;   /* +0xc */
};

struct Object00c68b00 { /* derived name */
    u8 unknown0[0x70];
    Array05943280<Entry00c68b00> entries; /* +0x70 */
};

void FUN_00c68b00(Object00c68b00 *self, void *object, int first, int second) /* derived name */
{
    if (object)
        self->entries.push(Entry00c68b00(object, first, second));
}
