/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_fade013d2490.h"
#include "tlg_game_name.h"
#include "tlg_game_rotation.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00fba4b0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 5 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15c59b7[30];
extern const char D_15c9a05[17];
extern const char D_15c9a16[39];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5acf110(D_15cb5dd, false);
Name D_5acf114(D_15cb5e6, false);
Name D_5acefdc(D_15c59b7, false);
Name D_5acf118(D_15c9a05, false);
Name D_5acf020(D_15c9a16, false);

/* derived name: this file's fade entry (tlg_game_fade013d2490.h): one
 * element type per file, as the base holds one resize of them per file */
struct FadeEntry00fba4b0 : FadeEntry013d2490 { /* derived name */
};

/* FUN_013e2700 */
template void Array05943280<FadeEntry00fba4b0>::resize(unsigned);

/* derived name: this file's copy of FUN_013d4610 (func_00f6d1a0.cpp) */
void FUN_013dfda0(Fade013d2490 *self) /* derived name */
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
int FUN_013e0310(Fade013d2490 *self); /* derived name */

/* derived name: this file's copy of FUN_013d2570 (func_00f509e0.cpp) */
void FUN_013e16d0(Fade013d2490 *self) /* derived name */
{
    if (self->state != 0 && self->unknown6c != 0 && FUN_013e0310(self) != 0) {
        FadeTarget013d2490 *target = self->owner->target;
        for (int i = 0; i < target->count; ++i)
            takePose(target->entries[i].unknown70, self->model, target->unknown28[i]);
    }
}

/* derived name: the class whose vtable is at 0x16d4318 (config/vtables.derived.base.txt),
 * whose slot 1 calls FUN_013e12e0 */
class Object016d4318 : public FadeRig013d1440 /* derived name */
{
  public:
    FadeElement016d7b30 *findElement(const int *id);
    void slot1(void *argument);
    ~Object016d4318();

    int unknown48; /* +0x48: zero from the constructor, after the vptr (inlined into FUN_00f9ab50 here) */
};

/* FUN_013e14a0 (the executable's base-object destructor, folded into the
 * complete one here; its complete one, a jump to it, is FUN_013e1490): each
 * element deleted and its slot cleared, then the array emptied, before the
 * base class's destructor releases its block */
Object016d4318::~Object016d4318()
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
void FUN_013e12e0(Object016d4318 *self) /* derived name */
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
