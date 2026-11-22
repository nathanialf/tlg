/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* slot 5 of the nine tables (0x16ce490 to 0x16ce6d0, folded on one body,
 * tlg_game_name.h): the string of the entry's name at an index, or the
 * fallback when the index is out of range */
const char *Object016ce490::name(int index, const char *fallback) const
{
    const NamedValue *value = index >= 0 && index < count ? &values[index] : 0;
    if (value)
        return D_17ac870[value->name.index].string0;
    return fallback;
}
