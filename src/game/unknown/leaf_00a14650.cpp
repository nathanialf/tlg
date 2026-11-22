/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function "PhysicsDetachAllProjectile" (its
 * help "detach all projectile"; FUN_001bd010 registers it through
 * FUN_00c87e30, lea at 0x1d2f73): reads its first argument as an integer
 * through FUN_00c8cb60 and hands each projectile of the list at +0x18 of the
 * record at +0x58 of the object at 0x57c9390, from the last to the first, to
 * FUN_009f9c50 with 2 when the argument is set and 0 otherwise. Returns 0. */
struct ArgumentReader00c8c290 { /* derived name */

    /* a reader at an argument of the frame (0 the first), its index taken
     * from the top: the argument less the count of arguments */
    explicit ArgumentReader00c8c290(lua_State *state_, int argument = 0)
        : state(state_), unknown8(0), unknown14(0), unknown18(0)
    {
        index = argument - (int)((unsigned long)((char *)state_->top - (char *)state_->base) /
                                 sizeof(HksObject));
    }

    lua_State *state; /* +0x0 */
    void *unknown8;   /* +0x8 */
    int index;        /* +0x10 */
    int unknown14;    /* +0x14 */
    int unknown18;    /* +0x18 */
};

/* derived name: the projectiles, their count at +0x18 */
struct Projectiles00a14650 { /* derived name */
    u8 unknown0[0x18];
    int count; /* +0x18 */
};

struct Member057c9390_58 { /* derived name */
    u8 unknown0[0x18];
    Projectiles00a14650 *projectiles; /* +0x18 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x58];
    Member057c9390_58 *unknown58; /* +0x58 */
};

extern Object057c9390 *D_57c9390;

void FUN_00c8cb60(ArgumentReader00c8c290 *reader, int *value, void *unknown2); /* derived name */
void FUN_009f9c50(Projectiles00a14650 *projectiles, int index, int mode);      /* derived name */

int FUN_00a14650(lua_State *state) /* derived name */
{
    int all = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8cb60(&reader, &all, 0);
    Projectiles00a14650 *projectiles = D_57c9390->unknown58->projectiles;
    const int mode = all != 0 ? 2 : 0;
    for (int i = projectiles->count - 1; i >= 0; --i)
        FUN_009f9c50(projectiles, i, mode);
    return 0;
}
