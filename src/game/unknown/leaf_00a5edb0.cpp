/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "Spell_IsFinish" (FUN_00a5d530
 * registers it through FUN_00c87e30, lea at 0xa5e170, signature string "Bool
 * Spell_IsFinish()"): pushes the bool at +0xa of the object the pointer at
 * 0x5827ee0 holds and returns one result. The C function's own name is
 * unknown. */
struct Object05827ee0 { /* derived name */
    u8 unknown0[0xa];
    bool unknownA;
};

extern Object05827ee0 *D_5827ee0;

int FUN_00a5edb0(lua_State *state) /* derived name */
{
    pushBoolean(state, D_5827ee0->unknownA);
    return 1;
}
