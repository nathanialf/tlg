/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b4ce0.h"

/* derived names: the name (the script's Guide_fadeIn, FUN_008754f0) taken
 * out of the names at +0xc0, last first, compared by their strings: every
 * copy, or the last one only; nothing is done while +0xb8 is 0 or while the
 * name is held at +0xd8, and +0xb8 is cleared once none are left. The
 * removal is the array's removeSwap, out of line (FUN_002db3e0). */
void Object016b4ce0::remove(const Name &name, bool every)
{
    if (activeB8 == 0)
        return;
    if (namesD8.indexOf(name) >= 0)
        return;
    const int count = namesC0.size();
    if (every) {
        for (int i = count - 1; i >= 0; --i)
            if (namesC0.at(i).string() == name.string())
                namesC0.removeSwap(i);
    } else {
        for (int i = count - 1; i >= 0; --i) {
            if (namesC0.at(i).string() == name.string()) {
                namesC0.removeSwap(i);
                break;
            }
        }
    }
    if (namesC0.size() == 0)
        activeB8 = 0;
}
