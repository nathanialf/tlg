/* src/include/tlg_game_fade013d2490.h: the fading state ten classes of the
 * game region share (docs/TARGETS.md), read from the bytes of FUN_013d2490
 * and its nine copies. Every name here is derived. */
#ifndef TLG_GAME_FADE013D2490_H
#define TLG_GAME_FADE013D2490_H

#include "tlg_types.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_frame.h"
#include "tlg_game_vector.h"
#include "tlg_game_rotation.h"

/* derived names: an entry of the fader's own array at +0x18, 0x80 bytes,
 * whose int at +0x40 the update clears. Its constructor (inlined into each
 * unit's resize of an array of them, FUN_013d28a0 and its copies) stores
 * every field but the padding in member order: two frames, the int, two
 * copies of the unit's VECTOR_W and 1.0f at +0x70. */
struct FadeEntry013d2490 { /* derived name */

    FadeEntry013d2490()
        : unknown40(0), unknown50(VECTOR_W.v), unknown60(VECTOR_W.v), unknown70(1.0f)
    {
    }

    Frame016c1128 unknown0;  /* +0x0 */
    Frame016c1128 unknown20; /* +0x20 */
    int unknown40;           /* +0x40 */
    Vec4 unknown50;  /* +0x50: VECTOR_W from the constructor, a rotation from FUN_013d4610 */
    Vec4 unknown60;  /* +0x60: VECTOR_W from the constructor */
    float unknown70; /* +0x70: 1.0f from the constructor */
};

/* derived names: an entry of the target's array, 0xa0 bytes, whose int at
 * +0x90 the update clears; a vector at +0x20 (FUN_00f6c0c0 copies the 12th
 * entry's, FUN_00f6c190 the 16th's, `vmovaps`) */
struct FadeTargetEntry013d2490 { /* derived name */
    u8 unknown0[0x8];
    float length; /* +0x8: the length of its pose's position (the rigs' constructors) */
    int parent;   /* +0xc: the target's index of its bone's parent, the count for a root */
    u8 unknown10[0x10];
    Vec4 unknown20; /* +0x20: FUN_00f6c0c0 copies the 12th entry's, FUN_00f6c190 the 16th's */
    u8 unknown30[0x20];
    Vec4 unknown50;          /* +0x50: written by FUN_013ce2d0 (FUN_013d1440) */
    Vec4 unknown60;          /* +0x60: written by FUN_013ce660 (FUN_013d1440) */
    Frame016c1128 unknown70; /* +0x70: a pose, its rotation turned to w not negative (takePose) */
    int unknown90;           /* +0x90 */
    u8 unknown94[0xc];
};

struct FadeTarget013d2490 {           /* derived name */
    FadeTargetEntry013d2490 *entries; /* +0x0 */
    u8 unknown8[0x10];
    int count; /* +0x18: read again each pass (`movsxd rax, [r8+0x18]`) */
    u8 unknown1c[0xc];
    int *unknown28;      /* +0x28: per entry, the index of its pose (FUN_013d4610) */
    unsigned indexCount; /* +0x30: the indices' count, searched unsigned (FUN_013ce050) */
};

/* derived names: a pose of the model, 0x40 bytes, its rotation at +0x10
 * (FUN_013d4610 copies it into an entry as a whole object: a copy the lane
 * reads after it are not forwarded from, so they load it again) */
struct FadePose013d4610 { /* derived name */
    Vector4 position;     /* +0x0 */
    Vector4 rotation;     /* +0x10 */
    Vector4 unknown20;    /* +0x20: copied out whole by FUN_01404660 */
    u8 unknown30[0x10];
};

/* derived names: the model's skeleton at +0x40, whose poses FUN_013ce2d0
 * and FUN_013ce660 (each taking the skeleton, the vector to write, a pose
 * index and the poses) read; the int at +0x130 is not traced */
struct FadeBone013ce050 { /* derived name */
    u8 unknown0[0x27a];
    s16 parent;      /* +0x27a: the parent's pose index, -1 for a root */
    s16 firstChild;  /* +0x27c: the first child's pose index, -1 for none */
    s16 nextSibling; /* +0x27e: the next child of the parent, -1 after the last */
};

struct FadeSkeletonData013ce050 { /* derived name */
    u8 unknown0[0x238];
    FadeBone013ce050 **bones; /* +0x238: one per pose */
};

struct FadeSkeleton013ce2d0 { /* derived name */

    const FadeBone013ce050 *bone(int index) const /* derived name */
    {
        return data->bones[index];
    }

    FadeSkeletonData013ce050 *data; /* +0x0 (the rigs' constructors) */
    u8 unknown8[0xf8];
    FadePose013d4610 *poses; /* +0x100 (the model's +0x140) */
};

/* derived names: the object at +0x2f0 of the model: its second base, at
 * +0x190 (the call goes through that base's vtable, `add rdi, 0x190; call
 * [rax+8]`), answers by its slot 1 whether the fade is held; two lengths
 * (FUN_00f6b880, FUN_00f6b8e0). Its first base is not traced. */
class FadeSourceBase00f6b880 /* derived name */
{
  public:
    virtual ~FadeSourceBase00f6b880();

  private:
    u8 unknown8[0x188];
};

class FadeHold00f6b880 /* derived name */
{
  public:
    virtual void unknown0();
    virtual int unknown1();
};

class FadeSource00f6b880 : public FadeSourceBase00f6b880, public FadeHold00f6b880 /* derived name */
{
  public:
    u8 unknown198[0x388];
    float unknown520; /* +0x520 */
    u8 unknown524[0x34];
    float unknown558; /* +0x558 */
};

struct FadeModel013d4610 { /* derived name */

    /* the pose of an index, the model read before the index (FUN_013ce050:
     * `mov rcx, [r15+8]` before `mov rbx, [r14+0x28]`) */
    const FadePose013d4610 &pose(int index) const /* derived name */
    {
        return skeleton.poses[index];
    }

    u8 unknown0[0x40];
    FadeSkeleton013ce2d0 skeleton; /* +0x40 */
    u8 unknown148[0x2f0 - 0x40 - sizeof(FadeSkeleton013ce2d0)];
    FadeSource00f6b880 *source; /* +0x2f0 */
};

/* derived names: the position and rotation of a skeleton's pose, each
 * computed into a vector (FUN_013d1440 and its copies) */
void FUN_013ce2d0(FadeSkeleton013ce2d0 *skeleton, Vec4 *position, int index,
                  const FadePose013d4610 *poses); /* derived name */
void FUN_013ce660(FadeSkeleton013ce2d0 *skeleton, Vec4 *rotation, int index,
                  const FadePose013d4610 *poses); /* derived name */

struct FadeClock013d2490 { /* derived name */
    u8 unknown0[0x14];
    float step; /* +0x14: divided by the fade's length */
};

struct FadeOwner013d2490 { /* derived name */
    u8 unknown0[0x20];
    FadeClock013d2490 *clock; /* +0x20 */
    u8 unknown28[0x18];
    FadeTarget013d2490 *target; /* +0x40 */
};

/* derived names: the object of the ten classes: its state at +0x58 (1
 * fading in, 2 full, 3 fading out, 0 off) and level at +0x5c are stored as
 * one qword when a fade ends (`movabs rax, 0x3f80000000000002`) */
struct Fade013d2490 { /* derived name */
    u8 unknown0[0x8];
    FadeModel013d4610 *model;   /* +0x8 */
    FadeOwner013d2490 *owner;   /* +0x10 */
    FadeEntry013d2490 *entries; /* +0x18 */
    u8 unknown20[0x38];
    int state;   /* +0x58 */
    float level; /* +0x5c */
    u32 unknown60;
    float fadeIn;  /* +0x64: the fade-in's length */
    float fadeOut; /* +0x68: the fade-out's length */
    int unknown6c; /* +0x6c: cleared by the update */
};

/* derived name: a frame takes the model's pose of the index, position then
 * rotation (each read again from the skeleton's poses: a vector stored may
 * alias the pointer), the rotation turned to w not negative (FUN_013d2570,
 * FUN_013d1440, FUN_013fccf0 and their copies) */
inline void takePose(Frame016c1128 &frame, const FadeModel013d4610 *model,
                     int index) /* derived name */
{
    reinterpret_cast<Vector4 &>(frame.unknown0) = model->skeleton.poses[index].position;
    reinterpret_cast<Vector4 &>(frame.unknown10) = model->skeleton.poses[index].rotation;
    makeWPositive(frame.unknown10);
}

/* derived names: an element of the rig's array at +0x28: deleted through
 * its slot 1 (the deleting destructor) by the rig's destructor, found by the
 * int at +0x30 (FUN_013d4a40) */
class FadeElement016d7b30 /* derived name */
{
  public:
    virtual ~FadeElement016d7b30();

    u8 unknown8[0x28];
    int id; /* +0x30 */
};

/* derived names: the class whose vtable is at 0x16d7b30
 * (config/vtables.derived.base.txt names it), the base of the fifteen rigs.
 * The vtable has two slots, both the pure-virtual import (R_X86_64_64 at
 * 0x16d7b40 and 0x16d7b48): the two pure functions and no virtual destructor,
 * which the rigs declare (their slots 2 and 3, 0x13d15f0 and 0x13d1730 in
 * 0x16d3988). The link folded other classes' identical two-pure vtables into
 * it (the bases at +0x28 that 0x13974c0, 0x1397570, 0xb40050 and 0xb42e30
 * destroy: a counted reference at +0x8 of their own, another layout). Its
 * constructor is inlined into the rigs' (FUN_013ce050: the model at +0x8,
 * 0 at +0x10, 0.5f twice from +0x14, the ints from +0x1c and the array
 * cleared as one 28-byte zero, the array's lock word made free at +0x3c), its
 * destructor releases the array's block after its vptr store (FUN_013d1600).
 * The ints at +0x10 and +0x1c to +0x24 are not traced. */
class Object016d7b30 /* derived name */
{
  public:
    explicit Object016d7b30(FadeModel013d4610 *model)
        : model(model), unknown10(0), unknown14(0.5f), unknown18(0.5f), unknown1c(0), unknown20(0),
          unknown24(0)
    {
    }

    /* the rigs' slot 0 (FUN_013d4a40, one body in every vtable): the element
     * whose id is the one pointed at, or null */
    virtual FadeElement016d7b30 *findElement(const int *id) = 0; /* derived name */
    /* the rigs' slot 1 (FUN_013d0450 and its copies) */
    virtual void slot1(void *argument) = 0; /* derived name */

  protected:
    ~Object016d7b30() {}

  public:
    FadeModel013d4610 *model; /* +0x8 */
    int unknown10;
    float unknown14;
    float unknown18;
    int unknown1c; /* +0x1c: cleared again at the end of the rig's constructor */
    int unknown20;
    int unknown24;
    Array01343a80<FadeElement016d7b30 *> elements; /* +0x28 */
};

/* derived names: the layout of the fifteen classes whose slot 1 (FUN_013d0450
 * and its copies) calls FUN_013d1440 or its unit's copy, one class per unit:
 * the model at +0x8 and the target at +0x40 */
class FadeRig013d1440 : public Object016d7b30 /* derived name */
{
  public:
    FadeRig013d1440(FadeModel013d4610 *model, FadeTarget013d2490 *target)
        : Object016d7b30(model), target(target)
    {
    }

    /* the rigs' slots 2 and 3 (0x13d15f0, 0x13d1730 in 0x16d3988) */
    virtual ~FadeRig013d1440() {}

    FadeTarget013d2490 *target; /* +0x40 */
};

#endif
