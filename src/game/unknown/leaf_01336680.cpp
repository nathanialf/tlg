/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 5 of the vtable at 0x16c6418 (its pointer at
 * 0x16c6450), one of the vtables whose slot 0 is the destructor of
 * Object013a6a50 (FUN_013a6a50; tlg_game_object016c81c0.h's Object016c6418):
 * for each entry of the list at +0x10 (the count at +0x18) of the object at
 * +0x90 of the one the pointer at 0x57c9390 holds whose int at +0x8 is set
 * and whose record at +0x120 has its int at +0x38 set, hands FUN_00c20c00 the
 * member at +0x31e30 of a view: the one the object at +0x98 holds at +0x28,
 * or, while bit 0 of its flags at +0x134 is set, the one the object the
 * pointer at 0x5938c40 holds in its array at +0x58 at the index at +0x88,
 * and the record. The object itself is not read; the member's type is not
 * traced. */
class Object013a6a50; /* derived name */

struct View01336680 { /* derived name */
    u8 unknown0[0x31e30];
    u8 unknown31e30
        [8]; /* +0x31e30: handed by address to FUN_00c20c00; its type and size not traced */
};

struct Record01336680 { /* derived name */
    u8 unknown0[0x38];
    int unknown38; /* +0x38 */
};

struct Entry01336680 { /* derived name */
    u8 unknown0[8];
    int unknown8; /* +0x8 */
    u8 unknownc[0x114];
    Record01336680 *record; /* +0x120 */
};

struct List01336680 { /* derived name */

    /* the entry at a signed index (`movsxd` under the unsigned counter) */
    Entry01336680 *at(int index) const /* derived name */
    {
        return entries[index];
    }

    u8 unknown0[0x10];
    Entry01336680 **entries; /* +0x10 */
    u32 count;               /* +0x18 */
};

struct Owner01336680 { /* derived name */
    u8 unknown0[0x28];
    View01336680 *view; /* +0x28 */
    u8 unknown30[0x104];
    u32 flags; /* +0x134 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x90];
    List01336680 *list90;   /* +0x90 */
    Owner01336680 *owner98; /* +0x98 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x58];
    View01336680 *views[6]; /* +0x58: how many not traced */
    u32 current;            /* +0x88 */
};

extern Object057c9390 *D_57c9390;
extern Object05938c40 *D_5938c40;

void FUN_00c20c00(void *member, Record01336680 *record); /* derived name */

void FUN_01336680(Object013a6a50 *) /* derived name */
{
    List01336680 *list = D_57c9390->list90;
    for (u32 i = 0; i < list->count; ++i) {
        Entry01336680 *entry = list->at(i);
        if (entry->unknown8 == 0)
            continue;
        Record01336680 *record = entry->record;
        if (record->unknown38 == 0)
            continue;
        Owner01336680 *owner = D_57c9390->owner98;
        View01336680 *view =
            (owner->flags & 1) ? D_5938c40->views[D_5938c40->current] : owner->view;
        FUN_00c20c00(view->unknown31e30, record);
    }
}
