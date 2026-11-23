/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013baac0.h"

/* derived names: the complete destructor of the global objects at 0x59497d0,
 * 0x5949800 and 0x59497e8 (FUN_00d667c0's unit, which registers it with
 * __cxa_atexit for each); its own body is empty, so the destructor of its
 * base, the array's (0x134f620, which releases the references in the block
 * at +0x0 counted by the int at +0x8), runs as a tail call. */
Object013baac0::~Object013baac0() {}
