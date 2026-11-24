/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_simd.h"

/* derived names: slot 1 of the vtables at 0x16d5850 and 0x16d5878 (their
 * pointers at 0x16d5868 and 0x16d5890; slot 0 FUN_0140b680), stored by
 * FUN_010b0530, FUN_010b1800, FUN_014068b0 and FUN_01406b30: copies the
 * 32-byte entries (two vectors each, the entry's assignment copying one
 * vector at a time) of the array at +0x48 to
 * the array at +0x30, as many as the unsigned int at +0x60 counts (an
 * unsigned counter, the arrays' accessor taking an int index: sign-extended
 * each pass; both pointers reloaded each pass). The arrays' other fields are
 * not traced. Class and method unknown. Slot 0 (FUN_0140b680) first sets
 * each entry at +0x48 from the pose of its index (the pose's +0x20, then its
 * rotation) and copies it to +0x30. */
struct Entry01408ad0 /* derived name */
{
    Vec4 unknown0;  /* +0x0 */
    Vec4 unknown10; /* +0x10 */

    Entry01408ad0 &operator=(const Entry01408ad0 &other)
    {
        unknown0 = other.unknown0;
        unknown10 = other.unknown10;
        return *this;
    }
};

template <class T>
struct Array01408ad0 /* derived name */
{
    T *data; /* derived name */

    T &operator[](int index) const
    {
        return data[index];
    }
};

/* derived names: a pose of the skeleton, 0x40 bytes: a rotation at +0x10
 * and a vector at +0x20 */
struct Pose0140b680 { /* derived name */
    u8 unknown0[0x10];
    Vec4 rotation;  /* +0x10 */
    Vec4 unknown20; /* +0x20 */
    u8 unknown30[0x10];
};

struct Skeleton0140b680 { /* derived name */
    u8 unknown0[0x250];
    Pose0140b680 *poses; /* +0x250 */
};

/* derived names: the model of the object's owner: its skeleton at +0x40,
 * read again for each pose (a vector stored may alias it) */
struct Model0140b680 { /* derived name */

    const Pose0140b680 &pose(int index) const /* derived name */
    {
        return skeleton->poses[index];
    }

    u8 unknown0[0x40];
    Skeleton0140b680 *skeleton; /* +0x40 */
};

struct Owner0140b680 { /* derived name */
    u8 unknown0[0x8];
    Model0140b680 *model; /* +0x8 */
};

struct Object01408ad0 /* derived name */
{
    u8 unknown0[0x10];
    Owner0140b680 *owner;       /* +0x10 */
    Array01408ad0<int> indices; /* +0x18: a pose index for each entry */
    u8 unknown20[0x10];
    Array01408ad0<Entry01408ad0> unknown30; /* +0x30 */
    u8 unknown38[0x10];
    Array01408ad0<Entry01408ad0> unknown48; /* +0x48 */
    u8 unknown50[0x10];
    unsigned unknown60; /* +0x60: the count */
};

// NONMATCHING: greedy's assignment: the same 17 instructions; the base keeps the
// source pointer, the destination and the offset in rsi, rdx and rcx, where this
// has rdx, rcx and rsi.
void FUN_01408ad0(Object01408ad0 *self) /* derived name */
{
    for (unsigned i = 0; i < self->unknown60; i++)
        self->unknown30[i] = self->unknown48[i];
}

/* derived name: slot 0 of the same vtables: each entry of the array at +0x48
 * takes the vector at +0x20 and the rotation of the pose of its index, then
 * is copied to the array at +0x30 */
// NONMATCHING: the head's load order: the same loads and stores, 135 bytes as
// the base's; the base loads the skeleton and its poses before the entry's pose
// index (`mov rsi, [rcx+0x40]; mov r10, [rsi+0x250]; movsxd rsi, [r8+rax*4]`),
// this the index first; the registers follow. With the index read before the
// poses pointer (the helper for both reads) the entry's offset `shl rdx, 5`
// also comes after the model's load.
// Round 560C, link-stage IR cut and compiled alone: the IR already reads the model, the skeleton
// and the poses before the index (the source's order); moving the index chain first (0.26), the
// entries' pointer after the poses (0.36) or both pointers first (0.39) is not the base: the
// selection DAG's order of independent loads, not the subscript's.
void FUN_0140b680(Object01408ad0 *self) /* derived name */
{
    for (unsigned i = 0; i < self->unknown60; i++) {
        Entry01408ad0 &entry = self->unknown48[i];
        const Model0140b680 *model = self->owner->model;
        const Pose0140b680 *poses = model->skeleton->poses;
        const int index = self->indices[i];
        entry.unknown10 = poses[index].unknown20;
        entry.unknown0 = model->pose(index).rotation;
        self->unknown30[i] = self->unknown48[i];
    }
}
