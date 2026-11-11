/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object013c8500.h"

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16bc170 (config/vtables.derived.base.txt; stored by FUN_00dd2820
 * FUN_00dd2890 FUN_00de43d0 FUN_00de4790 FUN_013c84c0 FUN_013c8500), slot 1
 * of it: it stores the vtable and runs the class's release, slot 0 (the body
 * at 0xdd0cb0, which leaf_00dd0cb0.cpp writes as a free function on its
 * record): when the pointer at +0x8 is set, FUN_013bf660 with it and the
 * pointer at +0x10, then the first cleared. FUN_013c8500, slot 2, is the
 * deleting one (the clear dead before operator delete). The release is
 * defined in the class, so the destructor is the key function and this file
 * emits the vtable. The types are not traced. */

Object013c8500::~Object013c8500()
{
    release();
}
