/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 8 of the vtable at 0x16cd1b8 (its pointer at 0x16cd200) and,
 * through the thunk 0x1380570 (this - 0x10, the body inlined into it), slot 0 of
 * the base at +0x10 (its pointer at 0x16cd228): when the object at +0x18 is set and
 * its slot 7 returns nonzero, calls the class's slot 5 (FUN_01380880) and returns that
 * value; else 0, as FUN_0137ba00 does in the class at 0x16cc478. The
 * constructor is not traced. */
class Base01381810_0 /* derived name */
{
  public:
    virtual ~Base01381810_0();
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name */
    virtual void slot6(); /* derived name; not traced */
    virtual void slot7(); /* derived name; not traced */

    u8 unknown8[8];
};

class Member01381810_18 /* derived name */
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

class Base01381810_10 /* derived name */
{
  public:
    virtual int FUN_01380570() = 0; /* derived name, after its thunk */

    Member01381810_18 *member8; /* +0x8 */
    u8 unknown10[8];
};

class Object01381810 /* derived name */
    : public Base01381810_0,
      public Base01381810_10
{
  public:
    virtual ~Object01381810();

    int FUN_01380570();
};

int Object01381810::FUN_01380570()
{
    int result = 0;
    if (member8) {
        int value = member8->slot7();
        if (value) {
            slot5();
            result = value;
        }
    }
    return result;
}
