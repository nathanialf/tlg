/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a7a50.h"
#include "tlg_game_object05945a38.h"
#include "tlg_hks.h"

/* derived names: the script C function "Ai2ResetStaticVolSensor"
 * (FUN_002212a0 registers it through FUN_00c89b70, lea at 0x222148): under
 * the recursive lock of the object at 0x5945a38, hands FUN_00296f80 to
 * FUN_00cb8490 for the objects of the type D_57cada0 points to (the type
 * FUN_00297030 creates Object016a7a50 with), which empties the array of
 * names at +0x580 of each; returns 0 (no results). */
extern Type00503fb0 *D_57cada0; /* derived name: Object016a7a50's type */

void FUN_00cb8490(Type00503fb0 *type, int (*visit)(Object016b9108 *object),
                  int flags); /* derived name */

/* the visitor: an object of the type has its names dropped (the block kept);
 * returns 1 */
int FUN_00296f80(Object016b9108 *object) /* derived name */
{
    if (Object016a7a50 *sensor = static_cast<Object016a7a50 *>(kindOf(object, D_57cada0)))
        sensor->names580.removeAll();
    return 1;
}

int FUN_00296e40(lua_State *) /* derived name */
{
    D_5945a38->lock201028.lock();
    FUN_00cb8490(D_57cada0, FUN_00296f80, 0);
    D_5945a38->lock201028.unlock();
    return 0;
}
