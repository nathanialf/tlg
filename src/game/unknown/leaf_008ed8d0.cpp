/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: the 0x34-byte element FUN_008ed8d0 appends (called at
 * 0x8e732d and 0x8ece3d): sixteen bytes copied as one (`vmovups xmm`), four
 * names, three ints copied as one block (+0x28 before +0x20),
 * then two more names. The fields' use is not traced. */
struct Element008ed8d0 { /* derived name */
    int unknown0[4];     /* +0x0 */
    Name names10[4];     /* +0x10 */
    int unknown20[3];    /* +0x20 */
    Name name2c;         /* +0x2c */
    Name name30;         /* +0x30 */
};

/* FUN_008ed8d0 */
template void Array05943280<Element008ed8d0>::push(const Element008ed8d0 &);
