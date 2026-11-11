/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 6 of the vtable at 0x16b1508 (its pointer at
 * 0x16b1548, no row; stored by FUN_0096a0a0 and FUN_0137fd40): asks the
 * object the pointer at +0x28 holds for its slot 6 with -1 and, when that is
 * not 0, passes it to FUN_0137f740 with the object, returning the answer (0
 * without the object). It overrides slot 0 of the base at +0x10 (the
 * vtable's part at offset to top -0x10, whose slot 0 is the thunk 0x137f9d0,
 * the body inlined; cookbook 1192), so it has its own primary slot, the
 * class's first. The slots' meaning is not traced. */
class Target0137fa20 /* derived name */
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

class Base0137fa20 /* derived name */
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

class Base0137fa20_10 /* derived name */
{
  public:
    virtual int FUN_0137fa20() = 0; /* derived name */

  private:
    u8 unknown8[0x10];
};

class Object0137fa20 : public Base0137fa20, public Base0137fa20_10 /* derived name */
{
  public:
    int FUN_0137fa20(); /* derived name: slot 6 */

    Target0137fa20 *unknown28; /* +0x28 */
};

void FUN_0137f740(Object0137fa20 *self, Target0137fa20 *target); /* derived name */

// The thunk 0x137f9d0 is not matched: the base reloads the pointer for the call from the
// adjusted object (`add rbx, -0x10; mov rsi, [rbx + 0x28]`), this from the first load's address
// before the adjustment (`mov rsi, [rbx + 0x18]`): InstCombine gives both loads one GEP here.
int Object0137fa20::FUN_0137fa20() /* derived name */
{
    int result = 0;
    if (unknown28) {
        int value = unknown28->slot6(-1);
        if (value) {
            FUN_0137f740(this, unknown28);
            result = value;
        }
    }
    return result;
}
