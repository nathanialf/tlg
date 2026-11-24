/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_owner004baab0.h"
#include "tlg_hks.h"

/* derived names: the records from the object at 0x57c9390 to the owner of
 * the named vectors (+0x38, +0x900, +0x50, +0x18); not traced further */
struct Member057c9390_38_900_50 { /* derived name */
    u8 unknown0[0x18];
    Owner004baab0 *owner; /* +0x18 */
};

struct Member057c9390_38_900 { /* derived name */
    u8 unknown0[0x50];
    Member057c9390_38_900_50 *unknown50; /* +0x50 */
};

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x900];
    Member057c9390_38_900 *unknown900; /* +0x900 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38; /* +0x38 */
};

extern Object057c9390 *D_57c9390;

/* derived names: a reader of the frame's arguments (as leaf_00e7ff00.cpp's) */
struct ArgumentReader0046c870 { /* derived name */

    explicit ArgumentReader0046c870(lua_State *state_)
        : state(state_), unknown8(0), unknown14(0), unknown18(0)
    {
        index = 1 - (int)((unsigned long)((char *)state_->top - (char *)state_->base) /
                          sizeof(HksObject));
    }

    lua_State *state; /* +0x0 */
    void *unknown8;   /* +0x8 */
    int index;        /* +0x10 */
    int unknown14;    /* +0x14 */
    int unknown18;    /* +0x18 */
};

void FUN_00c8edb0(ArgumentReader0046c870 *reader, Vec4 *vector); /* derived name */

/* derived names: a script C function: when the owner of the named vectors
 * is set, the vector read from the arguments set under the name the first
 * argument holds (FUN_004baab0); returns 0 (no results). Its registration
 * and its own name are not traced. */
// The base keeps the name's index in r15d across FUN_004baab0 and the release's `lock xadd`
// by the memory dependence rule (tools/patches/llvm-3.7.1-atomic-01-ordered-rmw-uncaptured-local.patch).
int FUN_0046c870(lua_State *state) /* derived name */
{
    if (Owner004baab0 *owner = D_57c9390->unknown38->unknown900->unknown50->owner) {
        Name name = nameArgument(state, 1);
        ArgumentReader0046c870 reader(state);
        Vec4 value;
        FUN_00c8edb0(&reader, &value);
        owner->setVector(name, value);
    }
    return 0;
}
