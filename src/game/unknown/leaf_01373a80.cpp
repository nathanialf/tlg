/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_object01367090.h"

/* derived names: the 0xa8-byte element of the array FUN_008d19c0 and
 * FUN_008d9620 empty: two Names and a pair of counted references at +0x8,
 * destroyed last to first (the pair by FUN_01367090, then the Name at
 * +0x4, then the one at +0x0); the other fields are not traced */
struct Record01373a80 {      /* derived name */
    Name name0;              /* +0x0 */
    Name name4;              /* +0x4 */
    Object01367090 unknown8; /* +0x8 */
    u64 unknown18[18];       /* +0x18 */
};

/* FUN_01373a80: the array emptied and its capacity set (each element
 * destroyed, the count cleared, the block reallocated where the capacity
 * differs) */
template void Array05943280<Record01373a80>::clear(unsigned);
