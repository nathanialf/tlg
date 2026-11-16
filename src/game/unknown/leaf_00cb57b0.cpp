/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_module00cb57e0.h"

/* derived names: the module's complete destructor: takes the module out of
 * the list (the next module's back link set to the module's, the field the
 * back link points at set to the next module) and clears both links. Its
 * address is registered at exit by the 11 static initializers that make a
 * module, and taken nowhere else. */
Module00cb57e0::~Module00cb57e0()
{
    if (next) {
        next->pprev = pprev;
    }
    if (pprev) {
        *pprev = next;
    }
    next = 0;
    pprev = 0;
}
