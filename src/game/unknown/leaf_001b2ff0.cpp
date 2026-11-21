/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: the script C function "SaveData_NewGame" (FUN_001bd010,
 * lea at 0x1db512): over the perpetual data (+0x108 of the object at
 * 0x57c9390): FUN_00a17bb0 on its record at +0x38; the counters' record at
 * +0x30 marked (its int at +0x24 set to 1 unless already set, the eight
 * bytes after it cleared); the int at +0x30 of the object at 0x5827190
 * cleared when there is one; 0x20000 bytes at +0x52000 of the buffer at +0x40
 * cleared; then FUN_00a26540 and the save, FUN_00a26130 (as "SavePerpetual"
 * does). Returns no results. The records' types are not traced. */
struct lua_State;

struct Counts001b2ff0 { /* derived name */
    u8 unknown0[0x24];
    int unknown24; /* +0x24 */
    u64 unknown28; /* +0x28 */
};

struct Member057c9390_108 { /* derived name */
    u8 unknown0[0x30];
    Counts001b2ff0 *counts; /* +0x30, derived name */
    void *unknown38;        /* +0x38 */
    u8 *unknown40;          /* +0x40 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x108];
    Member057c9390_108 *unknown108;
};

extern Object057c9390 *D_57c9390;

struct Object05827190 { /* derived name */
    u8 unknown0[0x30];
    int unknown30; /* +0x30 */
};

extern Object05827190 *D_5827190;

void FUN_00a17bb0(void *record);               /* derived name */
void FUN_00a26540(Member057c9390_108 *member); /* derived name */
void FUN_00a26130(Member057c9390_108 *member); /* derived name */

int FUN_001b2ff0(lua_State *) /* derived name */
{
    Member057c9390_108 *data = D_57c9390->unknown108;
    FUN_00a17bb0(data->unknown38);
    Counts001b2ff0 *counts = data->counts;
    if (counts->unknown24 == 0)
        counts->unknown24 = 1;
    counts->unknown28 = 0;
    if (D_5827190)
        D_5827190->unknown30 = 0;
    memset(data->unknown40 + 0x52000, 0, 0x20000);
    FUN_00a26540(data);
    FUN_00a26130(data);
    return 0;
}
