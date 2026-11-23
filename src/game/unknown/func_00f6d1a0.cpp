/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_fade013d2490.h"
#include "tlg_game_object016d3ad0.h"
#include "tlg_game_name.h"
#include "tlg_game_rotation.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00f6d1a0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 6 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15c541c[25];
extern const char D_15c91d2[10];
extern const char D_15c91dc[10];
extern const char D_15c9538[11];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5acea90(D_15cb5dd, false);
Name D_5acea94(D_15cb5e6, false);
Name D_5ace904(D_15c9538, false);
Name D_5ace908(D_15c91dc, false);
Name D_5ace90c(D_15c91d2, false);
Name D_5ace900(D_15c541c, false);

/* FUN_013d4760 */
template void Array05943280<FadeEntry00f6d1a0>::resize(unsigned);

/* derived name: the fade's entries take their target's rotations (the
 * model's pose for each, +0x10 of a 0x40-byte pose), turned to w not
 * negative, and VECTOR_W at +0x60 */
void Object016d3ad0::slot2()
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
void Object016d3ad0::slot6()
{
    if (state != 0 && unknown6c != 0 && FUN_013d4aa0() != 0) {
        FadeTarget013d2490 *target = owner->target;
        for (int i = 0; i < target->count; ++i)
            takePose(target->entries[i].unknown70, model, target->unknown28[i]);
    }
}

/* derived name: the class whose vtable is at 0x16d3b18 (config/vtables.derived.base.txt),
 * whose slot 1 calls FUN_013d5a70 */
class Object016d3b18 : public FadeRig013d1440 /* derived name */
{
  public:
    FadeElement016d7b30 *findElement(const int *id);
    void slot1(void *argument);
    ~Object016d3b18();

    int unknown48; /* +0x48: zero from the constructor, after the vptr (inlined into FUN_00f59e00 here) */
};

/* FUN_013d5c30 (the executable's base-object destructor, folded into the
 * complete one here; its complete one, a jump to it, is FUN_013d5c20): each
 * element deleted and its slot cleared, then the array emptied, before the
 * base class's destructor releases its block */
Object016d3b18::~Object016d3b18()
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
void FUN_013d5a70(Object016d3b18 *self) /* derived name */
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
