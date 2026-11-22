/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: the element of an array appended to by FUN_001bd010 (0x1bd709 and more), with the pointer 0x57c9b20 at 0x1bd6ce:
 * five ints copied together (the last first, then one 16-byte move), two Names, then a pointer; the fields are not traced */
struct Record002033c0 { /* derived name */
    int unknown0;       /* +0x0 */
    int unknown4;       /* +0x4 */
    int unknown8;       /* +0x8 */
    int unknownc;       /* +0xc */
    int unknown10;      /* +0x10 */
    Name name14;        /* +0x14 */
    Name name18;        /* +0x18 */
    void *unknown20;    /* +0x20 */
};

/* FUN_002033c0: the append (the count raised, the block grown when it is
 * full, then the element's copy) */
template void Array05943280<Record002033c0>::push(const Record002033c0 &);
