/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_hks.h"

/* derived names: the script C function "PropertySwitch_ReverseApply"
 * (FUN_001db8b0 registers it through FUN_00c87e30, lea at 0x1db812): reads
 * its first argument as a name (nameArgument)
 * and hands a copy of the name to FUN_00cb8790 with the object the pointer
 * at 0x57ca270 holds and the visitor FUN_002186c0 (as FUN_00858740 hands
 * FUN_00217db0); returns 0 (no results). */
struct Registry057ca270; /* derived name */

extern Registry057ca270 *D_57ca270;

struct Object002186c0;                                      /* derived name */
int FUN_002186c0(Object002186c0 *object, const Name &name); /* derived name */
void FUN_00cb8790(Registry057ca270 *registry, int (*visit)(Object002186c0 *, const Name &),
                  const Name &name); /* derived name */

int FUN_001b5740(lua_State *state) /* derived name */
{
    const Name name = nameArgument(state, 1);
    Name copy(name);
    FUN_00cb8790(D_57ca270, FUN_002186c0, copy);
    return 0;
}
