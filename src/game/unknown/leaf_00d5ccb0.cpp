/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: sets the object's array of 16-byte entries (+0x130, the
 * count at +0x12c) to a copy of n given ones, word by word, the array made
 * again (delete[] and new[]) when the count changes; an array already set is
 * kept unless bit 4 of the flags at +0xd4 is set. */
struct Entry00d5ccb0 { /* derived name */
    int unknown0;
    int unknown4;
    int unknown8;
    int unknownc;
};

struct Object00d5ccb0 { /* derived name */
    u8 unknown0[0xd4];
    u8 flagsd4; /* +0xd4: bit 4 lets the array be set again */
    u8 unknownd5[0x57];
    u32 count;              /* +0x12c */
    Entry00d5ccb0 *entries; /* +0x130 */
};

void FUN_00d5ccb0(Object00d5ccb0 *self, u32 count, const Entry00d5ccb0 *entries) /* derived name */
{
    if (!(self->flagsd4 & 0x10) && self->entries)
        return;
    if (self->count != count) {
        delete[] self->entries;
        self->entries = new Entry00d5ccb0[count];
        self->count = count;
    }
    for (u32 i = 0; i < self->count; i++) {
        self->entries[i].unknown0 = entries[i].unknown0;
        self->entries[i].unknown4 = entries[i].unknown4;
        self->entries[i].unknown8 = entries[i].unknown8;
        self->entries[i].unknownc = entries[i].unknownc;
    }
}
