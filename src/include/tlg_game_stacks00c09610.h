/* src/include/tlg_game_stacks00c09610.h: the machine the calls FUN_00c0bc10,
 * FUN_00c0bcb0 and FUN_00c0e720 append are run on (the first argument of a
 * CallFunction583950 there): six stacks of sixteen, each with the index of
 * its top (-1 when empty) after the last, at +0x610 to +0x624. A push past
 * the sixteenth is dropped; a pop reads the top before it lowers the index
 * (`mov rax, [rbx+rdx*8+0x188]` above the store of +0x614 in FUN_00c09610)
 * and of an empty stack gives null, zeros or the identity rotation. Every name here is derived. */
#ifndef TLG_GAME_STACKS00C09610_H
#define TLG_GAME_STACKS00C09610_H

#include "tlg_math.h"
#include "tlg_types.h"

class Object016b85e0; /* tlg_game_object016b85e0.h */
struct Body0059d4e0;  /* tlg_game_mover0059d4e0.h */

/* derived names: an object of the first stack: a block of the game's heaps
 * (released through FUN_00ebf3f0) with a position at +0x10 and a rotation at
 * +0x20 */
struct Transform00c09610 {
    u8 unknown0[0x10];
    Float4A position; /* +0x10 */
    Float4A rotation; /* +0x20 */
};

/* derived names: an entry of the second stack: a block that owns another,
 * released before it */
struct Holder00c09610 {
    void *block;
};

/* derived names: the object at +0xf0, a rotation at +0x20 (FUN_00c09230) */
struct Reference00c09610 {
    u8 unknown0[0x20];
    Float4A rotation; /* +0x20 */
};

/* derived names */
struct Stacks00c09610 {
    enum { DEPTH = 16 };

    Transform00c09610 *topTransform() const
    {
        if (transformTop < 0)
            return 0;
        return transforms[transformTop];
    }

    Transform00c09610 *popTransform()
    {
        if (transformTop < 0)
            return 0;
        Transform00c09610 *transform = transforms[transformTop];
        --transformTop;
        return transform;
    }

    void pushTransform(Transform00c09610 *transform)
    {
        if (transformTop < DEPTH - 1)
            transforms[++transformTop] = transform;
    }

    Holder00c09610 *popHolder()
    {
        if (holderTop < 0)
            return 0;
        Holder00c09610 *holder = holders[holderTop];
        --holderTop;
        return holder;
    }

    void pushHolder(Holder00c09610 *holder)
    {
        if (holderTop < DEPTH - 1)
            holders[++holderTop] = holder;
    }

    Float4A popVector()
    {
        Float4A vector(0.0f, 0.0f, 0.0f, 0.0f);
        if (vectorTop >= 0) {
            vector = vectors[vectorTop];
            --vectorTop;
        }
        return vector;
    }

    void pushVector(const Float4A &vector)
    {
        if (vectorTop < DEPTH - 1)
            vectors[++vectorTop] = vector;
    }

    /* the rotation at the top, the identity when there is none
     * (FUN_005a5b90, FUN_005a6110) */
    Float4A topRotation() const
    {
        if (rotationTop < 0)
            return Float4A(0.0f, 0.0f, 0.0f, 1.0f);
        return rotations[rotationTop];
    }

    Float4A popRotation()
    {
        Float4A rotation(0.0f, 0.0f, 0.0f, 1.0f);
        if (rotationTop >= 0) {
            rotation = rotations[rotationTop];
            --rotationTop;
        }
        return rotation;
    }

    void pushRotation(const Float4A &rotation)
    {
        if (rotationTop < DEPTH - 1)
            rotations[++rotationTop] = rotation;
    }

    void pushPosition(const Float4A &position)
    {
        if (positionTop < DEPTH - 1)
            positions[++positionTop] = position;
    }

    void pushChange(const Float4A &change)
    {
        if (changeTop < DEPTH - 1)
            changes[++changeTop] = change;
    }

    u8 unknown0[0xc];
    float step; /* +0xc: the time a call's step takes (FUN_0059d4e0 and its siblings) */
    u8 unknown10[0x18];
    Object016b85e0 *node; /* +0x28: the node the machine runs for */
    u8 unknown30[0xc0];
    Reference00c09610 *reference; /* +0xf0 */
    u8 unknownf8[0x10];
    Transform00c09610 *transforms[DEPTH]; /* +0x108 */
    Holder00c09610 *holders[DEPTH];       /* +0x188 */
    Float4A vectors[DEPTH];               /* +0x210 */
    Float4A rotations[DEPTH];             /* +0x310 */
    Float4A positions[DEPTH];             /* +0x410: a transform's position kept (FUN_00c09230) */
    Float4A changes[DEPTH];               /* +0x510: a transform's turn kept (FUN_00c09230) */
    int transformTop;                     /* +0x610 */
    int holderTop;                        /* +0x614 */
    int vectorTop;                        /* +0x618 */
    int rotationTop;                      /* +0x61c */
    int positionTop;                      /* +0x620 */
    int changeTop;                        /* +0x624 */
    u8 unknown628[0x38];
    Body0059d4e0 *body; /* +0x660: what FUN_0059d4e0 and its siblings move */
};

#endif
