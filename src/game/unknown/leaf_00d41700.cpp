/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a qsort comparator over pointers to records whose first field
 * points to an object holding at +0xc an index into the table at 0x17ac870
 * (FUN_00d34e50 passes it, lea at 0xd37755 and 0xd379d0): 1 when the first's
 * entry has the smaller unsigned int at +0x8, else -1. The table is the game's
 * object; its entries' other fields are not traced. */
struct Entry017ac870 { /* derived name */
    u8 unknown0[8];
    unsigned unknown8;
    u8 unknownc[0x14];
};

extern Entry017ac870 D_17ac870[];

struct Object00d41700 { /* derived name */
    u8 unknown0[0xc];
    unsigned unknownc;
};

int FUN_00d41700(const void *a, const void *b) /* derived name */
{
    const Object00d41700 *first = *static_cast<Object00d41700 *const *>(a);
    const Object00d41700 *second = *static_cast<Object00d41700 *const *>(b);
    return D_17ac870[first->unknownc].unknown8 < D_17ac870[second->unknownc].unknown8 ? 1 : -1;
}
