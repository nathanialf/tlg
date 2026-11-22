/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d7eb0.h"

/* slot 5 of 0x16d7e68: for each of the five lists, the element `from` of the
 * list at +0x28, then of the list at +0xa0, copied over the element `to`
 * (each list's block read again for each copy) */
void Object016d7e68::slot5(int to, int from)
{
    for (int i = 0; i < 5; ++i) {
        lists28.at(i).at(to) = lists28.at(i).at(from);
        listsa0.at(i).at(to) = listsa0.at(i).at(from);
    }
}
