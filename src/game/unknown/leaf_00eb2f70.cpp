/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lib_unknown.h"

/* derived names: slot 6 of four vtables (its pointer at 0x16be750,
 * 0x16be938, 0x16be990 and 0x16c9f80: a base class's method): 0 when
 * the argument's index at +0xc is below the count at +0x30; otherwise clears
 * the flag at +0x3c and, when the body id the index selects in the array at
 * +0x34 is not 0x7fffffff (the invalid id), sets it to whether that body is
 * valid in the world the index selects in the array of 0x720-byte worlds at
 * +0x38 of the object's pointer at +0x28 and is in its broad phase; 1 (0 for the first case: an int, `mov eax, 1`).
 * The classes are not traced. */
struct Argument00eb2f70 { /* derived name */
    u8 unknown0[0xc];
    unsigned unknownC;
};

struct Worlds00eb2f70 { /* derived name */
    u8 unknown0[0x38];
    hknpWorld *unknown38;
};

struct Object00eb2f70 { /* derived name */
    u8 unknown0[0x28];
    Worlds00eb2f70 *unknown28;
    unsigned unknown30;
    int unknown34[2]; /* two, the flag follows */
    bool unknown3c;
};

int FUN_00eb2f70(Object00eb2f70 *self, const Argument00eb2f70 *argument) /* derived name */
{
    if (argument->unknownC < self->unknown30) {
        return 0;
    }
    self->unknown3c = false;
    int bodyId = self->unknown34[argument->unknownC];
    if (bodyId != 0x7fffffff) {
        hknpWorld &world = self->unknown28->unknown38[argument->unknownC];
        self->unknown3c =
            world.isBodyValid(bodyId) && world.bodyManager.bodies[bodyId].broadPhaseId != u32(-1);
    }
    return 1;
}
