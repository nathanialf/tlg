/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00bc3b10.h"

/* FUN_00bc3b40: each pair of references dropped, the shared one first,
 * then the pointer and the int at +0x80 and +0x88 cleared */
void Object00bc3b10::releaseResources()
{
    releaseAndClear(shared50);
    releaseAndClear(counted20);
    releaseAndClear(shared58);
    releaseAndClear(counted28);
    releaseAndClear(shared60);
    releaseAndClear(counted30);
    releaseAndClear(shared68);
    releaseAndClear(counted38);
    releaseAndClear(shared70);
    releaseAndClear(counted40);
    releaseAndClear(shared78);
    releaseAndClear(counted48);
    unknown80 = 0;
    unknown88 = 0;
}
