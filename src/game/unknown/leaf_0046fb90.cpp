/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function "Soldier_ExcludeJudgeKick_Enter"
 * (FUN_002212a0 registers it through FUN_00c89b70, lea at 0x22354e): reads
 * its first argument as an object through FUN_00c8c290 with a reader of the
 * frame (as leaf_0046bc50.cpp's); when it is of the type D_5939080 points to
 * (or one derived from it), its third argument is read as a string
 * (FUN_00e81bd0) and made a Name, and FUN_00a92c30 is called on the object
 * at +0x908 of the object at +0x38 of D_57c9390 with the object's Name, that
 * Name and true. Returns 0. The C function's own name is unknown. */
struct ArgumentReader00c8c290 { /* derived name */

    explicit ArgumentReader00c8c290(lua_State *state_)
        : state(state_), unknown8(0), unknown14(0), unknown18(0)
    {
        index =
            -(int)((unsigned long)((char *)state_->top - (char *)state_->base) / sizeof(HksObject));
    }

    lua_State *state; /* +0x0 */
    void *unknown8;   /* +0x8 */
    int index;        /* +0x10 */
    int unknown14;    /* +0x14 */
    int unknown18;    /* +0x18 */
};

struct KickJudge0046fb90; /* derived name */

/* derived name: an object of that type, a soldier (the C functions'
 * prefix); its own members are not read here */
class Soldier0046fb90 : public Object016b9108 /* derived name */
{
};

struct World0046fb90 /* derived name */
{
    u8 unknown0[0x908];
    KickJudge0046fb90 *kickJudge; /* +0x908 */
};

struct Game0046fb90 /* derived name */
{
    u8 unknown0[0x38];
    World0046fb90 *world; /* +0x38 */
};

extern Game0046fb90 *D_57c9390; /* derived name */
extern Type00503fb0 *D_5939080; /* derived name: the object's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */
void FUN_00a92c30(KickJudge0046fb90 *judge, const Name *name, const Name *other,
                  bool enter); /* derived name */

/* derived name: the object the frame's first argument holds, read through
 * FUN_00c8c290 (the reader's and the object's slots end here: the string and
 * the Name below take them) */
static inline Object016b9108 *objectArgument(lua_State *state)
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    return object;
}

// NONMATCHING: the Name's index after FUN_00a92c30: the base keeps it in ebx across the call
// (the callee known not to write the Name: an attribute the link infers from its body, which
// the module does not hold yet); the build reloads it from the stack
int FUN_0046fb90(lua_State *state) /* derived name */
{
    Object016b9108 *object = objectArgument(state);
    if (object && object->isKindOf(D_5939080)) {
        Soldier0046fb90 *soldier = static_cast<Soldier0046fb90 *>(object);
        HashedString string;
        FUN_00e81bd0(&string, state, 2);
        Name name(string);
        FUN_00a92c30(D_57c9390->world->kickJudge, &soldier->name, &name, true);
    }
    return 0;
}
