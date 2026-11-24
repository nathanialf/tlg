/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_nametable.h"
#include "tlg_hks_string.h"

/* derived names: an entry of the two tables of numbers by name at +0x29a0
 * and +0x2ac0 of the object FUN_008eba90 reads (0x18 bytes) */
struct Entry008edad0 {   /* derived name */
    unsigned hash;       /* +0x0 */
    Name name;           /* +0x4 */
    float value;         /* +0x8 */
    Entry008edad0 *next; /* +0x10 */
};

typedef NameTable<Entry008edad0, 32> Table008edad0; /* derived name */

/* derived names: pushes a table of the numbers by their names: made with
 * room for the count, then for each entry its name's string (nil for none)
 * set to its value; one name is kept across the walk, the next entry found
 * before the entry is read */
// NONMATCHING: 449 bytes as the base; the first search of the buckets: the base walks them with a
// pointer (`mov rax, rbx` after FUN_00d91880, `mov r14, [rax]; add rax, 8`) and leaves the search
// to a test of the entry (its 0 set before the call), the build indexes the table (`mov r13,
// [r14+rax*8]`) and keeps it in r14; the second search and the body are the base's shape. Round 574E:
// the search as `if (entry) break` gives the same first search; a search inside next() made one
// search for both (385 bytes)
void FUN_008edad0(lua_State *state, const Table008edad0 *table) /* derived name */
{
    FUN_00d91880(state, 0, table->size());
    Name name;
    Table008edad0::Iterator it(*table);
    while (const Entry008edad0 *entry = it.next()) {
        const float value = entry->value;
        name = entry->name;
        pushString(state, name.string());
        pushNumber(state, value);
        setTable(state);
    }
}
