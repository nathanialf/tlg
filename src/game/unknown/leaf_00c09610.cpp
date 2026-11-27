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
// NONMATCHING: 204/210 in the module, the base's 869 bytes: the first position's four lanes
// spilled across the product's call take their slots in the other order (x at -0x54 and w at
// -0x58, the base w at -0x54 and x at -0x58; the empty pop's zero stores w, z, y, x there). The
// lanes' phis come out of SROA's promotion x, y, z, w for this pop and z, y, x for the second
// (PromoteMemoryToRegister.cpp:855 puts each phi at the block's front; RemoveFromAllocasList
// reorders the list it walks): popVector as a default then overwritten gives the same.
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
    const Float4A position = self->popVector();
    Float4A rotation = self->popRotation();
    const Float4A offset = self->popVector();
    const Float4A by = self->popRotation();
    rotateBy(rotation, by);
    self->pushVector(
        Float4A(offset.x + position.x, offset.y + position.y, offset.z + position.z, position.w));
    self->pushRotation(rotation);
    return 0;
}
