/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 34 of the vtable at 0x16be9a8 (stored by FUN_00eb3c90
 * and FUN_00eb3fb0): slot 10 of each object of the list at +0x60 (the next at
 * +0x38 of each). The types are not traced. Class and method unknown. */
class Node00ebbb70 /* derived name */
{
  public:
    virtual void slot0();  /* derived name; not traced */
    virtual void slot1();  /* derived name; not traced */
    virtual void slot2();  /* derived name; not traced */
    virtual void slot3();  /* derived name; not traced */
    virtual void slot4();  /* derived name; not traced */
    virtual void slot5();  /* derived name; not traced */
    virtual void slot6();  /* derived name; not traced */
    virtual void slot7();  /* derived name; not traced */
    virtual void slot8();  /* derived name; not traced */
    virtual void slot9();  /* derived name; not traced */
    virtual void slot10(); /* derived name; not traced */

    u8 unknown8[0x30];
    Node00ebbb70 *next;
};

struct Object00ebbb70 { /* derived name */
    u8 unknown0[0x60];
    Node00ebbb70 *first;
};

// NONMATCHING: the loop is rotated (a guard test, then the body with the test at its end); the base
// keeps it unrotated (jmp to the test, the header laid out last); 3.8.1 and 3.9.1 give the base's
// form for this source, 4.0.0 rotates it (round 135B, prebuilt releases)
void FUN_00ebbb70(Object00ebbb70 *self) /* derived name */
{
    for (Node00ebbb70 *node = self->first; node; node = node->next) {
        node->slot10();
    }
}
