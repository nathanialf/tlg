/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_fade013d2490.h"
#include "tlg_game_object016d6b08.h"
#include "tlg_game_name.h"
#include "tlg_game_rotation.h"
#include "tlg_game_vector.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_record00fbd1d0.h"
#include "tlg_math.h"

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

/* FUN_0147db50 */
template void Array05943280<FadeEntry01249ca0>::resize(unsigned);

/* derived name: this file's copy of FUN_013d4610 (func_00f6d1a0.cpp) */
void Object016d6b08::slot2()
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
void Object016d6b08::slot6()
{
    if (state != 0 && unknown6c != 0 && FUN_0147bc50() != 0) {
        FadeTarget013d2490 *target = owner->target;
        for (int i = 0; i < target->count; ++i)
            takePose(target->entries[i].unknown70, model, target->unknown28[i]);
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
/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: cost 360 at the
 * link, over its threshold of 175: one signature changes no row) */
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
 * (func_00fba4b0.cpp): the index of its joint in the fade's target and its
 * children, an array of nodes at +0x8 */
class TreeNode0147ba30 /* derived name */
{
  public:
    TreeNode0147ba30() : index(0) {}

    ~TreeNode0147ba30();

    int index;                                /* +0x0: copied with the node */
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
/* derived name: rotated by the inverse of the rotation, in place (its
 * definition is not written; leaf_00ff5c30.cpp declares it the same way) */
const Float4 *FUN_0135b050(const Float4A *rotation, const Float4A *point); /* derived name */

/* derived names: the fade's target entry of a joint, its position (+0x50)
 * and rotation (+0x60) computed from the model's pose on first use, the
 * entry's int at +0x90 set */
static inline FadeTargetEntry013d2490 &joint(Object016d6b08 *fade, const int &i) /* derived name */
{
    FadeTarget013d2490 *target = fade->owner->target;
    FadeTargetEntry013d2490 &entry = target->entries[i];
    if (!entry.unknown90) {
        FadeSkeleton013ce2d0 &skeleton = fade->model->skeleton;
        const int index = target->unknown28[i];
        FUN_013ce2d0(&skeleton, &entry.unknown50, index, skeleton.poses);
        FUN_013ce660(&skeleton, &entry.unknown60, index, skeleton.poses);
        entry.unknown90 = 1;
    }
    return entry;
}

/* derived name: the point less the origin, the point's w kept: the point
 * copied, then its x, y and z set to the differences */
static inline Float4A offset(const Vec4 &point, const Vec4 &origin) /* derived name */
{
    Float4A result(lane(point, 0), lane(point, 1), lane(point, 2), lane(point, 3));
    const float x = lane(point, 0) - lane(origin, 0);
    const float y = lane(point, 1) - lane(origin, 1);
    const float z = lane(point, 2) - lane(origin, 2);
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}

/* derived name: the point turned by the inverse of the rotation */
static inline Float4A inverseRotated(Float4A point, const Vec4 &rotation) /* derived name */
{
    FUN_0135b050(&reinterpret_cast<const Float4A &>(rotation), &point);
    return point;
}

/* derived name: a joint's position from the root joint's, in the root's frame */
static inline Float4A fromRoot(Object016d6b08 *fade, const FadeTargetEntry013d2490 &root,
                               const int &i) /* derived name */
{
    return inverseRotated(offset(joint(fade, i).unknown50, root.unknown50), root.unknown60);
}

/* derived names: the bones of the tree under node as segments from their
 * parent's joint to their own, in the root joint's frame, appended in tree
 * order. The fade is this unit's fading state (model at +0x8, owner at
 * +0x10 whose +0x40 is the target), taken as Object016d6b08. The append is
 * out of line only while it has two callers (this one and FUN_00faab20, its
 * copy in func_00fba4b0.cpp: cost 250 at stage 1, 175 at the link). */
/* joint() names the skeleton before it reads the index (the index, defined later, is the heavier
 * range and keeps r13d; &skeleton is spilled), and takes the index by reference (the node's index
 * is read after the fade's target) */
void FUN_0123d660(Object016d6b08 *fade, Array01343a80<Record00fbd1d0> &segments,
                  const TreeNode0147ba30 &node, const TreeNode0147ba30 &parent) /* derived name */
{
    const FadeTargetEntry013d2490 &root = joint(fade, 0);
    const Float4A from = fromRoot(fade, root, parent.index);
    const Float4A to = fromRoot(fade, root, node.index);
    segments.push(Record00fbd1d0(from, to));
    for (unsigned i = 0; i < node.children.size(); ++i)
        FUN_0123d660(fade, segments, node.children.at(i), node);
}
