/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"

/* derived names: the element of the locked array FUN_008e6d10 and
 * FUN_008ed120 copy (0x8e768a, 0x8ed4b1): one Name; the class is this
 * unit's own, not traced (the copy shared by the other units is
 * FUN_004cdb70, over Name itself) */
struct Entry008edca0 { /* derived name */
    Name name;         /* +0x0 */
};

/* FUN_008edca0: the locked array copied: each name's count raised as it is
 * copied */
template Array01343a80<Entry008edca0>::Array01343a80(const Array01343a80<Entry008edca0> &);
