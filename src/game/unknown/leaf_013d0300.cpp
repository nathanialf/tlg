/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: an entry of 0x90 bytes, two pairs of values at +0x60 and
 * +0x68 with a flag for each at +0x58, the first of each for `in` */
struct Entry013d0300 { /* derived name */
    u8 unknown0[0x58];
    int enabled[2]; /* +0x58 */
    int first[2];   /* +0x60: -1 for none */
    int second[2];  /* +0x68 */
    u8 unknown70[0x20];
};

struct Table013d0300 { /* derived name */
    u8 unknown0[0x18];
    Entry013d0300 *entries; /* +0x18 */
};

struct Object013d0300 { /* derived name */
    u8 unknown0[0x8];
    Table013d0300 *table; /* +0x8 */
};

/* derived name: the entry's pair for one side, when that side is enabled and
 * has a first value */
int FUN_013d0300(Object013d0300 *self, int index, int in, int *first,
                 int *second) /* derived name */
{
    const Entry013d0300 &entry = self->table->entries[index];
    const int *from;
    const int *to;
    if (in) {
        if (!entry.enabled[0])
            return 0;
        from = &entry.first[0];
        to = &entry.second[0];
    } else {
        if (!entry.enabled[1])
            return 0;
        from = &entry.first[1];
        to = &entry.second[1];
    }
    const int a = *from;
    if (a == -1)
        return 0;
    const int b = *to;
    *first = a;
    *second = b;
    return 1;
}
