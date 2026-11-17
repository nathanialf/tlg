/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_hks.h"
#include "tlg_libc.h"

/* derived names: the script C function FUN_00a5d530 registers (lea at
 * 0xa5e136) under the script name "Spell_SetupParameterTable": the counted
 * reference at 0x5827ee8 set to the object the first argument's string names
 * (looked up, not interned: the last argument of FUN_013baad0 0) when it is
 * usable by this thread and its type is the one D_5827ed0 points to (that
 * type itself: no walk to the parents), else emptied; returns 0 (no
 * results). A null or empty string names nothing. The C function's own name
 * is unknown; the class is not traced. */
struct Table00a5ebe0 : Object016b9108 /* derived name */
{};

extern const Type00503fb0 *D_5827ed0;               /* derived name: the table's type */
extern AtomicRef0045c470<Object016b9108> D_5827ee8; /* derived name */

int FUN_00a5ebe0(lua_State *state) /* derived name */
{
    const char *string = 0;
    if (state->base < state->top)
        string = FUN_00db6b20(state, state->base, 0);
    Name name;
    if (string && *string)
        name.index = FUN_013baad0(string, FUN_013bad90(string), strlen(string), false);
    D_5827ee8.set(findNamedOf<Table00a5ebe0>(name, D_5827ed0));
    return 0;
}
