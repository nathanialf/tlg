/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: whether its argument is one of 4, 5, 6, 7, 8, 9, 10, 11, 12,
 * 13, 14, 15: bit n of the 64-bit set 0xfff0 (movl of the set, btq, setb; no
 * range check, so the set is 64 bits wide and the argument is its bit number).
 * Callers: FUN_001a3e00 and others, 6 call sites. Owner and meaning unknown. */
bool FUN_001a7040(u32 value) /* derived name */
{
    return (1ULL << value) & 0xfff0ULL;
}
