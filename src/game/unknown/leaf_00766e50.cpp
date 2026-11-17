/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016acb20.h"

/* derived name: slot 14: when slot 22 says so, the member at +0x100 is run
 * while its int is set, the body put back home (Object00774560::goHome) and
 * the body's int at +0x1b0c copied to +0x3c; the pose is not read */
void Object016acb20::slot14(Pose0077bac0 *)
{
    if (slot22()) {
        if (unknown100.unknown8)
            unknown100.FUN_00216780();
        goHome();
        unknown3c = unknown68->unknown1b0c;
    }
}

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor FUN_00774560 runs as a
 * tail call. The destructor is the class's key function, so this file emits
 * the vtable. */
Object016acb20::~Object016acb20() {}

/* derived name: slot 9: when slot 22 says so, the member at +0x100 reset
 * (FUN_00214e10); then, when the second reference holds a state, the
 * state's int at +0x60 given bit 0, the int at +0x3d0 cleared and both
 * references emptied */
void Object016acb20::slot9()
{
    if (slot22()) {
        FUN_00214e10(&unknown100);
        if (State00774760 *state = unknown3c8.get()) {
            state->setUnknown60(state->unknown60 | 1);
            unknown3d0 = 0;
            unknown3c0.clear();
            unknown3c8.clear();
        }
    }
}
