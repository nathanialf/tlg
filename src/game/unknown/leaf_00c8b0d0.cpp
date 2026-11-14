/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_math.h"
#include "tlg_game_entry00c8b0d0.h"

/* derived names: appends an entry to the current one of two sets of 64
 * (the set's index at +0x68b4, the count at +0x68b0): the two vectors
 * copied in, the float at +0x30 set to -1 and the counted reference at
 * +0x98 emptied by compare-and-swap; returns the count after, or 0 when
 * the set is full. The 0xb0-byte entry is the one FUN_00373200 empties
 * four of (its float at +0x30, its reference at +0x98); the owner and the
 * entry's other members are not traced. */

struct Object00c8b0d0 { /* derived name */
    u8 unknown0[0x10b0];
    Entry00c8b0d0 entries[2][64]; /* +0x10b0 */
    unsigned entryCount;          /* +0x68b0 */
    unsigned current;             /* +0x68b4 */
};

unsigned FUN_00c8b0d0(Object00c8b0d0 *self, const Float4A &a, const Float4A &b) /* derived name */
{
    if (self->entryCount >= 64)
        return 0;
    Entry00c8b0d0 &entry = self->entries[self->current][self->entryCount++];
    entry.unknown0 = a;
    entry.unknown10 = b;
    entry.unknown30 = -1.0f;
    entry.unknown98.clear();
    return self->entryCount;
}
