/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lib_unknown.h"

/* derived names: the function at 0x16be5d0 (+0x140 from the vtable stored at
 * 0x16be490): when both arguments have a body (the record at +0x48, its body
 * id at +0x34 not 0x7fffffff, the invalid id), on the world of the larger of
 * their world indices (+0x30) in the array of 0x720-byte worlds at +0x38 of
 * the object's record at +0x268 (a null world when that record is null), and
 * when the two bodies have different motions: the first body is moved to the
 * second's transform times the transform given (its w lanes made clean) and
 * attached to the second (FUN_0004ebd0, one id, mode 2). The first body's
 * int at +0x38 is then set. The classes are not traced. */
struct Body00ea1090 { /* derived name */
    u8 unknown0[0x30];
    u32 unknown30;
    int unknown34;
    int unknown38;
};

struct Argument00ea1090 { /* derived name */
    u8 unknown0[0x48];
    Body00ea1090 *unknown48;
};

struct Worlds00ea1090 { /* derived name */
    u8 unknown0[0x38];
    hknpWorld *unknown38;
};

struct Object00ea1090 { /* derived name */
    u8 unknown0[0x268];
    Worlds00ea1090 *unknown268;
};

// NONMATCHING: the null world's arm: the base keeps `xor r15d, r15d; test rsi, rsi; je` before
// the bodies' load, the build drops it (SimplifyCFG's removeUndefIntroducingPredecessor: the
// phi's first use is the load of +0x20 in its own block); then register assignment
void FUN_00ea1090(Object00ea1090 *self, Argument00ea1090 *child, Argument00ea1090 *parent,
                  const hkTransform &offset) /* derived name */
{
    Body00ea1090 *childBody = child->unknown48;
    if (childBody == 0) {
        return;
    }
    Body00ea1090 *parentBody = parent->unknown48;
    if (parentBody == 0) {
        return;
    }
    hknpBodyId childId(childBody->unknown34);
    if (childId.value == 0x7fffffff) {
        return;
    }
    const int parentId = parentBody->unknown34;
    if (parentId == 0x7fffffff) {
        return;
    }
    hknpWorld *world =
        self->unknown268 != 0
            ? &self->unknown268
                   ->unknown38[childBody->unknown30 > parentBody->unknown30 ? childBody->unknown30
                                                                            : parentBody->unknown30]
            : 0;
    const hknpBody &parentBodyData = world->bodyManager.bodies[parentId];
    if (world->bodyManager.bodies[int(childId.value)].motionId != parentBodyData.motionId) {
        hkTransform local;
        local.FUN_00010a70(offset);
        hkTransform transform;
        transform.FUN_00010b40(parentBodyData.transform, local);
        FUN_0005d6b0(world, childId.value, &transform, 0);
        world->FUN_0004ebd0(parentId, &childId, 1, 2);
    }
    childBody->unknown38 = 1;
}
