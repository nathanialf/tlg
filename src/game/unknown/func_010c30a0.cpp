/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"
#include "tlg_game_aim010c25d0.h"

/* derived names: FUN_010c30a0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 2 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad18e0(D_15cb5dd, false);
Name D_5ad18e4(D_15cb5e6, false);

/* FUN_010c25d0 (called by FUN_010b7c20 after FUN_010c1ce0): the pose's
 * second bone taken from the source pose, lifted by a value kept between -1
 * and 1 (stored at +0xc8), moved by the aim's offsets, turned to look at the
 * point the offsets reach from the source bone (its up toward the first
 * bone), w made positive, or the identity when the points meet, then turned
 * about its x axis by the aim's angle. FUN_012ce440 is its bytes in
 * func_012cef10.cpp (that unit's VECTOR_ZERO and VECTOR_W), not written. */
// NONMATCHING: 133/213 (1136 bytes, base 1139; the frame, the lerp, the clamp, the offset's
// sums, the look-at, the rotation's w made positive (makeWPositive(Float4A &): the negation's
// address made once and kept in r13 across FUN_013cee80's call) and the sine/cosine tail
// equal; the sway's absolute value is a compare and select, which the selection DAG folds to the
// base's vandps, so its products are the base's: sway * up.x, sway * up.y, up.z * sway). Left:
// (a) the aim's up.z (+0x118) is read again in both arms of the +0xc4 test in the base, up.x and
// up.y come from the first arms, and the sway's x sum is term + x in the base (here x + term;
// y + term and z + term equal); the registers of the two diamonds follow. (c) the entry: the
// zero for the lift's test is made in the
// entry here (xmm12), before the clamp in the base (xmm2), and the pose pointer is read before
// the limit's floats.
void Aimer010c25d0::aimFirst()
{
    const Bone010c25d0 &original = source->bones[1];
    const Limit010c25d0 &limit = settings->limits[index];
    const float reach = limit.reach;
    const float floor = limit.floor;
    Bone010c25d0 &bone = pose->bones[1];
    bone.position = original.position;
    bone.rotation = original.rotation;
    const float weight = settings->weights[index];
    const float raised = floor * (1.0f - weight) + (unknown1a4 + 0.68596917f) * weight;
    float lift = raised < floor ? floor : raised;
    lift = clampTo(lift, -1.0f, 1.0f);
    lifts[0] = lift;

    const Aim010c25d0 &aim = aims[0];
    float x, y, z, step;
    if (lift >= 0.0f) {
        x = aim.up.x * lift;
        y = aim.up.y * lift;
        z = aim.up.z * lift;
        step = lift * 0.5f;
    } else {
        x = -lift * aim.down.x;
        y = -lift * aim.down.y;
        z = -lift * aim.down.z;
        step = 0.0f;
    }
    const float turn = unknownc4;
    if (turn > 0.0f) {
        const float scale = turn * 0.5f;
        x += scale * aim.down.x;
        y += scale * aim.down.y;
        z += scale * aim.down.z;
    } else {
        const float scale = turn * -0.75f;
        x += aim.up.x * scale;
        y += aim.up.y * scale;
        z += aim.up.z * scale;
    }
    const float sway = (unknownc0 < 0.0f ? -unknownc0 : unknownc0) * 0.15f;
    x += aim.up.x * sway;
    y += aim.up.y * sway;
    z += aim.up.z * sway;
    if (reach > 0.0f) {
        const float scale = (1.0f - step) * reach;
        x += scale * aim.forward.x;
        y += scale * aim.forward.y;
        z += scale * aim.forward.z;
    } else {
        const float scale = -reach;
        x += scale * aim.backward.x;
        y += scale * aim.backward.y;
        z += scale * aim.backward.z;
    }
    const Float4A to = source->bones[1].pointAt(x + aim.base.x, y + aim.base.y, z + aim.base.z);
    Pose010c25d0 *target = pose;
    Matrix010c25d0 matrix;
    if (FUN_00f52470(&matrix, &target->bones[0].position, 1, target->bones[1].position.x,
                     target->bones[1].position.y, target->bones[1].position.z, to.x, to.y, to.z)) {
        matrix.getRotation(target->bones[1].rotation);
    } else {
        target->bones[1].rotation = Float4Data(reinterpret_cast<const Float4Data &>(VECTOR_W));
    }

    FUN_00fbd3b0(&pose->bones[1].rotation, sin(0.017453292f * aims[0].angle),
                 cos(0.017453292f * aims[0].angle), 0);
}
