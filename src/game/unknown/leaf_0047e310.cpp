/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a virtual method that passes its arguments on to FUN_0047dea0
 * as a tail call; slot 4 of the vtable at 0x16a9dc8 (stored by FUN_0047a6e0
 * FUN_0047dd70 FUN_0047de60). FUN_0047dea0 takes a script state and a stack
 * index, tested against the VM's pseudo-indices -9999, -10000 and -10002. The
 * record is the one FUN_0047dea0 works on; the return type is not traced. */
struct lua_State;
struct Object0047dea0; /* derived name */

void FUN_0047dea0(Object0047dea0 *self, lua_State *state, int index); /* derived name */

void FUN_0047e310(Object0047dea0 *self, lua_State *state, int index) /* derived name */
{
    FUN_0047dea0(self, state, index);
}
