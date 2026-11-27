/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: one of the three entries of FUN_007ff7e0's skip ring
 * (40 bytes: a pointer the ring hands back at +0x0, the name of the way
 * on at +0x24); nothing else is traced */
struct Entry00802d40 /* derived name */
{
    void *unknown0; /* +0x0 */
    u8 unknown8[0x1c];
    Name name24; /* +0x24 */
};

/* the object whose bit 0 at +0x30 lets a skip be named (not traced) */
struct Owner00802d40 /* derived name */
{
    u8 unknown0[0x30];
    u8 flags30; /* +0x30 */
};

/* derived names: three entries used in turn (+0x88 the current one, moved
 * on modulo 3), the pointer for the end at +0x78, the owner at +0x80 and the
 * flags at +0x8c (bit 2: the end is reached; bit 1 cleared by a skip) */
struct Ring00802d40 /* derived name */
{
    Entry00802d40 entries[3]; /* +0x0 */
    void *end;                /* +0x78 */
    Owner00802d40 *owner;     /* +0x80 */
    unsigned current;         /* +0x88 */
    unsigned flags;           /* +0x8c */
};

/* derived name: the current entry named "skip_end" or "skip_next" when the
 * owner allows it, then the next entry made current; returns its pointer
 * (the end's once bit 2 is set). Called twice by FUN_007ff7e0. */
void *FUN_00802d40(Ring00802d40 *ring) /* derived name */
{
    if (ring->owner && (ring->owner->flags30 & 1)) {
        Entry00802d40 &entry = ring->entries[ring->current];
        if (ring->flags & 4)
            entry.name24 = Name("skip_end");
        else
            entry.name24 = Name("skip_next");
    }
    void *next;
    if (ring->flags & 4) {
        next = ring->end;
    } else {
        ring->current = (ring->current + 1) % 3;
        next = ring->entries[ring->current].unknown0;
    }
    ring->flags &= ~2u;
    return next;
}
