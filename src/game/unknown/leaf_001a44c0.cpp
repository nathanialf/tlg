/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: whether its argument is one of 0, 1, 2, 3, 4, 6, 7, 10, 11,
 * 12, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24, 25, 26: bit n of the 64-bit set
 * 0x7f7dcdf (movl of the set, btq, setb; no range check, so the set is 64 bits
 * wide and the argument is its bit number). Callers: 24 call sites from
 * FUN_012fbf40 on (each passing a value masked with 0x1f). Owner and meaning
 * unknown. */
bool FUN_001a44c0(u32 value) /* derived name */
{
    return (1ULL << value) & 0x7f7dcdfULL;
}
