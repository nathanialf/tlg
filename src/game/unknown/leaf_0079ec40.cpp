/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016adac0.h"

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor FUN_00774560 runs as a
 * tail call. The destructor is the class's key function, so this file emits
 * the vtable. */
Object016adac0::~Object016adac0() {}

/* derived name: slot 9, as Object016acb20's (FUN_00766c90) with its int at
 * +0x3d8 */
void Object016adac0::slot9()
{
    if (slot22()) {
        FUN_00214e10(&unknown100);
        if (State00774760 *state = unknown3c8.get()) {
            state->setUnknown60(state->unknown60 | 1);
            unknown3d8 = 0;
            unknown3c0.clear();
            unknown3c8.clear();
        }
    }
}
