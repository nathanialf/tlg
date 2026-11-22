/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function
 * "Ai2InterestSystem_ResetAllInstructionLevel" (FUN_002212a0 registers it
 * through FUN_00c89b70, lea at 0x2225aa): reads its first argument as an
 * object through FUN_00c8c290 (as leaf_0031d9a0.cpp's); when it is of the
 * type D_5829020 points to (or one derived from it), hands the object at its
 * +0x138 to FUN_00aaadc0 with 0, then with 1, and returns 1; 0 otherwise. */
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

/* derived name: the object at +0x138 of an object of D_5829020's type */
struct System00aae230;

/* derived name: an object of D_5829020's type (leaf_002c40a0.cpp) */
class Object00aae230 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x114];
    System00aae230 *unknown138; /* +0x138 */
};

extern Type00503fb0 *D_5829020; /* derived name: the object's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */
void FUN_00aaadc0(System00aae230 *system, int level);                       /* derived name */

int FUN_00aae230(lua_State *state) /* derived name */
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8c290(&reader, &object);
    if (object && object->isKindOf(D_5829020)) {
        System00aae230 *system = static_cast<Object00aae230 *>(object)->unknown138;
        FUN_00aaadc0(system, 0);
        FUN_00aaadc0(system, 1);
        return 1;
    }
    return 0;
}
