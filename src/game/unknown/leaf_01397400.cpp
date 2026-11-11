/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a slot of the vtable group of 0x16b5a40
 * (config/vtables.derived.base.txt; its pointer at 0x16b5b68, +0x128 in the
 * group), written as a free function: asks the object the
 * pointer at +0x108 holds for its slot 6 with -1 and, when that is not 0,
 * calls the object's own slot 10, returning the answer (0 without the
 * object). The slots' meaning is not traced. */
class Target01397400 /* derived name */
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

class Object01397400 /* derived name */
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

    u8 unknown8[0x100];
    Target01397400 *unknown108; /* +0x108 */
};

int FUN_01397400(Object01397400 *self) /* derived name */
{
    int result = 0;
    if (self->unknown108) {
        int value = self->unknown108->slot6(-1);
        if (value) {
            self->slot10();
            result = value;
        }
    }
    return result;
}
