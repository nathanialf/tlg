/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_parameters01358c30.h"

/* derived names: each of the table's entries gets its three names, each
 * made new from the entry's string (FUN_00ad8d30, FUN_0057c270 and the
 * other constructors over Object016cb108 call it on their tables at +0x38
 * the first time one of them is made). The table and its count are read
 * once (`mov r13d, [rdi+0x38]` and `mov r12, [rdi+0x30]` before the loop,
 * the count counted down): the names' stores could reach them otherwise
 * (the game is built without type-based aliasing). */
void Parameters01358c30::bindNames() /* derived name */
{
    const int count = count38;
    Parameter01358c30 *entries = entries30;
    for (int i = 0; i < count; ++i) {
        Parameter01358c30 &entry = entries[i];
        entry.first.bind();
        entry.second.bind();
        entry.third.bind();
    }
}
