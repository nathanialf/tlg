/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a vtable slot (its pointer at 0x16b1548, no row), written
 * as a free function: asks the object the pointer at +0x28 holds for its
 * slot 6 with -1 and, when that is not 0, passes it to FUN_0137f740 with the
 * object, returning the answer (0 without the object). The slots' meaning
 * is not traced. */
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

struct Object0137fa20 /* derived name */
{
    u8 unknown0[0x28];
    Target0137fa20 *unknown28; /* +0x28 */
};

void FUN_0137f740(Object0137fa20 *self, Target0137fa20 *target); /* derived name */

int FUN_0137fa20(Object0137fa20 *self) /* derived name */
{
    int result = 0;
    if (self->unknown28) {
        int value = self->unknown28->slot6(-1);
        if (value) {
            FUN_0137f740(self, self->unknown28);
            result = value;
        }
    }
    return result;
}
