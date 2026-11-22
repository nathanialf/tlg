/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: the append of a four-byte aligned four-float vector
 * (alignment 4 to the owner's allocation, the element copied lane by lane:
 * `mov ecx, [r14]; mov [rax+rbx], ecx` to +0xc), called by FUN_00a166b0 on
 * the array at +0x150 of its object. The vector's use is not traced. */

/* FUN_00a16fa0 */
template void Array05943280<Float4>::push(const Float4 &);
