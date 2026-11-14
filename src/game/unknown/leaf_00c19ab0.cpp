/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: appends an item to a packed buffer: the item is recorded at
 * the next index, its offset is the end of the previous item (0 for the
 * first), the end recorded after it is that offset plus the size rounded up
 * to 16 bytes; returns the item's place in the buffer (its start at +0x28 of
 * the record). The record at +0x10 is re-read after every store. */
struct Record00c19ab0 /* derived name */
{
    u8 unknown0[0x10];
    void **items;   /* +0x10 */
    unsigned *ends; /* +0x18 */
    u8 unknown20[8];
    u8 *data; /* +0x28 */
};

struct Object00c19ab0 /* derived name */
{
    u8 unknown0[8];
    unsigned count;         /* +0x8 */
    Record00c19ab0 *record; /* +0x10 */
};

u8 *FUN_00c19ab0(Object00c19ab0 *self, void *item, unsigned size) /* derived name */
{
    const unsigned index = self->count;
    self->record->items[index] = item;
    const u64 offset = index ? self->record->ends[index - 1] : 0;
    self->record->ends[index] = offset + ((size + 15) & ~15u);
    self->count = index + 1;
    return self->record->data + offset;
}
