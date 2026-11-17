/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ad3b8.h"

/* derived name: the complete destructor (the class in tlg_game_object016ad3b8.h) */
Object016ad3b8::~Object016ad3b8() {}

/* derived name: slot 14: the body at +0x68 turned by the pose's rotation (the
 * body read once for the product and its store) and moved by the pose's
 * position (the body read again); FUN_0077bac0's body */
void Object016ad3b8::slot14(Pose0077bac0 *pose)
{
    follow(pose);
}
