/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether FUN_00eadcb0 gives nonzero for the pointer at
 * +0x38 of the record the pointer at +0x268 of the object the pointer at
 * 0x5a8dbc0 holds (null when that record is null) and its third and fourth
 * arguments; slot 5 of the vtable at 0x16d3488 (its pointer at 0x16d34c0; no
 * constructor stores it). The first two arguments are not read; the types
 * beyond the widths are not traced. */
struct Object013cc260;        /* derived name */
struct Member05a8dbc0_268_38; /* derived name */

struct Member05a8dbc0_268 { /* derived name */
    u8 unknown0[0x38];
    Member05a8dbc0_268_38 *unknown38;
};

struct Object05a8dbc0 { /* derived name */
    u8 unknown0[0x268];
    Member05a8dbc0_268 *unknown268;
};

extern Object05a8dbc0 *D_5a8dbc0;

int FUN_00eadcb0(Member05a8dbc0_268_38 *member, int first, int second); /* derived name */

bool FUN_013cc260(Object013cc260 *, void *, int first, int second) /* derived name */
{
    Member05a8dbc0_268 *record = D_5a8dbc0->unknown268;
    return FUN_00eadcb0(record ? record->unknown38 : 0, first, second) != 0;
}
