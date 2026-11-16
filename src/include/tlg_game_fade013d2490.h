/* src/include/tlg_game_fade013d2490.h: the fading state ten classes of the
 * game region share (docs/TARGETS.md), read from the bytes of FUN_013d2490
 * and its nine copies. Every name here is derived. */
#ifndef TLG_GAME_FADE013D2490_H
#define TLG_GAME_FADE013D2490_H

#include "tlg_types.h"
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
 * +0x90 the update clears */
struct FadeTargetEntry013d2490 { /* derived name */
    u8 unknown0[0x50];
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
    int *unknown28; /* +0x28: per entry, the index of its pose (FUN_013d4610) */
};

/* derived names: a pose of the model, 0x40 bytes, its rotation at +0x10
 * (FUN_013d4610 copies it into an entry as a whole object: a copy the lane
 * reads after it are not forwarded from, so they load it again) */
struct FadePose013d4610 { /* derived name */
    Vector4 position;     /* +0x0 */
    Vector4 rotation;     /* +0x10 */
    u8 unknown20[0x20];
};

/* derived names: the model's skeleton at +0x40, whose poses FUN_013ce2d0
 * and FUN_013ce660 (each taking the skeleton, the vector to write, a pose
 * index and the poses) read; the int at +0x130 is not traced */
struct FadeSkeleton013ce2d0 { /* derived name */
    u8 unknown0[0x100];
    FadePose013d4610 *poses; /* +0x100 (the model's +0x140) */
};

struct FadeModel013d4610 { /* derived name */
    u8 unknown0[0x40];
    FadeSkeleton013ce2d0 skeleton; /* +0x40 */
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

/* derived names: the layout of the fifteen classes whose slot 1 (FUN_013d0450
 * and its copies) calls FUN_013d1440 or its unit's copy, one class per unit:
 * the model at +0x8 and the target at +0x40 */
struct FadeRig013d1440 { /* derived name */
    u8 unknown0[0x8];
    FadeModel013d4610 *model; /* +0x8 */
    u8 unknown10[0x30];
    FadeTarget013d2490 *target; /* +0x40 */
};

#endif
