/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a virtual method (its address at 0x16b1048 in
 * .data.rel.ro): when the object at +0x148 is set and its slot 7 returns
 * nonzero, calls the object's own slot 14 and returns that value; else 0.
 * Class and method unknown; the slots' other signatures are not traced. */
class Member0137e1e0 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual int slot7();  /* derived name */
};

class Object0137e1e0 /* derived name */
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
    virtual void slot12(); /* derived name; not traced */
    virtual void slot13(); /* derived name; not traced */
    virtual void slot14(); /* derived name */

    u8 unknown8[0x140];
    Member0137e1e0 *unknown148; /* +0x148 */
};

int FUN_0137e1e0(Object0137e1e0 *self) /* derived name */
{
    int result = 0;
    if (self->unknown148) {
        int value = self->unknown148->slot7();
        if (value) {
            self->slot14();
            result = value;
        }
    }
    return result;
}
