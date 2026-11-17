/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"
#include "tlg_game_object016accb0.h"

/* derived names: FUN_00773e90 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 10 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15948c5[9];
extern const char D_15948ce[26];
extern const char D_15948e8[18];
extern const char D_15948fa[34];
extern const char D_159491c[29];
extern const char D_1594939[23];
extern const char D_1594950[24];
extern const char D_1594968[28];
extern const char D_1594984[13];
extern const char D_1595794[18];

Name D_58178ac(D_1595794, false);
Name D_5817900(D_15948c5, false);
Name D_5817908(D_15948ce, false);
Name D_5817904(D_15948e8, false);
Name D_581790c(D_15948fa, false);
Name D_5817910(D_159491c, false);
Name D_5817918(D_1594939, false);
Name D_581791c(D_1594950, false);
Name D_5817920(D_1594968, false);
Name D_5817914(D_1594984, false);

/* derived names: slot 7 of the vtable at 0x16accb0, reading this file's
 * VECTOR_W: when slot 22 allows it, the body's state at +0xc00 is set by the
 * body's int at +0x1c18 (40 and 41: zero; 39: the body's bits at +0xb08 less
 * the class's at +0x168), then the body's rotation taken from the pose (39,
 * 40) or set to VECTOR_W (41, a copy as plain floats), and its point from
 * the pose's; any other value leaves the body as it is */
// NONMATCHING: register assignment only (round 376B, whole module, 228 bytes against 225): the
// second switch's head keeps the pose's point address in rax (`lea rax, [r14+0x90]` at
// 0x770221) and the rotation's is formed from r14 itself (`sub r14, -0x80`); the build keeps
// r14 live into the merge block and forms the point there (`add r14, 0x90`), the rotation in
// a copy (`mov rcx, r14; sub rcx, -0x80`); the IR holds both addresses in the head block and
// both copies as memcpy (the references taken at the top give the same bytes)
void Object016accb0::slot7(Pose0077bac0 *pose)
{
    if (!slot22())
        return;
    switch (unknown68->unknown1c18) {
    case 40:
    case 41:
        unknown68->unknownc00->setUnknown60(0);
        break;
    case 39: {
        const int value = unknown68->unknownb08 & ~unknown164[1];
        unknown68->unknownc00->setUnknown60(value);
        break;
    }
    }
    const Float4A &rotation = pose->rotation80;
    const Float4A &point = pose->point90;
    switch (unknown68->unknown1c18) {
    case 39:
    case 40:
        unknown68->rotation = rotation;
        break;
    case 41:
        unknown68->rotation = Float4Data(reinterpret_cast<const Float4Data &>(VECTOR_W));
        break;
    default:
        return;
    }
    unknown68->position = point;
}

/* derived names: slot 19 of the vtable at 0x16accb0, reading this file's
 * VECTOR_W: the pose's rotation at +0xd0 turned by the body's, and the
 * point of the pose's held object at +0x110 (VECTOR_W, as plain floats,
 * when it holds none) turned by that rotation into the point at +0xd0 of the
 * object at +0x70 */
void Object016accb0::slot19(Pose0077bac0 *pose)
{
    const Float4A turn = FUN_013439c0(pose->rotationd0, unknown68->rotation);
    Float4A point;
    if (const Held00773d80 *held = pose->unknown58)
        point =
            Float4A(held->unknown110.x, held->unknown110.y, held->unknown110.z, held->unknown110.w);
    else
        point = reinterpret_cast<const Float4Data &>(VECTOR_W);
    unknown70->unknownd0 = FUN_01343bb0(point, turn);
}
