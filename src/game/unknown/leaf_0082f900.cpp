/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0082f900.h"

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_0082fa20, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object0082f900::~Object0082f900() {}

/* derived names: what the pointer at +0x28 (Object01343880's) holds for
 * slot 9: an object with flags at +0x24 (bit 7 set by mode 1) that
 * FUN_00c587f0 is handed; not traced */
struct Owner0082fb30 : Object016b9108 /* derived name */
{
    int flags24; /* +0x24 */
};

/* derived names: the object the reference at +0x40 holds, of the type the
 * pointer at 0x5939080 holds: its member at +0x190 is handed to
 * FUN_00c587f0; not traced */
struct Target0082fb30 : Object016b9108 /* derived name */
{
    u8 unknown24[0x16c];
    u8 member190[0x1]; /* +0x190 */
};

extern Type00503fb0 *D_5939080; /* derived name: the target's type */

void FUN_00c5a160(Object016b9108 *object);                      /* derived name */
void FUN_00c587f0(Owner0082fb30 *owner, u8 *member, int flags); /* derived name */

/* derived name: slot 9: the time run down by the step; in mode 0 and 1,
 * once it is out, the object handed to FUN_00c5a160 (mode 1 sets bit 7 of
 * the owner's flags first); in mode 2 the held object, when it is of the
 * target's type, handed with the owner to FUN_00c587f0.
 * NONMATCHING: the type walk's exit: the base keeps kindOf's found flag
 * (`mov dl, 1` in the loop, `cmovne` of null, the object tested again)
 * where the build threads the found edge to the owner's test; modes 0 and
 * 1 are the base's. */
void Object0082f900::slot9(float step)
{
    time -= step;
    switch (mode) {
    case 0:
        if (time <= 0.0f)
            FUN_00c5a160(this);
        break;
    case 1:
        if (time <= 0.0f) {
            static_cast<Owner0082fb30 *>(unknown28)->flags24 |= 0x80;
            FUN_00c5a160(this);
        }
        break;
    case 2:
        if (Object016b9108 *held = held40.get()) {
            Target0082fb30 *target = static_cast<Target0082fb30 *>(kindOf(held, D_5939080));
            if (target && unknown28)
                FUN_00c587f0(static_cast<Owner0082fb30 *>(unknown28), target->member190, 1);
        }
        break;
    }
}
