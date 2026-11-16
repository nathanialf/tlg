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

/* derived names: slot 2 of the same four vtables: 0 when a body id below the
 * count at +0x30 is not the invalid id, or when an id from the count up to
 * one is (the first id, tested when the count is 0: `cmp dword [rdi +
 * 0x34], 0x7fffffff` after the loop); 1 otherwise. */
int FUN_00eb2f20(Object00eb2f70 *self) /* derived name */
{
    for (unsigned i = 0; i < self->unknown30; ++i) {
        if (self->unknown34[i] != 0x7fffffff)
            return 0;
    }
    for (unsigned i = self->unknown30; i < 1; ++i) {
        if (self->unknown34[i] == 0x7fffffff)
            return 0;
    }
    return 1;
}

/* derived names: slot 8 of the class whose vtable is 0x16be8f8 (constructed
 * by FUN_00eb2af0): 0 when the argument's index at +0xc is below the
 * count at +0x30; otherwise false when its body id is the invalid one, else whether that
 * body is valid in the index's world and is in its broad phase (the test
 * FUN_00eb2f70 stores at +0x3c). */
int FUN_00eb3470(const Object00eb2f70 *self, const Argument00eb2f70 *argument) /* derived name */
{
    if (argument->unknownC < self->unknown30) {
        return 0;
    }
    bool valid = false;
    int bodyId = self->unknown34[argument->unknownC];
    if (bodyId != 0x7fffffff) {
        hknpWorld &world = self->unknown28->unknown38[argument->unknownC];
        valid =
            world.isBodyValid(bodyId) && world.bodyManager.bodies[bodyId].broadPhaseId != u32(-1);
    }
    return valid;
}

/* Object016c9f40 (vtable row; constructed by FUN_00eaffe0, FUN_00eb00b0 and
 * FUN_00eb0180) adds a pointer at +0x50; its slot 2 is 0 while that pointer
 * is null, else the base's slot 2 (FUN_00eb2f20). */
struct Object016c9f40 : Object00eb2f70 {
    u8 unknown40[0x10];
    void *unknown50;
};

int FUN_00eb0290(Object016c9f40 *self) /* derived name */
{
    if (self->unknown50 == 0) {
        return 0;
    }
    return FUN_00eb2f20(self);
}
