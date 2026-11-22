/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_hks_string.h"

/* derived names: the script C function "PhysicsGetAttachedProjectileList"
 * (FUN_001bd010 registers it through FUN_00c87e30, lea at 0x1d2fad): the
 * projectiles FUN_009ff4d0 lists from the object at +0x18 of the record at
 * +0x58 of the object at 0x57c9390 go into a local array; a new table
 * (FUN_00d91880, the count as its hash size) gets, under the numbers 1 on,
 * the name (+0xc of the object at +0x28) of each projectile whose byte at
 * +0x7c and int at +0x30 are set. Returns 1, the table. */
struct Owner00a14760 { /* derived name */
    u8 unknown0[0xc];
    Name name; /* +0xc */
};

struct Projectile00a14760 { /* derived name */
    u8 unknown0[0x28];
    Owner00a14760 *owner; /* +0x28 */
    int unknown30;        /* +0x30 */
    u8 unknown34[0x48];
    bool unknown7c; /* +0x7c */
};

struct Projectiles00a14760; /* derived name */

struct Member057c9390_58 { /* derived name */
    u8 unknown0[0x18];
    Projectiles00a14760 *unknown18; /* +0x18 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x58];
    Member057c9390_58 *unknown58; /* +0x58 */
};

extern Object057c9390 *D_57c9390;

void FUN_009ff4d0(Projectiles00a14760 *projectiles,
                  Array01343a80<Projectile00a14760 *> *list); /* derived name */

// NONMATCHING: the base keeps the list's block in r14 across the loop's calls and the
// release (the list's address not captured: FUN_009ff4d0's body, a creator with the
// creation lock's wait loop, is not in the module), where the build reloads it from the
// frame at each element (frame 0x28 where the base has 0x38).
int FUN_00a14760(lua_State *state) /* derived name */
{
    Array01343a80<Projectile00a14760 *> list;
    FUN_009ff4d0(D_57c9390->unknown58->unknown18, &list);
    const unsigned count = list.size();
    FUN_00d91880(state, 0, count);
    int key = 1;
    for (unsigned i = 0; i < count; ++i) {
        Projectile00a14760 *projectile = list.at(i);
        if (projectile->unknown7c && projectile->unknown30 != 0) {
            pushNumber(state, key);
            const NameTableEntry017ac870 &entry = D_17ac870[projectile->owner->name.index];
            FUN_013aacc0(state, entry.string0, entry.length14);
            setTable(state);
            ++key;
        }
    }
    return 1;
}
