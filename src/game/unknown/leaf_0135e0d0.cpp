/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_block.h"
#include "tlg_game_name.h"

/* derived names: an item the lists own: a block at +0x8 and a name at
 * +0x28 (released first, then the block given back) */
struct Item0135e0d0 { /* derived name */
    u8 unknown0[0x8];
    OwnedBlock05943280 block; /* +0x8 */
    u8 unknown10[0x18];
    Name name; /* +0x28 */
};

/* derived names: five lists of owned items, 0x78 bytes, two of them at
 * +0x60 and +0xd8 of the object FUN_0135c520 destroys */
struct Lists0135e0d0 { /* derived name */
    void clear();

    Array01343a80<Item0135e0d0 *> lists[5];
};

/* FUN_0135e0d0: every list's items deleted, then the list emptied and its
 * block given back */
void Lists0135e0d0::clear()
{
    for (int i = 0; i < 5; ++i) {
        Array01343a80<Item0135e0d0 *> &list = lists[i];
        for (unsigned j = 0; j < list.size(); ++j)
            delete list.at(j);
        list.clear(0);
    }
}
