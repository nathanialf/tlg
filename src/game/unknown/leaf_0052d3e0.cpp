/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a worker's function (its address taken at 0x133de97): it
 * counts itself in through the int the pointer at +0x28 points to, takes
 * entries from the shared count at +0x18 (atomically, from the top) of the
 * list at +0x10 and calls slot 16 of each entry whose int at +0x30 is set
 * with the float at +0x19c of the object the pointer at 0x5938c40 holds
 * (read once), then counts itself out through the int at +0x20. The classes
 * are not traced. */
class Entry0052d3e0 /* derived name */
{
  public:
    virtual void slot0();             /* derived name; not traced */
    virtual void slot1();             /* derived name; not traced */
    virtual void slot2();             /* derived name; not traced */
    virtual void slot3();             /* derived name; not traced */
    virtual void slot4();             /* derived name; not traced */
    virtual void slot5();             /* derived name; not traced */
    virtual void slot6();             /* derived name; not traced */
    virtual void slot7();             /* derived name; not traced */
    virtual void slot8();             /* derived name; not traced */
    virtual void slot9();             /* derived name; not traced */
    virtual void slot10();            /* derived name; not traced */
    virtual void slot11();            /* derived name; not traced */
    virtual void slot12();            /* derived name; not traced */
    virtual void slot13();            /* derived name; not traced */
    virtual void slot14();            /* derived name; not traced */
    virtual void slot15();            /* derived name; not traced */
    virtual void slot16(float value); /* derived name */

    u8 unknown8[0x28];
    int unknown30; /* +0x30 */
};

struct List0052d3e0 {        /* derived name */
    Entry0052d3e0 **entries; /* +0x0 */
};

struct Work0052d3e0 { /* derived name */
    u8 unknown0[0x10];
    List0052d3e0 *list; /* +0x10 */
    int *remaining;     /* +0x18 */
    int *finished;      /* +0x20 */
    int *started;       /* +0x28 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x19c];
    float unknown19c; /* +0x19c */
};

extern Object05938c40 *D_5938c40;

// NONMATCHING: the base rotates the loop (its first atomic take before the loop, the latch taking again: the unrotated-loop class) and computes the index as dec eax; cdqe (no nsw), the build folds the - 1 into the address
void FUN_0052d3e0(Work0052d3e0 *work) /* derived name */
{
    __sync_fetch_and_add(work->started, 1);
    float value = D_5938c40->unknown19c;
    List0052d3e0 *list = work->list;
    int count;
    while ((count = __sync_fetch_and_sub(work->remaining, 1)) > 0) {
        Entry0052d3e0 *entry = list->entries[count - 1];
        if (entry && entry->unknown30)
            entry->slot16(value);
    }
    __sync_fetch_and_add(work->finished, 1);
}
