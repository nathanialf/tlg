/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_rotation.h"
#include "tlg_game_stacks00c09610.h"

Float4A FUN_0134ab60(const Float4A &rotation);                   /* derived name */
void FUN_0020c3b0(Float4A *rotation, float x, float y, float z); /* derived name */

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
// NONMATCHING: first draft, 18/209 in the module, 886 bytes against 937: the frame is 0x58
// bytes against 0x78 (the base keeps the seven 16-byte locals apart: the angles at -0x40, -0x60
// and -0x70, the rotations at -0x50 and -0x80, the change at -0x90, its inverse at -0xa0);
// the position's three zero stores are one dword and one qword here
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
    const Float4A rotation = self->popRotation();
    Float4A angles = FUN_0134ab60(rotation);
    switch (modes->rotation) {
    case 1:
        transform->rotation = reference->rotation;
        break;
    case 2: {
        const Float4A own = FUN_0134ab60(transform->rotation);
        Float4A turned;
        FUN_0020c3b0(&turned, own.x, referenceAngles.y, own.z);
        transform->rotation = turned;
        angles = Float4A(0.0f, angles.y, 0.0f, 1.0f);
        break;
    }
    case 3:
        break;
    case 4: {
        const Float4A &to = reference->rotation;
        const Float4A inverse(-to.x, -to.y, -to.z, to.w);
        Float4A change;
        FUN_013439c0(&change, &transform->rotation, &inverse);
        self->pushChange(change);
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
        angles = Float4A(angles.x, 0.0f, angles.z, 1.0f);
        break;
    }
    Float4A result;
    FUN_0020c3b0(&result, angles.x, angles.y, angles.z);
    self->pushRotation(result);
    return 0;
}
