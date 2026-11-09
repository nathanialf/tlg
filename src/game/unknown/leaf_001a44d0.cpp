/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: whether its argument is one of 5, 9, 13, 19: bit n of the
 * 64-bit set 0x82220 (movl of the set, btq, setb; no range check, so the set
 * is 64 bits wide and the argument is its bit number). Callers: no direct
 * caller found. Owner and meaning unknown. */
bool FUN_001a44d0(u32 value) /* derived name */
{
    return (1ULL << value) & 0x82220ULL;
}
