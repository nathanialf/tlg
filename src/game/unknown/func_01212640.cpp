/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_fade013d2490.h"
#include "tlg_game_name.h"
#include "tlg_game_object01367090.h"
#include "tlg_game_rotation.h"
#include "tlg_game_vector.h"

/* derived names: FUN_01212640 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 13 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15c91d2[10];
extern const char D_15c91dc[10];
extern const char D_15c91e6[20];
extern const char D_15c91fa[19];
extern const char D_15c920d[18];
extern const char D_15c921f[20];
extern const char D_15c9233[19];
extern const char D_15c9246[18];
extern const char D_15c9258[24];
extern const char D_15c9270[23];
extern const char D_15c9287[25];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad7720(D_15cb5dd, false);
Name D_5ad7724(D_15cb5e6, false);
Name D_5ad7610(D_15c91d2, false);
Name D_5ad7614(D_15c91dc, false);
Name D_5ad7728(D_15c91e6, false);
Name D_5ad772c(D_15c91fa, false);
Name D_5ad7730(D_15c920d, false);
Name D_5ad7734(D_15c921f, false);
Name D_5ad7738(D_15c9233, false);
Name D_5ad773c(D_15c9246, false);
Name D_5ad7630(D_15c9258, false);
Name D_5ad7634(D_15c9270, false);
Name D_5ad7650(D_15c9287, false);

/* derived name: this file's fade entry (tlg_game_fade013d2490.h): one
 * element type per file, as the base holds one resize of them per file */
struct FadeEntry01212640 : FadeEntry013d2490 { /* derived name */
};

/* FUN_01478060 */
template void Array05943280<FadeEntry01212640>::resize(unsigned);

/* derived name: this file's copy of FUN_013d4610 (func_00f6d1a0.cpp) */
void FUN_01475f20(Fade013d2490 *self) /* derived name */
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

/* derived name: this file's copy of FUN_013d0470 (func_00f509e0.cpp) */
int FUN_014763d0(Fade013d2490 *self); /* derived name */

/* derived name: this file's copy of FUN_013d2570 (func_00f509e0.cpp) */
void FUN_01477d70(Fade013d2490 *self) /* derived name */
{
    if (self->state != 0 && self->unknown6c != 0 && FUN_014763d0(self) != 0) {
        FadeTarget013d2490 *target = self->owner->target;
        for (int i = 0; i < target->count; ++i)
            takePose(target->entries[i].unknown70, self->model, target->unknown28[i]);
    }
}

/* derived name: the class whose vtable is at 0x16d6930 (config/vtables.derived.base.txt),
 * whose slot 1 calls FUN_014773a0 */
class Object016d6930 : public FadeRig013d1440 /* derived name */
{
  public:
    Object016d6930(FadeModel013d4610 *model, FadeTarget013d2490 *target);
    FadeElement016d7b30 *findElement(const int *id);
    void slot1(void *argument);
    ~Object016d6930();

    int unknown48; /* +0x48: zero from the constructor, after the vptr */
};

/* FUN_01475840: each of the target's entries takes the length of its pose's
 * position, then the target's index of its bone's parent (the count for a
 * root, -1 for a parent the target lacks) */
Object016d6930::Object016d6930(FadeModel013d4610 *model, FadeTarget013d2490 *target)
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

/* FUN_01477560 (the executable's base-object destructor, folded into the
 * complete one here; its complete one, a jump to it, is FUN_01477550): each
 * element deleted and its slot cleared, then the array emptied, before the
 * base class's destructor releases its block */
Object016d6930::~Object016d6930()
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
void FUN_014773a0(Object016d6930 *self) /* derived name */
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

/* derived names: the object whose vtable is at 0x16c1dc8: an array of
 * reference pairs at +0x1a0; its class is not traced */
struct Object016c1dc8 { /* derived name */
    u8 unknown0[0x1a0];
    Array05943280<Object01367090> unknown1a0; /* +0x1a0 */
};

/* derived name: slot 5 of the vtable at 0x16c1dc8: the array emptied and its
 * block given back */
void FUN_01477f00(Object016c1dc8 *self) /* derived name */
{
    self->unknown1a0.clear();
}
