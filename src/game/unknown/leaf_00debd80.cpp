/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the script C function "c_breakpoint" of the "debug" library:
 * its entry in the name and function table at 0x16bc8b0 that FUN_00dbeaf0
 * registers under "debug" through FUN_00ddc6b0 (between "traceback" and
 * "print"). It stops the program where a native debugger catches the trap;
 * the VM's strings name lua_State. The C function's own name is unknown. */
struct lua_State;

int FUN_00debd80(lua_State *state) /* derived name */
{
    __builtin_trap();
}
