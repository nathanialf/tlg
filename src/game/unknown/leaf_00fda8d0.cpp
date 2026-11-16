/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_libc.h"
#include "tlg_math.h"

/* derived names: a bone of a track, two aligned rows */
struct Bone00fda8d0 { /* derived name */
    Float4A row0;     /* +0x0 */
    Float4A row1;     /* +0x10 */
};

/* derived names: a 64-byte transform of the pose, its rows at +0x10 and +0x20 copied */
struct Transform00fda8d0 { /* derived name */
    Float4A row0;
    Float4A row1; /* +0x10 */
    Float4A row2; /* +0x20 */
    Float4A row3;
};

struct Pose00fda8d0 { /* derived name */
    u8 unknown0[0x250];
    Transform00fda8d0 *transforms; /* +0x250 */
};

struct Owner00fda8d0 { /* derived name */
    u8 unknown0[0x40];
    Pose00fda8d0 *pose; /* +0x40 */
};

/* derived names: copies, for each of its tracks, two rows of the pose's
 * transform of the track's joint into the track's bone at the object's
 * index, then keeps the lengths of the first rows of tracks 1 and 2 at that
 * index, summed, at +0x134. One of four byte-identical functions (0xfda8d0,
 * 0x101e120, 0x1047010, 0x128e090), each called twice by its neighbours.
 * The classes are not traced. */
struct Object00fda8d0 { /* derived name */
    u8 unknown0[0x8];
    Owner00fda8d0 *owner;                              /* +0x8 */
    Array05943280<int> joints;                         /* +0x10 */
    Array05943280<Array05943280<Bone00fda8d0>> tracks; /* +0x28 */
    u8 unknown40[0x58];
    u32 trackCount; /* +0x98 */
    u8 unknown9c[0x8];
    int index; /* +0xa4 */
    u8 unknowna8[0x8c];
    float length; /* +0x134 */
};

static inline float lengthOf(const Float4A &v) /* derived name */
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

/* derived name: the pose's rows copied into each track's bone at the index */
static inline void copyPose(Object00fda8d0 *self, int index) /* derived name */
{
    for (unsigned i = 0; i < self->trackCount; ++i) {
        Owner00fda8d0 *owner = self->owner;
        Bone00fda8d0 &bone = self->tracks.at(i).at(index);
        const int joint = self->joints.at(i);
        bone.row1 = owner->pose->transforms[joint].row2;
        bone.row0 = owner->pose->transforms[joint].row1;
    }
}

// NONMATCHING: instruction order in the loop: the base loads the pose's transforms
// (`mov r9, [rdx+0x250]`) before the joint's index, the build after; 56/71
void FUN_00fda8d0(Object00fda8d0 *self) /* derived name */
{
    copyPose(self, self->index);
    self->length = lengthOf(self->tracks.at(1).at(self->index).row0);
    self->length += lengthOf(self->tracks.at(2).at(self->index).row0);
}
