/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object002c5780.h"

/* derived name: the entry appended to the array at +0x2f8 unless it is null
 * or the array holds it (the elements compared first with the count read
 * once, `cmp [rax+rcx*8], rbx; je`, then the count raised from it) */
void Object002c5780::addEntry(Entry002c5780 *entry)
{
    if (entry && !entries2f8.contains(entry))
        entries2f8.push(entry);
}
