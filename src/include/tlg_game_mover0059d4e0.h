/* src/include/tlg_game_mover0059d4e0.h: what FUN_0059d4e0, FUN_005a4b00,
 * FUN_005a4e70, FUN_005a5b90 and FUN_005a6110 (the calls FUN_0059d3f0 and
 * its four copies queue) read from the machine they are run on
 * (tlg_game_stacks00c09610.h: the step at +0xc, the node at +0x28 and the
 * body at +0x660, whose last slot holds a counted reference to a target). Each call takes the
 * node's component of one type, the target's first record of limits, and
 * moves or turns the body by them. Every name here is derived. */
#ifndef TLG_GAME_MOVER0059D4E0_H
#define TLG_GAME_MOVER0059D4E0_H

#include "tlg_device_thunk.h"
#include "tlg_game_node.h"
#include "tlg_game_object00774560.h"
#include "tlg_game_object016b85e0.h"
#include "tlg_game_rotation.h"
#include "tlg_game_stacks00c09610.h"
#include "tlg_math.h"

/* derived names: the first record of a target's limits (+0x48 FUN_005a4e70,
 * +0x58 FUN_005a5b90, +0x68 and +0x6c FUN_0059d4e0, +0x74 FUN_005a4b00) */
struct Limits0059d4e0 {
    u8 unknown0[0x48];
    float unknown48; /* +0x48 */
    u8 unknown4c[0xc];
    float unknown58; /* +0x58 */
    u8 unknown5c[0xc];
    float deadZone; /* +0x68: below it a tilt is no tilt (FUN_0059d4e0) */
    float turnRate; /* +0x6c: degrees a step at most (FUN_0059d4e0) */
    u8 unknown70[0x4];
    float unknown74; /* +0x74 */
};

/* derived names: the object a body's slot refers to: its records of limits
 * at +0xa8, their count after them */
struct Target0059d4e0 : Object016b9108 {
    u8 unknown24[0x84];
    Limits0059d4e0 **limits; /* +0xa8 */
    unsigned limitCount;     /* +0xb0 */

    /* the first record, null when there is none */
    Limits0059d4e0 *firstLimits() const
    {
        return limitCount ? limits[0] : 0;
    }
};

/* derived names: a slot of the body, 16 bytes: the reference at +0x8 */
struct Slot0059d4e0 {
    u8 unknown0[0x8];
    Ref00503fb0<Target0059d4e0> target; /* +0x8 */
};

/* derived names: the body at +0x660 of the machine: its slots at +0x390
 * with their count after them, a rotation at +0x460 and a position at
 * +0x470 */
struct Body0059d4e0 {
    u8 unknown0[0x390];
    Slot0059d4e0 *slots; /* +0x390 */
    unsigned slotCount;  /* +0x398 */
    u8 unknown39c[0xc4];
    Float4A rotation;        /* +0x460 */
    Vector0077bac0 position; /* +0x470 */

    /* the target of the last slot, a reference of its own (the slot's
     * index a signed int: `dec eax; cdqe`); empty without a slot */
    Ref00503fb0<Target0059d4e0> currentTarget() const
    {
        if (!slotCount)
            return Ref00503fb0<Target0059d4e0>();
        return slots[int(slotCount - 1)].target;
    }
};

/* derived names: the node's component of the type at 0x5814678, as
 * FUN_0059d4e0 and FUN_005a4e70 read it */
struct Mover0059d4e0 : Component00503fb0 {
    u8 unknown8c[0x98];
    float tilt; /* +0x124 */
    u8 unknown128[0x8];
    Vector0077bac0 velocity; /* +0x130 */
    u8 unknown13c[0x78];
    float unknown1b4; /* +0x1b4 */
};

/* derived names: the node's component of the type at 0x5814e08, as
 * FUN_005a4b00 and FUN_005a5b90 read it: a flag at +0x14d8 and a normal at
 * +0x1640 */
struct Slider0059d4e0 : Component00503fb0 {
    u8 unknown8c[0x4a4];
    Float4A up; /* +0x530: the direction FUN_005a6110 turns the body to */
    u8 unknown540[0xf98];
    int unknown14d8; /* +0x14d8 */
    u8 unknown14dc[0x164];
    float normal[3]; /* +0x1640 */
};

/* derived names: the node FUN_005a5b90's arguments carry: a flag at +0x48
 * that turns its slope the other way */
struct Argument0059d4e0 {
    u8 unknown0[0x48];
    int unknown48; /* +0x48 */
};

/* derived names: the rotation between two directions (FUN_00208b90,
 * leaf_00208b90.cpp), its four lanes as plain floats (copied into a
 * Float4A by two 64-bit loads and four 32-bit stores at 0x5a5f0a) */
struct Object0020d4b0 {
    Float4Data rotation;
};

void FUN_00208b90(Object0020d4b0 *self, float ax, float ay, float az, float bx, float by,
                  float bz); /* derived name */

/* derived names: a point turned by a rotation (leaf_01343bb0.cpp) */
void FUN_01343bb0(Float4A *out, const Float4A &point, const Float4A &q); /* derived name */

/* derived name: a rotation's axis and angle in degrees (leaf_0134bb20.cpp) */
float FUN_0134bb20(const Float4A &rotation, Float4A &axis); /* derived name */

/* derived names: a rotation of `angle` degrees about the axis (x, y, z)
 * (FUN_00206950, leaf_00206950.cpp; its body FUN_00206a90 normalizes the
 * axis and stores the four lanes) */
struct Object00206a90 {
    Float4A rotation;
};

void FUN_00206950(Object00206a90 *self, float x, float y, float z, float angle); /* derived name */

/* derived names: the five calls (leaf_0059d4e0.cpp) */
int FUN_0059d4e0(void *vm, const CallArguments583950 *arguments); /* derived name */
int FUN_005a4b00(void *vm, const CallArguments583950 *arguments); /* derived name */
int FUN_005a4e70(void *vm, const CallArguments583950 *arguments); /* derived name */
int FUN_005a5b90(void *vm, const CallArguments583950 *arguments); /* derived name */
int FUN_005a6110(void *vm, const CallArguments583950 *arguments); /* derived name */

#endif
