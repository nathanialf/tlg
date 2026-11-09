/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 5 of the object its second argument points to when
 * its int at +0x20 is non-zero, as a tail call; the first argument is unused.
 * The argument's class is not traced; slot 9 of the vtable at 0x16be3a8 (its
 * pointer at 0x16be400), the vtable stored by FUN_00e97eb0 FUN_00e980d0
 * FUN_00e98140. Class and method unknown. */
struct Object00e98390; /* derived name */

class Target00e98390 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */

    u8 unknown8[0x20 - 8];
    int unknown20;
};

void FUN_00e98390(Object00e98390 *, Target00e98390 *target) /* derived name */
{
    if (target->unknown20) {
        target->slot5();
    }
}
