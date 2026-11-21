/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_target004ad600.h"

/* derived names: the handler FUN_004acae0 stores at 0x57d7598, beside the
 * hash of "Marker.clearlaunch.enter" at 0x57d7590: the target's pointers at
 * +0x1d0 cleared and the array emptied, then each object of the array at
 * +0x1b8 deleted (its destructor FUN_004ac9b0), its slot cleared, and that
 * array emptied; each count is read once before its loop (`jle` on it, the
 * block read again at each slot). self is not used. Class and method
 * unknown. */
void FUN_004ad6b0(Object004ad600 *, Target004ad600 *target) /* derived name */
{
    int count = target->unknown1d0.size();
    for (int i = 0; i < count; i++)
        target->unknown1d0[i] = 0;
    target->unknown1d0.removeAll();
    count = target->unknown1b8.size();
    for (int i = 0; i < count; i++) {
        delete target->unknown1b8[i];
        target->unknown1b8[i] = 0;
    }
    target->unknown1b8.removeAll();
}
