/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_013bf850 on the object with each non-null pointer
 * of the hash table its argument describes (the buckets at +0x0, the mask at
 * +0xc, the counter masked into the table); slot 21 of the vtables at
 * 0x16bba90 (its pointer at 0x16bbb48), 0x16bc170 (at 0x16bc228) and
 * 0x16d2818 (at 0x16d28d0), the family of FUN_00dd1e40 (slot 25). The
 * pointers' target is not traced. Class and method unknown. */
struct Object00dd1dc0; /* derived name */
struct Target00dd1dc0; /* derived name */

struct Table00dd1dc0 {        /* derived name */
    Target00dd1dc0 **buckets; /* derived name */
    u8 unknown8[4];
    u32 mask; /* derived name */
};

void FUN_013bf850(Object00dd1dc0 *self, Target00dd1dc0 *value); /* derived name */

void FUN_00dd1dc0(Object00dd1dc0 *self, const Table00dd1dc0 *table) /* derived name */
{
    for (u32 i = 0; i < table->mask + 1; i++) {
        Target00dd1dc0 *value = table->buckets[i & table->mask];
        if (value)
            FUN_013bf850(self, value);
    }
}
