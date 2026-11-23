/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: an element of the list below, 64 bytes, a name first; the
 * rest is not traced */
struct Entry01352930 { /* derived name */
    Name name;         /* +0x0 */
    u8 unknown4[0x3c];
};

/* derived names: a record of 32 bytes in the array at +0x1c8 of the object
 * FUN_0047e690 empties (`shl rdi, 5`), destroyed one by one there and by
 * FUN_0047f7e0 and FUN_00482b90: two names and a list of entries */
struct Record01352930 { /* derived name */
    ~Record01352930();

    Name name0;                           /* +0x0 */
    Name name4;                           /* +0x4 */
    Array05943280<Entry01352930> entries; /* +0x8 */
};

/* FUN_01352930: the entries destroyed and their block released, then the
 * names, the last first */
Record01352930::~Record01352930() {}
