/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_joint_chain.h"

/* derived names: the unit's own rotation builder (FUN_010ffe20: an aligned
 * quaternion written through out, from two vectors of the source, its
 * position and the axis FUN_013533f0 gives) */
void FUN_010ffe20(Float4A *out, const JointFrame *frame, const Float4A *vector, float x, float y,
                  float z, float axisX, float axisY, float axisZ);

/* derived name: the rotation FUN_010ffe20 builds for a frame, a vector, a
 * position and an axis */
static inline Float4A frameRotation(const JointFrame &frame, const Float4A &vector,
                                    const Float4A &position, Float4 axis) /* derived name */
{
    Float4A rotation;
    FUN_010ffe20(&rotation, &frame, &vector, position.x, position.y, position.z, axis.x, axis.y,
                 axis.z);
    return rotation;
}

static inline Float4A sourceRotation(const JointSource &source) /* derived name */
{
    Float4 axis;
    FUN_013533f0(&axis, &source.rotation);
    return frameRotation(source.target, source.unknown40, source.position, axis);
}

/* derived names: resets the current joint from the chain's source: its
 * frames and position copied, its rotation built, its length measured.
 * A copy of FUN_013fd580 (leaf_013fd580.cpp) over its own unit's rotation
 * builder and constants. Called from 0x10f7e98, 0x10f8038, 0x10fd4fb, 0x10fd9ab. */
void FUN_01417e80(JointChain *self) /* derived name */
{
    self->joints[self->current].unknown0 = self->source->unknown0;
    self->joints[self->current].position = self->source->position;
    self->joints[self->current].rotation = sourceRotation(*self->source);
    self->joints[self->current].target = self->source->target;
    self->joints[self->current].reference = self->source->reference;
    self->joints[self->current].length = jointLength(self->joints[self->current]);
}
