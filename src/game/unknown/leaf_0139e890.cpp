/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: the element of the array FUN_00bd08f0 appends to (0xbd0b06,
 * 0xbd0b37: a local at -0x68 whose Name at +0x4 it sets from a string): an
 * int, then a Name (its count raised, its index stored); the fields are not
 * traced */
struct Record0139e890 { /* derived name */
    int unknown0;       /* +0x0 */
    Name name;          /* +0x4 */
};

/* FUN_0139e890: the append that returns the new element's index (the old
 * count kept across the growth and the copy, then returned) */
template unsigned Array05943280<Record0139e890>::add(const Record0139e890 &);
