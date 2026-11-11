/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 6 of the vtable at 0x16cc898 (its pointer at 0x16cc8d8 and in the vtable at 0x16cee58 at 0x16cf000) and,
 * through the thunk 0x137bf90 (this - 0x10, the body inlined into it), slot 0 of
 * the base at +0x10 (its pointer at 0x16cc900 and 0x16cf028): when the object at +0x18 is set and
 * its slot 7 returns nonzero, calls the class's slot 3 (its slot 3 the shared empty body 0x1af750) and returns that
 * value; else 0, as FUN_0137ba00 does in the class at 0x16cc478. The
 * constructor is not traced. */
class Base0137c110_0 /* derived name */
{
  public:
    virtual ~Base0137c110_0();
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */

    u8 unknown8[8];
};

class Member0137c110_18 /* derived name */
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

class Base0137c110_10 /* derived name */
{
  public:
    virtual int FUN_0137bf90() = 0; /* derived name, after its thunk */

    Member0137c110_18 *member8; /* +0x8 */
    u8 unknown10[8];
};

class Object0137c110 /* derived name */
    : public Base0137c110_0,
      public Base0137c110_10
{
  public:
    virtual ~Object0137c110();

    int FUN_0137bf90();
};

int Object0137c110::FUN_0137bf90()
{
    int result = 0;
    if (member8) {
        int value = member8->slot7();
        if (value) {
            slot3();
            result = value;
        }
    }
    return result;
}
