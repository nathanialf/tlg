/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_foot013e8d20.h"

/* derived names: the joint's position taken, the foot's velocity the move
 * from the last position times the scale (the w lane the position's own),
 * the position kept; on a contact the name "FootContact" posted with the
 * skeleton owner's name and the foot's (FUN_00fe1b70); called by FUN_0124c8c0 for two feet, the twin of FUN_013e8d20 in another unit */
// NONMATCHING: register assignment only (module 86/93, 360 bytes as the base): the foot's slot is
// in rcx and the position's w in esi where the base has rsi and ecx; the source order of the index and the
// value (a reference made first) gives the same code
// The base keeps the name's index in r14d across FUN_00fe1b70 and the release's `lock xadd`
// by the memory dependence rule (tools/patches/llvm-3.7.1-atomic-01-ordered-rmw-uncaptured-local.patch).
void FUN_0147f100(Foot013e8d20 *foot, int first, int contact, float scale) /* derived name */
{
    Float4A position(0.0f, 0.0f, 0.0f, 0.0f);
    FUN_013ce2d0(&foot->model->skeleton, reinterpret_cast<Vec4 *>(&position), foot->joint,
                 foot->model->skeleton.poses);
    if (first)
        foot->previous = position;
    Float4 &velocity = foot->model->state->velocities[foot->slot];
    velocity =
        Float4((position.x - foot->previous.x) * scale, (position.y - foot->previous.y) * scale,
               (position.z - foot->previous.z) * scale, position.w);
    foot->previous = position;
    if (contact) {
        FadeModel013d4610 *model = foot->model;
        FUN_00fe1b70(Name("FootContact"), model->skeleton.owner->named->name, foot->name);
    }
}
