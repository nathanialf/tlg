/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_fade013d2490.h"
#include "tlg_game_joint013eb0a0.h"
#include "tlg_game_name.h"
#include "tlg_game_rotation.h"
#include "tlg_game_vector.h"

/* derived names: FUN_0126c7f0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt) that the fade entries' resize reads. Among its
 * objects are 1 list of names built from strings, each destroyed by the array
 * destructor the compiler writes for it (0x1270590, registered with
 * __cxa_atexit in that order). Only the lists are written. */

/* an entry of 8 bytes, the name first: the initializer stores the name
 * only, and the destructor releases the name only (the second word not
 * traced) */
struct Entry0126c7f0 { /* derived name */

    Entry0126c7f0(const Name &name) : name(name) {}

    Name name;    /* +0x0 */
    u32 unknown4; /* +0x4 */
};

extern const char D_15c9ed8[6];
extern const char D_15c9ede[7];
extern const char D_15c9ee5[6];

// NONMATCHING: the file's initializer (FUN_0126c7f0): only the lists are
// written; its other objects are not.
static Entry0126c7f0 D_5ad7cc0[] = {Name(D_15c9ed8), Name(D_15c9ede), Name(D_15c9ee5)};

/* derived name: this file's fade entry (tlg_game_fade013d2490.h): one
 * element type per file, as the base holds one resize of them per file */
struct FadeEntry0126c7f0 : FadeEntry013d2490 { /* derived name */
};

/* FUN_01480670 */
template void Array05943280<FadeEntry0126c7f0>::resize(unsigned);

/* derived name: this file's copy of FUN_013d4610 (func_00f6d1a0.cpp) */
void FUN_01480760(Fade013d2490 *self) /* derived name */
{
    self->state = 1;
    FadeTarget013d2490 *target = self->owner->target;
    for (int i = 0; i < target->count; ++i) {
        FadeEntry013d2490 &entry = self->entries[i];
        reinterpret_cast<Vector4 &>(entry.unknown50) =
            self->model->skeleton.poses[target->unknown28[i]].rotation;
        makeWPositive(entry.unknown50);
        setLanes(entry.unknown60, VECTOR_W);
    }
}

/* derived name: a virtual method of this file (nodeFrame) */
JointFrame013eb0a0 FUN_01481020(const Placed013eb210 *self) /* derived name */
{
    return nodeFrame(self);
}

/* derived name: this file's copy of FUN_013d0470 (func_00f509e0.cpp) */
int FUN_01481a90(Fade013d2490 *self); /* derived name */

/* derived name: this file's copy of FUN_013d2570 (func_00f509e0.cpp) */
void FUN_01482e50(Fade013d2490 *self) /* derived name */
{
    if (self->state != 0 && self->unknown6c != 0 && FUN_01481a90(self) != 0) {
        FadeTarget013d2490 *target = self->owner->target;
        for (int i = 0; i < target->count; ++i)
            takePose(target->entries[i].unknown70, self->model, target->unknown28[i]);
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
