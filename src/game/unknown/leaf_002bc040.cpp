/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a7fc0.h"

/* derived names: the object put back to empty: the counted reference at
 * +0x28 emptied by compare-and-swap, the name at +0x30 assigned the empty
 * name (the empty entry's count raised, the old name's dropped, the index
 * cleared twice: 0x2bc10f and 0x2bc11f), the int at +0x34 cleared and the
 * four 8-byte words at +0x40 zeroed (one unaligned 32-byte store). The
 * class's constructor calls it (FUN_002bbed0, inlined there: 0x2bbffa). The
 * words' types are not traced. */
void Object016a7fc0::FUN_002bc040()
{
    held28.clear();
    name30 = Name();
    unknown34 = 0;
    unknown40[0] = 0;
    unknown40[1] = 0;
    unknown40[2] = 0;
    unknown40[3] = 0;
}
