/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 9 of the class of the vtable at 0x16be610
 * (config/vtables.derived.base.txt), which reads none of its own fields: the
 * object of the class of 0x16be818 a target holds at +0x48, else one made for
 * it (its constructor FUN_00eb1170 links the two: the target at +0x20, the
 * object at the target's +0x48) and kept when its slot 3 says so; otherwise
 * the link is undone, the object deleted and null returned. The members
 * before +0x20 are its base's (0x16b9850, leaf_00cef280.cpp; the constructor
 * sets +0x8 to -1, +0x10 to null and +0x18 from the target's +0x40). */
class Object016be818;

struct Target00ea8480 { /* derived name */
    u8 unknown0[0x48];
    Object016be818 *unknown48; /* +0x48 */
};

class Object016be818 /* derived name */
{
  public:
    explicit Object016be818(Target00ea8480 *target); /* FUN_00eb1170 */
    virtual ~Object016be818();
    virtual void slot2();
    virtual int slot3();

    u8 unknown8[0x18];
    Target00ea8480 *target; /* +0x20 */
    void *unknown28;        /* +0x28: null from the constructor */
};

class Object016be610; /* derived name: not traced */

Object016be818 *FUN_00ea8480(Object016be610 *, Target00ea8480 *target) /* derived name */
{
    Object016be818 *object = target->unknown48;
    if (!object) {
        object = new Object016be818(target);
        if (!object->slot3()) {
            if (object->target) {
                object->target->unknown48 = 0;
                object->target = 0;
            }
            delete object;
            object = 0;
        }
    }
    return object;
}
