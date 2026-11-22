/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* FUN_01344a20: the array of Names has its append (called at 79 sites, the
 * new element's index returned) as a function of its own in the
 * executable: the member instantiated here. The append of another array's
 * elements, FUN_0134cea0, calls it once for each element. */
template unsigned Array05943280<Name>::add(const Name &);
