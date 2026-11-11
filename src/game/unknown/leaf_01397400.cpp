/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 35 of the class whose vtable group is at 0x16b5a40
 * (config/vtables.derived.base.txt; its pointer at 0x16b5b68, +0x128 in the
 * group): asks the object the pointer at +0x108 holds for its slot 6 with -1
 * and, when that is not 0, calls the object's own slot 10, returning the
 * answer (0 without the object). It overrides slot 0 of the base at +0x10
 * (the group's part at offset to top -0x10, whose slot 0 is the thunk
 * 0x1396cb0, the body inlined; cookbook 1192), so it has its own primary
 * slot, the first after the 35 the primary base's vtable holds. The slots'
 * meaning is not traced; the class's key function is not in this file. */
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

class Base016b5a40 /* derived name */
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
    virtual void slot14(); /* derived name; not traced */
    virtual void slot15(); /* derived name; not traced */
    virtual void slot16(); /* derived name; not traced */
    virtual void slot17(); /* derived name; not traced */
    virtual void slot18(); /* derived name; not traced */
    virtual void slot19(); /* derived name; not traced */
    virtual void slot20(); /* derived name; not traced */
    virtual void slot21(); /* derived name; not traced */
    virtual void slot22(); /* derived name; not traced */
    virtual void slot23(); /* derived name; not traced */
    virtual void slot24(); /* derived name; not traced */
    virtual void slot25(); /* derived name; not traced */
    virtual void slot26(); /* derived name; not traced */
    virtual void slot27(); /* derived name; not traced */
    virtual void slot28(); /* derived name; not traced */
    virtual void slot29(); /* derived name; not traced */
    virtual void slot30(); /* derived name; not traced */
    virtual void slot31(); /* derived name; not traced */
    virtual void slot32(); /* derived name; not traced */
    virtual void slot33(); /* derived name; not traced */
    virtual void slot34(); /* derived name; not traced */

  private:
    u8 unknown8[8];
};

class Base016b5a40_10 /* derived name */
{
  public:
    virtual int FUN_01397400() = 0; /* derived name */
};

class Object016b5a40 : public Base016b5a40, public Base016b5a40_10 /* derived name */
{
  public:
    int FUN_01397400(); /* derived name: slot 35 */

  private:
    u8 unknown18[0xf0];
    Target01397400 *unknown108; /* +0x108 */
};

int Object016b5a40::FUN_01397400() /* derived name */
{
    int result = 0;
    if (unknown108) {
        int value = unknown108->slot6(-1);
        if (value) {
            slot10();
            result = value;
        }
    }
    return result;
}
