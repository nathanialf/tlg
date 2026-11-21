/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: slot 5 of the vtable at 0x16c6808 (its pointer at
 * 0x16c6840), one of the vtables whose slot 0 is the destructor of
 * Object013a6a50 (FUN_013a6a50; tlg_game_object016c81c0.h's Object016c6808):
 * calls slot 17 of each object of the list at +0xb8 (the count at +0xc0, read
 * once) of the object at +0xb8 of the one the pointer at 0x5938c40 holds that
 * is of the type the pointer at 0x57db090 holds (or one derived from it) and
 * whose record at +0x28 has bit 0 of its flags at +0x24 set. The object
 * itself is not read. */
class Object013a6a50; /* derived name */

struct Record0133e110 { /* derived name */
    u8 unknown0[0x24];
    u32 flags; /* +0x24 */
};

class Item0133e110 : public Object016b9108 /* derived name */
{
  public:
    virtual void slot5();  /* derived name; not traced */
    virtual void slot6();  /* derived name; not traced */
    virtual void slot7();  /* derived name; not traced */
    virtual void slot8();  /* derived name; not traced */
    virtual void slot9();  /* derived name; not traced */
    virtual void slot10(); /* derived name; not traced */
    virtual void slot11(); /* derived name; not traced */
    virtual void slot12(); /* derived name; not traced */
    virtual void slot13(); /* derived name; not traced */
    virtual void slot14(); /* derived name; not traced */
    virtual void slot15(); /* derived name; not traced */
    virtual void slot16(); /* derived name; not traced */
    virtual void slot17(); /* derived name; +0x88, not traced */

    Record0133e110 *record; /* +0x28 */
};

struct List0133e110 { /* derived name */

    /* the item at a signed index (`movsxd` under the unsigned counter) */
    Item0133e110 *at(int index) const /* derived name */
    {
        return items[index];
    }

    u8 unknown0[0xb8];
    Item0133e110 **items; /* +0xb8 */
    u32 count;            /* +0xc0 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0xb8];
    List0133e110 *listb8; /* +0xb8 */
};

extern Object05938c40 *D_5938c40;
extern Type00503fb0 *D_57db090; /* derived name: the items' type */

void FUN_0133e110(Object013a6a50 *) /* derived name */
{
    List0133e110 *list = D_5938c40->listb8;
    u32 count = list->count;
    for (u32 i = 0; i < count; ++i) {
        Item0133e110 *item = list->at(i);
        if (item && item->isKindOf(D_57db090) && item->record && (item->record->flags & 1))
            item->slot17();
    }
}
