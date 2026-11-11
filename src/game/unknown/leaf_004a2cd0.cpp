/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a handler FUN_00481170 stores at +0x8 of an entry of the
 * keyed table at +0x870 of its object (lea at 0x48148d and 0x4814a8): it
 * looks the event's int at +0xc up in the sixteen-bucket table at +0xa0 of
 * the record at +0x58 of the object the pointer at +0x900 of the record at
 * +0x38 of the object the pointer at 0x57c9390 holds (entries: the key at
 * +0x0, the callback at +0x8, the next entry at +0x10), calls the matching
 * entry's callback with the event and returns 0. The handler's first argument
 * is not read; the types are not traced. */
struct Event004a2cd0 { /* derived name */
    u8 unknown0[0xc];
    int id; /* derived name */
};

struct Entry004a2cd0 {                      /* derived name */
    int key;                                /* derived name */
    void (*callback)(Event004a2cd0 *event); /* derived name */
    Entry004a2cd0 *next;                    /* derived name */
};

struct Table004a2cd0 { /* derived name */
    u8 unknown0[0xa0];
    Entry004a2cd0 *buckets[16]; /* derived name */
};

struct Member057c9390_38_900 { /* derived name */
    u8 unknown0[0x58];
    Table004a2cd0 *unknown58;
};

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x900];
    Member057c9390_38_900 *unknown900;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38;
};

extern Object057c9390 *D_57c9390;

// NONMATCHING: the unrotated list loop, the base enters the walk at its null test
// (`jmp`) where the build rotates it (the same with the walk written as a for loop).
int FUN_004a2cd0(void *, Event004a2cd0 *event) /* derived name */
{
    Table004a2cd0 *table = D_57c9390->unknown38->unknown900->unknown58;
    Entry004a2cd0 *entry = table->buckets[event->id & 15];
    while (entry && entry->key != event->id)
        entry = entry->next;
    if (entry)
        entry->callback(event);
    return 0;
}
