/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a script C function that returns 1 (one result, the value
 * already on the stack top; it pushes nothing). FUN_00e705b0 pushes it (lea at
 * 0xe706f9) through FUN_00dd6ba0, the VM's push of a named C function, under
 * the script name "SVNFile"; the VM's strings name lua_State. A stub in the
 * retail build. The C function's own name is unknown. */
struct lua_State;

int FUN_00e6fc80(lua_State *state) /* derived name */
{
    return 1;
}
