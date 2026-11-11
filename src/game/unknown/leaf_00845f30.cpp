/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a job's function (its address taken at 0x8457d4): for
 * each of count objects of the list from index first, passes the job's
 * float to slot 10 of the object unless bit 1 of its slot 34's answer is
 * set. Class and method unknown. */
class Item00845f30 /* derived name */
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
    virtual void slot10(float value); /* derived name */
    virtual void slot11();            /* derived name; not traced */
    virtual void slot12();            /* derived name; not traced */
    virtual void slot13();            /* derived name; not traced */
    virtual void slot14();            /* derived name; not traced */
    virtual void slot15();            /* derived name; not traced */
    virtual void slot16();            /* derived name; not traced */
    virtual void slot17();            /* derived name; not traced */
    virtual void slot18();            /* derived name; not traced */
    virtual void slot19();            /* derived name; not traced */
    virtual void slot20();            /* derived name; not traced */
    virtual void slot21();            /* derived name; not traced */
    virtual void slot22();            /* derived name; not traced */
    virtual void slot23();            /* derived name; not traced */
    virtual void slot24();            /* derived name; not traced */
    virtual void slot25();            /* derived name; not traced */
    virtual void slot26();            /* derived name; not traced */
    virtual void slot27();            /* derived name; not traced */
    virtual void slot28();            /* derived name; not traced */
    virtual void slot29();            /* derived name; not traced */
    virtual void slot30();            /* derived name; not traced */
    virtual void slot31();            /* derived name; not traced */
    virtual void slot32();            /* derived name; not traced */
    virtual void slot33();            /* derived name; not traced */
    virtual u32 slot34();             /* derived name */
};

struct List00845f30 { /* derived name */
    Item00845f30 **items;
};

struct Job00845f30 { /* derived name */
    u8 unknown0[0x10];
    List00845f30 *list; /* +0x10 */
    float value;        /* +0x18 */
    int first;          /* +0x1c */
    u32 count;          /* +0x20 */
};

// NONMATCHING: the count tested as 64 bits (`test r14, r14`, the u32 index zero-extended) where
// the base tests r14d, and the float spilled before the list's loads; not reduced further
void FUN_00845f30(Job00845f30 *job) /* derived name */
{
    const u32 count = job->count;
    const float value = job->value;
    Item00845f30 **items = &job->list->items[job->first];
    for (u32 i = 0; i < count; i++) {
        if (!(items[i]->slot34() & 2))
            items[i]->slot10(value);
    }
}
