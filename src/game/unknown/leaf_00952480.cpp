/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the objects of a range stepped: from the index at +0x18
 * up to the one at +0x1c (both read once, as the float at +0x20), a counted
 * reference to the object at the index in the list at +0x10 is held while
 * its virtual function at slot 19 is called with the float, and the index
 * moves on by the int it returns; a null entry moves it by one. The index
 * is a signed int (`movsxd rcx, r15d`) compared unsigned with the end. The
 * classes are not traced. */
struct Item00952480 : Node00503fb0 { /* derived name */
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
    virtual void slot13();           /* derived name; not traced */
    virtual void slot14();           /* derived name; not traced */
    virtual void slot15();           /* derived name; not traced */
    virtual void slot16();           /* derived name; not traced */
    virtual void slot17();           /* derived name; not traced */
    virtual void slot18();           /* derived name; not traced */
    virtual int slot19(float value); /* derived name */
};

struct List00952480 {                 /* derived name */
    Ref00503fb0<Item00952480> *items; /* +0x0 */
};

struct Object00952480 { /* derived name */
    u8 unknown0[0x10];
    List00952480 *list; /* +0x10 */
    int first;          /* +0x18 */
    unsigned end;       /* +0x1c */
    float value;        /* +0x20 */
};

// NONMATCHING: block placement: every instruction is the base's, the block that calls FUN_00c14bc0 is laid
// out before the loop's header where the base has it before the latch, and the three spill slots are taken in
// another order (274 bytes for 268)
void FUN_00952480(Object00952480 *self) /* derived name */
{
    int index = self->first;
    unsigned end = self->end;
    float value = self->value;
    while (index < end) {
        Ref00503fb0<Item00952480> item(self->list->items[index]);
        if (!item.get()) {
            ++index;
            continue;
        }
        index += item.get()->slot19(value);
    }
}
