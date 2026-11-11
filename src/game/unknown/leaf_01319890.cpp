/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 13 of the vtable at 0x16c39b8 (its pointer at 0x16c3a30): -2
 * without a target, else what slot 5 of the target returns for the object and
 * the three further arguments, passed on, as a tail call (their types are not
 * traced). Class and method unknown. */
struct Object01319890; /* derived name */

class Target01319890 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual int slot5(Object01319890 *object, void *first, void *second,
                      void *third); /* derived name */
};

int FUN_01319890(Object01319890 *self, Target01319890 *target, void *first, void *second,
                 void *third) /* derived name */
{
    if (target) {
        return target->slot5(self, first, second, third);
    }
    return -2;
}
