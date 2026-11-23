/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_table0135b360.h"

/* FUN_00c09b10: the next slot set to the two names while fewer than 128 are
 * used, the second given name in the slot's first (FUN_00c0a000 passes the
 * names at +0x34 and +0x38 of a record) */
void Table0135b360::add(const Name &second, const Name &first)
{
    if (count < 128) {
        pairs[count].set(first, second);
        ++count;
    }
}
