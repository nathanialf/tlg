/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a script C function, the first entry of the registration
 * table at 0x16bc858 (each entry a function and its name; this one's name
 * slot is unfilled at 0x16bc860, the next names "yield"): runs FUN_00decbe0
 * on the state, then pushes FUN_00ded4f0 with one upvalue under the name
 * "wrap_resume" through FUN_00dd6ba0, the VM's push of a named C function, and
 * returns 1 (one result): the coroutine library's wrap. The other parameters
 * of FUN_00dd6ba0 and FUN_00decbe0's result are not traced. */
struct lua_State;

typedef int (*lua_CFunction)(lua_State *state);

int FUN_00decbe0(lua_State *state); /* derived name */
int FUN_00ded4f0(lua_State *state); /* derived name */
void FUN_00dd6ba0(lua_State *state, lua_CFunction function, int upvalues, const char *name,
                  int unknown4, int unknown5); /* derived name */

int FUN_00ded030(lua_State *state) /* derived name */
{
    FUN_00decbe0(state);
    FUN_00dd6ba0(state, FUN_00ded4f0, 1, "wrap_resume", 1, 0);
    return 1;
}
