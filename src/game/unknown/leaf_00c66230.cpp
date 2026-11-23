/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b86e0.h"
#include "tlg_sce_pad.h"

/* the destructors FUN_00c66230 and FUN_00c662e0: an open handle closed and
 * cleared, the block deleted, then the array */
// NONMATCHING: FUN_00c662e0 (D0): the base's deleting destructor holds this body (165 bytes); here
// it calls it (28 bytes): the body costs 280 at the unit stage, over 225 unhinted, under 325 hinted.
// A hinted (inline) destructor is emitted only where the class is used, the creator's unit
// (FUN_00c32940, not written)
Object016b86e0::~Object016b86e0()
{
    if (handle > 0) {
        scePadClose(handle);
        handle = 0;
    }
    delete state;
}
