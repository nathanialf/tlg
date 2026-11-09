/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a script library function, the entry "tick" of the
 * registration table at 0x16bce30 (name, function pairs); it raises the error
 * "profile.tick() has been deprecated. Please call hks_tick() from C instead."
 * through FUN_00dbe320 (variadic: al zeroed), as a tail call, and returns its
 * result. The VM's strings name lua_State and hks; FUN_00dbe320 is the error
 * call (its name not proven). The C function's own name is unknown. */
struct lua_State;

int FUN_00dbe320(lua_State *state, const char *format, ...); /* derived name */

int FUN_00de43b0(lua_State *state) /* derived name */
{
    return FUN_00dbe320(
        state, "profile.tick() has been deprecated. Please call hks_tick() from C instead.");
}
