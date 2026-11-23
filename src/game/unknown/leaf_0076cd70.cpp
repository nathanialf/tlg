/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016acbe8.h"

/* slot 15 of 0x16acbe8: with an object held at +0x210, its links taken out
 * of the list at 0x59396d0 (last first, each as many times as it is
 * counted: unlinkAll()'s loop over another list) and the reference
 * emptied; then the body's int at +0x58fc cleared */
void Object016acbe8::slot15()
{
    if (const Linked00c63970 *linked = static_cast<const Linked00c63970 *>(held210.get())) {
        if (linked->links.size() != 0) {
            Dispatcher00c644d0 *links = D_59396d0;
            for (int i = linked->links.size() - 1; i >= 0; --i) {
                const Link00c63970 &link =
                    static_cast<const Linked00c63970 *>(held210.get())->links.at(i);
                for (unsigned n = link.count; n != 0; --n)
                    FUN_00c63970(links, &link.first, &link.second, &held210);
            }
        }
        held210.clear();
    }
    unknown68->unknown58fc = 0;
}
