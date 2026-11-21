/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lib_unknown.h"
#include "tlg_math.h"

/* derived names: slot 34 of the vtable at 0x16be430 (its pointer at
 * 0x16be550; slot 65 of the one at 0x16be338): when its argument has a body
 * (the record at +0x48, its body id at +0x34 not 0x7fffffff, the invalid
 * id) and that body is dynamic on the world at +0x38 of the object's record
 * at +0x268 (a null world when that record is null), sets the body's
 * velocities from the two vectors given, x, y and z with a w of zero: the
 * linear one when bit 0 of the flags is set, the angular one when bit 1 is.
 * A body of kind 3 (the int at +0x18) keeps the vectors given at the
 * argument's +0xb0 and +0xc0; a body of kind 0 keeps them at +0x130 and
 * +0x140, and only when the argument's int at +0xac is not zero. The kind 0
 * test is written first: LLVM 3.7.1 folds the two tests into a switch whose
 * lowering tests first the case not laid out next. The classes are not
 * traced. */
struct Body00ea08e0 { /* derived name */
    u8 unknown0[0x18];
    int unknown18;
    u8 unknown1c[0x34 - 0x1c];
    int unknown34;
};

struct Argument00ea08e0 { /* derived name */
    u8 unknown0[0x48];
    Body00ea08e0 *unknown48;
    u8 unknown50[0xac - 0x50];
    int unknownac;
    Float4A unknownb0;
    Float4A unknownc0;
    u8 unknownd0[0x130 - 0xd0];
    Float4A linearVelocity;  /* +0x130 */
    Float4A angularVelocity; /* +0x140 */
};

struct Record00ea08e0 { /* derived name */
    u8 unknown0[0x38];
    hknpWorld *unknown38;
};

struct Object00ea08e0 { /* derived name */
    u8 unknown0[0x268];
    Record00ea08e0 *unknown268;
};

// NONMATCHING: loadXYZ_0's zero upper lane only (the zero's vxorps scheduled before the stores; 77 of 107 equal); equal with r248784's demanded-elements change for bitcasts (the probe -tlg-bitcast-demanded at both stages, round 388D), as leaf_00ea0b80.cpp
void FUN_00ea08e0(Object00ea08e0 *self, Argument00ea08e0 *argument, const Float4A &linearVelocity,
                  const Float4A &angularVelocity, int flags) /* derived name */
{
    Body00ea08e0 *body = argument->unknown48;
    if (body == 0) {
        return;
    }
    hknpWorld *world = self->unknown268 != 0 ? self->unknown268->unknown38 : 0;
    const int bodyId = body->unknown34;
    if (bodyId == 0x7fffffff) {
        return;
    }
    if ((world->bodyManager.bodies[bodyId].flags & hknpBody::IS_DYNAMIC) == 0) {
        return;
    }
    if (body->unknown18 == 0) {
        if (argument->unknownac == 0) {
            return;
        }
        if (flags & 1) {
            argument->linearVelocity = linearVelocity;
            world->FUN_0005dfc0(bodyId, loadXYZ_0(&linearVelocity.x));
        }
        if (flags & 2) {
            argument->angularVelocity = angularVelocity;
            world->FUN_0005e1a0(bodyId, loadXYZ_0(&angularVelocity.x));
        }
    } else if (body->unknown18 == 3) {
        if (flags & 1) {
            argument->unknownb0 = linearVelocity;
            world->FUN_0005dfc0(bodyId, loadXYZ_0(&linearVelocity.x));
        }
        if (flags & 2) {
            argument->unknownc0 = angularVelocity;
            world->FUN_0005e1a0(bodyId, loadXYZ_0(&angularVelocity.x));
        }
    }
}
