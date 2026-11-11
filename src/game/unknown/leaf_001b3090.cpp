/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the script C function "SaveData_FactoryReset" (FUN_001bd010
 * registers it through FUN_00c87e30, lea at 0x1db542): on the record the
 * pointer at +0x108 of the object the pointer at 0x57c9390 holds, passes its
 * pointer at +0x38 to FUN_00a17930 and its pointer at +0x30 to FUN_00a1bdd0,
 * then the record to FUN_00a26540 and FUN_00a26130, and returns 0 (no
 * results). The state is not read; the callees' results are not traced. The
 * C function's own name is unknown. */
struct lua_State;
struct Member0a17930; /* derived name */
struct Member0a1bdd0; /* derived name */

struct Member057c9390_108 /* derived name */
{
    u8 unknown0[0x30];
    Member0a1bdd0 *unknown30; /* +0x30 */
    Member0a17930 *unknown38; /* +0x38 */
};

struct Object057c9390 /* derived name */
{
    u8 unknown0[0x108];
    Member057c9390_108 *unknown108; /* +0x108 */
};

extern Object057c9390 *D_57c9390;

void FUN_00a17930(Member0a17930 *member);      /* derived name */
void FUN_00a1bdd0(Member0a1bdd0 *member);      /* derived name */
void FUN_00a26540(Member057c9390_108 *record); /* derived name */
void FUN_00a26130(Member057c9390_108 *record); /* derived name */

int FUN_001b3090(lua_State *) /* derived name */
{
    Member057c9390_108 *save = D_57c9390->unknown108;
    FUN_00a17930(save->unknown38);
    FUN_00a1bdd0(save->unknown30);
    FUN_00a26540(save);
    FUN_00a26130(save);
    return 0;
}
