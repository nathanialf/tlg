/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"

/* derived names: the script C function the VM knows as "FindObjectW" (the
 * name FUN_00e77a00 gives it through FUN_00dd6ba0, lea at
 * 0xe783b5): with an argument, reads it as an object through FUN_00c8c290
 * with a reader of the frame (as leaf_0046bc50.cpp's); when the object is
 * connected to the world (as LuaBindings::IsConnectedToWorld answers,
 * leaf_00e75d30.cpp) and its flag 0x20 at +0x16 is clear, it is pushed
 * (FUN_00c89360) and 1 returned, else 0 (no results). */
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
class Node00e75c20 : public Object016b9108 /* derived name */
{
  public:
    int unknown24; /* +0x24: bit 0, connected */
};

class Proxy00e75c20 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0xc];
    int unknown30; /* +0x30: not zero, connected */
};

void FUN_00c8c290(ArgumentReader00c8c290 *reader, Object016b9108 **object); /* derived name */

// NONMATCHING: the second walk: the base walks the type it read for the first (`cmp rcx, rax` at
// 0xe75ccc on both edges in), the build reads the object's type again on the edge from the clear
// bit 0; with the type read once into a local the walks are the base's but the first read comes
// before the wanted type's (`mov rax, [rsi+0x18]` above `mov rcx, [D_5939080]`)
int FUN_00e75c20(lua_State *state) /* derived name */
{
    if (argumentCount(state) > 0) {
        ArgumentReader00c8c290 reader(state);
        Object016b9108 *object = 0;
        FUN_00c8c290(&reader, &object);
        if (object &&
            ((object->isKindOf(D_5939080) &&
              (static_cast<Node00e75c20 *>(object)->unknown24 & 1)) ||
             (object->isKindOf(D_59391e0) && static_cast<Proxy00e75c20 *>(object)->unknown30 != 0)))
            return pushUnlessHidden(state, object);
    }
    return 0;
}
