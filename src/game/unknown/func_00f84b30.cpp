/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_fade013d2490.h"
#include "tlg_game_object016d3d88.h"
#include "tlg_game_name.h"
#include "tlg_game_rotation.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00f84b30 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 5 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15c5687[10];
extern const char D_15c5691[17];
extern const char D_15c56a2[22];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5aceda0(D_15cb5dd, false);
Name D_5aceda4(D_15cb5e6, false);
Name D_5acecb4(D_15c5687, false);
Name D_5acecb0(D_15c5691, false);
Name D_5acec50(D_15c56a2, false);

/* FUN_013d92a0 */
template void Array05943280<FadeEntry00f84b30>::resize(unsigned);

/* derived name: this file's copy of FUN_013d4610 (func_00f6d1a0.cpp) */
void Object016d3d88::slot2()
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

/* derived name: this file's copy of FUN_013d2570 (func_00f509e0.cpp) */
void Object016d3d88::slot6()
{
    if (state != 0 && unknown6c != 0 && FUN_013d7580() != 0) {
        FadeTarget013d2490 *target = owner->target;
        for (int i = 0; i < target->count; ++i)
            takePose(target->entries[i].unknown70, model, target->unknown28[i]);
    }
}

/* derived name: the class whose vtable is at 0x16d3e30 (config/vtables.derived.base.txt),
 * whose slot 1 calls FUN_013d8550 */
class Object016d3e30 : public FadeRig013d1440 /* derived name */
{
  public:
    Object016d3e30(FadeModel013d4610 *model, FadeTarget013d2490 *target);
    FadeElement016d7b30 *findElement(const int *id);
    void slot1(void *argument);
    ~Object016d3e30();

    int unknown48; /* +0x48: zero from the constructor, after the vptr */
};

/* FUN_013d6d50: each of the target's entries takes the length of its pose's
 * position, then the target's index of its bone's parent (the count for a
 * root, -1 for a parent the target lacks) */
Object016d3e30::Object016d3e30(FadeModel013d4610 *model, FadeTarget013d2490 *target)
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

/* FUN_013d8710 (the executable's base-object destructor, folded into the
 * complete one here; its complete one, a jump to it, is FUN_013d8700): each
 * element deleted and its slot cleared, then the array emptied, before the
 * base class's destructor releases its block */
Object016d3e30::~Object016d3e30()
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
void FUN_013d8550(Object016d3e30 *self) /* derived name */
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
