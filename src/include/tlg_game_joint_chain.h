/* derived names: an object holding an array of 0x90-byte joints at +0xc8,
 * the index of the current one at +0xe8 and the source a joint is reset from
 * at +0x40 (FUN_013fd580 and its five copies, one per unit, each called by
 * its own unit's code; the same object is read by slot 6 of the vtables at
 * 0x16d5760, 0x16d5ac0, 0x16d5c40, 0x16d5dc0 and four more). The class is
 * unknown. */
#ifndef TLG_GAME_JOINT_CHAIN_H
#define TLG_GAME_JOINT_CHAIN_H

#include "tlg_libc.h"
#include "tlg_math.h"
#include "tlg_types.h"

/* derived name: two aligned vectors, assigned member by member (the base
 * copies a frame as two aligned 16-byte moves) */
struct JointFrame { /* derived name */
    Float4A position;
    Float4A unknown10;

    JointFrame &operator=(const JointFrame &o)
    {
        position = o.position;
        unknown10 = o.unknown10;
        return *this;
    }
};

struct Joint { /* derived name */
    JointFrame unknown0;
    Float4A position;
    Float4A rotation; /* a quaternion */
    JointFrame target;
    JointFrame reference;
    float length; /* from the position to the target's position */
    u8 unknown84[0xc];
};

/* derived name: what a joint is reset from (FUN_013fd580) */
struct JointSource { /* derived name */
    JointFrame unknown0;
    Float4A position;
    Float4A unknown30;
    Float4A unknown40;
    Float4A rotation; /* FUN_013533f0 reads a quaternion here */
    JointFrame target;
    JointFrame reference;
};

struct JointChain { /* derived name */
    u8 unknown0[0x40];
    JointSource *source;
    u8 unknown48[0x80];
    Joint *joints;
    u8 unknownd0[0x18];
    int current;
};

/* derived names: the vector a quaternion turns D_57d8b80 into (the w copied
 * from it), written through out */
void FUN_013533f0(Float4 *out, const Float4A *rotation);

/* derived name: the distance from a joint's position to its target's */
inline float jointLength(const Joint &joint) /* derived name */
{
    float x = joint.target.position.x - joint.position.x;
    float y = joint.target.position.y - joint.position.y;
    float z = joint.target.position.z - joint.position.z;
    return sqrtf(x * x + y * y + z * z);
}

#endif
