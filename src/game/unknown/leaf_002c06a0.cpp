/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_libc.h"

/* derived names: an entry of the list at +0x258 of FUN_002c06a0's object,
 * its name at +0x24 */
struct Entry002c06a0 /* derived name */
{
    u8 unknown0[0x24];
    Name name; /* +0x24 */
};

struct Object002c06a0 /* derived name */
{
    u8 unknown0[0x258];
    Array05943280<Entry002c06a0 *> entries; /* +0x258 */
};

/* derived names: the entry of the object's list whose name is the string
 * (looked up without interning it; the empty name for no string or an empty
 * one), else the first entry, null for an empty list; called by
 * FUN_00307100 and FUN_00334620 (call sites 0x3071a5, 0x3349ea). */
Entry002c06a0 *FUN_002c06a0(Object002c06a0 *self, const char *string) /* derived name */
{
    Name name;
    if (string && *string)
        name.index = FUN_013baad0(string, FUN_013bad90(string), strlen(string), false);
    for (unsigned i = 0; i < self->entries.size(); ++i)
        if (name == self->entries.at(i)->name)
            return self->entries.at(i);
    return self->entries.size() ? self->entries[0] : 0;
}
