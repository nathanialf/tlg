/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: the element of an array appended to by FUN_0052c610 (0x52c67f, 0x52c6bc):
 * two Names (each count raised before the index is stored) and two ints copied as one 8-byte move (the block aligned 4); the fields are not traced */
struct Record0052d2f0 { /* derived name */
    Name name0;         /* +0x0 */
    Name name4;         /* +0x4 */
    int unknown8;       /* +0x8 */
    int unknownc;       /* +0xc */
};

/* FUN_0052d2f0: the append (the count raised, the block grown when it is
 * full, then the element's copy) */
template void Array05943280<Record0052d2f0>::push(const Record0052d2f0 &);
