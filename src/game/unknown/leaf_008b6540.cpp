/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16afff8 (+0x70 from the vtable stored at
 * 0x16aff88): when FUN_008b6580 returns nonzero for its argument, passes the
 * argument to FUN_008b6970 and calls the argument's slot 7, a tail call. The
 * object itself is not read; the classes and the return types are not traced. */
class Argument008b6540 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual void slot7(); /* derived name; not traced */
};

struct Object008b6540; /* derived name */

int FUN_008b6580(Argument008b6540 *argument);  /* derived name */
void FUN_008b6970(Argument008b6540 *argument); /* derived name */

void FUN_008b6540(Object008b6540 *, Argument008b6540 *argument) /* derived name */
{
    if (FUN_008b6580(argument) != 0) {
        FUN_008b6970(argument);
        argument->slot7();
    }
}
