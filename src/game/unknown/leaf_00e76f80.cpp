/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: a script function (a C function of the VM, its address
 * taken where it is registered, not traced): with an argument, the record
 * the first one holds (a light userdata, tag 2, the pointer itself; a full
 * userdata, tag 7, its data 0x20 bytes in) loses its node's reference, the
 * pointer cleared after, and its name is emptied (`lock inc` of entry 0's
 * count: the empty name assigned). Returns no value. */
struct Record00e76f80 { /* derived name */
    Node00503fb0 *node; /* +0x0: never null here (the count is read unguarded) */
    Name name;          /* +0x8 */
};

/* derived name: the record an argument holds as userdata, null for another
 * type or past the frame's top */
static inline Record00e76f80 *recordOf(lua_State *state, int argument)
{
    const HksObject *value = state->base + (argument - 1);
    if (!(value < state->top))
        return 0;
    int type = value->type & 0xf;
    if (type == 2)
        return static_cast<Record00e76f80 *>(value->value.pointer);
    if (type == 7)
        return reinterpret_cast<Record00e76f80 *>(static_cast<u8 *>(value->value.pointer) + 0x20);
    return 0;
}

// NONMATCHING: 66/79, same size. The two tags' tests in the other order: the base compares 2
// first (its arm then tests the pointer for null), the build 7 first; a switch and an if chain
// give the same bytes (SimplifyCFG makes both a switch of two cases).
int FUN_00e76f80(lua_State *state) /* derived name */
{
    if (static_cast<int>(state->top - state->base) > 0) {
        if (Record00e76f80 *record = recordOf(state, 1)) {
            dropReference(record->node);
            record->node = 0;
            record->name = Name();
        }
    }
    return 0;
}
