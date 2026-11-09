/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: whether its argument is one of 5, 6, 9, 10, 11, 15: bit n of
 * the 64-bit set 0x8e60 (movl of the set, btq, setb; no range check, so the
 * set is 64 bits wide and the argument is its bit number). Callers:
 * FUN_001a3e00 at 0x1a3dc1. Owner and meaning unknown. */
bool FUN_001a7050(u32 value) /* derived name */
{
    return (1ULL << value) & 0x8e60ULL;
}
