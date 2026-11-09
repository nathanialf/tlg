/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* derived names: the string library's "find" (the name of its entry in the
 * name and function pairs; the name and function pairs that follow the slots
 * of the vtable at 0x16bc170 (its pointer at 0x16bd028, the name's at
 * 0x16bd020), the vtable stored by FUN_00dd2820 FUN_00dd2890 FUN_00de43d0
 * FUN_00de4790 FUN_013c84c0 FUN_013c8500): FUN_00de2b10 with find true, as
 * FUN_00de1800 ("match") passes false. */
struct lua_State;

int FUN_00de2b10(lua_State *state, int find); /* derived name */

int FUN_00de17f0(lua_State *state) /* derived name */
{
    return FUN_00de2b10(state, 1);
}
