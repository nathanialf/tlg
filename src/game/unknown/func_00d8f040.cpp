/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01388080.h"

/* derived names: the members of the world's write lock held for a scope
 * (tlg_game_object01388080.h's WorldWriteLock05938c40), in a unit of their
 * own named for FUN_00d8f040, the lock they take (not written yet). Neither
 * has an address in the executable: the link inlines both at every use and
 * discards them, as it does func_00c14bc0.cpp's raiseReference. Which unit
 * of the original held them is not known. */
WorldWriteLock05938c40::WorldWriteLock05938c40()
{
    D_5938c40->world->lockWrite();
}

WorldWriteLock05938c40::~WorldWriteLock05938c40()
{
    D_5938c40->world->unlockWrite();
}
