/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_fade013d2490.h"
#include "tlg_game_name.h"
#include "tlg_game_object01367090.h"
#include "tlg_game_rotation.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00f509e0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 19 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15c510e[15];
extern const char D_15c511d[20];
extern const char D_15c5131[20];
extern const char D_15c5145[20];
extern const char D_15c5159[26];
extern const char D_15c5173[24];
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

Name D_5ace890(D_15cb5dd, false);
Name D_5ace894(D_15cb5e6, false);
Name D_5ace740(D_15c91d2, false);
Name D_5ace744(D_15c91dc, false);
Name D_5ace7a0(D_15c510e, false);
Name D_5ace79c(D_15c511d, false);
Name D_5ace898(D_15c5131, false);
Name D_5ace794(D_15c5145, false);
Name D_5ace798(D_15c5159, false);
Name D_5ace790(D_15c5173, false);
Name D_5ace89c(D_15c91e6, false);
Name D_5ace8a0(D_15c91fa, false);
Name D_5ace8a4(D_15c920d, false);
Name D_5ace8a8(D_15c921f, false);
Name D_5ace8ac(D_15c9233, false);
Name D_5ace8b0(D_15c9246, false);
Name D_5ace7c0(D_15c9258, false);
Name D_5ace7c4(D_15c9270, false);
Name D_5ace7c8(D_15c9287, false);

/* derived name: this file's fade entry. The base holds one resize of an
 * array of fade entries per file (FUN_013d28a0 and its eleven copies, in the
 * linkonce stretch), each building its elements from its own file's VECTOR_W:
 * one element type per file. */
struct FadeEntry00f509e0 : FadeEntry013d2490 { /* derived name */
};

/* FUN_013d28a0 */
template void Array05943280<FadeEntry00f509e0>::resize(unsigned);

/* derived name: this file's copy of FUN_013d4610 (func_00f6d1a0.cpp) */
void FUN_013cf950(Fade013d2490 *self) /* derived name */
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

/* derived name: this file's copy of the fade's large update (0xfcc bytes;
 * nonzero when it has run) */
int FUN_013d0470(Fade013d2490 *self); /* derived name */

/* derived name: while the fade runs, its int at +0x6c is set and its update
 * has run, each of its target's entries takes the model's pose for it */
void FUN_013d2570(Fade013d2490 *self) /* derived name */
{
    if (self->state != 0 && self->unknown6c != 0 && FUN_013d0470(self) != 0) {
        FadeTarget013d2490 *target = self->owner->target;
        for (int i = 0; i < target->count; ++i)
            takePose(target->entries[i].unknown70, self->model, target->unknown28[i]);
    }
}

/* derived name: the class whose vtable is at 0x16d3978 (config/vtables.derived.base.txt),
 * whose slot 1 (FUN_013d0450) calls FUN_013d1440 */
class Object016d3978 : public FadeRig013d1440 /* derived name */
{
  public:
    Object016d3978(FadeModel013d4610 *model, FadeTarget013d2490 *target);
    FadeElement016d7b30 *findElement(const int *id);
    void slot1(void *argument);
    ~Object016d3978();

    int unknown48; /* +0x48: zero from the constructor, after the vptr */
};

/* FUN_013ce050: each of the target's entries takes the length of its pose's
 * position, then the target's index of its bone's parent (the count for a
 * root, -1 for a parent the target lacks) */
Object016d3978::Object016d3978(FadeModel013d4610 *model, FadeTarget013d2490 *target)
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

/* FUN_013d1600 (the executable's base-object destructor, folded into the
 * complete one here; its complete one, a jump to it, is FUN_013d15f0): each
 * element deleted and its slot cleared, then the array emptied, before the
 * base class's destructor releases its block */
Object016d3978::~Object016d3978()
{
    for (unsigned i = 0; i < elements.size(); ++i) {
        if (elements.at(i)) {
            delete elements.at(i);
            elements.at(i) = 0;
        }
    }
    elements.clear();
}

/* derived name: each of the target's entries gets its pose's position and
 * rotation computed from the skeleton, then takes the pose itself */
void FUN_013d1440(Object016d3978 *self) /* derived name */
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

/* derived names: the object whose vtable is at 0x16befa8: an array of
 * reference pairs at +0x1a0; its class is not traced */
struct Object016befa8 { /* derived name */
    u8 unknown0[0x1a0];
    Array05943280<Object01367090> unknown1a0; /* +0x1a0 */
};

/* derived name: slot 5 of the vtable at 0x16befa8: the array emptied and its
 * block given back */
void FUN_013d2700(Object016befa8 *self) /* derived name */
{
    self->unknown1a0.clear();
}

/* derived names: one bone's marks (64 bytes): the byte the marks are or'ed
 * into, through the pointer at +0x30 */
struct BoneMark013d0160 { /* derived name */
    u8 unknown0[0x30];
    u8 *bits; /* +0x30 */
    u8 unknown38[0x8];
};

/* derived names: the marks of a skeleton's bones (the callers pass the one
 * at +0x160 of theirs): the skeleton's data at +0x0, the marks at +0x10 */
struct BoneMarks013d0160 {          /* derived name */
    FadeSkeletonData013ce050 *data; /* +0x0 */
    u8 unknown8[0x8];
    BoneMark013d0160 *marks; /* +0x10 */
};

/* derived name: the bone's bits or'ed into its mark, then 7 into every
 * bone below it, child by child (127 calls) */
void FUN_013d0160(BoneMarks013d0160 *self, int index, u8 bits) /* derived name */
{
    *self->marks[index].bits |= bits;
    FadeSkeletonData013ce050 *data = self->data;
    for (s16 child = data->bones[index]->firstChild; child != -1;
         child = data->bones[child]->nextSibling)
        FUN_013d0160(self, child, 7);
}
