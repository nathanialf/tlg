/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_block.h"
#include "tlg_game_rotation.h"
#include "tlg_game_stacks00c09610.h"

/* derived names: the call FUN_00c0bc10 and FUN_00c0bcb0 append: the entry
 * under the top of the first two stacks released (a holder's block first),
 * the top kept; then two positions and two rotations popped, the rotations'
 * product (rotateBy, the second popped applied to the first) pushed
 * after the positions' sum (the first's w kept). Returns 0. */
/* The sum is made in the first position itself: the four lanes spilled
 * across the product's call then take the base's slots (w at -0x54, x at
 * -0x58). A sum built as a new Float4A for the push is a temporary of four
 * lanes each stored once, which PromoteMemToReg removes first, each removal
 * moving the list's last alloca (a position lane) into its place: the
 * position's phis then come out x, y, z, w where the base has w, z, y, x
 * (round 601E). */
int FUN_00c09610(void *vm, const CallArguments583950 *arguments) /* derived name */
{
    Stacks00c09610 *self = static_cast<Stacks00c09610 *>(vm);
    Holder00c09610 *keptHolder = self->popHolder();
    Holder00c09610 *holder = self->popHolder();
    self->pushHolder(keptHolder);
    if (holder) {
        FUN_00ebf3f0(holder->block);
        FUN_00ebf3f0(holder);
    }
    Transform00c09610 *keptTransform = self->popTransform();
    Transform00c09610 *transform = self->popTransform();
    self->pushTransform(keptTransform);
    FUN_00ebf3f0(transform);
    Float4A position = self->popVector();
    Float4A rotation = self->popRotation();
    const Float4A offset = self->popVector();
    const Float4A by = self->popRotation();
    rotateBy(rotation, by);
    position.x += offset.x;
    position.y += offset.y;
    position.z += offset.z;
    self->pushVector(position);
    self->pushRotation(rotation);
    return 0;
}
