/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: a record of a counted reference at +0x8 and two names at
 * +0x10 and +0x14 (its destructor is called at 0x714709 and 0x13637e9);
 * the first word is not traced */
struct Record01365970 /* derived name */
{
    ~Record01365970();

    u8 unknown0[0x8];
    Ref00503fb0<Object016b9108> held8; /* +0x8 */
    Name name10;                       /* +0x10 */
    Name name14;                       /* +0x14 */
};

/* derived name: the members released last to first */
Record01365970::~Record01365970() {}
