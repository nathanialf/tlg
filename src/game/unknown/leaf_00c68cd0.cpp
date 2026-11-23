/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_libc.h"

/* derived names: a sorted entry: a pointer and a key, the key's low nine
 * bits its order, a signed value in offset order (the top bit of the nine
 * flipped), the bits above them the caller's flags. Neither is traced. */
struct Entry00c68cd0 { /* derived name */

    Entry00c68cd0(void *object, u32 key) : object(object), key(key) {}

    void *object; /* +0x0 */
    u32 key;      /* +0x8 */
};

/* derived name: the sort comparison of the entries: 1 when the first's
 * order is greater than the second's, else -1 */
int FUN_00c68cd0(const Entry00c68cd0 *a, const Entry00c68cd0 *b) /* derived name */
{
    return ((a->key & 0x1ff) ^ 0x100) > ((b->key & 0x1ff) ^ 0x100) ? 1 : -1;
}

struct Sorter00c68be0 { /* derived name */
    u8 unknown0[0x88];
    Array05943280<Entry00c68cd0> entries; /* +0x88 */
};

/* derived name: appends an entry for the object, its key the flags with
 * the entry's index, then sorts the entries again (called by FUN_00d826c0
 * and FUN_00d866e0) */
void FUN_00c68be0(Sorter00c68be0 *self, void *object, u32 flags) /* derived name */
{
    const u32 key = flags | self->entries.size();
    new (self->entries.append()) Entry00c68cd0(object, key);
    qsort(self->entries.begin(), self->entries.size(), sizeof(Entry00c68cd0),
          reinterpret_cast<int (*)(const void *, const void *)>(FUN_00c68cd0));
}
