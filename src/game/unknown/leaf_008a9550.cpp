/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: the 16-byte element FUN_008a9550 appends (called at
 * 0x885bf6 and 0x8866b6): a name (its count raised, then its index
 * copied), an int and a counted reference. The fields' use is not traced. */
struct Element008a9550 {              /* derived name */
    Name name;                        /* +0x0 */
    int unknown4;                     /* +0x4 */
    Ref00503fb0<Object016b9108> ref8; /* +0x8 */
};

/* FUN_008a9550 */
template void Array05943280<Element008a9550>::push(const Element008a9550 &);
