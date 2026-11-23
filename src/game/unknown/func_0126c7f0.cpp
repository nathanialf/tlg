/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_fade013d2490.h"
#include "tlg_game_object016d7840.h"
#include "tlg_game_object016d7510.h"
#include "tlg_game_joint013eb0a0.h"
#include "tlg_game_name.h"
#include "tlg_game_rotation.h"
#include "tlg_game_vector.h"
#include "tlg_game_axes01000aa0.h"
#include "tlg_game_object01481650.h"

/* derived names: FUN_0126c7f0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt) that the fade entries' resize reads.
 * Then, in declaration order, 35 names from strings, each registered with
 * Name's destructor (0x1331800), and a list, destroyed by the array
 * destructor the compiler writes for it (0x1270590). What reads them is not
 * traced. */

/* an entry of 8 bytes, the name first: the initializer stores the name
 * only, and the destructor releases the name only (the second word not
 * traced) */
struct Entry0126c7f0 { /* derived name */

    template <size_t N> Entry0126c7f0(const char (&string)[N], bool add = true) : name(string, add)
    {
    }

    Name name;    /* +0x0 */
    u32 unknown4; /* +0x4 */
};

extern const char D_15c9cfb[12];
extern const char D_15c9d74[14];
extern const char D_15c9d82[9];
extern const char D_15c9d8b[11];
extern const char D_15c9d96[11];
extern const char D_15c9da1[7];
extern const char D_15c9da8[6];
extern const char D_15c9dae[5];
extern const char D_15c9db3[11];
extern const char D_15c9dbe[11];
extern const char D_15c9dc9[5];
extern const char D_15c9dce[10];
extern const char D_15c9dd8[11];
extern const char D_15c9de3[11];
extern const char D_15c9dee[6];
extern const char D_15c9df4[4];
extern const char D_15c9df8[12];
extern const char D_15c9e04[10];
extern const char D_15c9e0e[18];
extern const char D_15c9e20[6];
extern const char D_15c9e26[12];
extern const char D_15c9e32[12];
extern const char D_15c9e3e[26];
extern const char D_15c9e58[16];
extern const char D_15c9e68[17];
extern const char D_15c9e79[17];
extern const char D_15c9e8a[17];
extern const char D_15c9e9b[16];
extern const char D_15c9eab[15];
extern const char D_15c9eba[15];
extern const char D_15c9ec9[15];
extern const char D_15c9ed8[6];
extern const char D_15c9ede[7];
extern const char D_15c9ee5[6];
extern const char D_15ca1f0[10];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad7e70(D_15cb5dd, false);
Name D_5ad7e74(D_15cb5e6, false);
Name D_5ad7d84;
Name D_5ad7cac(D_15c9d74, false);
Name D_5ad7ce0(D_15c9d82, false);
Name D_5ad7cd4(D_15c9d8b, false);
Name D_5ad7cd8(D_15c9d96, false);
Name D_5ad7cdc(D_15ca1f0, false);
Name D_5ad7d38(D_15c9da1, false);
Name D_5ad7ca4(D_15c9da8, false);
Name D_5ad7ca0(D_15c9dae, false);
Name D_5ad7ca8(D_15c9db3, false);
Name D_5ad7d3c(D_15c9dbe, false);
Name D_5ad7d40(D_15c9dc9, false);
Name D_5ad7d44(D_15c9dce, false);
Name D_5ad7d48(D_15c9dd8, false);
Name D_5ad7d4c(D_15c9de3, false);
Name D_5ad7d50(D_15c9dee, false);
Name D_5ad7d54(D_15c9df4, false);
Name D_5ad7e78(D_15c9df8, false);
Name D_5ad7d58(D_15c9e04, false);
Name D_5ad7d5c(D_15c9e0e, false);
Name D_5ad7d64(D_15c9e20, false);
Name D_5ad7d60(D_15c9e26, false);
Name D_5ad7e7c(D_15c9e32, false);
Name D_5ad7d34(D_15c9e3e, false);
Name D_5ad7d20(D_15c9e58, false);
Name D_5ad7d24(D_15c9e68, false);
Name D_5ad7d28(D_15c9e79, false);
Name D_5ad7d2c(D_15c9e8a, false);
Name D_5ad7d30(D_15c9e9b, false);
Name D_5ad7c9c(D_15c9eab, false);
Name D_5ad7e80(D_15c9eba, false);
Name D_5ad7e84(D_15c9ec9, false);
Name D_5ad7e88(D_15c9cfb, false);

static Entry0126c7f0 D_5ad7cc0[] = {D_15c9ed8, D_15c9ede, D_15c9ee5};

/* FUN_01480670 */
template void Array05943280<FadeEntry0126c7f0>::resize(unsigned);

/* derived name: this file's copy of FUN_013d4610 (func_00f6d1a0.cpp) */
void Object016d7840::slot2()
{
    state = 1;
    FadeTarget013d2490 *target = owner->target;
    for (int i = 0; i < target->count; ++i) {
        FadeEntry013d2490 &entry = entries.at(i);
        reinterpret_cast<Vector4 &>(entry.unknown50) =
            model->skeleton.poses[target->unknown28[i]].rotation;
        makeWPositive(entry.unknown50);
        setLanes(entry.unknown60, VECTOR_W);
    }
}

/* derived name: slot 2 of a vtable of this file (jointFrame, as FUN_013eb0a0
 * in func_01000ba0.cpp) */
JointFrame013eb0a0 FUN_01480ed0(void *self, const Joint013eb0a0 *joint) /* derived name */
{
    return jointFrame(joint);
}

/* derived name: slot 2 of a vtable of this file (jointFrame, as FUN_013eb0a0
 * in func_01000ba0.cpp) */
JointFrame013eb0a0 FUN_01481320(void *self, const Joint013eb0a0 *joint) /* derived name */
{
    return jointFrame(joint);
}

/* derived name: slot 2 of a vtable of this file (jointFrame, as FUN_013eb0a0
 * in func_01000ba0.cpp) */
JointFrame013eb0a0 FUN_01481470(void *self, const Joint013eb0a0 *joint) /* derived name */
{
    return jointFrame(joint);
}

/* derived name: a virtual method of this file (nodeFrame) */
JointFrame013eb0a0 FUN_01481020(const Placed013eb210 *self) /* derived name */
{
    return nodeFrame(self);
}

/* Slot 2 of Object016d7510: the subject's target's position and the node's
 * rotation, or zero and this file's VECTOR_W without a target */
JointFrame013eb0a0 Object016d7510::slot2(const Subject01480e70 *subject)
{
    if (subject->target) {
        JointFrame013eb0a0 frame;
        frame.position = subject->target->position;
        frame.rotation = node.get()->unknown140;
        return frame;
    }
    return JointFrame013eb0a0::identity();
}

/* derived name: this file's copy of FUN_013d2570 (func_00f509e0.cpp) */
void Object016d7840::slot6()
{
    if (state != 0 && unknown6c != 0 && FUN_01481a90() != 0) {
        FadeTarget013d2490 *target = owner->target;
        for (int i = 0; i < target->count; ++i)
            takePose(target->entries[i].unknown70, model, target->unknown28[i]);
    }
}

/* derived name: the class whose vtable is at 0x16d7888 (config/vtables.derived.base.txt),
 * whose slot 1 calls FUN_01482a60 */
class Object016d7888 : public FadeRig013d1440 /* derived name */
{
  public:
    Object016d7888(FadeModel013d4610 *model, FadeTarget013d2490 *target);
    FadeElement016d7b30 *findElement(const int *id);
    void slot1(void *argument);
    ~Object016d7888();

    int unknown48; /* +0x48: zero from the constructor, after the vptr */
};

/* FUN_0147f600: each of the target's entries takes the length of its pose's
 * position, then the target's index of its bone's parent (the count for a
 * root, -1 for a parent the target lacks) */
Object016d7888::Object016d7888(FadeModel013d4610 *model, FadeTarget013d2490 *target)
    : FadeRig013d1440(model, target), unknown48(0)
{
    const int count = target->count;
    for (int i = 0; i < count; ++i) {
        const Vec4 &position = this->model->pose(target->unknown28[i]).position.v;
        const float x = lane(position, 0);
        const float y = lane(position, 1);
        const float z = lane(position, 2);
        this->target->entries[i].length = sqrtf(x * x + y * y + z * z);
    }
    for (int i = 0; i < count; ++i) {
        const int parent = this->model->skeleton.bone(target->unknown28[i])->parent;
        if (parent == -1) {
            this->target->entries[i].parent = count;
        } else {
            int index = -1;
            for (unsigned j = 0; j < target->indexCount; ++j) {
                if (target->unknown28[j] == parent) {
                    index = j;
                    break;
                }
            }
            this->target->entries[i].parent = index;
        }
    }
    unknown1c = 0;
}

/* FUN_01482c20 (the executable's base-object destructor, folded into the
 * complete one here; its complete one, a jump to it, is FUN_01482c10): each
 * element deleted and its slot cleared, then the array emptied, before the
 * base class's destructor releases its block */
Object016d7888::~Object016d7888()
{
    for (unsigned i = 0; i < elements.size(); ++i) {
        if (elements.at(i)) {
            delete elements.at(i);
            elements.at(i) = 0;
        }
    }
    elements.clear();
}

/* derived name: this file's copy of FUN_013d1440 (func_00f509e0.cpp) */
/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: cost 360 at the
 * link, over its threshold of 175: one signature changes no row) */
void FUN_01482a60(Object016d7888 *self) /* derived name */
{
    FadeTarget013d2490 *target = self->target;
    for (int i = 0; i < target->count; ++i) {
        FadeTargetEntry013d2490 &entry = target->entries[i];
        FadeModel013d4610 *model = self->model;
        const int index = target->unknown28[i];
        FUN_013ce2d0(&model->skeleton, &entry.unknown50, index, model->skeleton.poses);
        FUN_013ce660(&model->skeleton, &entry.unknown60, index, model->skeleton.poses);
        takePose(entry.unknown70, self->model, target->unknown28[i]);
    }
}

/* FUN_0126c6f0: slot 2 of the class, with this file's axes */
// NONMATCHING: 17/60 at the base's 60 instructions: the same stores in order, the axes' halves
// in other registers (the base loads x into rax and rdx and y's second half after the clearing,
// here all four halves before it)
Axes01000aa0 Object01481650::slot2() const
{
    return Axes01000aa0::make();
}
