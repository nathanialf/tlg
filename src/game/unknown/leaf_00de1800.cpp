/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a script C function registered under the script name "match"
 * in the name and function table at 0x16bcfd0 ("len", "sub", "upper", "lower",
 * "reverse", "find", "match", "gsub", "gmatch", "gfind", "format": the string
 * library's registrations); it calls FUN_00de2b10 with 0 as a tail call, as
 * the "find" entry FUN_00de17f0 does with 1. The VM's strings name lua_State.
 * The C names are unknown. */
struct lua_State;

int FUN_00de2b10(lua_State *state, int find); /* derived name */

int FUN_00de1800(lua_State *state) /* derived name */
{
    return FUN_00de2b10(state, 0);
}
