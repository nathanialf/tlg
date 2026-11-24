/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object05945a38.h"

/* derived names: the object named "CameraManager" of the type the pointer at
 * 0x580dfe0 holds (the type FUN_005f3810 creates its objects with), made
 * when there is none (Object05945a38::object); called by FUN_001bd010 (0x1d759b). */
extern Type00503fb0 *D_580dfe0; /* derived name: the camera manager's type */

// The base keeps the name's index in ebx across FUN_00cbc5a0 and the release's `lock xadd`
// (`mov ebx, eax`, then `test ebx, ebx` for its release) by the memory dependence rule
// (tools/patches/llvm-3.7.1-atomic-01-ordered-rmw-uncaptured-local.patch).
Object016b9108 *FUN_005fb120() /* derived name */
{
    return D_5945a38->object(Name("CameraManager"), D_580dfe0);
}
