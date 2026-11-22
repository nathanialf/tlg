/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: the append of a 16-byte aligned four-float vector
 * (alignment 16 to the owner's allocation, the element copied lane by
 * lane: `mov ecx, [r14]; mov [rax+rbx], ecx` to +0xc). Its caller
 * FUN_00a66840 appends six of them built on its stack, an axis and a
 * distance each (1, 0, 0 and -1, -0, -0 the first two): the planes of a
 * box. */

/* FUN_00a670a0 */
template void Array05943280<Float4A>::push(const Float4A &);
