/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016acf08.h"

void FUN_007196a0(Body0077bac0 *body); /* derived name: not traced */

/* derived names: slot 7 of the vtable at 0x16acf08: the body handed to
 * FUN_007196a0, then the waiting point given to the body unless its x, y
 * and z are all zero, and the waiting rotation unless it is the identity,
 * each put back to (0, 0, 0, 1) once given */
void Object016acf08::slot7(Pose0077bac0 *)
{
    FUN_007196a0(unknown68);
    if (unknown100.x != 0.0f || unknown100.y != 0.0f || unknown100.z != 0.0f) {
        unknown68->position = unknown100;
        unknown100 = Float4A(0.0f, 0.0f, 0.0f, 1.0f);
    }
    if (unknown110.x != 0.0f || unknown110.y != 0.0f || unknown110.z != 0.0f ||
        unknown110.w != 1.0f) {
        unknown68->rotation = unknown110;
        unknown110 = Float4A(0.0f, 0.0f, 0.0f, 1.0f);
    }
}
