/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: looks the key up in the record's pairs (the count at +0x10,
 * the 8-byte pairs from +0x14, the key second) and, when one matches, returns
 * the pointer of the handle table's entry (0x17ac870, 32-byte entries) that
 * the first int of the pair the key indexes names: the pair is taken at the
 * key, not at the match; the third argument (rdx, returned as it came) when no
 * pair matches. The types are not traced. Class and method unknown. */
struct Entry017ac870 { /* derived name */
    void *unknown0;
    u8 unknown8[0x18];
};

extern Entry017ac870 D_17ac870[];

struct Pair01388460 {  /* derived name */
    unsigned unknown0; /* the handle */
    int unknown4;      /* the key */
};

struct Object01388460 { /* derived name */
    u8 unknown0[0x10];
    unsigned unknown10;        /* +0x10: the pair count */
    Pair01388460 unknown14[1]; /* +0x14 */
};

void *FUN_01388460(Object01388460 *self, int key, void *missing) /* derived name */
{
    void *result = missing;
    for (unsigned i = 0; i < self->unknown10; i++) {
        if (self->unknown14[i].unknown4 == key) {
            result = D_17ac870[self->unknown14[key].unknown0].unknown0;
            break;
        }
    }
    return result;
}
