/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_fade013d2490.h"
#include "tlg_game_name.h"
#include "tlg_game_rotation.h"
#include "tlg_game_vector.h"
#include "tlg_game_array01343a80.h"

/* derived names: FUN_01249ca0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 5 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15c99df[38];
extern const char D_15c9a05[17];
extern const char D_15c9a16[39];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad7ae0(D_15cb5dd, false);
Name D_5ad7ae4(D_15cb5e6, false);
Name D_5ad79ac(D_15c99df, false);
Name D_5ad7ae8(D_15c9a05, false);
Name D_5ad79f0(D_15c9a16, false);

/* derived name: this file's fade entry (tlg_game_fade013d2490.h): one
 * element type per file, as the base holds one resize of them per file */
struct FadeEntry01249ca0 : FadeEntry013d2490 { /* derived name */
};

/* FUN_0147db50 */
template void Array05943280<FadeEntry01249ca0>::resize(unsigned);

/* derived name: this file's copy of FUN_013d4610 (func_00f6d1a0.cpp) */
void FUN_0147bac0(Fade013d2490 *self) /* derived name */
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
int FUN_0147bc50(Fade013d2490 *self); /* derived name */

/* derived name: this file's copy of FUN_013d2570 (func_00f509e0.cpp) */
void FUN_0147d010(Fade013d2490 *self) /* derived name */
{
    if (self->state != 0 && self->unknown6c != 0 && FUN_0147bc50(self) != 0) {
        FadeTarget013d2490 *target = self->owner->target;
        for (int i = 0; i < target->count; ++i)
            takePose(target->entries[i].unknown70, self->model, target->unknown28[i]);
    }
}

/* derived name: the class whose vtable is at 0x16d6de0 (config/vtables.derived.base.txt),
 * whose slot 1 calls FUN_0147cc20 */
class Object016d6de0 : public FadeRig013d1440 /* derived name */
{
  public:
    FadeElement016d7b30 *findElement(const int *id);
    void slot1(void *argument);
    ~Object016d6de0();

    int unknown48; /* +0x48: zero from the constructor, after the vptr (inlined into FUN_0122be10 here) */
};

/* FUN_0147cde0 (the executable's base-object destructor, folded into the
 * complete one here; its complete one, a jump to it, is FUN_0147cdd0): each
 * element deleted and its slot cleared, then the array emptied, before the
 * base class's destructor releases its block */
Object016d6de0::~Object016d6de0()
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
void FUN_0147cc20(Object016d6de0 *self) /* derived name */
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

/* derived names: this file's 32-byte tree node, as TreeNode013dfc20
 * (func_00fba4b0.cpp): its children an array of nodes at +0x8 (the callers
 * at 0x123da38 and on build one on the stack and destroy it). Its int at
 * +0x0 is not traced. */
class TreeNode0147ba30 /* derived name */
{
  public:
    ~TreeNode0147ba30();

  private:
    int unknown0;                             /* +0x0: copied with the node */
    Array01343a80<TreeNode0147ba30> children; /* +0x8 */
};

/* FUN_0147ba30: each child destroyed first to last, then the children's block
 * released */
TreeNode0147ba30::~TreeNode0147ba30() {}

// NONMATCHING: the node's copy constructor (FUN_0147ef10 in the base, the
// children's copy inlined into it and a call to itself per child) is inlined
// here and calls the children's copy: in stage 1 the inliner takes the call
// sites of the SCC {node copy, array copy} in the order its DFS pops them (a
// reading of Inliner.cpp, not compiled), and the base's order needs the SCC
// entered through the array's copy (a caller of it in this unit, not written
// yet)
/* FUN_0147b970: a copy of a node appended to a node array, its index returned */
template unsigned Array05943280<TreeNode0147ba30>::add(const TreeNode0147ba30 &);
