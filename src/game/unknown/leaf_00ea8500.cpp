/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 2 of the object its second argument points to and
 * returns 1; the first argument is unused. The argument's class is not traced;
 * slot 11 of the vtable at 0x16be610 (its pointer at 0x16be678), the vtable
 * stored by FUN_00e992b0 FUN_00ea4cd0. Class and method unknown. */
struct Object00ea8500; /* derived name */

class Target00ea8500 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
};

int FUN_00ea8500(Object00ea8500 *, Target00ea8500 *target) /* derived name */
{
    target->slot2();
    return 1;
}
