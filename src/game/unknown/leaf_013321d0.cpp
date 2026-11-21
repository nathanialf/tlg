/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include <xmmintrin.h>

/* derived names: slot 5 of the vtable at 0x16c6100 (its pointer at
 * 0x16c6138), one of the vtables whose slot 0 is the destructor of
 * Object013a6a50 (FUN_013a6a50; tlg_game_object016c81c0.h's Object016c6100):
 * when the float at +0x19c of the object the pointer at 0x5938c40 holds is
 * above zero, hands it to slot 13 of each object of the list at +0x28 (the
 * count at +0x30, read once) of the object at +0x38 of the one the pointer at
 * 0x57c9390 holds, the object eight places on prefetched first (`prefetchnta`);
 * an object is skipped while its int at +0x30 is zero, when bit 7 of the
 * flags at +0x24 of its record at +0x28 is set, or bit 6 with the record's int
 * at +0x48 zero. The object itself is not read. */
class Object013a6a50; /* derived name */

struct Record013321d0 { /* derived name */
    u8 unknown0[0x24];
    u32 flags; /* +0x24 */
    u8 unknown28[0x20];
    int unknown48; /* +0x48 */
};

class Item013321d0 /* derived name */
{
  public:
    virtual void slot0();            /* derived name; not traced */
    virtual void slot1();            /* derived name; not traced */
    virtual void slot2();            /* derived name; not traced */
    virtual void slot3();            /* derived name; not traced */
    virtual void slot4();            /* derived name; not traced */
    virtual void slot5();            /* derived name; not traced */
    virtual void slot6();            /* derived name; not traced */
    virtual void slot7();            /* derived name; not traced */
    virtual void slot8();            /* derived name; not traced */
    virtual void slot9();            /* derived name; not traced */
    virtual void slot10();           /* derived name; not traced */
    virtual void slot11();           /* derived name; not traced */
    virtual void slot12();           /* derived name; not traced */
    virtual void update(float step); /* derived name; slot 13 (+0x68) */

    u8 unknown8[0x20];
    Record013321d0 *record; /* +0x28 */
    int unknown30;          /* +0x30 */
};

struct List013321d0 { /* derived name */

    /* the item at a signed index (`movsxd` under the unsigned counter) */
    Item013321d0 *at(int index) const /* derived name */
    {
        return items[index];
    }

    u8 unknown0[0x28];
    Item013321d0 **items; /* +0x28 */
    u32 count;            /* +0x30 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    List013321d0 *list38; /* +0x38 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x19c];
    float unknown19c; /* +0x19c */
};

extern Object057c9390 *D_57c9390;
extern Object05938c40 *D_5938c40;

void FUN_013321d0(Object013a6a50 *) /* derived name */
{
    float step = D_5938c40->unknown19c;
    if (step <= 0.0f)
        return;
    List013321d0 *list = D_57c9390->list38;
    u32 count = list->count;
    for (u32 i = 0; i < count; ++i) {
        if (i + 8 < count)
            _mm_prefetch(reinterpret_cast<const char *>(list->at(i + 8)), _MM_HINT_NTA);
        Item013321d0 *item = list->at(i);
        if (item->unknown30 == 0)
            continue;
        Record013321d0 *record = item->record;
        if (record->flags & 0x80)
            continue;
        if ((record->flags & 0x40) && record->unknown48 == 0)
            continue;
        item->update(step);
    }
}
