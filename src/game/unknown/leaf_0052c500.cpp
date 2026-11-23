/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_nametable.h"

/* derived names: an entry of a table of values by name, 0x18 bytes: the
 * hash (the name's index) at +0x0, the name at +0x4, the value at +0x8, the
 * next entry at +0x10 */
struct ValueEntry0052c500 { /* derived name */
    u32 hash;               /* +0x0 */
    Name name;              /* +0x4 */
    int value;              /* +0x8 */
    u8 unknownc[0x4];
    ValueEntry0052c500 *next; /* +0x10 */
};

typedef NameTable<ValueEntry0052c500, 32> ValueTable0052c500; /* derived name */

/* derived names: an entry of the table of scopes, each with its own table
 * of values (+0x8) */
struct ScopeEntry0052c500 {     /* derived name */
    u32 hash;                   /* +0x0 */
    Name name;                  /* +0x4 */
    ValueTable0052c500 *values; /* +0x8 */
    ScopeEntry0052c500 *next;   /* +0x10 */
};

/* derived names: the object FUN_005269a0, FUN_005f3370, FUN_00b10280 and
 * FUN_00b108e0 look values up in: the table of values every scope shares
 * at +0x4b38 and the table of scopes after it (+0x4c58) */
struct Values0052c500 { /* derived name */
    u8 unknown0[0x4b38];
    ValueTable0052c500 values;                /* +0x4b38 */
    NameTable<ScopeEntry0052c500, 32> scopes; /* +0x4c58 */
};

/* derived names: the value of a name and whether there is one: in the
 * scope's own table first and then in the shared one, which a scope of
 * index 0 or one with no table goes to directly */
static int get(const ValueTable0052c500 &table, const Name &name, int *value)
{
    if (ValueEntry0052c500 *entry = table.find(name.index)) {
        *value = entry->value;
        return 1;
    }
    return 0;
}

void FUN_0052c500(const Values0052c500 *self, const Name &name, unsigned scope, int *found,
                  int *value) /* derived name */
{
    if (scope == 0) {
        *found = get(self->values, name, value);
        return;
    }
    ScopeEntry0052c500 *entry = self->scopes.find(scope);
    if (!entry) {
        *found = get(self->values, name, value);
        return;
    }
    *found = get(*entry->values, name, value);
    if (!*found)
        *found = get(self->values, name, value);
}
