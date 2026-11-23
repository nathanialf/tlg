/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aa0d0.h"

static inline bool isActive(const Source004afdb0 *source) /* derived name */
{
    return !(source->flags5c & 1) && source->unknown30 != 0;
}

// NONMATCHING: 14/30; every test and load in the base's order, but the base ends in `and al, cl` (cl 1 once the
// source is held, 0 on every earlier failure; al the source's test), the only such tail in the game region, where
// this form returns from each arm; `&`, `&=` and a flag variable were measured (round 484D) and do not give it
bool Object016aa0d0::slot5() const
{
    const Value004afdb0 *value = held28.get();
    if (!value || (value->flags24 & 0x81) != 1 ||
        ((value->flags24 & 0x40) && value->unknown48 == 0))
        return false;
    const Source004afdb0 *source = held30.get();
    return source && isActive(source);
}
