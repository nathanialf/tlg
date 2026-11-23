/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00bc1a50.h"

/* FUN_00bc15b0: the three sets' references side by side (+0x4118,
 * +0x4138, +0x4158, +0x4120 and on), then the nine after them in the
 * base's order */
void Object00bc1a50::releaseSharedSets()
{
    sharedA[0].reset();
    sharedB[0].reset();
    sharedC[0].reset();
    sharedA[1].reset();
    sharedB[1].reset();
    sharedC[1].reset();
    sharedA[2].reset();
    sharedB[2].reset();
    sharedC[2].reset();
    sharedA[3].reset();
    sharedB[3].reset();
    sharedC[3].reset();
    shared4188.reset();
    shared4190.reset();
    shared4198.reset();
    shared41a0.reset();
    shared4180.reset();
    shared4178.reset();
    shared41b0.reset();
    shared41b8.reset();
    shared41a8.reset();
}
