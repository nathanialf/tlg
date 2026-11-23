/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"

/* derived names: a named list of names, 0x20 bytes */
struct Element01373de0 {       /* derived name */
    Name name;                 /* +0x0 */
    Array01343a80<Name> names; /* +0x8 */
};

/* derived names: a record of FUN_008e4880's and FUN_008e6d10's: a name and
 * an array of named lists at +0x10, destroyed by its own destructor (the
 * lists first to last, each one's names, its block, its name; then the
 * array's block; the record's name last) */
struct Record01373de0 { /* derived name */
    ~Record01373de0();

    Name name; /* +0x0 */
    u8 unknown4[0xc];
    Array05943280<Element01373de0> elements; /* +0x10 */
};

/* FUN_01373de0 */
Record01373de0::~Record01373de0() {}
