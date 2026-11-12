/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_libc.h"

/* derived names: an arena that lays out blocks in two passes: with no
 * cursor at +0x8 it only adds each block's size, aligned to 8, to the total
 * at +0x10; with one it also hands out the block, cleared, at the cursor
 * aligned to 8; the alignment at +0x18 is raised to at least 8. */
struct Arena00ebf620 { /* derived name */
    u8 unknown0[0x8];
    char *cursor;            /* +0x8 */
    unsigned long size;      /* +0x10 */
    unsigned long alignment; /* +0x18 */
};

/* derived names: the 0x350-byte record the pointer at 0x5a8df90 holds; its
 * ints at +0x0 and +0x1a8 start at -1. Its fields are not traced. */
struct Record05a8df90 { /* derived name */
    int unknown0;       /* +0x0 */
    u8 unknown4[0x1a4];
    int unknown1a8; /* +0x1a8 */
    u8 unknown1ac[0x350 - 0x1ac];
};

extern Record05a8df90 *D_5a8df90;

/* derived names: an entry of the table its address sits in at 0x57ada38:
 * places the record at 0x5a8df90 in the arena it is given (nothing for no
 * arena) and returns 0. */
int FUN_00ebf620(Arena00ebf620 *arena) /* derived name */
{
    if (!arena)
        return 0;
    char *cursor = arena->cursor;
    unsigned long size = arena->size;
    Record05a8df90 *record = 0;
    if (cursor) {
        char *aligned =
            reinterpret_cast<char *>((reinterpret_cast<unsigned long>(cursor) + 7) & ~7ul);
        arena->cursor = aligned + sizeof(Record05a8df90);
        memset(aligned, 0, sizeof(Record05a8df90));
        record = reinterpret_cast<Record05a8df90 *>(aligned);
    }
    arena->size = (size + sizeof(Record05a8df90) + 7) & ~7ul;
    if (arena->alignment < 8)
        arena->alignment = 8;
    if (record) {
        D_5a8df90 = record;
        record->unknown1a8 = -1;
        record->unknown0 = -1;
    }
    return 0;
}
