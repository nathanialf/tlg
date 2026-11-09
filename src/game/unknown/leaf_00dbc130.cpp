/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a script C function that returns 0 (no results). FUN_00dbe830
 * registers it through FUN_00ddccd0 (lea at 0xdbe960) as "next helper" beside
 * "hpairs" (FUN_00ddcea0), before "_G"; the VM loop (FUN_0149ada0,
 * FUN_014a29e0, FUN_014a8fa0) compares a called function with this address and
 * runs the iteration inline, so this body is not reached there. The VM's
 * strings name lua_State. */
struct lua_State;

int FUN_00dbc130(lua_State *state) /* derived name */
{
    return 0;
}
