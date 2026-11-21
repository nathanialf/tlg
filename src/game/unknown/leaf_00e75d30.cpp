/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* LuaBindings::IsConnectedToWorld (the name FUN_00e6e060 gives the VM for
 * it through FUN_00dd6ba0, lea at 0xe6eace; 0xe7843d gives it as
 * "IsConnectedToWorld"): with an argument, reads it as an object through
 * FUN_00c8c290 with a reader of the frame (as leaf_0046bc50.cpp's) and
 * pushes whether it is connected: for an object of the type D_5939080
 * points to (or one derived from it) bit 0 of its int at +0x24, for one of
 * the type D_59391e0 points to its int at +0x30 not zero, else false.
 * Returns 1 (one result). The row keeps its FUN_ name until a ruling, as
 * leaf_00e7e520.cpp's. derived names otherwise. */
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

extern Type00503fb0 *D_5939080; /* derived name: the node's type */
extern Type00503fb0 *D_59391e0; /* derived name: a type of node that stands for another */

/* derived names: the two kinds of object it answers for; their other
 * members are not read here */
class Node00e75d30 : public Object016b9108 /* derived name */
{
  public:
    int unknown24; /* +0x24: bit 0, connected */
};

class Proxy00e75d30 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0xc];
    int unknown30; /* +0x30: not zero, connected */
};

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */

namespace LuaBindings
{

// NONMATCHING: the frame's top: the base forms its address in each arm (`add rbx, 0x48` before
// the call and in the arm with no argument) and both arms meet before one push of the value; here
// the arm with no argument stores its false through the top it read for the count (with one push
// after the arms meet, the 0 is kept in r15 across the reader's call: leaf_00e778e0.cpp's class)
int IsConnectedToWorld(lua_State *state)
{
    Object016b9108 *object = 0;
    if (argumentCount(state) > 0) {
        ArgumentReader00c8c290 reader(state);
        FUN_00c8c290(&reader, &object);
        int connected = 0;
        if (object) {
            if (object->isKindOf(D_5939080))
                connected = static_cast<Node00e75d30 *>(object)->unknown24 & 1;
            else if (object->isKindOf(D_59391e0))
                connected = static_cast<Proxy00e75d30 *>(object)->unknown30;
        }
        pushBoolean(state, connected != 0);
    } else {
        pushBoolean(state, false);
    }
    return 1;
}

} // namespace LuaBindings
