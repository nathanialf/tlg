/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: the 0x50-byte element FUN_0098ca30 appends (its caller
 * FUN_00977c60, two sites): two 16-byte aligned four-float vectors, copied
 * lane by lane (`mov edx, [rbx]; mov [rax+rcx], edx` up to +0x1c), then
 * twelve floats copied as one block (two overlapping `vmovups ymm` at +0x20
 * and +0x30). The fields' use is not traced. */
struct Element0098ca30 { /* derived name */
    Float4A unknown0;    /* +0x0 */
    Float4A unknown10;   /* +0x10 */
    float unknown20[12]; /* +0x20 */
};

/* FUN_0098ca30 */
template void Array05943280<Element0098ca30>::push(const Element0098ca30 &);
