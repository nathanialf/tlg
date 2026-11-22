/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_fade013d2490.h"
#include "tlg_game_object016d5140.h"
#include "tlg_game_joint013eb0a0.h"
#include "tlg_game_name.h"
#include "tlg_game_rotation.h"
#include "tlg_game_vector.h"

/* derived names: FUN_01000ba0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt) that the fade entries' resize reads. Among its
 * objects are 1 list of names built from strings, each destroyed by the array
 * destructor the compiler writes for it (0x1005070, registered with
 * __cxa_atexit in that order). Only the lists are written. */

/* an entry of 8 bytes, the name first: the initializer stores the name
 * only, and the destructor releases the name only (the second word not
 * traced) */
struct Entry01000ba0 { /* derived name */

    Entry01000ba0(const Name &name) : name(name) {}

    Name name;    /* +0x0 */
    u32 unknown4; /* +0x4 */
};

extern const char D_15c9ed8[6];
extern const char D_15c9ede[7];
extern const char D_15c9ee5[6];

// NONMATCHING: the file's initializer (FUN_01000ba0): only the lists are
// written; its other objects are not.
static Entry01000ba0 D_5acf7a0[] = {Name(D_15c9ed8), Name(D_15c9ede), Name(D_15c9ee5)};

/* FUN_013ea7b0 */
template void Array05943280<FadeEntry01000ba0>::resize(unsigned);

/* derived name: this file's copy of FUN_013d4610 (func_00f6d1a0.cpp) */
void Object016d5140::slot2()
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

/* derived name: slot 2 of a vtable of this file (jointFrame; its copies
 * 0x13eb510, 0x13eb6f0 here and 0x1480ed0, 0x1481320, 0x1481470 in
 * func_0126c7f0.cpp wait on it) */
// NONMATCHING: every instruction but the registers: the base forms the
// negation's address (`lea r15, [rbp-0x40]`) before the call and holds it in
// a saved register (r12 pushed, `sub rsp, 0x30`); the build forms it after
// the call (75/79 by position)
JointFrame013eb0a0 FUN_013eb0a0(void *self, const Joint013eb0a0 *joint) /* derived name */
{
    return jointFrame(joint);
}

/* derived name: a virtual method of this file (nodeFrame) */
JointFrame013eb0a0 FUN_013eb210(const Placed013eb210 *self) /* derived name */
{
    return nodeFrame(self);
}

/* derived name: this file's copy of FUN_013d2570 (func_00f509e0.cpp) */
void Object016d5140::slot6()
{
    if (state != 0 && unknown6c != 0 && FUN_013ebd10() != 0) {
        FadeTarget013d2490 *target = owner->target;
        for (int i = 0; i < target->count; ++i)
            takePose(target->entries[i].unknown70, model, target->unknown28[i]);
    }
}

/* derived name: the class whose vtable is at 0x16d5188 (config/vtables.derived.base.txt),
 * whose slot 1 calls FUN_013ecce0 */
class Object016d5188 : public FadeRig013d1440 /* derived name */
{
  public:
    Object016d5188(FadeModel013d4610 *model, FadeTarget013d2490 *target);
    FadeElement016d7b30 *findElement(const int *id);
    void slot1(void *argument);
    ~Object016d5188();

    int unknown48; /* +0x48: zero from the constructor, after the vptr */
};

/* FUN_013e9310: each of the target's entries takes the length of its pose's
 * position, then the target's index of its bone's parent (the count for a
 * root, -1 for a parent the target lacks) */
Object016d5188::Object016d5188(FadeModel013d4610 *model, FadeTarget013d2490 *target)
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

/* FUN_013ecea0 (the executable's base-object destructor, folded into the
 * complete one here; its complete one, a jump to it, is FUN_013ece90): each
 * element deleted and its slot cleared, then the array emptied, before the
 * base class's destructor releases its block */
Object016d5188::~Object016d5188()
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
void FUN_013ecce0(Object016d5188 *self) /* derived name */
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
