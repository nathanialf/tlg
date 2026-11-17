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
