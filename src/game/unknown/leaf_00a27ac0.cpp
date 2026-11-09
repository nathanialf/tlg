/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a script C function that calls FUN_00850590 (no arguments:
 * its body never reads rdi) and returns 0 (no results). FUN_00a27090 registers
 * it (lea at 0xa27221) through FUN_00c87e30 under the script name
 * "Treasure_UpdateEquipAbility", as leaf_00c862f0.cpp's function is pushed.
 * The C function's own name is unknown. */
struct lua_State;

void FUN_00850590(); /* derived name */

int FUN_00a27ac0(lua_State *state) /* derived name */
{
    FUN_00850590();
    return 0;
}
