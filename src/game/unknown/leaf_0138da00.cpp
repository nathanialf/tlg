/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* slot 6 of the nine tables (0x16ce490 to 0x16ce6d0, folded on one body,
 * tlg_game_name.h): the index of the entry whose name is the string's, or
 * -1. The string is looked up without being interned (`xor ecx, ecx`), and
 * a null or empty string is the empty name. */
int Object016ce490::find(const char *string) const
{
    Name name;
    if (string && *string)
        name.index = FUN_013baad0(string, FUN_013bad90(string), strlen(string), false);
    for (int i = 0; i < count; ++i)
        if (values[i].name == name)
            return i;
    return -1;
}
