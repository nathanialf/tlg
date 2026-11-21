/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_object016a96d0.h"

/* derived names: with the source's list, +0x1b0 says whether its first item's
 * kind is 0x24 to 0x26 and +0x1b8 whether it is 1 (both cleared first, and
 * left clear without a list); +0x1b4 whether +0x1b0 was set before and no
 * longer is. Then slot 28. */
// NONMATCHING: 11/47, 166 bytes against 170: the base carries the new +0x1b0 as an int
// across the list test (`xor edx, edx` before it, `test edx, edx; sete cl` after the merge,
// then `test eax, eax; jne; xor ecx, ecx`); the build folds `!unknown1b0` into the phi as an
// i1 (`mov cl, 1` first, `xor cl, 1` in the list arm: InstCombine's FoldOpIntoPhi) and ands it.
void Object016a96d0::slot24(Source00402f30 *source)
{
    const int was = unknown1b0;
    unknown1b0 = 0;
    unknown1b8 = 0;
    if (List00402f30 *list = source->list) {
        Item00402f30 *item = list->first();
        unknown1b0 = item && item->kind >= 0x24 && item->kind <= 0x26;
        item = list->first();
        unknown1b8 = item && item->kind == 1;
    }
    unknown1b4 = was && !unknown1b0;
    slot28();
}
