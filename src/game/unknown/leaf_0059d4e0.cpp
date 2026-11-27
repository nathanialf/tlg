/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_mover0059d4e0.h"
#include "tlg_libc.h"

extern const Type00503fb0 *D_5814678;
extern const Type00503fb0 *D_5814e08;

/* derived names: the body turned about x toward the mover's tilt: a tilt
 * no larger than the target's dead zone is none, the rest clamped to
 * [-1, 1] and taken as the sine of the angle (degrees), the angle held to
 * the target's rate over the step, the rotation of that angle normalized
 * and applied to the body's (rotateBy). Only while the mover's +0x1b4 is
 * above the dead zone; returns 1 without a mover, a target or its limits,
 * else 0. */
// NONMATCHING: 85/173 in the module, 720 bytes against 751: from the return's 1 on (the base
// sets it in r14 before the slot's read, as FUN_005a4e70 does), and the link inlines
// FUN_00206950 (one signature: leaf_00208b90.cpp's open class) where the base calls it
int FUN_0059d4e0(void *vm, const CallArguments583950 *arguments) /* derived name */
{
    Stacks00c09610 *self = static_cast<Stacks00c09610 *>(vm);
    Object016b85e0 *node = self->node;
    const float step = self->step;
    Body0059d4e0 *body = self->body;
    Mover0059d4e0 *mover = static_cast<Mover0059d4e0 *>(node->component(D_5814678));
    Target0059d4e0 *target = body->currentTarget().get();
    Limits0059d4e0 *limits = target ? target->firstLimits() : 0;
    if (!mover || !limits)
        return 1;
    if (!(mover->unknown1b4 > limits->deadZone))
        return 0;
    float sine = fabsf(mover->tilt) > limits->deadZone ? mover->tilt : 0.0f;
    sine = sine < -1.0f ? -1.0f : (sine < 1.0f ? sine : 1.0f);
    float angle = asinf(sine) * 57.29577f;
    const float rate = step * limits->turnRate;
    angle = angle < -rate ? -rate : (angle < rate ? angle : rate);
    Object00206a90 turn;
    FUN_00206950(&turn, 1.0f, 0.0f, 0.0f, angle);
    const Float4A &q = turn.rotation;
    const float lengthSquared = q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
    Float4A by;
    if (lengthSquared > 1e-10f) {
        const float scale = 1.0f / sqrtf(lengthSquared);
        by = Float4A(q.x * scale, q.y * scale, q.z * scale, q.w * scale);
    } else {
        by = Float4A(0.0f, 0.0f, 0.0f, 1.0f);
    }
    rotateBy(body->rotation, by);
    return 0;
}

/* derived names: the body moved down the slope of the mover's normal
 * (+0x1640: n x (n x up), the normal's height below one, its rest as the
 * speed) over the step and the target's +0x74; returns 1 without a mover
 * of the type at 0x5814e08 with +0x14d8 set, a target or its limits, or
 * for a normal near the vertical, else 0. */
// NONMATCHING: 23/133 in the module, 566 bytes against 571: the base keeps the return value in
// eax, set after the limits' lookup (four callee-saved registers, no r13), and keeps the lookup's
// null paths apart (`xor ecx, ecx` twice, the target tested again after the reference's release)
// where the build threads them; the base's height test survives (`vucomiss; jb`)
int FUN_005a4b00(void *vm, const CallArguments583950 *arguments) /* derived name */
{
    Stacks00c09610 *self = static_cast<Stacks00c09610 *>(vm);
    Object016b85e0 *node = self->node;
    const float step = self->step;
    Body0059d4e0 *body = self->body;
    Slider0059d4e0 *slider = static_cast<Slider0059d4e0 *>(node->component(D_5814e08));
    Target0059d4e0 *target = body->currentTarget().get();
    Limits0059d4e0 *limits = target ? target->firstLimits() : 0;
    if (!slider || !limits || !slider->unknown14d8)
        return 1;
    const float x = slider->normal[0];
    const float y = slider->normal[1];
    const float z = slider->normal[2];
    const float height = y < 0.0f ? -y : y;
    if (!(height >= 0.0f && height < 0.99999f))
        return 1;
    float speed = 1.0f - height;
    speed = speed < 0.0f ? 0.0f : (speed < 1.0f ? speed : 1.0f);
    speed = speed * step * limits->unknown74;
    body->position = body->position + speed * Vector0077bac0(y * x, x * -x - z * z, z * y);
    return 0;
}

/* derived names: the body moved by the mover's velocity over the step while
 * the mover's +0x1b4 is above the target's +0x48; returns 1 without a mover,
 * a target or its limits, else 0. */
// NONMATCHING: 105/107 aligned, 446 bytes against 455: the temporary reference's two residuals
// (FUN_00a8d620's): the count read after the raise through the raise's address (`cmp [rbx]`,
// the base `cmp [r12+8]`), and the target's null test after the release folded (the base keeps
// `test r12, r12; je` at 0x5a4f93). The move is the base's (a Vector0077bac0 sum: the three
// products, the three sums, then the three stores)
int FUN_005a4e70(void *vm, const CallArguments583950 *arguments) /* derived name */
{
    Stacks00c09610 *self = static_cast<Stacks00c09610 *>(vm);
    Object016b85e0 *node = self->node;
    const float step = self->step;
    Body0059d4e0 *body = self->body;
    Mover0059d4e0 *mover = static_cast<Mover0059d4e0 *>(node->component(D_5814678));
    Target0059d4e0 *target = body->currentTarget().get();
    Limits0059d4e0 *limits = target ? target->firstLimits() : 0;
    if (!mover || !limits)
        return 1;
    if (mover->unknown1b4 > limits->unknown48)
        body->position = body->position + step * mover->velocity;
    return 0;
}

/* derived names: the body turned by the arc from up to the direction
 * (n x (n x up)) the mover's normal slopes toward, seen from the body: the
 * node's +0x140 turned by the top of the machine's rotations and by the
 * body's rotation, the slope taken back through that rotation and flattened
 * to x and z (its sign by the argument's node's +0x48), the arc's angle held
 * to the target's +0x58 over the step; the same gates as FUN_005a4b00. */
// NONMATCHING: first draft, 1360 bytes against 1095: the link inlines FUN_00208b90,
// FUN_01343bb0 and FUN_00206950 (one signature each: their open class) where the base calls them
int FUN_005a5b90(void *vm, const CallArguments583950 *arguments) /* derived name */
{
    Stacks00c09610 *self = static_cast<Stacks00c09610 *>(vm);
    const Argument0059d4e0 *argument = static_cast<const Argument0059d4e0 *>(arguments->node);
    Object016b85e0 *node = self->node;
    const float step = self->step;
    Body0059d4e0 *body = self->body;
    Slider0059d4e0 *slider = static_cast<Slider0059d4e0 *>(node->component(D_5814e08));
    Target0059d4e0 *target = body->currentTarget().get();
    Limits0059d4e0 *limits = target ? target->firstLimits() : 0;
    if (!slider || !limits || !slider->unknown14d8)
        return 1;
    const float height = fabsf(slider->normal[1]);
    if (!(height >= 0.0f && height < 0.99999f))
        return 1;
    const Float4A top = self->topRotation();
    const Float4A nodeRotation = node->unknown140;
    Float4A turned;
    FUN_013439c0(&turned, &nodeRotation, &top);
    Float4A world;
    FUN_013439c0(&world, &turned, &body->rotation);
    const float x = slider->normal[0];
    const float y = slider->normal[1];
    const float z = slider->normal[2];
    const Float4A slope(y * -x, z * z + x * x, -(z * y), 0.0f);
    const Float4A inverse(-world.x, -world.y, -world.z, world.w);
    Float4A local;
    FUN_01343bb0(&local, slope, inverse);
    const float scale = 1.0f / sqrtf(local.z * local.z + local.x * local.x);
    const float sign = argument->unknown48 ? -1.0f : 1.0f;
    Object0020d4b0 arc;
    FUN_00208b90(&arc, 0.0f, 0.0f, 1.0f, local.x * scale * sign, 0.0f, local.z * scale * sign);
    const Float4A rotation(arc.rotation);
    Float4A axis;
    float angle = FUN_0134bb20(rotation, axis);
    const float rate = step * limits->unknown58;
    angle = angle < -rate ? -rate : (angle < rate ? angle : rate);
    Object00206a90 turn;
    FUN_00206950(&turn, axis.x, axis.y, axis.z, angle);
    rotateBy(body->rotation, turn.rotation);
    return 0;
}

/* derived names: the body turned by the arc from up to the mover's +0x530
 * seen from the body (the node's +0x140 turned by the top of the machine's
 * rotations and by the body's rotation), the arc's angle held to the
 * target's +0x58 over the step; returns 1 without a mover of the type at
 * 0x5814e08, a target or its limits, else 0. */
// NONMATCHING: first draft, 1237 bytes against 861: as FUN_005a5b90
int FUN_005a6110(void *vm, const CallArguments583950 *arguments) /* derived name */
{
    Stacks00c09610 *self = static_cast<Stacks00c09610 *>(vm);
    Object016b85e0 *node = self->node;
    const float step = self->step;
    Body0059d4e0 *body = self->body;
    Slider0059d4e0 *slider = static_cast<Slider0059d4e0 *>(node->component(D_5814e08));
    Target0059d4e0 *target = body->currentTarget().get();
    Limits0059d4e0 *limits = target ? target->firstLimits() : 0;
    if (!slider || !limits)
        return 1;
    const Float4A top = self->topRotation();
    const Float4A nodeRotation = node->unknown140;
    Float4A turned;
    FUN_013439c0(&turned, &nodeRotation, &top);
    Float4A world;
    FUN_013439c0(&world, &turned, &body->rotation);
    const Float4A inverse(-world.x, -world.y, -world.z, world.w);
    Float4A local;
    FUN_01343bb0(&local, slider->up, inverse);
    Object0020d4b0 arc;
    FUN_00208b90(&arc, 0.0f, 0.0f, 1.0f, local.x, local.y, local.z);
    const Float4A rotation(arc.rotation);
    Float4A axis;
    float angle = FUN_0134bb20(rotation, axis);
    const float rate = step * limits->unknown58;
    angle = angle < -rate ? -rate : (angle < rate ? angle : rate);
    Object00206a90 turn;
    FUN_00206950(&turn, axis.x, axis.y, axis.z, angle);
    rotateBy(body->rotation, turn.rotation);
    return 0;
}
