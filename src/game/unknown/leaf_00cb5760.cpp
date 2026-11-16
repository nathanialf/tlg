/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_module00cb57e0.h"

/* derived names: the module's complete constructor: clears the link pair,
 * stores the name, the table and its count, and pushes the module at the head
 * of the list at 0x5945880. Called by 11 static initializers (FUN_002030d0,
 * FUN_00b98590, FUN_00ea2c50, FUN_00ebf1f0, FUN_00f2b350, FUN_01078a90,
 * FUN_011f70a0, FUN_0129e6d0, FUN_012ae040, FUN_012b95f0, FUN_012f9b60). */
// NONMATCHING: the base reloads the head after the old head's back link is stored
// (`mov [rcx + 8], rdi; mov rax, [head]`): this unit's stage 1 alone gives the reload (the head
// only declared, its size unknown to BasicAA); the link stage forwards the first load. The link
// also inlines this constructor into the static initializers (at the threshold of 175), where the
// base calls it at all 11 sites: both say the base's link stage did not optimise it.
Module00cb57e0::Module00cb57e0(const char *name, const ModuleFunction00cb57e0 *functions,
                               int functionCount)
    : next(0), pprev(0), name(name), functions(functions), functionCount(functionCount)
{
    if (D_5945880)
        D_5945880->pprev = &next;
    next = D_5945880;
    pprev = &D_5945880;
    D_5945880 = this;
}
