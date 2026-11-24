/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object05945a38.h"

/* derived names: the object named "soundtask" of the type the pointer at
 * 0x5827b58 holds, made when there is none (Object05945a38::object; the shape
 * of FUN_005fb120); called by FUN_001bd010. */
extern Type00503fb0 *D_5827b58; /* derived name: the sound task's type */

// The base keeps the name's index in ebx across FUN_00cbc5a0 and the release's `lock xadd`
// by the memory dependence rule (tools/patches/llvm-3.7.1-atomic-01-ordered-rmw-uncaptured-local.patch).
Object016b9108 *FUN_00a319f0() /* derived name */
{
    return D_5945a38->object(Name("soundtask"), D_5827b58);
}
