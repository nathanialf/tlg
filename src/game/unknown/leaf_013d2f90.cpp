/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013d2f90.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16d3868 (config/vtables.derived.base.txt): it stores the vtable and releases
 * the array at +0x18 (its block, tlg_game_block.h). The destructor is
 * the class's key function, so this file emits the vtable; the deleting one
 * is the compiler's. The class is in tlg_game_object013d2f90.h. */
Base013d2f90::Base013d2f90(Array01343a80<u32> *values) : current(values), unknown10(0) {}

void Object013d2f90::zeroValues()
{
    values18.resize(36);
    for (unsigned i = 0; i < values18.size(); ++i)
        values18[i] = 0;
}

Object013d2f90::~Object013d2f90() {}

void Object013d2f90::reset()
{
    zeroValues();
}
