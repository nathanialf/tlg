/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 3 of its argument with the object, null skipped,
 * as a tail call; slot 4 of the vtable at 0x16c3808 (its pointer at
 * 0x16c3838). The argument's class and the return type are not traced. Class
 * and method unknown. */
struct Object01303c60; /* derived name */

class Target01303c60 /* derived name */
{
  public:
    virtual void slot0();                       /* derived name; not traced */
    virtual void slot1();                       /* derived name; not traced */
    virtual void slot2();                       /* derived name; not traced */
    virtual void slot3(Object01303c60 *object); /* derived name; not traced */
};

void FUN_01303c60(Object01303c60 *self, Target01303c60 *target) /* derived name */
{
    if (target) {
        target->slot3(self);
    }
}
