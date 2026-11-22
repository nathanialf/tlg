/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: the 96-byte element FUN_00b442c0 appends (called twice by
 * FUN_00b43ee0): five 16-byte aligned four-float vectors copied lane by lane
 * (`mov edx, [rbx]; mov [rax+rcx], edx` to +0x4c), then the twelve bytes
 * from +0x50 as one block (`mov edx, [rbx+0x58]` before the quad at
 * +0x50). The fields' use is not traced. */
struct Element00b442c0 { /* derived name */
    Float4A unknown0;    /* +0x0 */
    Float4A unknown10;   /* +0x10 */
    Float4A unknown20;   /* +0x20 */
    Float4A unknown30;   /* +0x30 */
    Float4A unknown40;   /* +0x40 */
    int unknown50;       /* +0x50 */
    int unknown54;       /* +0x54 */
    int unknown58;       /* +0x58 */
};

/* FUN_00b442c0 */
template void Array05943280<Element00b442c0>::push(const Element00b442c0 &);
