/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 4 of its argument with the object, null skipped,
 * as a tail call; slot 12 of the vtable at 0x16c39b8 (its pointer at
 * 0x16c3a28). The argument's class and the return type are not traced. Class
 * and method unknown. */
struct Object01319870; /* derived name */

class Target01319870 /* derived name */
{
  public:
    virtual void slot0();                       /* derived name; not traced */
    virtual void slot1();                       /* derived name; not traced */
    virtual void slot2();                       /* derived name; not traced */
    virtual void slot3();                       /* derived name; not traced */
    virtual void slot4(Object01319870 *object); /* derived name; not traced */
};

void FUN_01319870(Object01319870 *self, Target01319870 *target) /* derived name */
{
    if (target) {
        target->slot4(self);
    }
}
