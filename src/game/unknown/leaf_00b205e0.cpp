/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 21 of the vtable at 0x16b53f8: clears the int at +0x4c
 * of the object its third argument points to, calls that object's slot 11, and
 * sets the int to 1 when bit 0 of the byte at +0x48 is then set. The types are
 * not traced. Class and method unknown. */
class Target00b205e0 /* derived name */
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
    virtual void slot11(); /* derived name; not traced */

    u8 unknown8[0x40];
    u8 unknown48 : 1;
    u8 unknown49[3];
    int unknown4c;
};

struct Object00b205e0; /* derived name */

void FUN_00b205e0(Object00b205e0 *, void *, Target00b205e0 *target) /* derived name */
{
    target->unknown4c = 0;
    target->slot11();
    if (target->unknown48) {
        target->unknown4c = 1;
    }
}
