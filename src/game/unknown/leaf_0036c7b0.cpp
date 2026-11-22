/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_0036c7b0: 199/207, register assignment in the loop over the 0x50-byte elements at +0xe8: the base keeps the block in rdx and the index in ecx (as in the loop at +0x100), the build the other way. FUN_0036cb10, the deleting one, is equal but calls it. */
#include "tlg_game_object016a8bc8.h"

/* derived name: the complete destructor: the body is empty; the members
 * are released, last first, then the base. FUN_0036cb10, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a8bc8::~Object016a8bc8() {}
