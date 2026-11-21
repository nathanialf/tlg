/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_hks.h"

/* derived names: the script C function
 * "Ai2VolumeIsInVolumeSubTypeClearParameters" (FUN_002212a0 registers it
 * through FUN_00c89b70): with exactly one argument, read as an object
 * through FUN_00c8c290, and the object of the type D_57cb390 points to (or
 * one derived from it: Object016a7ea8's, leaf_002aa650.cpp), empties its
 * array of counted references at +0x308 (each dropped, the count cleared)
 * and returns 1; else returns 0. Nothing is pushed. */
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

/* derived name: an object of that type: its array of references at +0x308
 * (their objects not traced) */
class Volume002b0b70 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x308 - sizeof(Object016b9108)];
    Array05943280<Ref00503fb0<Object016b9108>> parameters; /* +0x308 */
};

extern Type00503fb0 *D_57cb390; /* derived name: the volume's type */

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */

/* derived name: the object an argument of the frame holds, read through
 * FUN_00c8c290 */
static inline Object016b9108 *objectArgument(lua_State *state, int argument)
{
    Object016b9108 *object = 0;
    ArgumentReader00c8c290 reader(state, argument);
    FUN_00c8c290(&reader, &object);
    return object;
}

int FUN_002b0b70(lua_State *state) /* derived name */
{
    if (argumentCount(state) != 1)
        return 0;
    Object016b9108 *object = objectArgument(state, 0);
    if (!object || !object->isKindOf(D_57cb390))
        return 0;
    static_cast<Volume002b0b70 *>(object)->parameters.removeAll();
    return 1;
}
