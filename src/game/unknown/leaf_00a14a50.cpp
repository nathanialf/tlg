/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a script C function that calls FUN_009f9430 (no arguments:
 * its body never reads rdi) and returns 0 (no results). FUN_001bd010 registers
 * it (lea at 0x1d2fe7) through FUN_00c87e30 under the script name
 * "PhysicsClearAttachingProjectileTemplate", as leaf_00c862f0.cpp's function
 * is pushed. The C function's own name is unknown. */
struct lua_State;

void FUN_009f9430(); /* derived name */

int FUN_00a14a50(lua_State *state) /* derived name */
{
    FUN_009f9430();
    return 0;
}
