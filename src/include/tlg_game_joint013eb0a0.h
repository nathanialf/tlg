/* src/include/tlg_game_joint013eb0a0.h: a joint placed against its node, and
 * the frame three classes of two units return for it (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_JOINT013EB0A0_H
#define TLG_GAME_JOINT013EB0A0_H

#include "tlg_types.h"
#include "tlg_math.h"
#include "tlg_game_frame.h"
#include "tlg_game_rotation.h"

/* derived names: a node whose position (+0x120) and rotation (+0x140) a
 * joint is placed against */
struct Node013eb0a0 { /* derived name */
    u8 unknown0[0x120];
    Vec4 position; /* +0x120 */
    u8 unknown130[0x10];
    Float4A rotation; /* +0x140 */
};

/* derived names: a joint: its node at +0x40, its offset from the node's
 * position at +0x80 and its own rotation at +0x90 */
struct Joint013eb0a0 { /* derived name */
    u8 unknown0[0x40];
    Node013eb0a0 *node; /* +0x40 */
    u8 unknown48[0x38];
    Vec4 offset;      /* +0x80 */
    Float4A rotation; /* +0x90 */
};

/* derived names: the frame returned for a joint: a position and a
 * rotation. Built as the identity it is zero and the including unit's VECTOR_W, the
 * constant copied whole before the position is set (both 64-bit loads
 * before the zero's store, FUN_013eb210); built from two values it copies
 * each whole (16-byte moves). Its lanes are floats of a 16-byte aligned struct, so the
 * returned object's alignment is not known to the optimiser: the
 * rotation's lanes are read back with an unaligned load (`vmovups`). */
struct JointFrame013eb0a0 { /* derived name */

    /* the lanes left unset, as Float4A's own (slot 2 of Object016d7510,
     * FUN_01480e70, stores the position before it reads the node) */
    JointFrame013eb0a0() {}

    static JointFrame013eb0a0 identity() /* derived name */
    {
        JointFrame013eb0a0 frame;
        const Float4Data unit = reinterpret_cast<const Float4Data &>(VECTOR_W);
        frame.position.set(0.0f, 0.0f, 0.0f, 0.0f);
        frame.rotation = unit;
        return frame;
    }

    JointFrame013eb0a0(const Float4A &position_, const Float4A &rotation_)
    {
        position = position_;
        rotation = rotation_;
    }

    Float4A position; /* +0x0 */
    Float4A rotation; /* +0x10 */
};

/* derived names: an object placed by a node at +0x10 (FUN_013eb210) */
struct Placed013eb210 { /* derived name */
    u8 unknown0[0x10];
    Node013eb0a0 *node; /* +0x10 */
};

/* derived name: the node's position and rotation, or zero and the including
 * unit's VECTOR_W without a node (copied whole as plain floats, then lane
 * by lane: two 64-bit loads, four 32-bit stores) */
inline JointFrame013eb0a0 nodeFrame(const Placed013eb210 *self) /* derived name */
{
    const Node013eb0a0 *node = self->node;
    if (node)
        return JointFrame013eb0a0(reinterpret_cast<const Float4A &>(node->position),
                                  node->rotation);
    return JointFrame013eb0a0::identity();
}

/* derived name: the joint's frame: the node's position moved by the offset
 * (its w the offset's own), and the product of the joint's rotation and the
 * node's (FUN_013439c0) turned to w not negative. The same body is slot 2
 * of vtables in each of two units (FUN_013eb0a0, FUN_013eb510,
 * FUN_013eb6f0; FUN_01480ed0, FUN_01481320, FUN_01481470): `self` is not
 * read. */
inline JointFrame013eb0a0 jointFrame(const Joint013eb0a0 *joint) /* derived name */
{
    JointFrame013eb0a0 frame(Float4A(0.0f, 0.0f, 0.0f, 0.0f),
                             reinterpret_cast<const Float4A &>(VECTOR_W));
    const Node013eb0a0 *node = joint->node;
    const float x = lane(node->position, 0) + lane(joint->offset, 0);
    const float y = lane(node->position, 1) + lane(joint->offset, 1);
    const float z = lane(node->position, 2) + lane(joint->offset, 2);
    const float w = lane(joint->offset, 3);
    frame.position.x = x;
    frame.position.y = y;
    frame.position.z = z;
    frame.position.w = w;
    Float4A product;
    FUN_013439c0(&product, &joint->rotation, &node->rotation);
    frame.rotation = product;
    makeWPositive(reinterpret_cast<Vec4 &>(frame.rotation));
    return frame;
}

#endif
