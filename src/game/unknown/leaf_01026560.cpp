/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: the 0x30-byte element FUN_01026560 appends (its callers
 * FUN_01024f70 and FUN_01275770, three sites each): an int, then two
 * 16-byte aligned four-float vectors, copied lane by lane (`mov edx, [rbx];
 * mov [rax+rcx], edx`, then +0x10 to +0x2c a float at a time). The fields'
 * use is not traced. */
struct Element01026560 { /* derived name */
    int unknown0;
    Float4A unknown10; /* +0x10 */
    Float4A unknown20; /* +0x20 */
};

/* FUN_01026560 */
template void Array05943280<Element01026560>::push(const Element01026560 &);
