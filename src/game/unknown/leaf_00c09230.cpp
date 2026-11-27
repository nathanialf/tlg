/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_rotation.h"
#include "tlg_game_stacks00c09610.h"

Float4A FUN_0134ab60(const Float4A &rotation);                   /* derived name */
void FUN_0020c3b0(Float4A *rotation, float x, float y, float z); /* derived name */

/* derived names: the same rotation returned, and the product of two
 * rotations returned (FUN_013439c0): each a temporary of the statement that
 * takes it (the base gives each its own frame slot, -0x80 and -0x90: no
 * lifetime markers on a temporary) */
inline Float4A rotationFromAngles(float x, float y, float z) /* derived name */
{
    Float4A made;
    FUN_0020c3b0(&made, x, y, z);
    return made;
}

inline Float4A rotationProduct(const Float4A &first, const Float4A &second) /* derived name */
{
    Float4A product;
    FUN_013439c0(&product, &first, &second);
    return product;
}

/* derived names: the four modes FUN_00c09230 reads where a call's
 * arguments are (FUN_00c0e720 appends them from its node's +0x28) */
struct Modes00c09230 {
    int position; /* what the transform keeps of its position */
    int vector;   /* +0x4: what the pushed vector keeps */
    int rotation; /* +0x8: what the transform keeps of its rotation */
    int angles;   /* +0xc: what the pushed rotation keeps */
};

/* derived names: the call FUN_00c0e720 appends: on the transform at the top
 * of the first stack (nothing without one), the popped vector and the
 * transform's position share their lanes by the first mode (mode 5 keeps
 * the position on its own stack first), the vector cut by the second and
 * pushed again; the popped rotation's angles (FUN_0134ab60) and the
 * transform's rotation by the third against the reference's at +0xf0 (mode
 * 4 keeps the turn from it on its own stack), the angles cut by the fourth
 * and pushed again as a rotation (FUN_0020c3b0). Returns 0. */
// NONMATCHING: 205/206 in the module, the base's frame (0x78: the turn's angles, the made
// rotation, the change and its inverse are temporaries of their statements, unmarked and so each
// in a slot of its own; the made rotation reuses the popped one, -0x50): the zeroed position of
// modes 1 and 5 is stored as a dword and a qword (y and z merged by the DAG's
// MergeConsecutiveStores) where the base keeps three dwords
int FUN_00c09230(void *vm, const CallArguments583950 *arguments) /* derived name */
{
    Stacks00c09610 *self = static_cast<Stacks00c09610 *>(vm);
    const Modes00c09230 *modes = reinterpret_cast<const Modes00c09230 *>(arguments);
    Transform00c09610 *transform = self->topTransform();
    if (!transform)
        return 0;

    Float4A vector = self->popVector();
    switch (modes->position) {
    case 1:
        transform->position.x = 0.0f;
        transform->position.y = 0.0f;
        transform->position.z = 0.0f;
        break;
    case 2:
        transform->position.x = 0.0f;
        transform->position.z = 0.0f;
        vector.y = 0.0f;
        break;
    case 3:
        transform->position.y = 0.0f;
        vector.x = 0.0f;
        vector.z = 0.0f;
        break;
    case 4:
        break;
    case 5:
        self->pushPosition(transform->position);
        transform->position.x = 0.0f;
        transform->position.y = 0.0f;
        transform->position.z = 0.0f;
        break;
    default:
        vector = Float4A(0.0f, 0.0f, 0.0f, 0.0f);
        break;
    }
    switch (modes->vector) {
    case 1:
        vector = Float4A(0.0f, 0.0f, 0.0f, 0.0f);
        break;
    case 2:
        vector.x = 0.0f;
        vector.z = 0.0f;
        break;
    case 3:
        vector.y = 0.0f;
        break;
    }
    self->pushVector(vector);

    Reference00c09610 *reference = self->reference;
    const Float4A referenceAngles = FUN_0134ab60(reference->rotation);
    Float4A rotation = self->popRotation();
    Float4A angles = FUN_0134ab60(rotation);
    switch (modes->rotation) {
    case 1:
        transform->rotation = reference->rotation;
        break;
    case 2: {
        const Float4A &own = FUN_0134ab60(transform->rotation);
        transform->rotation = rotationFromAngles(own.x, referenceAngles.y, own.z);
        angles.x = 0.0f;
        angles.z = 0.0f;
        angles.w = 1.0f;
        break;
    }
    case 3:
        break;
    case 4: {
        const Float4A &to = reference->rotation;
        self->pushChange(rotationProduct(transform->rotation, Float4A(-to.x, -to.y, -to.z, to.w)));
        transform->rotation = to;
        break;
    }
    default:
        angles = Float4A(0.0f, 0.0f, 0.0f, 0.0f);
        break;
    }
    switch (modes->angles) {
    case 1:
        angles = Float4A(0.0f, 0.0f, 0.0f, 0.0f);
        break;
    case 2:
        angles.y = 0.0f;
        angles.w = 1.0f;
        break;
    }
    FUN_0020c3b0(&rotation, angles.x, angles.y, angles.z);
    self->pushRotation(rotation);
    return 0;
}
