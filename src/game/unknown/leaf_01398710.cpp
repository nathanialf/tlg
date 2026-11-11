/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 6 of six vtables (its pointers at 0x16cf8f0,
 * 0x16cfa60, 0x16cfc00, 0x16cfd70, 0x16cfe10, 0x16cfeb0; no rows): asks the
 * object the pointer at +0xa0 holds for its slot 6 with -1 and, when that is
 * not 0, calls the object's own slot 10, returning the answer (0 without the
 * object). It overrides slot 0 of the base at +0x10 (the vtables' secondary
 * part at offset to top -0x10, whose slot 0 is the thunk 0x1397ac0, the body
 * inlined; cookbook 1192), so it has its own primary slot, the class's
 * first. The slots' meaning is not traced. */
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

class Base01398710 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */

  private:
    u8 unknown8[8];
};

class Base01398710_10 /* derived name */
{
  public:
    virtual int FUN_01398710() = 0; /* derived name */
};

class Object01398710 : public Base01398710, public Base01398710_10 /* derived name */
{
  public:
    int FUN_01398710();    /* derived name: slot 6 */
    virtual void slot7();  /* derived name; not traced */
    virtual void slot8();  /* derived name; not traced */
    virtual void slot9();  /* derived name; not traced */
    virtual void slot10(); /* derived name; not traced */

  private:
    u8 unknown18[0x88];
    Target01398710 *unknowna0; /* +0xa0 */
};

int Object01398710::FUN_01398710() /* derived name */
{
    int result = 0;
    if (unknowna0) {
        int value = unknowna0->slot6(-1);
        if (value) {
            slot10();
            result = value;
        }
    }
    return result;
}
