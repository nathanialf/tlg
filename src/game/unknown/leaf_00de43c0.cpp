/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a script library function, the entry "stats" of the
 * registration table at 0x16bce30 (name, function pairs, after "tick"
 * FUN_00de43b0): it calls FUN_00dd5f90 with the state and returns 0 (no
 * results). The VM's strings name lua_State. The C function's own name is
 * unknown. */
struct lua_State;

void FUN_00dd5f90(lua_State *state); /* derived name */

int FUN_00de43c0(lua_State *state) /* derived name */
{
    FUN_00dd5f90(state);
    return 0;
}
