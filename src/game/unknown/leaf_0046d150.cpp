/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_hks.h"

/* derived names: the script C function "SoldierMission_SubtypeToEntity"
 * (FUN_002212a0 registers it through FUN_00c89b70): reads its first
 * argument as a name (nameArgument) and pushes, through FUN_00c89360, the
 * entity (+0x28) of the first soldier of the mission's list whose subtype is
 * that name, or null; returns 1. A soldier's subtype is its own name at
 * +0x39c, else the name at +0x58 of the record FUN_002a45c0 finds for the
 * key at 0x57d5304 in its entity, else the name at 0x57d4f60. */
struct Entity0046d150; /* derived name */

struct Record002a45c0 { /* derived name */
    u8 unknown0[0x58];
    Name name; /* +0x58 */
};

struct Soldier0046d150 { /* derived name */
    u8 unknown0[0x28];
    Entity0046d150 *entity; /* +0x28 */
    u8 unknown30[0x36c];
    Name subtype; /* +0x39c */
};

struct Mission057c9390_38_900 { /* derived name */
    u8 unknown0[0x18];
    Array05943280<Soldier0046d150 *> soldiers; /* +0x18 */
};

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x900];
    Mission057c9390_38_900 *unknown900;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38;
};

extern Object057c9390 *D_57c9390;
extern const Name D_57d5304; /* derived name: the key of a soldier's subtype record */
extern const Name D_57d4f60; /* derived name: the subtype of a soldier without one */

Record002a45c0 *FUN_002a45c0(Entity0046d150 *entity, const Name *key,
                             int unknown2);                  /* derived name */
void FUN_00c89360(lua_State *state, Entity0046d150 *entity); /* derived name */

/* derived name: the soldier's subtype */
static inline const Name &subtypeOf(const Soldier0046d150 *soldier)
{
    if (soldier->subtype.index != 0)
        return soldier->subtype;
    const Record002a45c0 *record = FUN_002a45c0(soldier->entity, &D_57d5304, 1);
    return record ? record->name : D_57d4f60;
}

int FUN_0046d150(lua_State *state) /* derived name */
{
    const Name subtype = nameArgument(state, 1);
    const Array05943280<Soldier0046d150 *> &soldiers = D_57c9390->unknown38->unknown900->soldiers;
    Entity0046d150 *entity = 0;
    for (Soldier0046d150 *soldier : soldiers) {
        if (subtypeOf(soldier) == subtype) {
            entity = soldier->entity;
            break;
        }
    }
    FUN_00c89360(state, entity);
    return 1;
}
