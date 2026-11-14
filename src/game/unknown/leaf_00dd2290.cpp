/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_013bf850 on the object with the pointer at +0x18
 * of the record its argument holds, then with the pointer of each of the
 * record's entries (0x18 bytes each from +0x20, their count at +0x0, a byte
 * index); slot 42 of the vtables at 0x16bba90 (its pointer at 0x16bbbe0),
 * 0x16bc170 (at 0x16bc2c0) and 0x16d2818 (at 0x16d2968), FUN_00dd1dc0's
 * family (slot 21). The pointers' target is not traced. Class and method
 * unknown. */
struct Object00dd1dc0; /* derived name */
struct Target00dd1dc0; /* derived name */

struct Entry00dd2290 { /* derived name */
    Target00dd1dc0 *value;
    u8 unknown8[0x10];
};

struct Record00dd2290 { /* derived name */
    u64 count;
    u8 unknown8[0x10];
    Target00dd1dc0 *unknown18; /* +0x18 */
    Entry00dd2290 entries[1];  /* +0x20 */

    /* derived name: the entry for a byte index (`movzx ecx, bl`) */
    const Entry00dd2290 &entry(u8 index) const
    {
        return entries[index];
    }
};

struct Holder00dd2290 { /* derived name */
    Record00dd2290 *record;
};

void FUN_013bf850(Object00dd1dc0 *self, Target00dd1dc0 *value); /* derived name */

void FUN_00dd2290(Object00dd1dc0 *self, const Holder00dd2290 *holder) /* derived name */
{
    FUN_013bf850(self, holder->record->unknown18);
    for (u64 i = 0; i < holder->record->count; i++)
        FUN_013bf850(self, holder->record->entry(i).value);
}
