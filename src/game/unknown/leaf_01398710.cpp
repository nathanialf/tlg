/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a slot of six vtables (its pointers at 0x16cf8f0, 0x16cfa60, 0x16cfc00, 0x16cfd70, 0x16cfe10, 0x16cfeb0; no rows), written as a free function: asks the object the
 * pointer at +0xa0 holds for its slot 6 with -1 and, when that is not 0,
 * calls the object's own slot 10, returning the answer (0 without the
 * object). The slots' meaning is not traced. */
class Target01398710 /* derived name */
{
  public:
    virtual void slot0();         /* derived name; not traced */
    virtual void slot1();         /* derived name; not traced */
    virtual void slot2();         /* derived name; not traced */
    virtual void slot3();         /* derived name; not traced */
    virtual void slot4();         /* derived name; not traced */
    virtual void slot5();         /* derived name; not traced */
    virtual int slot6(int which); /* derived name */
};

class Object01398710 /* derived name */
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

    u8 unknown8[0x98];
    Target01398710 *unknowna0; /* +0xa0 */
};

int FUN_01398710(Object01398710 *self) /* derived name */
{
    int result = 0;
    if (self->unknowna0) {
        int value = self->unknowna0->slot6(-1);
        if (value) {
            self->slot10();
            result = value;
        }
    }
    return result;
}
