/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 5 of the vtables at 0x16b5a40 (stored by FUN_00b3ec10)
 * and 0x16b5c48 (stored by FUN_00b404d0 and the destructor FUN_01397620),
 * both with rows (config/vtables.derived.base.txt): clears bits 4 and 5 of the flags byte at +0x20, then calls
 * slot 5 of the objects the pointers at +0x58 and +0x60 hold, each when set
 * (the second as a tail call). FUN_00b40830, slot 1 of the secondary vtables
 * at 0x16b5ab8 and 0x16b5cc0, is its this-adjusting thunk through the base at
 * +0x30, the body inlined. The targets' class and the meaning of the bits are not traced. */
class Target00b407f0 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name */
};

/* The class that defines slot 5: a primary base of 0x28 bytes holding the
 * flags at +0x20 (slots 0 to 4: the destructors and three more), a base at
 * +0x28 with one slot and one at +0x30 with three, whose slot 1 the method
 * overrides (the vtables' offsets to top -0x28 and -0x30), and the two
 * targets after them. The destructor is declared here and defined with the
 * classes' other functions, so this file emits no vtable. */
class Base00b407f0 /* derived name */
{
  public:
    virtual ~Base00b407f0();
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */

  protected:
    u8 unknown8[0x18];
    u8 unknown20; /* +0x20: flags */
    u8 unknown21[7];
};

class Base00b407f0_28 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
};

class Base00b407f0_30 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot5(); /* derived name: the method of slot 5 of the primary vtable */
    virtual void slot2(); /* derived name; not traced */

  private:
    u8 unknown8[0x20];
};

class Object00b407f0 : public Base00b407f0,
                       public Base00b407f0_28,
                       public Base00b407f0_30 /* derived name */
{
  public:
    virtual ~Object00b407f0();
    virtual void slot5();

  private:
    Target00b407f0 *unknown58; /* +0x58 */
    Target00b407f0 *unknown60; /* +0x60 */
};

void Object00b407f0::slot5()
{
    unknown20 &= ~0x30;
    if (unknown58)
        unknown58->slot5();
    if (unknown60)
        unknown60->slot5();
}
