/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"
#include "tlg_types.h"
#include "tlg_game_object016d5140.h"

/* derived names: two slots of the class whose vtable is at 0x16c05d8
 * (Object00ff18f0, config/vtables.derived.base.txt), slots 64 (0xff5c30, its
 * pointer at 0x16c07e8) and 69 (0xff5d30, at 0x16c0810), the conditions of
 * leaf_00ff5e60.cpp's two over the object's fade at +0x10. Each takes the
 * rotation of the fade's first target entry (computed with its position on
 * first use, the entry's int at +0x90 set), looks the vector at +0x30 of its
 * second argument up through FUN_0134b990 in the field at +0x10 of its
 * fourth, and tests the found vector against the rotation: 0xff5c30 the x
 * FUN_0135b050 gives for the two, at most 0.5; 0xff5d30 its dot product with
 * the rotation's axis (FUN_01353470), not below -0.5. The third argument is
 * not read; the types are not traced. */
struct Source00ff5c30 { /* derived name */
    u8 unknown0[0x30];
    Float4 unknown30; /* +0x30 */
};

struct Target00ff5c30 { /* derived name */
    u8 unknown0[0x10];
    u8 unknown10; /* type not traced; its address is passed */
};

/* the object (Object00ff18f0) as these slots read it; its fade's class is
 * taken as this stretch's (0xff6950, beside these slots, is Object016d5140's
 * destructor), not proven */
struct Object00ff5c30 { /* derived name */
    u8 unknown0[0x10];
    Object016d5140 *fade; /* +0x10 */
};

const Float4 *FUN_0134b990(void *field, const Float4A *point);             /* derived name */
const Float4 *FUN_0135b050(const Float4A *rotation, const Float4A *point); /* derived name */
void FUN_01353470(Float4Data &axis,
                  const Float4A &rotation); /* derived name: the rotation's axis */

/* derived name: the fade's first target entry, its position and rotation
 * computed from the model's pose on first use. The skeleton is named before
 * the index is read, as joint() in func_00fba4b0.cpp and the model in the
 * other units' lazy poses: the index, defined later, is the heavier range and
 * keeps r13d across the pose calls, the skeleton's address spilled. */
static inline FadeTargetEntry013d2490 &rootEntry(Object016d5140 *fade)
{
    FadeTarget013d2490 *target = fade->owner->target;
    FadeTargetEntry013d2490 &entry = target->entries[0];
    if (!entry.unknown90) {
        FadeSkeleton013ce2d0 &skeleton = fade->model->skeleton;
        const int index = target->unknown28[0];
        FUN_013ce2d0(&skeleton, &entry.unknown50, index, skeleton.poses);
        FUN_013ce660(&skeleton, &entry.unknown60, index, skeleton.poses);
        entry.unknown90 = 1;
    }
    return entry;
}

/* derived name: the rotation of the fade's first target entry */
static inline const Float4A &rootRotation(Object016d5140 *fade)
{
    return reinterpret_cast<const Float4A &>(rootEntry(fade).unknown60);
}

/* derived name: the position and the rotation of the fade's first target
 * entry, the two vectors from +0x50 */
static inline const Float4A *rootPose(Object016d5140 *fade)
{
    return reinterpret_cast<const Float4A *>(&rootEntry(fade).unknown50);
}

/* derived name: the target's vector for a position, looked up through
 * FUN_0134b990 from an aligned copy of the position */
static inline const Float4 &lookup(Target00ff5c30 *target, const Float4 &position)
{
    Float4A point(position.x, position.y, position.z, position.w);
    return *FUN_0134b990(&target->unknown10, &point);
}

int FUN_00ff5c30(Object00ff5c30 *self, const Source00ff5c30 *source, void *,
                 Target00ff5c30 *target) /* derived name */
{
    const Float4A &rotation = rootRotation(self->fade);
    const Float4 &found = lookup(target, source->unknown30);
    Float4A point(found.x, found.y, found.z, found.w);
    return FUN_0135b050(&rotation, &point)->x <= 0.5f;
}

// NONMATCHING: one sum (69/75; the registers the base's since rootEntry names the skeleton
// first, round 555C): the dot product is
// (y + x) + z in the link's IR, kept so by the base and rewritten (x + z) + y here by the machine
// combiner (its root's only use the compare with the folded constant, cookbook 3265). The
// rotation read through the pose's second vector is the base's: an address formed apart from the
// slow path's `&entry.unknown60` (not merged by GVN's PRE into the cached arm). Round 558C: the
// link's IR with the three products before both sums, or the first sum after the third product,
// keeps the rewrite (the base also folds the compare's constant)
int FUN_00ff5d30(Object00ff5c30 *self, const Source00ff5c30 *source, void *,
                 Target00ff5c30 *target) /* derived name */
{
    const Float4A *pose = rootPose(self->fade);
    const Float4 found = lookup(target, source->unknown30);
    Float4Data axis;
    FUN_01353470(axis, pose[1]);
    return axis.x * found.x + axis.y * found.y + axis.z * found.z >= -0.5f;
}
